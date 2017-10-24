#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 12

String data;
int GREEN;
int RED;
int BLUE;
int GREEN1 = 2;
int RED1 = 3;
int BLUE1 = 6;
int GREEN2 = 10;
int RED2 = 11;
int BLUE2 = 8;

int rgb[3];
int rgb1[3];
int rgb2[3];

int fav1a[3];
int fav2a[3];
int fav3a[3];

int fav1b[3];
int fav2b[3];
int fav3b[3];

void setup() {
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  rgb[0] = 0;
  rgb[1] = 0;
  rgb[2] = 0;
  rgb1[0] = 0;
  rgb1[1] = 0;
  rgb1[2] = 0;
  rgb2[0] = 0;
  rgb2[1] = 0;
  rgb2[2] = 0;
}

void loop() {

}

void serialEvent() {
  if (Serial.available()) {
    data = Serial.readString();

    if (data == "G") {
      greenON(1);
    }
    if (data == "g") {
      greenOFF(1);
    }
    if (data == "R") {
      redON(1);
    }
    if (data == "r") {
      redOFF(1);
    }
    if (data == "B") {
      blueON(1);
    }
    if (data == "b") {
      blueOFF(1);
    }
    if (data == "Red") {
      setColorDinamic(255, 0, 0, 1);
    }
    if (data == "Green") {
      setColorDinamic(0, 255, 0, 1);
    }
    if (data == "Blue") {
      setColorDinamic(0, 0, 255, 1);
    }
    if (data == "White") {
      setColorDinamic(255, 255, 255, 1);
    }
    if (data == "Pink") {
      setColorDinamic(255, 0, 110, 1);
    }
    if (data == "Purple") {
      setColorDinamic(100, 0, 255, 1);
    }
    if (data == "DeepPurple") {
      setColorDinamic(50, 0, 255, 1);
    }
    if (data == "Indigo") {
      setColorDinamic(0, 20, 255, 1);
    }
    if (data == "Cyan") {
      setColorDinamic(0, 150, 255, 1);
    }
    if (data == "Teal") {
      setColorDinamic(0, 180, 160, 1);
    }
    if (data == "LightGreen") {
      setColorDinamic(0, 255, 100, 1);
    }
    if (data == "Lime") {
      setColorDinamic(50, 200, 80, 1);
    }
    if (data == "Yellow") {
      setColorDinamic(255, 150, 0, 1);
    }
    if (data == "LightOrange") {
      setColorDinamic(255, 25, 0, 1);
    }
    if (data == "Orange") {
      setColorDinamic(255, 50, 0, 1);
    }
    if (data == "DarkOrange") {
      setColorDinamic(255, 25, 0, 1);
    }
    if (data == "chroma") {
      chroma(1);
    }
    if (data == "testLoop") {
      testLoop();
    }
    if (data == "pulseR") {
      pulseR(1);
    }
    if (data == "pulseG") {
      pulseG(1);
    }
    if (data == "pulseB") {
      pulseB(1);
    }
    if (data == "brilhoRP") {
      brilhoRP(1);
    }
    if (data == "brilhoRM") {
      brilhoRM(1);
    }
    if (data == "brilhoGP") {
      brilhoGP(1);
    }
    if (data == "brilhoGM") {
      brilhoGM(1);
    }
    if (data == "brilhoBP") {
      brilhoBP(1);
    }
    if (data == "brilhoBM") {
      brilhoBM(1);
    }
    if (data == "FreezeChroma") {
      freezeChroma(1);
    }
    if (data == "setFav1") {
      setFav(1, 1);
    }
    if (data == "showFav1") {
      showFav(1, 1);
    }
    if (data == "setFav2") {
      setFav(2, 1);
    }
    if (data == "showFav2") {
      showFav(2, 1);
    }
    if (data == "setFav3") {
      setFav(3, 1);
    }
    if (data == "showFav3") {
      showFav(3, 1);
    }
    if (data == "10%") {
      setColorDinamic(0, 250, 0, 1);
    }
    if (data == "20%") {
      setColorDinamic(25, 225, 0, 1);
    }
    if (data == "30%") {
      setColorDinamic(50, 200, 0, 1);
    }
    if (data == "40%") {
      setColorDinamic(75, 175, 0, 1);
    }
    if (data == "50%") {
      setColorDinamic(100, 150, 0, 1);
    }
    if (data == "60%") {
      setColorDinamic(125, 125, 0, 1);
    }
    if (data == "70%") {
      setColorDinamic(150, 100, 0, 1);
    }
    if (data == "80%") {
      setColorDinamic(175, 75, 0, 1);
    }
    if (data == "90%") {
      setColorDinamic(200, 50, 0, 1);
    }
    if (data == "100%") {
      setColorDinamic(255, 0, 0, 1);
    }
    if (data == "reset") {
      resetAll(1);
    }

    //FITA NUMERO 2 -----------------------------------------------------------

    if (data == "G2") {
      greenON(2);
    }
    if (data == "g2") {
      greenOFF(2);
    }
    if (data == "R2") {
      redON(2);
    }
    if (data == "r2") {
      redOFF(2);
    }
    if (data == "B2") {
      blueON(2);
    }
    if (data == "b2") {
      blueOFF(2);
    }
    if (data == "Red2") {
      setColorDinamic(255, 0, 0, 2);
    }
    if (data == "Green2") {
      setColorDinamic(0, 255, 0, 2);
    }
    if (data == "Blue2") {
      setColorDinamic(0, 0, 255, 2);
    }
    if (data == "White2") {
      setColorDinamic(255, 255, 255, 2);
    }
    if (data == "Pink2") {
      setColorDinamic(255, 0, 110, 2);
    }
    if (data == "Purple2") {
      setColorDinamic(100, 0, 255, 2);
    }
    if (data == "DeepPurple2") {
      setColorDinamic(50, 0, 255, 2);
    }
    if (data == "Indigo2") {
      setColorDinamic(0, 20, 255, 2);
    }
    if (data == "Cyan2") {
      setColorDinamic(0, 150, 255, 2);
    }
    if (data == "Teal2") {
      setColorDinamic(0, 180, 160, 2);
    }
    if (data == "LightGreen2") {
      setColorDinamic(0, 255, 100, 2);
    }
    if (data == "Lime2") {
      setColorDinamic(50, 200, 80, 2);
    }
    if (data == "Yellow2") {
      setColorDinamic(255, 150, 0, 2);
    }
    if (data == "LightOrange2") {
      setColorDinamic(255, 25, 0, 2);
    }
    if (data == "Orange2") {
      setColorDinamic(255, 50, 0, 2);
    }
    if (data == "DarkOrange2") {
      setColorDinamic(255, 25, 0, 2);
    }
    if (data == "chroma2") {
      chroma(2);
    }
    if (data == "pulseR2") {
      pulseR(2);
    }
    if (data == "pulseG2") {
      pulseG(2);
    }
    if (data == "pulseB2") {
      pulseB(2);
    }
    if (data == "brilhoRP2") {
      brilhoRP(2);
    }
    if (data == "brilhoRM2") {
      brilhoRM(2);
    }
    if (data == "brilhoGP2") {
      brilhoGP(2);
    }
    if (data == "brilhoGM2") {
      brilhoGM(2);
    }
    if (data == "brilhoBP2") {
      brilhoBP(2);
    }
    if (data == "brilhoBM2") {
      brilhoBM(2);
    }
    if (data == "FreezeChroma2") {
      freezeChroma(2);
    }
    if (data == "setFav12") {
      setFav(1, 2);
    }
    if (data == "showFav12") {
      showFav(1, 2);
    }
    if (data == "setFav22") {
      setFav(2, 2);
    }
    if (data == "showFav22") {
      showFav(2, 2);
    }
    if (data == "setFav32") {
      setFav(3, 2);
    }
    if (data == "showFav32") {
      showFav(3, 2);
    }
    if (data == "10%2") {
      setColorDinamic(0, 250, 0, 2);
    }
    if (data == "20%2") {
      setColorDinamic(25, 225, 0, 2);
    }
    if (data == "30%2") {
      setColorDinamic(50, 200, 0, 2);
    }
    if (data == "40%2") {
      setColorDinamic(75, 175, 0, 2);
    }
    if (data == "50%2") {
      setColorDinamic(100, 150, 0, 2);
    }
    if (data == "60%2") {
      setColorDinamic(125, 125, 0, 2);
    }
    if (data == "70%2") {
      setColorDinamic(150, 100, 0, 2);
    }
    if (data == "80%2") {
      setColorDinamic(175, 75, 0, 2);
    }
    if (data == "90%2") {
      setColorDinamic(200, 50, 0, 2);
    }
    if (data == "100%2") {
      setColorDinamic(255, 0, 0, 2);
    }
    if (data == "reset2") {
      resetAll(2);
    }
  }
}

