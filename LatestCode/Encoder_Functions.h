#ifndef ENCODER_FUNCTIONS_H
#define ENCODER_FUNCTIONS_H
#include <Arduino.h> //must include this fse=or arduino functionality

//header file for encoder function

void updateEncoder(int CLK, int currentStateCLK,int lastStateCLK,int DT, int Tempo,int rotaryCounter,String currentDir, int delay_val_4, int delay_val6_8, int timeSig, int SW, int lastButtonPressR, bool startMet); //


#endif
