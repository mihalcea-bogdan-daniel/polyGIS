ECHO OFF
ECHO STARTING CMAKE ... 
PAUSE
ECHO Archicad development kit location?(Hit enter for default = C:\Program Files\GRAPHISOFT\API Development Kit 24.3009)
set /p "AC_API_DEV_PATH=" || SET "AC_API_DEV_PATH=C:\Program Files\GRAPHISOFT\API Development Kit 24.3009" 
ECHO Archicad development kit location: %AC_API_DEV_PATH%
ECHO What is your AddOn name? (Hit enter for default = polyGIS)
set /p "ADDON_NAME=" || SET "ADDON_NAME=polyGIS" 
ECHO Archicad AddOn name is: %ADDON_NAME%
PAUSE
if exist Build\ (
    ECHO Build folder exists
    cd Build
    cmake -G "Visual Studio 15 2017" -A "x64" -DAC_API_DEVKIT_DIR="%AC_API_DEV_PATH%" -DAC_ADDON_NAME="%ADDON_NAME%" ..
    cd ..
) else (
    ECHO Creating /Build folder
    mkdir Build
    cd Build
    cmake -G "Visual Studio 15 2017" -A "x64" -DAC_API_DEVKIT_DIR="%AC_API_DEV_PATH%" -DAC_ADDON_NAME="%ADDON_NAME%" ..
    cd ..
)
PAUSE