void resetAll(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  setColorDinamic(0, 0, 0, strip);
}

void greenON(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(GREEN, i);
    delay(10);
  }

  if (strip == 1) {
    rgb1[1] = 255;
  }
  if (strip == 2) {
    rgb2[1] = 255;
  }

}

void greenOFF(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  for (int i = rgb[1]; i >= 0; i--) {
    analogWrite(GREEN, i);
    delay(1);
  }
  if (strip == 1) {
    rgb1[1] = 0;
  }
  if (strip == 2) {
    rgb2[1] = 0;
  }
}

void redON(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(RED, i);
    delay(10);
  }
  if (strip == 1) {
    rgb1[0] = 255;
  }
  if (strip == 2) {
    rgb2[0] = 255;
  }
}

void redOFF(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  for (int i = rgb[0]; i >= 0; i--) {
    analogWrite(RED, i);
    delay(1);
  }
  if (strip == 1) {
    rgb1[0] = 0;
  }
  if (strip == 2) {
    rgb2[0] = 0;
  }
}

void blueON(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(BLUE, i);
    delay(10);
  }
  if (strip == 1) {
    rgb1[2] = 255;
  }
  if (strip == 2) {
    rgb2[2] = 255;
  }
}

void blueOFF(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  for (int i = rgb[2]; i >= 0; i--) {
    analogWrite(BLUE, i);
    delay(1);
  }
  if (strip == 1) {
    rgb1[2] = 0;
  }
  if (strip == 2) {
    rgb2[2] = 0;
  }
}

