if not exist build (
    mkdir build
) else (
    del /S /Q /F build
    rd /S /Q build
    mkdir build
)
 
cd build
cmake ..
cmake --build .

cd ..\..\
if not exist CrossPlatformLib (
    mkdir CrossPlatformLib
) else (
    del /S /Q /F CrossPlatformLib
    rd /S /Q CrossPlatformLib
    mkdir CrossPlatformLib
)
cd Library

xcopy Interface\ ..\CrossPlatformLib\Interface\ /e
copy ThirdLibWin\libxl\binx64\libxl.dll ..\CrossPlatformLib\
copy Bin64\Debug\CrossPlatformLib.dll ..\CrossPlatformLib\
copy Bin64\Debug\CrossPlatformLib.lib ..\CrossPlatformLib\

del /S /Q /F Bin64
rd /S /Q Bin64

del /S /Q /F build
rd /S /Q build

TIMEOUT /T -1
