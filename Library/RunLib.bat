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
if not exist Out (
    mkdir Out
) else (
    del /S /Q /F Out
    rd /S /Q Out
    mkdir Out
)
cd Library

xcopy Interface\ ..\Out\Interface\ /e
copy ThirdLibWin\libxl\binx64\libxl.dll ..\Out\
copy Bin64\Debug\CrossPlatformLib.dll ..\Out\

del /S /Q /F Bin64
rd /S /Q Bin64

del /S /Q /F build
rd /S /Q build

TIMEOUT /T -1
