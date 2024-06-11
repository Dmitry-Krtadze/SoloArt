#include <Servo.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

// Дефініції пінів для двигунів та сервоприводів
#define IN1 7
#define IN2 6
#define ENA 5
#define IN3 4
#define IN4 3
#define ENB 2
#define BUZZER 8 // Пін для звукового сигналу

// Ініціалізація об'єктів для сервоприводу та Bluetooth зв'язку
Servo cameraServo;
SoftwareSerial BTSerial(10, 11); // RX, TX
Adafruit_MPU6050 mpu;

// Проміжні змінні для обробки даних
int prevAccX = 0, prevAccY = 0;
int prevGyroX = 0, prevGyroY = 0;

// Функція для ініціалізації системи
void setup() {
  // Ініціалізація серійного зв'язку для налагодження
  Serial.begin(9600);
  BTSerial.begin(9600);

  // Ініціалізація двигунів
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // Ініціалізація звукового сигналу
  pinMode(BUZZER, OUTPUT);

  // Ініціалізація сервоприводу для камери
  cameraServo.attach(9);
  cameraServo.write(90); // встановити камеру у початкове положення

  // Ініціалізація MPU6050
  if (!mpu.begin()) {
    Serial.println("Не вдалося знайти MPU6050!");
    while (1);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("Налаштування завершено");
}

// Головна функція циклу
void loop() {
  // Прийом команд через Bluetooth
  if (BTSerial.available()) {
    char command = BTSerial.read();
    executeCommand(command);
  }

  // Отримання даних з MPU6050 для стабілізації
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  stabilizeRobot(a, g);

  // Отримання команд через серійний порт (для налагодження)
  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
  }
}

// Функція для виконання отриманих команд
void executeCommand(char command) {
  switch (command) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'L':
      turnLeft();
      break;
    case 'R':
      turnRight();
      break;
    case 'S':
      stopRobot();
      break;
    case 'C':
      captureImage();
      break;
    case 'H':
      honkBuzzer();
      break;
    default:
      Serial.println("Невідома команда");
      break;
  }
}

// Функції для керування рухом робота
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

// Функція для захоплення зображення
void captureImage() {
  Serial.println("Захоплення зображення");
  BTSerial.println("CAPTURE");
}

// Функція для активації звукового сигналу
void honkBuzzer() {
  digitalWrite(BUZZER, HIGH);
  delay(500);
  digitalWrite(BUZZER, LOW);
}

// Функція для стабілізації робота на основі даних з MPU6050
void stabilizeRobot(sensors_event_t a, sensors_event_t g) {
  // Обробка акселерометричних даних
  if (abs(a.acceleration.x) > 2 || abs(a.acceleration.y) > 2) {
    stopRobot();
    Serial.println("Стабілізація робота");
  }

  // Додаткові функції стабілізації на основі гіроскопічних даних
  if (abs(g.gyro.x) > 1 || abs(g.gyro.y) > 1) {
    correctOrientation(g.gyro.x, g.gyro.y);
  }
}

// Функція для корекції орієнтації робота
void correctOrientation(float gyroX, float gyroY) {
  if (gyroX > 1) {
    turnLeft();
    delay(100);
    stopRobot();
  } else if (gyroX < -1) {
    turnRight();
    delay(100);
    stopRobot();
  }

  if (gyroY > 1) {
    moveBackward();
    delay(100);
    stopRobot();
  } else if (gyroY < -1) {
    moveForward();
    delay(100);
    stopRobot();
  }
}

// Функція для обробки температурних даних (на випадок перегріву)
void monitorTemperature(sensors_event_t temp) {
  if (temp.temperature > 30) {
    stopRobot();
    Serial.println("Перегрів! Зупинка робота.");
    honkBuzzer();
  }
}
