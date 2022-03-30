
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

//to test all code is working together



//sda = 20, scl = 21 for mega board i2c module

#define CLK 3 //clock pin on rotary encoder
#define DT 6 //pin for direction of rotary encoder
#define SW 18 //button on rotary encoder
#define LED_Others 9 //for any beat that is not beat 1
#define LED_Beat1 10 //for beat 1
#define buttonPin 19 //button to change time signature
#define timeSigButton 1


//old motor code variables
//motor pins
#define dirPin 4
#define stepPin 5
#define stepsPerRevolution 240

new motor code variables
#define dirPinPos 2
#define dirPinNeg 4
#define stepPin 3
#define stepsPerRevolution 1500

LiquidCrystal_I2C lcd(0x27, 20, 4); //20x4 display, defining the lcd
bool Hi_Hat_Sig = 0; //signal for hi hat to be turned on or off. it is off initially
//int Drums_Status = 0; //Other drums with actuators are turned OFF initially
String Hi_Hat_Status; //string for lcd
//String Drums_Status_; //string for lcd
int Fun_called = 0; //keeping track of the lcd calls
String encdir ="";
String Curr_Selection = "<-";

int rotaryCounter = 0; //for keeping track of rotary position
int currentStateCLK; //rotary CLK pin state
int lastStateCLK; //last state of CLK pin
bool startMet = 0; //flag to start the metronome
String currentDir =""; //current direction of enncoder
unsigned long lastButtonPressR = 0; //last press of rotary encoder button
unsigned long lastButtonPressB = 0; //last press of time signature button

int Tempo = 120; //holds the starting tempo
int delay_val_4 = 500; //initial delay for tempo of 120 and quarter note gets beat (x/4 time)
int delay_val6_8 = 167; //initial delay for tempo of 120 and 1/8 note triplet gets beat (x/8 time)
int delay_val = delay_val_4; //holds value for LED's
int beatsPerMeasure = 4; //starting beats per measure
int count = 0; //counter for number of beats played in a measure
String timeSigValues[4] = {"4/4", "6/8", "3/4", "2/4"}; //time signature values - might be needed for lcd
int timeSig = 0; //starting time signature case

//interrupt function declarations
