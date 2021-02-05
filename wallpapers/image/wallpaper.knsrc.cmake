[KNewStuff3]
Name=Wallpapers
Name[ast]=Fondos de pantalla
Name[ca]=Fons de pantalla
Name[ca@valencia]=Fons de pantalla
Name[cs]=Tapety
Name[da]=Baggrundsbilleder
Name[de]=Hintergrundbilder
Name[el]=Ταπετσαρίες
Name[en_GB]=Wallpapers
Name[es]=Fondos del escritorio
Name[et]=Taustapildid
Name[eu]=Horma-paperak
Name[fi]=Taustakuvat
Name[fr]=Fonds d'écran
Name[gl]=Fondos de escritorio
Name[he]=רקעים
Name[hu]=Háttérképek
Name[id]=Wallpaper
Name[it]=Sfondi
Name[ko]=배경 그림
Name[lt]=Darbalaukio fonai
Name[lv]=Tapetes
Name[nl]=Achtergrondafbeeldingen
Name[nn]=Bakgrunnsbilete
Name[pa]=ਵਾਲਪੇਪਰ
Name[pl]=Tapety
Name[pt]=Papéis de Parede
Name[pt_BR]=Papéis de parede
Name[ru]=Обои
Name[sk]=Tapety
Name[sl]=Slike ozadij
Name[sr]=тапети
Name[sr@ijekavian]=тапети
Name[sr@ijekavianlatin]=tapeti
Name[sr@latin]=tapeti
Name[sv]=Skrivbordsunderlägg
Name[tr]=Duvar Kağıtları
Name[uk]=Зображення тла
Name[x-test]=xxWallpapersxx
Name[zh_CN]=壁纸
Name[zh_TW]=桌布

ProvidersUrl=https://autoconfig.kde.org/ocs/providers.xml
Categories=KDE Wallpaper 800x600,KDE Wallpaper 1024x768,KDE Wallpaper 1280x1024,KDE Wallpaper 1440x900,KDE Wallpaper 1600x1200,KDE Wallpaper (other)
TargetDir=wallpapers
Uncompress=subdir-archive

AdoptionCommand=@QtBinariesDir@/qdbus org.kde.plasmashell /PlasmaShell org.kde.PlasmaShell.evaluateScript "for (var i in desktops()) { d = desktops()[i]; d.wallpaperPlugin = 'org.kde.image'; d.currentConfigGroup = ['Wallpaper', 'org.kde.image', 'General']; d.writeConfig('Image', %f) }"
