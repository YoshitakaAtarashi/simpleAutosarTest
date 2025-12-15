# AUTOSAR 学習環境

AUTOSAR（AUTomotive Open System ARchitecture）の基本概念を学ぶための簡易実装環境です。

## 概要

この環境は、本格的なAUTOSARツールチェーンを使わずに、AUTOSAR標準の基本構造と動作原理を理解するための教育的な実装です。

### AUTOSAR アーキテクチャレイヤー

```
┌─────────────────────────────────────┐
│   Application Layer (SWC)           │  アプリケーション層
│   - EngineControl                    │
│   - SensorReader                     │
└─────────────────────────────────────┘
            ↕ (RTE API)
┌─────────────────────────────────────┐
│   RTE (Runtime Environment)          │  実行時環境
└─────────────────────────────────────┘
            ↕
┌─────────────────────────────────────┐
│   Basic Software (BSW)               │  基本ソフトウェア
│   ├─ OS (Operating System)           │
│   ├─ Com (Communication)             │
│   ├─ EcuM (ECU Manager)              │
│   └─ Det (Diagnostic)                │
└─────────────────────────────────────┘
            ↕
┌─────────────────────────────────────┐
│   MCAL (Microcontroller Abstraction) │  マイコン抽象化層
│   (簡易シミュレーション実装)         │
└─────────────────────────────────────┘
```

## ディレクトリ構成

```
AutosarTest/
├── src/
│   ├── bsw/              # Basic Software
│   │   ├── os/           # Operating System
│   │   ├── com/          # Communication
│   │   ├── ecum/         # ECU Manager
│   │   └── det/          # Diagnostic Event Manager
│   ├── rte/              # Runtime Environment
│   ├── swc/              # Software Components
│   │   ├── EngineControl/
│   │   └── SensorReader/
│   └── mcal/             # Microcontroller Abstraction (シミュレーション)
├── config/               # 設定ファイル
├── build/                # ビルド出力
└── docs/                 # ドキュメント
```

## ビルド方法

```bash
# ビルドディレクトリの作成
mkdir build
cd build

# CMakeでビルドシステムを生成
cmake ..

# ビルド実行
cmake --build .
```

## 実行方法

```bash
# ビルド後、実行ファイルを起動
./build/AutosarSim
```

## 学習ポイント

1. **レイヤードアーキテクチャ**: AUTOSAR標準の階層構造を理解
2. **RTE**: アプリケーションとBSWの分離とインターフェース
3. **タスクスケジューリング**: OSによる周期的タスク実行
4. **通信**: ソフトウェアコンポーネント間のデータ交換
5. **設定管理**: 静的設定による動作カスタマイズ

## 主要な機能

- **OS**: 簡易的な周期タスクスケジューラ
- **Com**: コンポーネント間通信（シグナルベース）
- **RTE**: ポート・インターフェース抽象化
- **EcuM**: ECU状態管理とシャットダウン制御
- **Det**: エラー検出とレポート

## 次のステップ

この学習環境に慣れたら、以下のツールで本格的なAUTOSAR開発へ：
- Vector MICROSAR
- ETAS AUTOSAR Tools
- Arctic Core（オープンソース）

## ライセンス

MIT License - 教育目的での使用を想定
