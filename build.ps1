# 簡単なビルド＆実行スクリプト（Windows PowerShell用）

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  AUTOSAR Learning Environment" -ForegroundColor Cyan
Write-Host "  Build Script" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# ビルドディレクトリ作成
if (-not (Test-Path "build")) {
    Write-Host "Creating build directory..." -ForegroundColor Yellow
    New-Item -ItemType Directory -Path "build" | Out-Null
}

# ビルドディレクトリに移動
Set-Location "build"

# CMake設定
Write-Host "Configuring CMake..." -ForegroundColor Yellow
cmake ..

if ($LASTEXITCODE -ne 0) {
    Write-Host "CMake configuration failed!" -ForegroundColor Red
    Set-Location ..
    exit 1
}

# ビルド実行
Write-Host "Building project..." -ForegroundColor Yellow
cmake --build .

if ($LASTEXITCODE -ne 0) {
    Write-Host "Build failed!" -ForegroundColor Red
    Set-Location ..
    exit 1
}

# 元のディレクトリに戻る
Set-Location ..

Write-Host ""
Write-Host "Build completed successfully!" -ForegroundColor Green
Write-Host ""
Write-Host "To run the simulation, execute:" -ForegroundColor Cyan
Write-Host "  .\build\Debug\AutosarSim.exe" -ForegroundColor White
Write-Host "or" -ForegroundColor Cyan
Write-Host "  .\run.ps1" -ForegroundColor White
