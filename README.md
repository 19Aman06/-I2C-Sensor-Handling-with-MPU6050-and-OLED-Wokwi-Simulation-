# -I2C-Sensor-Handling-with-MPU6050-and-OLED-Wokwi-Simulation-

This project simulates an I²C sensor (MPU6050 accelerometer + gyroscope) connected to a Raspberry Pi Pico, with data displayed on an SSD1306 OLED. It demonstrates sensor initialization, configuration, polling, error handling, logging with timestamps, and graceful recovery — all implemented in Wokwi online simulator.

#Features
#(MPU6050 + OLED)
  ->I²C bus initialization
  ->Sensor configuration (accelerometer/gyroscope ranges)
  ->Polling every 500 ms
  ->Error handling (timeout, invalid data, disconnection)
  ->Logging with timestamps
  ->Displaying values on OLED

#Setup & Usage
  ->Open Wokwi.
  ->Create a new Raspberry Pi Pico project.
  ->Add MPU6050 and SSD1306 OLED in diagram.json.
  ->Install libraries: Adafruit GFX, Adafruit SSD1306, Adafruit MPU6050.
  ->Run simulation → view sensor data on OLED + Serial Monitor.

#Output
 AccelX: 0.12 Y: -0.05 Z: 9.81
 AccelX: 0.10 Y: -0.06 Z: 9.80


