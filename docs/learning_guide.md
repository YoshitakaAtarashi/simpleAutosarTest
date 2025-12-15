# AUTOSAR 学習ガイド

## 1. AUTOSARとは

AUTOSAR（AUTomotive Open System ARchitecture）は、自動車用ECUのソフトウェアアーキテクチャ標準です。

### 主な目的
- **再利用性**: ソフトウェアコンポーネントの再利用
- **移植性**: 異なるECUへの容易な移植
- **標準化**: 統一されたインターフェース
- **スケーラビリティ**: 小規模から大規模システムまで対応

## 2. アーキテクチャ層

### Application Layer（アプリケーション層）
- **役割**: ビジネスロジックの実装
- **特徴**: ハードウェア非依存
- **例**: エンジン制御、センサー処理

### RTE (Runtime Environment)
- **役割**: SWCとBSWの仲介
- **機能**: 
  - ポート通信の抽象化
  - データ整合性保証
  - API提供

### BSW (Basic Software)
- **役割**: ハードウェア制御と基本サービス
- **モジュール**:
  - **OS**: タスクスケジューリング
  - **Com**: 通信管理
  - **EcuM**: ECUライフサイクル管理
  - **Det**: エラー検出

### MCAL (Microcontroller Abstraction Layer)
- **役割**: ハードウェア抽象化
- **本実装**: シミュレーション用簡易実装

## 3. 主要概念

### Software Component (SWC)
AUTOSARの基本単位。独立した機能ブロック。

```c
// SWC例: SensorReader
void SensorReader_Run(void) {
    uint32_t value = ReadSensor();  // 内部処理
    Rte_Write_SensorValue(value);   // RTEを通じて出力
}
```

### Port & Interface
SWC間の通信インターフェース。

- **Sender-Receiver**: データ交換
- **Client-Server**: 関数呼び出し

### Runnable
SWC内で実行される関数。タスクから呼ばれる。

## 4. 実装の学習ポイント

### ステップ1: 基本構造の理解
1. [README.md](../README.md)でプロジェクト全体を把握
2. [architecture.md](architecture.md)で層構造を理解

### ステップ2: BSW層の学習
3. [Os.c](../src/bsw/os/Os.c): タスクスケジューラの実装
4. [Com.c](../src/bsw/com/Com.c): シグナル通信の実装
5. [EcuM.c](../src/bsw/ecum/EcuM.c): 状態管理の実装

### ステップ3: RTE層の学習
6. [Rte.c](../src/rte/Rte.c): ポート抽象化の仕組み

### ステップ4: SWC層の学習
7. [SensorReader.c](../src/swc/SensorReader/SensorReader.c): センサーSWC
8. [EngineControl.c](../src/swc/EngineControl/EngineControl.c): 制御SWC

### ステップ5: 統合と実行
9. [main.c](../src/main.c): システム全体の起動フロー

## 5. 拡張アイデア

### 初級
- [ ] 新しいセンサーSWCの追加
- [ ] 周期の異なるタスクの追加
- [ ] エラー処理の強化

### 中級
- [ ] Client-Server通信の実装
- [ ] イベント駆動タスクの追加
- [ ] メモリ管理モジュールの追加

### 上級
- [ ] CANバス通信のシミュレーション
- [ ] NVM（不揮発性メモリ）の実装
- [ ] 診断プロトコル（UDS）の基礎実装

## 6. 本格的なAUTOSARへの移行

この学習環境に慣れたら：

1. **AUTOSAR Specification**を読む
   - Classic Platform 4.x
   - Adaptive Platform

2. **商用ツール**を試す
   - Vector MICROSAR
   - ETAS ISOLAR
   - EB tresos

3. **オープンソース実装**
   - Arctic Core
   - AUTOSAR-OS

## 7. 参考資料

- AUTOSAR公式サイト: https://www.autosar.org/
- AUTOSAR仕様書（無料ダウンロード可能）
- 「図解 AUTOSAR」などの書籍
