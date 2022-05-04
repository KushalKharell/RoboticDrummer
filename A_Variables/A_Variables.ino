
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

#define CLK 3 //clock pin on rotary encoder - interrupt pin
#define DT 2 //pin for direction of rotary encoder
//#define SW 18 //button on rotary encoder
#define LED_Others 11 //for any beat that is not beat 1
#define LED_Beat1 10 //for beat 1
#define buttonPin 19 //button to change time signature
#define timeSigButton 1

//hi hat motor code variables
#define HiHat_dirPinPos 4
#define HiHat_dirPinNeg 5
#define HiHat_stepPin 6

//Kick motor code variables
#define Kick_dirPinPos 49
#define Kick_dirPinNeg 48
#define Kick_stepPin 50

//solonoid pin
#define Solenoid1 46

//step size for motors
#define stepsPerRevolution 100 //half of the motor's full step size

//sda = 20, scl = 21 for mega board i2c module
LiquidCrystal_I2C lcd(0x27, 20, 4); //20x4 display, defining the lcd
bool Hi_Hat_Sig = 0; //signal for hi hat to be turned on or off. it is off initially
int Kick_Sig = 0; //Other drums with actuators are turned OFF initially
String Hi_Hat_Status = "OFF"; //string for lcd
String Kick_Status = "OFF"; //string for lcd
int Snare_Sig = 0; //signal for snare to be turned on/off
String Snare_Status = "OFF"; //string for lcd
int Fun_called = 1; //keeping track of the which option is selected on LCD (tempo = 1, time sig = 2, hi-hat = 3, kick = 4, snare = 5)
String encdir ="";
String Curr_Selection = "<-";
bool lcdChange = false; //to check if the lcd needs updated
bool buttonUpdate = false; //to check if button was pressed

//timers - to eliminate use of delay() function
unsigned long timeBeginHiHat; //holds time at start of LCD_Menu()
unsigned long timeEndHiHat; //holds time at end of LCD_Menu()

unsigned long timeBeginKick; //holds time at start of LCD_Menu()
unsigned long timeEndKick; //holds time at end of LCD_Menu()

unsigned long timeBeginSnare; //holds time at start of LCD_Menu()
unsigned long timeEndSnare; //holds time at end of LCD_Menu()

unsigned long currentTime; //to hold the current time 
unsigned long stepInterval = 1200; //number of microseconds to delay between steps 

//for rotary encoder - in updateEncoder() function
int rotaryCounter = 0; //for keeping track of rotary position
int currentStateCLK; //rotary CLK pin state
int lastStateCLK; //last state of CLK pin
bool startMet = 0; //flag to start the metronome
String currentDir =""; //current direction of enncoder
unsigned long lastButtonPressR = 0; //last press of rotary encoder button
unsigned long lastButtonPressB = 0; //last press of time signature button

//for tempo calculation - timeSigTempo()
int Tempo = 120; //holds the starting tempo - based on step size
int delay_val_4 = 500; //initial delay for tempo of 120 and quarter note gets beat (x/4 time)
int delay_val6_8 = 167; //initial delay for tempo of 120 and 1/8 note triplet gets beat (x/8 time)
unsigned long delay_val = delay_val_4; //holds value for LED's
int beatsPerMeasure = 4; //starting beats per measure
int count = 0; //counter for number of beats played in a measure
String timeSigValues[4] = {"4/4", "6/8", "3/4", "2/4"}; //time signature values - might be needed for lcd
int timeSig = 0; //starting time signature case 

int hiHatFlag = 0;
