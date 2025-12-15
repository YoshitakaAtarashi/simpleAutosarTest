/**
 * @file Std_Types.h
 * @brief AUTOSAR Standard Types Definition
 * 
 * AUTOSAR標準のデータ型定義
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdint.h>
#include <stdbool.h>

/* AUTOSAR Standard Return Type */
typedef uint8_t Std_ReturnType;

#define E_OK        ((Std_ReturnType)0x00)
#define E_NOT_OK    ((Std_ReturnType)0x01)

/* Boolean type */
#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif

/* NULL pointer definition */
#ifndef NULL
#define NULL    ((void*)0)
#endif

#endif /* STD_TYPES_H */
