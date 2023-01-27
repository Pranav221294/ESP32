#include <Arduino.h>
#include "driver/uart.h"
#include <stdio.h>
#include <string.h>
#include "Esp_UART_1.h"
#include "Esp_UART_2.h"

void setup() 
{
   Serial.begin(115200);
   UART_1_init();
   UART_2_init();



}

void loop() 
{
  

  
}