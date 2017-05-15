/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: wrg
 *
 * Created on May 14, 2017, 5:29 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <wiringPi.h>
#include "../headers/dht11.h"
#include "../headers/writer.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*
     * Get Temp From Reader and Sever via a sever
     */
    printf("Interfacing Temperature and Humidity Sensor (DHT11) With Raspberry Pi\n");\
    if(wiringPiSetup()==-1)  
        exit(1);  
    while(1)  
    {  
        float * data = dht11_read_val();
        if(data != NULL) {
            float farenheit = data[1]*9./5.+32;
            writeDHT11Data(data[0], data[1]);
            printf("Humidity = %.2f Temperature = %.2f *C (%.2f *F)\n", data[0], data[1],farenheit);
        }
        delay(3000);  
    }  
    
    return 0;
}

