#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_ADDRESS  0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Servo pins
Servo baseServo;
Servo liftServo;
Servo pushServo;

int basePin = 13;
int liftPin = 12;
int pushPin = 14;


int plasticBase = 30;
int paperBase   = 90;
int organicBase = 150;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("OLED init failed"));
    while (true);
  }

  baseServo.attach(basePin);
  liftServo.attach(liftPin);
  pushServo.attach(pushPin);

  baseServo.write(90);
  liftServo.write(90);
  pushServo.write(0);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("System Ready");
  display.display();

  Serial.println("Waiting for waste type...");
}

void loop() {
  if (Serial.available() > 0) {
    String wasteType = Serial.readStringUntil('\n');
    wasteType.trim();

    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("Detected: " + wasteType);
    display.display();

    if (wasteType == "plastic") {
      moveArm(plasticBase);
    } 
    else if (wasteType == "paper") {
      moveArm(paperBase);
    } 
    else if (wasteType == "organic") {
      moveArm(organicBase);
    } 
    else {
      Serial.println("Unknown type");
    }

    delay(2000);
  }
}

void moveArm(int baseAngle) {
  Serial.print("Moving to base angle: ");
  Serial.println(baseAngle);

  baseServo.write(baseAngle);
  delay(1000);

  liftServo.write(120);
  delay(1000);


  pushServo.write(90);
  delay(1000);

  
  pushServo.write(0);
  delay(500);

  
  liftServo.write(90);
  delay(1000);

  baseServo.write(90);
  delay(1000);
}
