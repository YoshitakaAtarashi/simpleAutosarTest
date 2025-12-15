"""
AUTOSAR Simulation GUI
Simple Python-based AUTOSAR simulator with GUI interface
"""

import tkinter as tk
from tkinter import ttk
import threading
import time
import random
from collections import deque
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure

class AutosarSimulator:
    """AUTOSAR BSW and SWC simulation core"""
    
    def __init__(self):
        self.running = False
        self.tick = 0
        
        # Communication signals (RTE)
        self.signals = {
            'SensorValue': 100,
            'EngineSpeed': 800,
            'ThrottlePosition': 0,
            'EngineCommand': 0
        }
        
        # SWC states
        self.sensor_cycle = 0
        self.engine_cycle = 0
        self.current_engine_speed = 800  # Idle RPM
        
        # Data history for plotting
        self.history_size = 100
        self.time_history = deque(maxlen=self.history_size)
        self.sensor_history = deque(maxlen=self.history_size)
        self.engine_history = deque(maxlen=self.history_size)
        
    def sensor_reader_run(self):
        """SensorReader SWC - 10ms cycle"""
        self.sensor_cycle += 1
        
        # Simulate sensor reading (with some noise)
        noise = random.randint(-5, 5)
        self.signals['SensorValue'] = max(50, min(150, self.signals['SensorValue'] + noise))
        
    def engine_control_run(self):
        """EngineControl SWC - 20ms cycle"""
        self.engine_cycle += 1
        
        # Read sensor value
        sensor_value = self.signals['SensorValue']
        
        # Simple control logic: sensor value * 20
        target_speed = sensor_value * 20
        
        # Smooth transition to target
        if self.current_engine_speed < target_speed:
            self.current_engine_speed += 10
        elif self.current_engine_speed > target_speed:
            self.current_engine_speed -= 10
            
        self.signals['EngineSpeed'] = self.current_engine_speed
        
    def os_tick(self):
        """OS scheduler tick - 1ms"""
        self.tick += 1
        
        # Task scheduling
        if self.tick % 10 == 0:  # 10ms task
            self.sensor_reader_run()
            
        if self.tick % 20 == 0:  # 20ms task
            self.engine_control_run()
            
        # Record history every 100ms
        if self.tick % 100 == 0:
            self.time_history.append(self.tick / 1000.0)  # Convert to seconds
            self.sensor_history.append(self.signals['SensorValue'])
            self.engine_history.append(self.signals['EngineSpeed'])


