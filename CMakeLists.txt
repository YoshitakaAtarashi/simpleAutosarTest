cmake_minimum_required(VERSION 3.10)
project(AutosarSim C)

# C標準設定
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# インクルードディレクトリ
include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/bsw/common
    ${PROJECT_SOURCE_DIR}/src/bsw/os
    ${PROJECT_SOURCE_DIR}/src/bsw/com
    ${PROJECT_SOURCE_DIR}/src/bsw/det
    ${PROJECT_SOURCE_DIR}/src/bsw/ecum
    ${PROJECT_SOURCE_DIR}/src/rte
    ${PROJECT_SOURCE_DIR}/src/swc/SensorReader
    ${PROJECT_SOURCE_DIR}/src/swc/EngineControl
)

# ソースファイル
set(BSW_SOURCES
    src/bsw/os/Os.c
    src/bsw/com/Com.c
    src/bsw/det/Det.c
    src/bsw/ecum/EcuM.c
)

set(RTE_SOURCES
    src/rte/Rte.c
)

set(SWC_SOURCES
    src/swc/SensorReader/SensorReader.c
    src/swc/EngineControl/EngineControl.c
)

# 実行ファイル
add_executable(AutosarSim
    src/main.c
    ${BSW_SOURCES}
    ${RTE_SOURCES}
    ${SWC_SOURCES}
)

# Windowsの場合の追加設定
if(WIN32)
    # コンソールアプリケーションとして設定
    set_target_properties(AutosarSim PROPERTIES
        WIN32_EXECUTABLE FALSE
    )
endif()

# コンパイルオプション
if(MSVC)
    target_compile_options(AutosarSim PRIVATE /W4)
else()
    target_compile_options(AutosarSim PRIVATE -Wall -Wextra)
endif()

# 出力ディレクトリ設定
set_target_properties(AutosarSim PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build
)

# インストールターゲット
install(TARGETS AutosarSim DESTINATION bin)

# ビルド情報表示
message(STATUS "===========================================")
message(STATUS "  AUTOSAR Learning Environment")
message(STATUS "===========================================")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "===========================================")