void setColor(int r, int g, int b, int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }

  resetAll(strip);

  for (int i = 0; i <= r; i++) {
    analogWrite(RED, i);
    delay(5);
  }
  for (int i = 0; i <= g; i++) {
    analogWrite(GREEN, i);
    delay(5);
  }
  for (int i = 0; i <= b; i++) {
    analogWrite(BLUE, i);
    delay(5);
  }

  if (strip == 1) {
    rgb1[0] = r;
    rgb1[1] = g;
    rgb1[2] = b;
  }
  if (strip == 2) {
    rgb2[0] = r;
    rgb2[1] = g;
    rgb2[2] = b;
  }

}

void chroma(int strip) {
  int pinR = RED;
  int pinG = GREEN;
  int pinB = BLUE;

  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }

  resetAll(strip);
  // Declara as variáveis dos loops
  int r, g, b;

  while (Serial.available() == 0) {
    // Fade do azul (ja estava aceso) até o violeta, adicionando o vermelho
    for (r = 0; r <= 255; r++) {
      analogWrite(pinR, r);
      delay(10);
    }

    // Fade do violeta até o vermelho, removendo o azul
    for (b = 255; b >= 0; b--) {
      analogWrite(pinB, b);
      delay(10);
    }

    // Fade do vermelho até o amarelo, adicionando o verde
    for (g = 0; g <= 255; g++) {
      analogWrite(pinG, g);
      delay(10);
    }

    // Fade do amarelo até o verde, removendo o vermelho
    for (r = 255; r >= 0; r--) {
      analogWrite(pinR, r);
      delay(10);
    }

    // Fade do verde até o turquesa, adicionando o azul
    for (b = 0; b <= 255; b++) {
      analogWrite(pinB, b);
      delay(10);
    }

    // Fade do turquesa até o azul, removendo o verde
    for (g = 255; g >= 0; g--) {
      analogWrite(pinG, g);
      delay(10);
    }

    // Em seguida o loop continua, com o azul aceso
  }
  resetAll(strip);
}

void testLoop() {
  bool repeat = true;
  while (Serial.available() == 0) {
    chroma(1);
  }
}

void pulseR (int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  resetAll(strip);
  // Declara as variáveis dos loops

  while (Serial.available() == 0) {

    for (int i = 0; i <= 255; i++) {
      analogWrite(RED, i);
      delay(5);
    }

    for (int i = 255; i >= 0; i--) {
      analogWrite(RED, i);
      delay(5);
    }
  }
}

void pulseG (int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  resetAll(strip);
  // Declara as variáveis dos loops

  while (Serial.available() == 0) {

    for (int i = 0; i <= 255; i++) {
      analogWrite(GREEN, i);
      delay(5);
    }

    for (int i = 255; i >= 0; i--) {
      analogWrite(GREEN, i);
      delay(5);
    }
  }
}

