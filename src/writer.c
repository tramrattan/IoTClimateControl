/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include"writer.h"

#define DHT11DATA_FILE "/home/pi/data/dht11.txt"

 _Bool writeDHT11Data(float humidity, float tmp){
     FILE *fp;
     char str[80];
     fp = fopen(DHT11DATA_FILE, "a");
     if(fp == NULL) {
         return false;
     }
     sprintf(str, "%.2f, %.2f\n", humidity, tmp);
     fprintf(fp, str);
     fclose(fp);
     return true;
}
