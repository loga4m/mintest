#!/bin/bash

echo "mintest installer...>"
echo "Clean up..."
sudo echo "mintest uninstaller...>"
sudo rm -rf /usr/local/lib/mintest
sudo rm -rf /usr/include/mintest

sources=$(find ./src -name "*.cpp")
echo "$sources"

if [ -z "$sources" ]; then
  echo "Error: no source files."
  exit 1
fi

echo "Compiling source..."
sudo g++ -fPIC -shared $sources -o ./mintest.so

echo "Copying library files..."
sudo mkdir /usr/include/mintest
sudo mv ./mintest.so /usr/local/lib/libmintest.so
sudo cp -r ./include/* /usr/include/mintest
sudo ldconfig

sudo echo "Successfully installed."
