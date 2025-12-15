/**
 * @file SensorReader.c
 * @brief Sensor Reader Software Component Implementation
 * 
 * センサーからデータを読み取るSWC
 * 実際のハードウェアの代わりに、シミュレーション値を生成
 */

#include "SensorReader.h"
#include "Rte.h"
#include <stdio.h>
#include <stdlib.h>

static uint32_t cycleCount = 0;

/**
 * @brief SensorReader初期化
 */
void SensorReader_Init(void) {
    cycleCount = 0;
    printf("[SWC-SensorReader] Initialized\n");
}

/**
 * @brief SensorReader実行（10ms周期）
 */
void SensorReader_Run(void) {
    cycleCount++;
    
    /* シミュレーション：センサー値を生成（50-150の範囲で変動） */
    uint32_t sensorValue = 100 + (rand() % 50) - 25;
    
    /* RTEを通じてセンサー値を送信 */
    Std_ReturnType result = Rte_Write_SensorValue(sensorValue);
    
    if (result == E_OK) {
        if (cycleCount % 100 == 0) {  /* 1秒ごとに表示 */
            printf("[SWC-SensorReader] Sensor Value: %u (cycle: %u)\n", 
                   sensorValue, cycleCount);
        }
    }
}
