
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int digitButton = 2;
const int confirmButton = 4;
const int buzzer = 6;

const String password = "0614";

String enteredPassword = "";
int currentDigit = 0;

void setup() {
  pinMode(digitButton, INPUT_PULLUP);
  pinMode(confirmButton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  showScreen();
}

void loop() {
  if (digitalRead(digitButton) == LOW) {
    delay(30);

    if (digitalRead(digitButton) == LOW) {
      currentDigit = (currentDigit + 1) % 10;
      showScreen();
      waitForRelease(digitButton);
    }
  }

  if (digitalRead(confirmButton) == LOW) {
    delay(30);

    if (digitalRead(confirmButton) == LOW) {
      enteredPassword += String(currentDigit);
      currentDigit = 0;

      if (enteredPassword.length() == password.length()) {
        checkPassword();
      } else {
        showScreen();
      }

      waitForRelease(confirmButton);
    }
  }
}

void showScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter PIN:");

  lcd.setCursor(0, 1);
  lcd.print("PIN: ");

  for (int i = 0; i < enteredPassword.length(); i++) {
    lcd.print("*");
  }

  lcd.print(currentDigit);
}

void checkPassword() {
  lcd.clear();

  if (enteredPassword == password) {
    lcd.print("Access Granted!");
    tone(buzzer, 1000, 200);
    delay(250);
    tone(buzzer, 1500, 200);
  } else {
    lcd.print("Access Denied!");
    tone(buzzer, 250, 700);
  }

  delay(2000);
  enteredPassword = "";
  currentDigit = 0;
  showScreen();
}

void waitForRelease(int buttonPin) {
  while (digitalRead(buttonPin) == LOW) {
    delay(10);
  }

  delay(30);
}
