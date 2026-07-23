# -Digital-Safe-Locker-PIC18-
A password-protected electronic locker with LCD display, wrong-attempt buzzer, auto-lock, and password change functionality.
This project is a Digital-Safe-Lockerbuilt using the PIC18F4520 microcontroller. It uses a 4×4 keypad for password entry, a 16×2 LCD to display system messages, an EEPROM to securely store the password, a relay to control the lock mechanism, and a buzzer for user feedback and security alerts.

The system is designed to simulate a simple electronic safe where only users with the correct PIN can unlock the safe. It also allows the password to be changed without reprogramming the microcontroller.

Features :
🔑 4-digit PIN authentication
💾 Password stored in internal EEPROM (retains data after power loss)
🔒 Relay-controlled locking and unlocking
📟 LCD displays system status and user prompts
🔔 Buzzer feedback for key presses and incorrect passwords
🔄 Change PIN after successful login
⏱ Automatic relocking after timeout
🚨 Security lockout after three incorrect attempts

Hardware Requirements :
PIC18F4520 Microcontroller
16×2 LCD Display
4×4 Matrix Keypad
Relay Module / Solenoid Lock
Buzzer
Power Supply (5V)
MPLAB X IDE
XC8 Compiler

Pin Configuration :
Component	PIC18F4520 Pins
Keypad Rows	RB0 – RB3
Keypad Columns	RB4 – RB7
LCD	Connected through LCD.h library
Relay	RD2
Buzzer	RD3

How It Works :
1. System Startup
The microcontroller initializes the hardware.
The saved PIN is read from EEPROM.
If no password exists (EEPROM contains 0xFF), the default password is set to:
1234
The LCD displays:
SAFE IS LOCKED

2. Entering the PIN :
The user enters a four-digit PIN using the keypad.
Every key press is confirmed with:
A short buzzer beep
An asterisk (*) displayed on the LCD instead of the actual digit
Example:
Enter PIN:

3. Correct Password :
If the entered PIN matches the stored PIN:
The relay is activated to unlock the safe.
The LCD displays:
ACCESS GRANTED
The user can then:
Press 1 to change the PIN
Press * to lock immediately
Wait for the timeout, after which the safe locks automatically

4. Changing the PIN :
After pressing 1:
Enter a new 4-digit PIN.
The new PIN is written to EEPROM.
Future logins will use the updated password.
LCD Message:
PIN CHANGED!

5. Wrong Password:
If an incorrect PIN is entered:
The buzzer sounds.
The LCD displays:
WRONG PIN!
The system keeps track of failed login attempts.

6. Security Lockout
After three consecutive incorrect attempts:
The LCD displays:
SYSTEM LOCKED
SECURITY ALARM
The buzzer repeatedly sounds as a security alert.
After the penalty period, the failed-attempt counter resets.

EEPROM Usage :
EEPROM Address	Stored Data
0	             - PIN Digit 1
1              - PIN Digit 2
2	             - PIN Digit 3
3	             - PIN Digit 4

Using EEPROM ensures the password is preserved even when the system is powered off.
