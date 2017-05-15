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
#include "dht11.h"

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
        dht11_read_val();
        delay(3000);  
    }  
    
    return 0;
}

