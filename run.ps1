# 実行スクリプト（Windows PowerShell用）

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  AUTOSAR Simulation" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# 実行ファイルの検索
$exePaths = @(
    ".\build\Debug\AutosarSim.exe",
    ".\build\Release\AutosarSim.exe",
    ".\build\AutosarSim.exe"
)

$exePath = $null
foreach ($path in $exePaths) {
    if (Test-Path $path) {
        $exePath = $path
        break
    }
}

if ($null -eq $exePath) {
    Write-Host "Executable not found! Please build the project first." -ForegroundColor Red
    Write-Host "Run: .\build.ps1" -ForegroundColor Yellow
    exit 1
}

Write-Host "Running simulation from: $exePath" -ForegroundColor Green
Write-Host ""

# シミュレーション実行
& $exePath

Write-Host ""
Write-Host "Simulation finished." -ForegroundColor Green
