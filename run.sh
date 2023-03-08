#!/bin/bash

# This script is used to downmload packages from the internet and install them
# Need to do with cmake or make a real script to find os...

if [ -d "./build" ]; then
  rm -rf ./build
fi

if [ -f "./r-type_client" ];then
  rm ./r-type_client
fi

if [ -f "./r-type_server" ];then
  rm ./r-type_server
fi

mkdir build && cd build && conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True && cmake .. -G "Unix Makefiles" && cmake --build .
# mkdir build && cd build && conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True && cd .. && cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build

cp ./client/r-type_client ../r-type_client
cp ./server/r-type_server ../r-type_server