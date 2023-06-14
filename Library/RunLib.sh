if [ -d "./build/" ]; then
    rm -r build
    mkdir build
else 
    mkdir build
fi

cd build
cmake ..
cmake --build .

cd ../../
if [ -d "./Out/" ]; then
    rm -r Out
    mkdir Out
else 
    mkdir Out
fi
cd Library

cp -R ./Interface/ ../Out/
cp ./Bin64/libCrossPlatformLib.so ../Out/
mkdir -p ../Out/ThirdLibLinux/libxl/;cp -arf ./ThirdLibLinux/libxl/lib64 ../Out/ThirdLibLinux/libxl/

rm -r ./Bin64
rm -r ./build

TIMEOUT /T -1