void pulseB (int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  resetAll(strip);
  // Declara as variáveis dos loops

  while (Serial.available() == 0) {

    for (int i = 0; i <= 255; i++) {
      analogWrite(BLUE, i);
      delay(5);
    }

    for (int i = 255; i >= 0; i--) {
      analogWrite(BLUE, i);
      delay(5);
    }
  }
}
void brilhoRP(int strip) {

  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }

  if (rgb[0] <= 230) {
    for (int i = rgb[0]; i <= rgb[0] + 25; i++) {
      analogWrite(RED, i);
      delay(5);
    }
    rgb[0] = rgb[0] + 25;
    if (strip == 1) {
      rgb1[0] = rgb[0];
    }
    if (strip == 2) {
      rgb2[0] = rgb[0];
    }
  }
  else {
    for (int i = rgb[0]; i < 255; i++) {
      analogWrite(RED, i);
      delay(5);
    }
    rgb[0] = 255;
    if (strip == 1) {
      rgb1[0] = rgb[0];
    }
    if (strip == 2) {
      rgb2[0] = rgb[0];
    }
  }
}
void brilhoRM(int strip) {

  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }

  if (rgb[0] >= 25) {
    for (int i = rgb[0]; i >= rgb[0] - 25; i--) {
      analogWrite(RED, i);
      delay(5);
    }
    rgb[0] = rgb[0] - 25;
    if (strip == 1) {
      rgb1[0] = rgb[0];
    }
    if (strip == 2) {
      rgb2[0] = rgb[0];
    }
  }
  else {
    for (int i = rgb[0]; i >= 0; i--) {
      analogWrite(RED, i);
      delay(5);
    }
    rgb[0] = 0;
    if (strip == 1) {
      rgb1[0] = rgb[0];
    }
    if (strip == 2) {
      rgb2[0] = rgb[0];
    }
  }
}
void brilhoGP(int strip) {

  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }

  if (rgb[1] <= 230) {
    for (int i = rgb[1]; i <= rgb[1] + 25; i++) {
      analogWrite(GREEN, i);
      delay(5);
    }
    rgb[1] = rgb[1] + 25;
    if (strip == 1) {
      rgb1[1] = rgb[1];
    }
    if (strip == 2) {
      rgb2[1] = rgb[1];
    }
  }
  else {
    for (int i = rgb[1]; i < 255; i++) {
      analogWrite(GREEN, i);
      delay(5);
    }
    rgb[1] = 255;
    if (strip == 1) {
      rgb1[1] = rgb[1];
    }
    if (strip == 2) {
      rgb2[1] = rgb[1];
    }
  }
}
void brilhoGM(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  if (rgb[1] >= 25) {
    for (int i = rgb[1]; i >= rgb[1] - 25; i--) {
      analogWrite(GREEN, i);
      delay(5);
    }
    rgb[1] = rgb[1] - 25;
    if (strip == 1) {
      rgb1[1] = rgb[1];
    }
    if (strip == 2) {
      rgb2[1] = rgb[1];
    }
  }
  else {
    for (int i = rgb[1]; i >= 0; i--) {
      analogWrite(GREEN, i);
      delay(5);
    }
    rgb[1] = 0;
    if (strip == 1) {
      rgb1[1] = rgb[1];
    }
    if (strip == 2) {
      rgb2[1] = rgb[1];
    }
  }
}

