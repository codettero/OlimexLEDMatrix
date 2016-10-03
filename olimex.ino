#include "font.h"

#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h>

/* MAC address from Ethernet shield sticker under board */
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 202); // IP address, may need to change depending on network
EthernetServer server(80);  // create a server at port 80

String HTTP_req;          // stores the HTTP request
boolean LED_status = 0;   // state of LED, off by default

#define USE_NEW_HEADER // comment this to use the Lutz Reiter 2014 version of the header

#ifdef USE_NEW_HEADER
#include "led_matrix.h"
#else
#include "OliLedMatrixRGB.h"
#endif

/* LED MATRIX PINS */
#define LED_LATCH 8

/* The number of matrix physically chained */
#define NUMBER_OF_MATRIX 1

#ifdef USE_NEW_HEADER
LedMatrix ledMatrixRGB(LED_LATCH, NUMBER_OF_MATRIX);
#else
OliLedMatrixRGB ledMatrixRGB(LED_LATCH);
#endif

/* Control variable */
int str = 0;

void setup() {
  digitalWrite(LED_LATCH,LOW);
    ledMatrixRGB.clear();
  #ifdef DEBUG // defined (or not) in led_matrix.h
    // Using the serial for debugging purposes
    Serial.begin(9600);
  #endif

    Ethernet.begin(mac, ip);  // initialize Ethernet device
    server.begin();           // start to listen for clients
}

void loop() {
 EthernetClient client = server.available();  // try to get client
  if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                HTTP_req += c;  // save the HTTP request 1 char at a time
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    // send web page
                    client.println("<!DOCTYPE html>");
                    client.println("<html>");
                    client.println("<head>");
                    client.println("<title>Ardu Control</title>");
                    client.println("</head>");
                    client.println("<body>");
                    client.println("<h1>Zambeste</h1>");
                    client.println("<p>Apasa si Ardu iti va zambi!</p>");
                    client.println("<form method=\"get\">");
                    client.println("<input type=\"text\" name=\"inputText\" > Introduceti");
                    client.println("<br><br><button type=\"button\" onclick=\"submit()\" > Send");
                    ProcessCheckbox(client);
                    client.println("</form>");
                    client.println("</body>");
                    client.println("</html>");
                    Serial.print(HTTP_req);
                    HTTP_req = "";    // finished with request, empty string
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                }
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)


    if(str == 1)
    {
        ledMatrixRGB.clear();
        ledMatrixRGB.setColor(Blue);
        ledMatrixRGB.drawPixel(5,5);
        ledMatrixRGB.display();  
        str = 0;
    }

    if(str == 2)
    {
        ledMatrixRGB.clear();
        ledMatrixRGB.setColor(Blue);
        ledMatrixRGB.drawPixel(2,2);
        ledMatrixRGB.display();
        str = 0;  
    }

    if(str == 3)
    {
        ledMatrixRGB.clear();
        ledMatrixRGB.setColor(Red);
        ledMatrixRGB.drawCircle(4,4,2);
        str = 0;
    }
}


void ProcessCheckbox(EthernetClient cl)
{ 
  if (HTTP_req.indexOf("favicon.ico") == -1)
    if (HTTP_req.indexOf("GET /?inputText=1") > -1) {  
        str = 1;
        }
        else if (HTTP_req.indexOf("GET /?inputText=2") > -1){
          str = 2;
        }
        else if (HTTP_req.indexOf("GET /?inputText=3") > -1){
          str = 3;
        }
        
        
    }
