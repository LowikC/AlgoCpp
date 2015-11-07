set BUILD_DIR=..\build-cmake-vs2013

mkdir %BUILD_DIR%
cd %BUILD_DIR%

cmake -G "Visual Studio 12" ..\script-cmake
