if [ -d "./build/" ]; then   #判断文件夹build是否存在，存在则先删除再创建
    rm -r build
    mkdir build
else 
    mkdir build
fi

cd build
cmake ..
cmake --build .
TIMEOUT /T -1
