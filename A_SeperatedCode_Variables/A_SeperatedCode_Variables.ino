#define CLK 3 //clock pin on rotary encoder
#define DT 20 //pin for direction of rotary encoder
#define SW 18 //button on rotary encoder
#define LED_Others 9 //for any beat that is not beat 1
#define LED_Beat1 10 //for beat 1
#define timeSigButton 19 //button to change time signature

//motor pins
#define dirPin 4
#define stepPin 5
#define stepsPerRevolution 240

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
