# IoT4Girls
IoT4Girls is a Romanian workshop for high school girls held by Codette and TechLounge. The main theme of this practical course is Internet of Things (IoT); in this repository you will find part of the materials used in this scope.

# Olimex LED Matrix
Arduino Library for interfacing multiple Olimex RGB 8x8 Matrix.
Provider link: https://www.olimex.com/Products/MSP430/Booster/MOD-LED8x8/

## Installation
Download the files and include the header provided in your project. For those of you who are new to programming, you should know that you can use any programming interface you want, including the Arduino IDE. 

## Getting started

The RGB Matrix uses the SPI library, which means that it needs to be connected to the SPI pins. Usualy: CLOCK: 13, DATA: 10. The LATCH pin can be any pin and has to be supplied in the constructor.

The RGB Matrix does support multiplexing, it just has to be called on update.

Working examples are provided.