void brilhoBP(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  if (rgb[2] <= 230) {
    for (int i = rgb[2]; i <= rgb[2] + 25; i++) {
      analogWrite(BLUE, i);
      delay(5);
    }
    rgb[2] = rgb[2] + 25;
    if (strip == 1) {
      rgb1[2] = rgb[2];
    }
    if (strip == 2) {
      rgb2[2] = rgb[2];
    }
  }
  else {
    for (int i = rgb[2]; i < 255; i++) {
      analogWrite(BLUE, i);
      delay(5);
    }
    rgb[2] = 255;
    if (strip == 1) {
      rgb1[2] = rgb[2];
    }
    if (strip == 2) {
      rgb2[2] = rgb[2];
    }
  }
}
void brilhoBM(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  if (rgb[2] >= 25) {
    for (int i = rgb[2]; i >= rgb[2] - 25; i--) {
      analogWrite(BLUE, i);
      delay(5);
    }
    rgb[2] = rgb[2] - 25;
    if (strip == 1) {
      rgb1[2] = rgb[2];
    }
    if (strip == 2) {
      rgb2[2] = rgb[2];
    }
  }
  else {
    for (int i = rgb[2]; i >= 0; i--) {
      analogWrite(BLUE, i);
      delay(5);
    }
    rgb[2] = 0;
    if (strip == 1) {
      rgb1[2] = rgb[2];
    }
    if (strip == 2) {
      rgb2[2] = rgb[2];
    }
  }
}
void freezeChroma(int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  resetAll(strip);
  // Declara as variáveis dos loops
  int r, g, b;


  while (Serial.available() == 0) {
    // Fade do azul (ja estava aceso) até o violeta, adicionando o vermelho
    for (r = 0; r <= 255; r++) {
      if (Serial.available() == 0) {
        analogWrite(RED, r);
        rgb[0] = r;
        if (strip == 1) {
          rgb1[0] = rgb[0];
        }
        if (strip == 2) {
          rgb2[0] = rgb[0];
        }
        delay(10);
      }
      else {
        return;
      }
    }

    // Fade do violeta até o vermelho, removendo o azul
    for (b = 255; b >= 0; b--) {
      if (Serial.available() == 0) {
        analogWrite(BLUE, b);
        rgb[2] = b; if (strip == 1) {
          rgb1[2] = rgb[2];
        }
        if (strip == 2) {
          rgb2[2] = rgb[2];
        }
        delay(10);
      }
      else {
        return;
      }
    }

    // Fade do vermelho até o amarelo, adicionando o verde
    for (g = 0; g <= 255; g++) {
      if (Serial.available() == 0) {
        analogWrite(GREEN, g);
        rgb[1] = g;
        if (strip == 1) {
          rgb1[1] = rgb[1];
        }
        if (strip == 2) {
          rgb2[1] = rgb[1];
        }
        delay(10);
      }
      else {
        return;
      }
    }

    // Fade do amarelo até o verde, removendo o vermelho
    for (r = 255; r >= 0; r--) {
      if (Serial.available() == 0) {
        analogWrite(RED, r);
        rgb[0] = r;
        if (strip == 1) {
          rgb1[0] = rgb[0];
        }
        if (strip == 2) {
          rgb2[0] = rgb[0];
        }
        delay(10);
      }
      else {
        return;
      }
    }

    // Fade do verde até o turquesa, adicionando o azul
    for (b = 0; b <= 255; b++) {
      if (Serial.available() == 0) {
        analogWrite(BLUE, b);
        rgb[2] = b;
        if (strip == 1) {
          rgb1[2] = rgb[2];
        }
        if (strip == 2) {
          rgb2[2] = rgb[2];
        }
        delay(10);
      }
      else {
        return;
      }
    }

    // Fade do turquesa até o azul, removendo o verde
    for (g = 255; g >= 0; g--) {
      if (Serial.available() == 0) {
        analogWrite(GREEN, g);
        rgb[1] = g;
        if (strip == 1) {
          rgb1[1] = rgb[1];
        }
        if (strip == 2) {
          rgb2[1] = rgb[1];
        }
        delay(10);
      }
      else {
        return;
      }
    }

    // Em seguida o loop continua, com o azul aceso
  }
}
void setFav(int num, int strip) {

  if (strip == 1) {
    if (num == 1) {
      fav1a[0] = rgb1[0];
      fav1a[1] = rgb1[1];
      fav1a[2] = rgb1[2];
    }
    if (num == 2) {
      fav2a[0] = rgb1[0];
      fav2a[1] = rgb1[1];
      fav2a[2] = rgb1[2];
    }
    if (num == 3) {
      fav3a[0] = rgb1[0];
      fav3a[1] = rgb1[1];
      fav3a[2] = rgb1[2];
    }
  }

  if (strip == 2) {
    if (num == 1) {
      fav1b[0] = rgb2[0];
      fav1b[1] = rgb2[1];
      fav1b[2] = rgb2[2];
    }
    if (num == 2) {
      fav2b[0] = rgb2[0];
      fav2b[1] = rgb2[1];
      fav2b[2] = rgb2[2];
    }
    if (num == 3) {
      fav3b[0] = rgb2[0];
      fav3b[1] = rgb2[1];
      fav3b[2] = rgb2[2];
    }
  }
}
void showFav(int num, int strip) {
  if (strip == 1) {
    if (num == 1) {
      setColorDinamic(fav1a[0], fav1a[1], fav1a[2], strip);
      rgb[0] = fav1a[0];
      rgb[1] = fav1a[1];
      rgb[2] = fav1a[2];
      return;
    }
    if (num == 2) {
      setColorDinamic(fav2a[0], fav2a[1], fav2a[2], strip);
      rgb[0] = fav2a[0];
      rgb[1] = fav2a[1];
      rgb[2] = fav2a[2];
      return;
    }
    if (num == 3) {
      setColorDinamic(fav3a[0], fav3a[1], fav3a[2], strip);
      rgb[0] = fav3a[0];
      rgb[1] = fav3a[1];
      rgb[2] = fav3a[2];
      return;
    }
  }

  if (strip == 2) {
    if (num == 1) {
      setColorDinamic(fav1b[0], fav1b[1], fav1b[2], strip);
      rgb[0] = fav1b[0];
      rgb[1] = fav1b[1];
      rgb[2] = fav1b[2];
      return;
    }
    if (num == 2) {
      setColorDinamic(fav2b[0], fav2b[1], fav2b[2], strip);
      rgb[0] = fav2b[0];
      rgb[1] = fav2b[1];
      rgb[2] = fav2b[2];
      return;
    }
    if (num == 3) {
      setColorDinamic(fav3b[0], fav3b[1], fav3b[2], strip);
      rgb[0] = fav3b[0];
      rgb[1] = fav3b[1];
      rgb[2] = fav3b[2];
      return;
    }
  }
}

