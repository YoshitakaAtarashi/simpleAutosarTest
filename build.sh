#!/bin/bash
# ビルド＆実行スクリプト（Linux/macOS用）

echo "========================================"
echo "  AUTOSAR Learning Environment"
echo "  Build Script"
echo "========================================"
echo ""

# ビルドディレクトリ作成
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

# ビルドディレクトリに移動
cd build

# CMake設定
echo "Configuring CMake..."
cmake ..

if [ $? -ne 0 ]; then
    echo "CMake configuration failed!"
    cd ..
    exit 1
fi

# ビルド実行
echo "Building project..."
make

if [ $? -ne 0 ]; then
    echo "Build failed!"
    cd ..
    exit 1
fi

# 元のディレクトリに戻る
cd ..

echo ""
echo "Build completed successfully!"
echo ""
echo "To run the simulation, execute:"
echo "  ./build/AutosarSim"
echo "or"
echo "  ./run.sh"
