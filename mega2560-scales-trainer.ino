/*
  Project Buttons Matrix Mapping
E-38-22-24-43
B-41-30-39-28
G-33-27-32-25
D-31-35-34-36
A-40-37-23-26
E-29-45-44-42
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_ADDRESS);

const String notes[4][15] = {
  {"E(8)","E(7)","E(8)","E(10)","E(8)","E(10)","A(7)","E(10)","A(7)","A(8)","A(7)","A(8)"},
  {"A(10)","A(8)","A(10)","D(7)","A(10)","D(7)","D(9)","D(7)","D(9)","D(10)","D(9)","D(10)"},
  {"e(8)","e(10)","e(8)","e(7)","e(8)","e(7)","B(10)","e(7)","B(10)","B(8)","B(10)","B(8)"},
  {"G(10)","B(8)","G(10)","G(9)","G(10)","G(9)","G(7)","G(9)","G(7)","D(10)","G(7)","D(10)"},
  };
const char sequence[] = {'E2'};
int currentNote = 0;
int currentRow = 0;

void verifyNote(const String note) {
  Serial.println(notes[currentRow][currentNote]);
  Serial.println(note);
  if(notes[currentRow][currentNote] == note) {
    Serial.println("Right");
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("RIGHT!");
    display.display();

    if(currentNote < 11) {
      currentNote++;
    }else if(currentNote == 11 && currentRow < 4){
      currentNote = 0;
      currentRow++;
    }else if(currentNote == 11 && currentRow == 4) {
      currentNote = 0;
      currentRow = 0;
    }
    
    delay(700);
  }else {
    Serial.println("Wrong");
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println(note);
    display.setCursor(55, 10);
    display.println("!=");
    display.setCursor(0, 30);
    display.println(notes[currentRow][currentNote]);
    display.display();
    delay(700);
  }
  
}

void displayNote(const char* note) {
  verifyNote(note);
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println(note);
  display.display();
}

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  for(int i = 22 ;i<46; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(1);
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.println("Guitar Scales");
  display.display();
}

void loop() {
  const int btn22State = digitalRead(22);
  const int btn23State = digitalRead(23);
  const int btn24State = digitalRead(24);
  const int btn25State = digitalRead(25);
  const int btn26State = digitalRead(26);
  const int btn27State = digitalRead(27);
  const int btn28State = digitalRead(28);
  const int btn29State = digitalRead(29);
  const int btn30State = digitalRead(30);
  const int btn31State = digitalRead(31);
  const int btn32State = digitalRead(32);
  const int btn33State = digitalRead(33);
  const int btn34State = digitalRead(34);
  const int btn35State = digitalRead(35);
  const int btn36State = digitalRead(36);
  const int btn37State = digitalRead(37);
  const int btn38State = digitalRead(38);
  const int btn39State = digitalRead(39);
  const int btn40State = digitalRead(40);
  const int btn41State = digitalRead(41);
  const int btn42State = digitalRead(42);
  const int btn43State = digitalRead(43);
  const int btn44State = digitalRead(44);
  const int btn45State = digitalRead(45);

  if (btn22State == LOW) {
    displayNote("e(8)");
  }
  if (btn23State == LOW) {
    displayNote("A(9)");
  }
  if (btn24State == LOW) {
    displayNote("e(9)");
  }
  if (btn25State == LOW) {
    displayNote("G(10)");
  }
  if (btn26State == LOW) {
    displayNote("A(10)");
  }
  if (btn27State == LOW) {
    displayNote("G(8)");
  }
  if (btn28State == LOW) {
    displayNote("B(10)");
  }
  if (btn29State == LOW) {
    displayNote("E(7)");
  }
  if (btn30State == LOW) {
    displayNote("B(8)");
  }
  if (btn31State == LOW) {
    displayNote("D(7)");
  }
  if (btn32State == LOW) {
    displayNote("G(9)");
  }
  if (btn33State == LOW) {
    displayNote("G(7)");
  }
  if (btn34State == LOW) {
    displayNote("D(9)");
  }
  if (btn35State == LOW) {
    displayNote("D(8)");
  }
  if (btn36State == LOW) {
    displayNote("D(10)");
  }
  if (btn37State == LOW) {
    displayNote("A(8)");
  }
  if (btn38State == LOW) {
    displayNote("e(7)");
  }
  if (btn39State == LOW) {
    displayNote("B(9)");
  }
  if (btn40State == LOW) {
    displayNote("A(7)");
  }
  if (btn41State == LOW) {
    displayNote("B(7)");
  }
  if (btn42State == LOW) {
    displayNote("E(10)");
  }
  if (btn43State == LOW) {
    displayNote("e(10)");
  }
  if (btn44State == LOW) {
    displayNote("E(9)");
  }
  if (btn45State == LOW) {
    displayNote("E(8)");
  }
  delay(500);
}
