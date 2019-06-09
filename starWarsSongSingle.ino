//Setting up the notes values
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

//Setting pin values
const int buzzerPin = 8;
const int buttonPin = 11;

//LEDs not neccesary but carried over from other program
const int ledPin1 = 12;
const int ledPin2 = 13;


//Creating counters
int counter = 0;
int presses = 0;

//Creating song notes and timing sections
int notesFirstSection[] = {a, a, a, f, cH, a, f, cH, a, eH, eH, eH, fH, cH, gS, f, cH, a};
int timeFirstSection[] = {500, 500, 500, 350, 150, 500, 350, 150, 650, 500, 500, 500, 350, 150, 500, 350, 150, 650};

int notesSecondSection[] = {aH, a, a, aH, gSH, gH, fSH, fH, fSH, aS, dSH, dH, cSH, cH, b, cH};
int timeSecondSection[] = {500, 300, 150, 500, 325, 175, 125, 125, 250, 250, 500, 325, 175, 125, 125, 250};

int notesVariant1[] = {f, gS, f, a, cH, a, cH, eH};
int timeVariant1[] = {250, 500, 350, 125, 500, 375, 125, 650};

int notesVariant2[] = {f, gS, f, cH, a, f, cH, a};
int timeVariant2[] = {250, 500, 375, 125, 500, 375, 125, 650};

//This is the one I'm using for notes. The above were to help me translate from initial to now.
int notesAll[] = {a, a, a, f, cH, a, f, cH, a, eH, eH, eH, fH, cH, gS, f, cH, a,
                  aH, a, a, aH, gSH, gH, fSH, fH, fSH, aS, dSH, dH, cSH, cH, b, cH,
                  f, gS, f, a, cH, a, cH, eH,
                  aH, a, a, aH, gSH, gH, fSH, fH, fSH, aS, dSH, dH, cSH, cH, b, cH,
                  f, gS, f, cH, a, f, cH, a};
int timeAll[] = {500, 500, 500, 350, 150, 500, 350, 150, 650, 500, 500, 500, 350, 150, 500, 350, 150, 650,
                 500, 300, 150, 500, 325, 175, 125, 125, 250, 250, 500, 325, 175, 125, 125, 250,
                 250, 500, 350, 125, 500, 375, 125, 650,
                 500, 300, 150, 500, 325, 175, 125, 125, 250, 250, 500, 325, 175, 125, 125, 250,
                 250, 500, 375, 125, 500, 375, 125, 650};

//Setting up
void setup()
{
    //Setup pin modes
    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
}

//Creating a function to turn the buzzer on and off with a specific note and time
void beep(int note, int duration)
{
    //Play tone on buzzerPin
    tone(buzzerPin, note, duration);

    //Play different LED depending on value of 'counter'
    if (counter % 2 == 0)
    {
        digitalWrite(ledPin1, HIGH);
        delay(duration);
        digitalWrite(ledPin1, LOW);
    }
    else
    {
        digitalWrite(ledPin2, HIGH);
        delay(duration);
        digitalWrite(ledPin2, LOW);
    }

    //Stop tone on buzzerPin
    noTone(buzzerPin);

    delay(50);

    //Increment counter
    counter++;
}

//Main program loop
void loop()
{
    //Check for button press
    if(digitalRead(buttonPin) == HIGH){
        presses = presses + 1;
        beep(notesAll[presses],timeAll[presses]);
        //I would put a delay here but the beep does the delay for me. 
    }
}