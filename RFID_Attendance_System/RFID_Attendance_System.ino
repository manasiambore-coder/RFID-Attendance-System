#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

#define GREEN_LED A0
#define RED_LED A1
#define BUZZER 8

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String validUID = "F3:E1:1C:39";

bool cardProcessed = false;

void setup() {
  Serial.begin(9600);

  SPI.begin();
  rfid.PCD_Init();

  lcd.init();
  lcd.backlight();

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RFID Attendance");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");

  Serial.println("RFID Attendance System Ready");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan Your Card");

  Serial.println("Scan your RFID card...");
}

void loop() {

  // Wait until previous card is removed
  if (cardProcessed) {

    if (!rfid.PICC_IsNewCardPresent()) {
      cardProcessed = false;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Scan Your Card");

      Serial.println("Card removed.");
      Serial.println("Scan your RFID card...");

      delay(300);
    }

    return;
  }

  // Check for new card
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  String uid = "";

  Serial.print("Card UID: ");

  for (byte i = 0; i < rfid.uid.size; i++) {

    if (rfid.uid.uidByte[i] < 0x10) {
      Serial.print("0");
      uid += "0";
    }

    Serial.print(rfid.uid.uidByte[i], HEX);

    uid += String(rfid.uid.uidByte[i], HEX);

    if (i < rfid.uid.size - 1) {
      Serial.print(":");
      uid += ":";
    }
  }

  Serial.println();

  uid.toUpperCase();

  // Prevent repeated scanning
  cardProcessed = true;

  // =========================
  // VALID CARD
  // =========================

  if (uid == validUID) {

    Serial.println("Student: Manasi");
    Serial.println("Access: GRANTED");
    Serial.println("Attendance: MARKED");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome Manasi");
    lcd.setCursor(0, 1);
    lcd.print("Attendance Done");

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    // One short beep
    digitalWrite(BUZZER, HIGH);
    delay(300);
    digitalWrite(BUZZER, LOW);

    delay(2700);

    digitalWrite(GREEN_LED, LOW);
  }

  // =========================
  // INVALID CARD
  // =========================

  else {

    Serial.println("Student: Unknown");
    Serial.println("Access: DENIED");
    Serial.println("Attendance: NOT MARKED");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
    lcd.setCursor(0, 1);
    lcd.print("Invalid Card");

    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    // Two short beeps
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);

    delay(150);

    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);

    delay(2450);

    digitalWrite(RED_LED, LOW);
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(500);
}