# ビルドと実行手順

## 必要な環境

- CMake 3.10以上
- C コンパイラ（GCC、Clang、MSVC等）
- Windows / Linux / macOS

## ビルド手順

### Windowsの場合

```powershell
# プロジェクトルートに移動
cd D:\genAI\AutosarTest

# ビルドディレクトリ作成
mkdir build
cd build

# CMake設定（Visual Studio使用の場合）
cmake ..

# ビルド実行
cmake --build .

# 実行
.\Debug\AutosarSim.exe
```

### MinGW使用の場合

```powershell
cmake -G "MinGW Makefiles" ..
cmake --build .
.\AutosarSim.exe
```

### Linux / macOSの場合

```bash
# プロジェクトルートに移動
cd ~/AutosarTest

# ビルドディレクトリ作成
mkdir build
cd build

# CMake設定
cmake ..

# ビルド実行
make

# 実行
./AutosarSim
```

## 実行結果の例

```
========================================
  AUTOSAR Learning Environment
  Simple ECU Simulation
========================================

=== STARTUP PHASE ===
[ECUM] ECU State Manager Initializing...
[DET] Initialized
[COM] Initialized
[OS] Initialized
[ECUM] State: STARTUP
[RTE] Runtime Environment Initialized
[SWC-SensorReader] Initialized
[SWC-EngineControl] Initialized (Idle RPM: 800)
[ECUM] Startup Phase 2
[ECUM] State: RUN

=== TASK REGISTRATION ===
[OS] Task 0 registered (period: 10 ms)
[OS] Task 1 registered (period: 20 ms)
[OS] Task 2 registered (period: 100 ms)

=== RUN PHASE ===
Simulation will run for 10 seconds...

[OS] Starting scheduler...
[SWC-SensorReader] Sensor Value: 112 (cycle: 100)
[SWC-EngineControl] Sensor: 107, Engine RPM: 1850 -> 2140 (cycle: 50)
[DIAG] System running normally (cycle: 10)
...
```

## トラブルシューティング

### CMakeが見つからない場合
- CMakeをインストール: https://cmake.org/download/

### コンパイラが見つからない場合
- Windows: Visual Studio または MinGW をインストール
- Linux: `sudo apt install build-essential`
- macOS: Xcode Command Line Tools をインストール

### ビルドエラーが発生する場合
```bash
# buildディレクトリをクリーンアップ
cd build
rm -rf *  # または PowerShell: Remove-Item * -Recurse -Force

# 再度CMake実行
cmake ..
cmake --build .
```

## デバッグビルド

```bash
# デバッグ情報付きビルド
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

## リリースビルド

```bash
# 最適化ビルド
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```
