# AUTOSAR Learning Environment

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Language: Python](https://img.shields.io/badge/Language-Python-green.svg)](https://www.python.org/)

A simple educational implementation for learning AUTOSAR (AUTomotive Open System ARchitecture) basic concepts and architecture.

[日本語版 README](README_ja.md)

## 🎯 Overview

This environment provides a hands-on way to understand AUTOSAR standard structure and operational principles without complex AUTOSAR toolchains. Perfect for students, engineers, and anyone interested in automotive software architecture.

### Features

- ✅ **Complete AUTOSAR layered architecture** (BSW, RTE, SWC)
- ✅ **Task scheduler** with periodic task execution
- ✅ **Inter-component communication** via RTE
- ✅ **Interactive GUI simulator** with real-time visualization
- ✅ **Fully documented** code with learning guides
- ✅ **Cross-platform** (Windows, Linux, macOS)

## 🏗️ AUTOSAR Architecture

```
┌─────────────────────────────────────┐
│   Application Layer (SWC)           │
│   - EngineControl                   │
│   - SensorReader                    │
└─────────────────────────────────────┘
            ↕ (RTE API)
┌─────────────────────────────────────┐
│   RTE (Runtime Environment)         │
└─────────────────────────────────────┘
            ↕
┌─────────────────────────────────────┐
│   Basic Software (BSW)              │
│   ├─ OS (Operating System)          │
│   ├─ Com (Communication)            │
│   ├─ EcuM (ECU Manager)             │
│   └─ Det (Diagnostic)               │
└─────────────────────────────────────┘
            ↕
┌─────────────────────────────────────┐
│   MCAL (Simulated)                  │
└─────────────────────────────────────┘
```

## 📁 Project Structure

```
AutosarTest/
├── src/
│   ├── bsw/              # Basic Software Layer
│   │   ├── os/           # Operating System
│   │   ├── com/          # Communication
│   │   ├── ecum/         # ECU Manager
│   │   └── det/          # Diagnostic Event Manager
│   ├── rte/              # Runtime Environment
│   ├── swc/              # Software Components
│   │   ├── EngineControl/
│   │   └── SensorReader/
│   └── main.c            # Main entry point
├── config/               # Configuration files
├── docs/                 # Documentation
├── simulator_gui.py      # Python GUI simulator
├── CMakeLists.txt        # Build configuration
└── README.md             # This file
```

## 🚀 Quick Start

### Option 1: C Console Simulator

**Requirements:**
- CMake 3.10+
- C compiler (GCC, Clang, MSVC)

**Build and Run:**

```bash
# Windows (PowerShell)
.\build.ps1
.\run.ps1

# Linux/macOS
./build.sh
./run.sh
```

**Manual Build:**

```bash
mkdir build && cd build
cmake ..
cmake --build .
./AutosarSim          # Linux/macOS
.\Debug\AutosarSim.exe   # Windows
```

### Option 2: Python GUI Simulator (Recommended)

**Requirements:**
- Python 3.7+
- matplotlib

**Run:**

```bash
# Windows
.\run_gui.ps1

# Linux/macOS
./run_gui.sh

# Or manually
pip install matplotlib
python simulator_gui.py
```

## 📸 Screenshots

### GUI Simulator

![AUTOSAR GUI Simulator](images/simulator.png)

Interactive graphical interface with real-time control and visualization:
- **Control Panel**: Adjustable sensor values and throttle position sliders
- **System Status**: Real-time display of engine speed, system time, task cycles, and ECU state
- **Live Graphs**: Real-time plotting of sensor values and engine speed over time
- **Start/Pause/Reset Controls**: Full control over simulation execution

### Console Simulator
The console simulator shows real-time task execution and signal communication:

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
...
```

## 📚 Learning Points

1. **Layered Architecture**: Understand AUTOSAR standard layer structure
2. **RTE (Runtime Environment)**: Interface between Application and BSW
3. **Task Scheduling**: Periodic task execution by OS
4. **Communication**: Data exchange between software components
5. **Configuration Management**: Static configuration for behavior customization

## 🎓 What You'll Learn

### Basic Software Layer (BSW)
- **OS**: Simple periodic task scheduler (1ms tick)
- **Com**: Signal-based inter-component communication
- **EcuM**: ECU lifecycle management (Startup → Run → Shutdown)
- **Det**: Development error detection and reporting

### Runtime Environment (RTE)
- Port-based abstraction between SWC and BSW
- Sender-Receiver communication pattern
- Data integrity and synchronization

### Software Components (SWC)
- **SensorReader**: Reads sensor data (10ms cycle)
- **EngineControl**: Controls engine based on sensor input (20ms cycle)
- Independent, hardware-agnostic application logic

## 📖 Documentation

- [Learning Guide](docs/learning_guide.md) - Step-by-step tutorial
- [Architecture Details](docs/architecture.md) - In-depth architecture explanation
- [Build Instructions](docs/build_instructions.md) - Detailed build steps
- [GUI Simulator Guide](docs/gui_simulator.md) - Python GUI documentation
- [Glossary](docs/glossary.md) - AUTOSAR terminology

## 🔧 Extending the Project

### Beginner
- [ ] Add new sensor SWC
- [ ] Implement different task periods
- [ ] Enhance error handling

### Intermediate
- [ ] Implement Client-Server communication
- [ ] Add event-driven tasks
- [ ] Create memory management module

### Advanced
- [ ] Simulate CAN bus communication
- [ ] Implement NVM (Non-Volatile Memory)
- [ ] Add UDS diagnostic protocol basics

## 🌟 Next Steps with Real AUTOSAR

After mastering this environment:

1. **Study AUTOSAR Specifications**
   - Classic Platform 4.x
   - Adaptive Platform

2. **Try Commercial Tools**
   - Vector MICROSAR
   - ETAS ISOLAR
   - EB tresos

3. **Explore Open Source**
   - Arctic Core
   - AUTOSAR-OS

## 🤝 Contributing

Contributions are welcome! Please feel free to submit issues and pull requests.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

This project is created for educational purposes to help understand AUTOSAR concepts. It is not affiliated with the AUTOSAR consortium.

## 📧 Contact

For questions or feedback, please open an issue on GitHub.

---

**Note**: This is a simplified educational implementation. For production automotive software, use certified AUTOSAR tools and follow safety standards (ISO 26262, ASPICE, etc.).
