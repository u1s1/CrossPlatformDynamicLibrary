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

xcopy Library\Interface\ Out\Interface\ /e
copy ThirdLibWin\libxl\binx64\libxl.dll Out\
copy Library\Bin64\Debug\CrossPlatformLib.dll Out\

del /S /Q /F Library\Bin64
rd /S /Q Library\Bin64

del /S /Q /F Library\build
rd /S /Q Library\build

TIMEOUT /T -1
