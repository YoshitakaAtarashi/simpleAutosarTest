/**
 * @file Rte.c
 * @brief AUTOSAR Runtime Environment Implementation
 * 
 * RTEはSWCとBSWの間の通信を仲介します
 */

#include "Rte.h"
#include <stdio.h>

/**
 * @brief RTE初期化
 */
void Rte_Init(void) {
    printf("[RTE] Runtime Environment Initialized\n");
}

/**
 * @brief センサー値の書き込み
 */
Std_ReturnType Rte_Write_SensorValue(uint32_t value) {
    return Com_SendSignal(RTE_PORT_SensorValue, value);
}

/**
 * @brief センサー値の読み込み
 */
Std_ReturnType Rte_Read_SensorValue(uint32_t* value) {
    return Com_ReceiveSignal(RTE_PORT_SensorValue, value);
}

/**
 * @brief エンジン回転数の書き込み
 */
Std_ReturnType Rte_Write_EngineSpeed(uint32_t value) {
    return Com_SendSignal(RTE_PORT_EngineSpeed, value);
}

/**
 * @brief エンジン回転数の読み込み
 */
Std_ReturnType Rte_Read_EngineSpeed(uint32_t* value) {
    return Com_ReceiveSignal(RTE_PORT_EngineSpeed, value);
}

/**
 * @brief スロットル位置の書き込み
 */
Std_ReturnType Rte_Write_ThrottlePosition(uint32_t value) {
    return Com_SendSignal(RTE_PORT_ThrottlePosition, value);
}

/**
 * @brief スロットル位置の読み込み
 */
Std_ReturnType Rte_Read_ThrottlePosition(uint32_t* value) {
    return Com_ReceiveSignal(RTE_PORT_ThrottlePosition, value);
}

/**
 * @brief エンジンコマンドの書き込み
 */
Std_ReturnType Rte_Write_EngineCommand(uint32_t value) {
    return Com_SendSignal(RTE_PORT_EngineCommand, value);
}

/**
 * @brief エンジンコマンドの読み込み
 */
Std_ReturnType Rte_Read_EngineCommand(uint32_t* value) {
    return Com_ReceiveSignal(RTE_PORT_EngineCommand, value);
}
