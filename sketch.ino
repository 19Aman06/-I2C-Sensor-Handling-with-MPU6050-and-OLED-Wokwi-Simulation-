#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_ADDR     0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin(); // SDA=GP4, SCL=GP5

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED not found");
    while(1);
  }
  display.clearDisplay();

  // Initialize MPU6050
  if(!mpu.begin()) {
    Serial.println("MPU6050 not found");
    while(1);
  }

  // Configure sensor
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("Setup complete");
}

void loop() {
  // Poll every 500 ms
  delay(500);

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Handle invalid data
  if (isnan(a.acceleration.x) || isnan(a.acceleration.y) || isnan(a.acceleration.z)) {
    Serial.println("Invalid sensor data");
    return;
  }

  // Log with timestamp
  unsigned long now = millis();
  Serial.print("Time: "); Serial.print(now);
  Serial.print(" ms | AccelX: "); Serial.print(a.acceleration.x);
  Serial.print(" Y: "); Serial.print(a.acceleration.y);
  Serial.print(" Z: "); Serial.println(a.acceleration.z);

  // Show on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("AccelX: "); display.println(a.acceleration.x);
  display.print("AccelY: "); display.println(a.acceleration.y);
  display.print("AccelZ: "); display.println(a.acceleration.z);
  display.display();
}
