/**
 * @file EngineControl.c
 * @brief Engine Control Software Component Implementation
 * 
 * センサー値を基にエンジン制御を行うSWC
 */

#include "EngineControl.h"
#include "Rte.h"
#include <stdio.h>

static uint32_t cycleCount = 0;
static uint32_t currentEngineSpeed = 0;

/**
 * @brief EngineControl初期化
 */
void EngineControl_Init(void) {
    cycleCount = 0;
    currentEngineSpeed = 800;  /* アイドル回転数 */
    printf("[SWC-EngineControl] Initialized (Idle RPM: %u)\n", currentEngineSpeed);
}

/**
 * @brief EngineControl実行（20ms周期）
 */
void EngineControl_Run(void) {
    cycleCount++;
    
    uint32_t sensorValue = 0;
    uint32_t targetSpeed = 0;
    
    /* RTEからセンサー値を読み取り */
    Std_ReturnType result = Rte_Read_SensorValue(&sensorValue);
    
    if (result == E_OK) {
        /* センサー値に基づいてエンジン回転数を計算 */
        /* 簡易的な制御ロジック: センサー値 * 20 */
        targetSpeed = sensorValue * 20;
        
        /* 現在値から目標値へスムーズに変化 */
        if (currentEngineSpeed < targetSpeed) {
            currentEngineSpeed += 10;
        } else if (currentEngineSpeed > targetSpeed) {
            currentEngineSpeed -= 10;
        }
        
        /* エンジン回転数をRTEに書き込み */
        Rte_Write_EngineSpeed(currentEngineSpeed);
        
        if (cycleCount % 50 == 0) {  /* 1秒ごとに表示 */
            printf("[SWC-EngineControl] Sensor: %u, Engine RPM: %u -> %u (cycle: %u)\n",
                   sensorValue, currentEngineSpeed, targetSpeed, cycleCount);
        }
    } else {
        /* センサー値が取得できない場合はアイドル回転数を維持 */
        currentEngineSpeed = 800;
    }
}