void setColorDinamic(int r, int g, int b, int strip) {
  if (strip == 1) {
    RED = RED1;
    GREEN = GREEN1;
    BLUE = BLUE1;
    rgb[0] = rgb1[0];
    rgb[1] = rgb1[1];
    rgb[2] = rgb1[2];
  }
  if (strip == 2) {
    RED = RED2;
    GREEN = GREEN2;
    BLUE = BLUE2;
    rgb[0] = rgb2[0];
    rgb[1] = rgb2[1];
    rgb[2] = rgb2[2];
  }
  /*  TROCA DINAMICA NO VERMELHO */
  if (r > rgb[0]) {
    for (int i = rgb[0]; i <= r; i++) {
      analogWrite(RED, i);
      delay(5);
      rgb[0] = i;
      if (strip == 1) {
        rgb1[0] = rgb[0];
      }
      if (strip == 2) {
        rgb2[0] = rgb[0];
      }
    }
  } else if (r < rgb[0]) {
    for (int i = rgb[0]; i >= r; i--) {
      analogWrite(RED, i);
      delay(5);
      rgb[0] = i;
      if (strip == 1) {
        rgb1[0] = rgb[0];
      }
      if (strip == 2) {
        rgb2[0] = rgb[0];
      }
    }
  } else {
    rgb[0] = r;
    if (strip == 1) {
        rgb1[0] = rgb[0];
      }
      if (strip == 2) {
        rgb2[0] = rgb[0];
      }
  }
  /*  TROCA DINAMICA NO VERDE */
  if (g > rgb[1]) {
    for (int i = rgb[1]; i <= g; i++) {
      analogWrite(GREEN, i);
      delay(5);
      rgb[1] = i;
      if (strip == 1) {
        rgb1[1] = rgb[1];
      }
      if (strip == 2) {
        rgb2[1] = rgb[1];
      }
    }
  } else if (g < rgb[1]) {
    for (int i = rgb[1]; i >= g; i--) {
      analogWrite(GREEN, i);
      delay(5);
      rgb[1] = i;
      if (strip == 1) {
        rgb1[1] = rgb[1];
      }
      if (strip == 2) {
        rgb2[1] = rgb[1];
      }
    }
  } else {
    rgb[1] = g;
    if (strip == 1) {
        rgb1[1] = rgb[1];
      }
      if (strip == 2) {
        rgb2[1] = rgb[1];
      }
  }
  /*  TROCA DINAMICA NO AZUL */
  if (b > rgb[2]) {
    for (int i = rgb[2]; i <= b; i++) {
      analogWrite(BLUE, i);
      delay(5);
      rgb[2] = i;
      if (strip == 1) {
        rgb1[2] = rgb[2];
      }
      if (strip == 2) {
        rgb2[2] = rgb[2];
      }
    }
  } else if (b < rgb[2]) {
    for (int i = rgb[2]; i >= b; i--) {
      analogWrite(BLUE, i);
      delay(5);
      rgb[2] = i;
      if (strip == 1) {
        rgb1[2] = rgb[2];
      }
      if (strip == 2) {
        rgb2[2] = rgb[2];
      }
    }
  } else {
    rgb[2] = b;
    if (strip == 1) {
        rgb1[2] = rgb[2];
      }
      if (strip == 2) {
        rgb2[2] = rgb[2];
      }
  }

}

