/*
    SPDX-FileCopyrightText: 2004 Esben Mose Hansen <kde@mosehansen.dk>

    SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "historyitem.h"

#include "klipper_debug.h"
#include <QMap>

#include <kurlmimedata.h>

#include "historyimageitem.h"
#include "historymodel.h"
#include "historystringitem.h"
#include "historyurlitem.h"

HistoryItem::HistoryItem(const QByteArray &uuid)
    : m_uuid(uuid)
{
}

HistoryItem::~HistoryItem()
{
}

HistoryItemPtr HistoryItem::create(const QMimeData *data)
{
    if (data->hasUrls()) {
        KUrlMimeData::MetaDataMap metaData;
        QList<QUrl> urls = KUrlMimeData::urlsFromMimeData(data, KUrlMimeData::PreferKdeUrls, &metaData);
        if (urls.isEmpty()) {
            return HistoryItemPtr();
        }
        QByteArray bytes = data->data(QStringLiteral("application/x-kde-cutselection"));
        bool cut = !bytes.isEmpty() && (bytes.at(0) == '1'); // true if 1
        return HistoryItemPtr(new HistoryURLItem(urls, metaData, cut));
    }
    if (data->hasText()) {
        const QString text = data->text();
        if (text.isEmpty()) { // reading mime data can fail. Avoid ghost entries
            return HistoryItemPtr();
        }
        return HistoryItemPtr(new HistoryStringItem(data->text()));
    }
    if (data->hasImage()) {
        const QImage image = qvariant_cast<QImage>(data->imageData());
        if (image.isNull()) {
            return HistoryItemPtr();
        }
        return HistoryItemPtr(new HistoryImageItem(image));
    }

    return HistoryItemPtr(); // Failed.
}

HistoryItemPtr HistoryItem::create(QDataStream &dataStream)
{
    if (dataStream.atEnd()) {
        return HistoryItemPtr();
    }
    QString type;
    dataStream >> type;
    if (type == QLatin1String("url")) {
        QList<QUrl> urls;
        QMap<QString, QString> metaData;
        int cut;
        dataStream >> urls;
        dataStream >> metaData;
        dataStream >> cut;
        return HistoryItemPtr(new HistoryURLItem(urls, metaData, cut));
    }
    if (type == QLatin1String("string")) {
        QString text;
        dataStream >> text;
        return HistoryItemPtr(new HistoryStringItem(text));
    }
    if (type == QLatin1String("image")) {
        QImage image;
        dataStream >> image;
        return HistoryItemPtr(new HistoryImageItem(image));
    }
    qCWarning(KLIPPER_LOG) << "Failed to restore history item: Unknown type \"" << type << "\"";
    return HistoryItemPtr();
}

#include "moc_historyitem.cpp"
