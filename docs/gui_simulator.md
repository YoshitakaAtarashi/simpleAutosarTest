# AUTOSAR GUI Simulator

Python-based GUI simulator for AUTOSAR learning environment.

## Features

- **Real-time Visualization**: Live graphs showing sensor values and engine speed
- **Interactive Controls**: Adjust sensor values and throttle position with sliders
- **Task Monitoring**: View task execution cycles and system time
- **AUTOSAR Architecture**: Simulates BSW, RTE, and SWC layers

## Installation

### Requirements

- Python 3.7 or higher
- matplotlib library

### Setup

1. Install required Python packages:

```bash
pip install -r requirements.txt
```

Or manually install matplotlib:

```bash
pip install matplotlib
```

## Running the Simulator

```bash
python simulator_gui.py
```

## GUI Components

### Control Panel

- **Sensor Value Slider**: Adjust sensor input (50-150 range)
- **Throttle Position Slider**: Control throttle position (0-100%)
- **Start/Pause Button**: Control simulation execution
- **Reset Button**: Reset simulation to initial state

### System Status

- **Engine Speed**: Current engine RPM (calculated from sensor value)
- **System Time**: Elapsed simulation time
- **Sensor Cycles**: Number of SensorReader task executions
- **Engine Cycles**: Number of EngineControl task executions
- **ECU State**: Current ECU operational state

### Real-time Data Graphs

- **Top Graph**: Sensor value over time
- **Bottom Graph**: Engine speed over time

## AUTOSAR Simulation

The simulator implements:

### BSW Layer
- **OS**: Task scheduler with 1ms tick
  - Task 1: SensorReader (10ms cycle)
  - Task 2: EngineControl (20ms cycle)

### RTE Layer
- Signal-based communication between SWCs
- Ports: SensorValue, EngineSpeed, ThrottlePosition

### SWC Layer
- **SensorReader**: Reads sensor values and publishes via RTE
- **EngineControl**: Calculates engine speed based on sensor input

### Control Logic

Engine speed calculation:
```
Target RPM = Sensor Value × 20
Current RPM smoothly transitions to Target RPM
```

## Usage Example

1. **Start Simulation**: Click "Start" button
2. **Adjust Sensor**: Move the sensor value slider
3. **Observe Response**: Watch engine speed change in real-time
4. **View Graphs**: Monitor data trends over time
5. **Pause/Resume**: Use Start/Pause button to control execution
6. **Reset**: Click "Reset" to return to initial state

## Comparison with C Implementation

| Feature | C Simulator | Python GUI Simulator |
|---------|-------------|---------------------|
| Platform | Console | GUI |
| Visualization | Text output | Real-time graphs |
| Interaction | Pre-programmed | Interactive sliders |
| Duration | Fixed 10s | User-controlled |
| Learning Focus | Code structure | System behavior |

## Tips

- Start the simulation and observe how engine speed follows sensor value
- Try rapid sensor changes to see the smoothing effect
- Watch the task cycle counters to understand scheduling
- Use graphs to analyze system dynamics

## Next Steps

Extend the simulator by adding:
- [ ] CAN bus communication visualization
- [ ] Diagnostic events display
- [ ] Multiple ECU simulation
- [ ] Configurable task periods
- [ ] Error injection capabilities

## Troubleshooting

### Matplotlib not found
```bash
pip install matplotlib
```

### GUI doesn't start
- Verify Python version: `python --version` (3.7+)
- Check tkinter installation: `python -m tkinter`

### Slow performance
- Reduce graph update frequency by increasing `update_interval` in code
- Reduce history size by changing `history_size` parameter
