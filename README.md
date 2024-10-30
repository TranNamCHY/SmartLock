# Introduction
The system is designed to work with fingerprint sensor modules, magnetic card sensors, keyboards, servo motors,
ESP8266 circuit board, Oled screen and STM32F103C8T6 circuit board. System capable of identifying users based 
on passwords, magnetic cards and fingerprints. It controls the Servo for the door opening/closing process, in 
addition it also has other functions such as power saving mode, or the ability to update firmware from far aka FOTA. 

## System Architecture
![System Architecture](./Image/architecture.png)

The System divided into 2 subsystems:

    o Major system: Including microcontroller STM32F103C8T6 and peripherals used include: AS608 fingerprint sensor,
    RFID magnetic RC 522 card sensor, 3x4 matrix keyboard module, 0.96 inch oled screen and 5V Servo motor. 
    This system will perform all basic functions. Mainly, the STM32F103C8T6 microcontroller acts as the central microprocessor 
    that controls the system's flow of operations and uses sensors and peripherals to perform system's functions.
    
    o Minor System: Only includes the ESP8266 circuit board, this system performs functions required to access and use 
    the Internet such as FOTA, etc. It communicates with the STM32 microcontroller via the UART communication standard, carry 
    out requests sent from the central processor of the entire system and send back the desired results to the main system.

First, Install dependencies (Required both on PC and Zynq7000):

```bash
pip install numpy
pip install matplotlib
```
**Note: on Zynq7000, you may not be able to install numpy or matplotlib by pip package, try to find a prebuilt rootfs with numpy or matplotlib 
installed or add numpy package to rootfs by petalinux.

Next, if you just want to run by CPU, simply run with:

```bash
$ python test_cpu.py
```
**Note: if you got the error message like: "segmentation fault" when run the test, you may need to recompile the "matrix_ultility.c" by yourself, visit
my repository: https://github.com/TranNamCHY/Convolution_Driver for more detail.

In case you want to run convolution and maxpooling by FPGA mode, you first need to install a device driver for the Convolution and Maxpooling FPGA module, 
you could find the detailed instruction at my repository: https://github.com/TranNamCHY/Convolution_Driver.

Then, run it with no arguments:

```bash
$ python test_fpga.py
```



## About CNN

The CNN network designed in two testbench has architecture: Con3x3(16 filters), Maxpooling2x2, Con3x3(16 filters), Maxpooling2x2, Flatten, Dense(16 neurons), Softmax.

Training set include 500 face image of 16 people classified into 16 label, each label represent a person. The CNN was trained to classify the face in input image to one of 16 label.

The testing set include 160 face image, each label has 10, used to evaluate the accurancy of the final model.

![Training process](./traing.png)

Because the traing algorithm is just gradient descent, the final accuracy of traing step barely reach to 100%. 
