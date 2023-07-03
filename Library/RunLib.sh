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
if [ -d "./CrossPlatformLib/" ]; then
    rm -r CrossPlatformLib
    mkdir CrossPlatformLib
else 
    mkdir CrossPlatformLib
fi
cd Library

cp -R ./Interface/ ../CrossPlatformLib/
cp ./Bin64/libCrossPlatformLib.so ../CrossPlatformLib/
mkdir -p ../CrossPlatformLib/ThirdLibLinux/libxl/;cp -arf ./ThirdLibLinux/libxl/lib64 ../CrossPlatformLib/ThirdLibLinux/libxl/

rm -r ./Bin64
rm -r ./build

TIMEOUT /T -1
