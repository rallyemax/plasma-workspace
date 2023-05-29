/*
    SPDX-FileCopyrightText: 2008 Sebastian Kügler <sebas@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <KRunner/AbstractRunner>
#include <KRunner/Action>

class RecentDocuments : public KRunner::AbstractRunner
{
    Q_OBJECT

public:
    RecentDocuments(QObject *parent, const KPluginMetaData &metaData);

    void match(KRunner::RunnerContext &context) override;
    void run(const KRunner::RunnerContext &context, const KRunner::QueryMatch &match) override;

private:
    const KRunner::Actions m_actions;
};
