# IoT4Girls
IoT4Girls is a Romanian workshop for high school girls held by Codette and TechLounge. The main theme of this practical course is Internet of Things (IoT); in this repository you will find part of the materials used in this scope.

# Olimex LED Matrix
Arduino Library for interfacing multiple Olimex RGB 8x8 Matrix.
Provider link: https://www.olimex.com/Products/MSP430/Booster/MOD-LED8x8/

## Installation
Download the files and include the header "led_matrix.h"; optionally, if you want to use a font, you can include "font.h". For those of you who are new to programming, you should know that you can use any programming interface you want, including the Arduino IDE. 

## Getting started

The matrix can be chained directly, as can be seen in the image below, where there are 3 chained matrix: ![Example of how to create the matrix chain.][matrix_chain]

A working example of an Internet of Things application is in the "olimex.ino" file. If you are using the Arduino IDE, be sure to move all source and header files in a folder named "olimex" before compiling. The application uses the Arduino web server to control what gets displayed on the Olimex matrix chain. For this example you also require an Arduino Ethernet shield.

You have to provide the matrix constructor with the number of matrix you have phisically chained; in our example, we have used the NUMBER_OF_MATRIX macro.

The matrix / Arduino pin correspondance can be viewed in the table below. The latch pin can be changed as you wish.

| Matrix Pins | Arduino Pins |
| --------- | -------------- |
|			GND		|		GND					 |
|			GND		|		GND					 |
|			DATA	|		11					 |
|			LATCH	|		8					   |
|			SCK		|		13					 |
|			VCC		|		VCC					 |

[matrix_chain]: https://github.com/codettero/iot4girls/blob/master/matrix_chain.jpg "Example of how to create the matrix chain."
