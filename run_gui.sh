#!/bin/bash
# GUI Simulator Quick Start Script (Linux/macOS)

echo "========================================"
echo "  AUTOSAR GUI Simulator"
echo "========================================"
echo ""

# Check Python installation
echo "Checking Python installation..."
if ! command -v python3 &> /dev/null; then
    echo "Python3 not found! Please install Python 3.7 or higher."
    exit 1
fi

python3 --version
echo ""

# Check matplotlib installation
echo "Checking matplotlib..."
python3 -c "import matplotlib" 2>&1

if [ $? -ne 0 ]; then
    echo "matplotlib not found. Installing..."
    pip3 install matplotlib
    
    if [ $? -ne 0 ]; then
        echo "Failed to install matplotlib!"
        exit 1
    fi
else
    echo "matplotlib is installed"
fi

echo ""
echo "Starting AUTOSAR GUI Simulator..."
echo ""

# Run the simulator
python3 simulator_gui.py
