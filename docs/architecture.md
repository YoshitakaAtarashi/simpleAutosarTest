# AUTOSAR アーキテクチャ詳細

## レイヤー間の責務

### Application Layer (SWC)
- ビジネスロジックの実装
- ハードウェア非依存
- RTEを通じてのみ通信

### RTE (Runtime Environment)
- SWCとBSWの仲介
- ポート・インターフェースの抽象化
- データ整合性の保証

### BSW (Basic Software)
- ハードウェア制御
- OS、通信、診断など
- 標準化されたAPI提供

### MCAL (Microcontroller Abstraction Layer)
- ハードウェア依存部分の抽象化
- 本実装ではシミュレーション用の簡易実装

## 設計原則

1. **疎結合**: コンポーネント間の依存を最小化
2. **再利用性**: SWCは異なるECUで再利用可能
3. **スケーラビリティ**: 小規模から大規模システムまで対応
4. **標準化**: 統一されたインターフェース

## タスクスケジューリング

```
Task1 (10ms周期) → SensorReader更新
Task2 (20ms周期) → EngineControl計算
Task3 (100ms周期) → 診断処理
```
