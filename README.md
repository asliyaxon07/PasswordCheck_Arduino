# Arduino Password Lock

## Project Overview
This project is a simple electronic password lock built using an Arduino Uno. Users enter a four-digit PIN using two pushbuttons. A 16x2 I2C LCD displays the status, and a buzzer provides audio feedback.

## Components
- Arduino Uno
- 16x2 I2C LCD
- 2 pushbuttons
- Buzzer
- Breadboard
- Jumper wires
- USB cable

## Wiring

| Component | Arduino Pin |
|---|---|
| LCD VCC | 5V |
| LCD GND | GND |
| LCD SDA | A4 |
| LCD SCL | A5 |
| Digit button | D2 and GND |
| Confirm button | D3 and GND |
| Buzzer (+) | D8 |
| Buzzer (-) | GND |

Both buttons use the Arduino's internal pull-up resistors through `INPUT_PULLUP`.

## How It Works
1. The LCD displays the PIN entry screen.
2. Press the digit button to select a number from 0 to 9.
3. Press the confirm button to enter the selected digit.
4. Repeat until four digits have been entered.
5. The Arduino compares the entered PIN with the stored password.
6. If the PIN is correct, the LCD displays "Access Granted!" and the buzzer plays a success sound.
7. If the PIN is incorrect, the LCD displays "Access Denied!" and the buzzer plays an error sound.
8. The game resets so another PIN can be entered.

## Default Password
`2580`

To change the password, edit this line in the Arduino code:

`const String password = "2580";`

## Libraries
- Wire.h — included with the Arduino environment.
- LiquidCrystal_I2C.h — used to control the I2C LCD.

Install the LiquidCrystal_I2C library through the Arduino IDE Library Manager if it is not already installed.

## How to Upload
1. Connect the Arduino Uno to your computer using USB.
2. Open `Arduino_Password_Lock.ino` in Arduino IDE.
3. Select **Arduino Uno** under Tools > Board.
4. Select the correct port under Tools > Port.
5. Click Verify, then Upload.
6. Test the buttons, LCD, and buzzer.

## Concepts Practiced
- Digital input and `INPUT_PULLUP`
- Conditional statements
- Strings and password comparison
- Functions
- LCD output
- Buzzer control using `tone()`
- Button debouncing

## Note
This is an educational simulation of a password lock. It does not provide real security or physically lock a door.

## Author
Created as a beginner-friendly Arduino electronics and programming project.
