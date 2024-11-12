#!/bin/bash

echo "build c test"
cd C || exit
rm -r build
mkdir -p build
cd build || exit
cmake ..
make
cd ../..

echo ""
echo "run c test"
echo ""

./C/build/c_test

echo ""
echo "run go test"

echo ""
echo "prepare environment"
OS=$(uname)
if [[ "$OS" == "Darwin" ]]; then
    export DYLD_LIBRARY_PATH=../C/build:$DYLD_LIBRARY_PATH
    echo "macOS detected. DYLD_LIBRARY_PATH set."
elif [[ "$OS" == "Linux" ]]; then
    export LD_LIBRARY_PATH=../C/build:$LD_LIBRARY_PATH
    echo "Linux detected. LD_LIBRARY_PATH set."
else
    echo "Unsupported OS: $OS"
fi

cd GO || exit
echo ""
go run cgo_qsort.go
cd .. || exit
