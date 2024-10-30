# Introduction
The system is designed to work with fingerprint sensor modules, magnetic card sensors, keyboards, servo motors,
ESP8266 circuit board, Oled screen and STM32F103C8T6 circuit board. System capable of identifying users based 
on passwords, magnetic cards and fingerprints. It controls the Servo for the door opening/closing process, in 
addition it also has other functions such as power saving mode, or the ability to update firmware from far aka FOTA. 

## System Architecture
![System Architecture](./Image/architecture.png)

The System divided into 2 subsystems:

- Major system: Including microcontroller STM32F103C8T6 and peripherals used include: AS608 fingerprint sensor,
    RFID magnetic RC 522 card sensor, 3x4 matrix keyboard module, 0.96 inch oled screen and 5V Servo motor. 
    This system will perform all basic functions. Mainly, the STM32F103C8T6 microcontroller acts as the central microprocessor 
    that controls the system's flow of operations and uses sensors and peripherals to perform system's functions.
    
- Minor System: Only includes the ESP8266 circuit board, this system performs functions required to access and use 
    the Internet such as FOTA, etc. It communicates with the STM32 microcontroller via the UART communication standard, carry 
    out requests sent from the central processor of the entire system and send back the desired results to the main system.

The operation flow of Major and Minor system were illustrated by the flow chart as below:

Flow chart of Major system:

![Flow chart of Major system](./Image/mainflowchart.png)

Flow chart of Minor system:

![Flow chart of Minor system](./Image/minorflowchart.png)

## More

To understand more deeply about the system, you coud check my report attached at Document folder.
