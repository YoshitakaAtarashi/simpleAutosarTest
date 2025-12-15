# GUI Simulator Quick Start Script (Windows)

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  AUTOSAR GUI Simulator" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Check Python installation
Write-Host "Checking Python installation..." -ForegroundColor Yellow
$pythonCmd = Get-Command python -ErrorAction SilentlyContinue

if (-not $pythonCmd) {
    Write-Host "Python not found! Please install Python 3.7 or higher." -ForegroundColor Red
    Write-Host "Download from: https://www.python.org/downloads/" -ForegroundColor Yellow
    exit 1
}

$pythonVersion = python --version
Write-Host "Found: $pythonVersion" -ForegroundColor Green
Write-Host ""

# Check matplotlib installation
Write-Host "Checking matplotlib..." -ForegroundColor Yellow
$matplotlibCheck = python -c "import matplotlib" 2>&1

if ($LASTEXITCODE -ne 0) {
    Write-Host "matplotlib not found. Installing..." -ForegroundColor Yellow
    pip install matplotlib
    
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Failed to install matplotlib!" -ForegroundColor Red
        exit 1
    }
} else {
    Write-Host "matplotlib is installed" -ForegroundColor Green
}

Write-Host ""
Write-Host "Starting AUTOSAR GUI Simulator..." -ForegroundColor Green
Write-Host ""

# Run the simulator
python simulator_gui.py
