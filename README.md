# FM-SIM
Simulateur de forgemagie 2.26

## Build Window

#### Prérequis
- vcpkg
- un compilateur c++17

1) Installez nana avec vcpkg
2) Créez un dossier temporaire
3) Dans ce dossier, lancez `cmake .. -DCMAKE_TOOLCHAIN_FILE=<chemin vers vcpkg>\scripts\buildsystems\vcpkg.cmake` puis `cmake . --build`
4) lancer `fm.exe`