class AutosarGUI:
    """Main GUI application"""
    
    def __init__(self, root):
        self.root = root
        self.root.title("AUTOSAR Simulator")
        self.root.geometry("1000x700")
        
        self.simulator = AutosarSimulator()
        self.update_interval = 10  # ms
        
        self.setup_ui()
        self.start_simulation()
        
    def setup_ui(self):
        """Setup GUI components"""
        
        # Main frame
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # Title
        title_label = ttk.Label(main_frame, text="AUTOSAR Learning Environment - GUI Simulator", 
                                font=('Arial', 16, 'bold'))
        title_label.grid(row=0, column=0, columnspan=2, pady=10)
        
        # Control Panel
        control_frame = ttk.LabelFrame(main_frame, text="Control Panel", padding="10")
        control_frame.grid(row=1, column=0, sticky=(tk.W, tk.E, tk.N, tk.S), padx=5, pady=5)
        
        # Sensor Value Control
        ttk.Label(control_frame, text="Sensor Value:").grid(row=0, column=0, sticky=tk.W, pady=5)
        self.sensor_var = tk.IntVar(value=100)
        self.sensor_scale = ttk.Scale(control_frame, from_=50, to=150, 
                                      variable=self.sensor_var, orient=tk.HORIZONTAL, length=300)
        self.sensor_scale.grid(row=0, column=1, padx=10, pady=5)
        self.sensor_label = ttk.Label(control_frame, text="100")
        self.sensor_label.grid(row=0, column=2, pady=5)
        
        # Throttle Position Control
        ttk.Label(control_frame, text="Throttle Position:").grid(row=1, column=0, sticky=tk.W, pady=5)
        self.throttle_var = tk.IntVar(value=0)
        self.throttle_scale = ttk.Scale(control_frame, from_=0, to=100, 
                                        variable=self.throttle_var, orient=tk.HORIZONTAL, length=300)
        self.throttle_scale.grid(row=1, column=1, padx=10, pady=5)
        self.throttle_label = ttk.Label(control_frame, text="0%")
        self.throttle_label.grid(row=1, column=2, pady=5)
        
        # Control Buttons
        button_frame = ttk.Frame(control_frame)
        button_frame.grid(row=2, column=0, columnspan=3, pady=10)
        
        self.start_btn = ttk.Button(button_frame, text="Start", command=self.toggle_simulation)
        self.start_btn.grid(row=0, column=0, padx=5)
        
        self.reset_btn = ttk.Button(button_frame, text="Reset", command=self.reset_simulation)
        self.reset_btn.grid(row=0, column=1, padx=5)
        
        # Status Display
        status_frame = ttk.LabelFrame(main_frame, text="System Status", padding="10")
        status_frame.grid(row=1, column=1, sticky=(tk.W, tk.E, tk.N, tk.S), padx=5, pady=5)
        
        # Engine Speed Display
        ttk.Label(status_frame, text="Engine Speed:").grid(row=0, column=0, sticky=tk.W, pady=5)
        self.engine_speed_label = ttk.Label(status_frame, text="800 RPM", 
                                           font=('Arial', 14, 'bold'), foreground='blue')
        self.engine_speed_label.grid(row=0, column=1, sticky=tk.W, pady=5)
        
        # System Time
        ttk.Label(status_frame, text="System Time:").grid(row=1, column=0, sticky=tk.W, pady=5)
        self.time_label = ttk.Label(status_frame, text="0.000 s", font=('Arial', 12))
        self.time_label.grid(row=1, column=1, sticky=tk.W, pady=5)
        
        # Task Cycles
        ttk.Label(status_frame, text="Sensor Cycles:").grid(row=2, column=0, sticky=tk.W, pady=5)
        self.sensor_cycle_label = ttk.Label(status_frame, text="0")
        self.sensor_cycle_label.grid(row=2, column=1, sticky=tk.W, pady=5)
        
        ttk.Label(status_frame, text="Engine Cycles:").grid(row=3, column=0, sticky=tk.W, pady=5)
        self.engine_cycle_label = ttk.Label(status_frame, text="0")
        self.engine_cycle_label.grid(row=3, column=1, sticky=tk.W, pady=5)
        
        # ECU State
        ttk.Label(status_frame, text="ECU State:").grid(row=4, column=0, sticky=tk.W, pady=5)
        self.ecu_state_label = ttk.Label(status_frame, text="RUN", 
                                        font=('Arial', 12, 'bold'), foreground='green')
        self.ecu_state_label.grid(row=4, column=1, sticky=tk.W, pady=5)
        
        # Graph Display
        graph_frame = ttk.LabelFrame(main_frame, text="Real-time Data", padding="10")
        graph_frame.grid(row=2, column=0, columnspan=2, sticky=(tk.W, tk.E, tk.N, tk.S), padx=5, pady=5)
        
        # Create matplotlib figure
        self.fig = Figure(figsize=(10, 4), dpi=100)
        
        # Sensor Value Plot
        self.ax1 = self.fig.add_subplot(211)
        self.ax1.set_title('Sensor Value')
        self.ax1.set_ylabel('Value')
        self.ax1.grid(True)
        self.line1, = self.ax1.plot([], [], 'b-', linewidth=2)
        self.ax1.set_ylim(0, 200)
        
        # Engine Speed Plot
        self.ax2 = self.fig.add_subplot(212)
        self.ax2.set_title('Engine Speed')
        self.ax2.set_xlabel('Time (s)')
        self.ax2.set_ylabel('RPM')
        self.ax2.grid(True)
        self.line2, = self.ax2.plot([], [], 'r-', linewidth=2)
        self.ax2.set_ylim(0, 4000)
        
        self.fig.tight_layout()
        
        # Embed matplotlib in tkinter
        self.canvas = FigureCanvasTkAgg(self.fig, master=graph_frame)
        self.canvas.draw()
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
        
        # Configure grid weights
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        main_frame.columnconfigure(0, weight=1)
        main_frame.columnconfigure(1, weight=1)
        main_frame.rowconfigure(2, weight=1)
        
    def toggle_simulation(self):
        """Start/Stop simulation"""
        self.simulator.running = not self.simulator.running
        
        if self.simulator.running:
            self.start_btn.config(text="Pause")
            self.ecu_state_label.config(text="RUN", foreground="green")
        else:
            self.start_btn.config(text="Start")
            self.ecu_state_label.config(text="PAUSED", foreground="orange")
            
    def reset_simulation(self):
        """Reset simulation"""
        self.simulator.running = False
        self.simulator.tick = 0
        self.simulator.sensor_cycle = 0
        self.simulator.engine_cycle = 0
        self.simulator.current_engine_speed = 800
        self.simulator.signals['SensorValue'] = 100
        self.simulator.signals['EngineSpeed'] = 800
        
        self.simulator.time_history.clear()
        self.simulator.sensor_history.clear()
        self.simulator.engine_history.clear()
        
        self.sensor_var.set(100)
        self.throttle_var.set(0)
        
        self.start_btn.config(text="Start")
        self.ecu_state_label.config(text="RESET", foreground="gray")
        
        self.update_display()
        
    def start_simulation(self):
        """Start simulation thread"""
        self.update_display()
        
    def update_display(self):
        """Update GUI display"""
        
        # Update simulator if running
        if self.simulator.running:
            # Apply user inputs
            self.simulator.signals['SensorValue'] = self.sensor_var.get()
            self.simulator.signals['ThrottlePosition'] = self.throttle_var.get()
            
            # Execute OS tick
            self.simulator.os_tick()
        
        # Update labels
        self.sensor_label.config(text=str(self.sensor_var.get()))
        self.throttle_label.config(text=f"{self.throttle_var.get()}%")
        self.engine_speed_label.config(text=f"{self.simulator.signals['EngineSpeed']} RPM")
        self.time_label.config(text=f"{self.simulator.tick / 1000.0:.3f} s")
        self.sensor_cycle_label.config(text=str(self.simulator.sensor_cycle))
        self.engine_cycle_label.config(text=str(self.simulator.engine_cycle))
        
        # Update graphs
        if len(self.simulator.time_history) > 0:
            self.line1.set_data(list(self.simulator.time_history), 
                               list(self.simulator.sensor_history))
            self.line2.set_data(list(self.simulator.time_history), 
                               list(self.simulator.engine_history))
            
            # Adjust x-axis
            if len(self.simulator.time_history) > 1:
                time_range = max(self.simulator.time_history) - min(self.simulator.time_history)
                if time_range > 0:
                    self.ax1.set_xlim(min(self.simulator.time_history), 
                                     max(self.simulator.time_history))
                    self.ax2.set_xlim(min(self.simulator.time_history), 
                                     max(self.simulator.time_history))
            
            self.canvas.draw()
        
        # Schedule next update
        self.root.after(self.update_interval, self.update_display)


def main():
    """Main entry point"""
    root = tk.Tk()
    app = AutosarGUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()
