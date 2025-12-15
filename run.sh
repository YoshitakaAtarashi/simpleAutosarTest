#!/bin/bash
# 実行スクリプト（Linux/macOS用）

echo "========================================"
echo "  AUTOSAR Simulation"
echo "========================================"
echo ""

# 実行ファイルの確認
if [ ! -f "./build/AutosarSim" ]; then
    echo "Executable not found! Please build the project first."
    echo "Run: ./build.sh"
    exit 1
fi

echo "Running simulation..."
echo ""

# シミュレーション実行
./build/AutosarSim

echo ""
echo "Simulation finished."
