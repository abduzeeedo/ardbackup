#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 13

int numLeds = 16;
int rgb3[3];
int colorPick[3];
int maxRed = 70;
int maxGreen = 255;
int maxBlue = 70;
int posAtual;
int porcentAtual;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, PIN, NEO_RGB + NEO_KHZ400);

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

int allFav1[3];
int allFav2[3];
int allFav3[3];

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  rgb3[0] = 0;
  rgb3[1] = 0;
  rgb3[2] = 0;
  colorPick[0] = 0;
  colorPick[1] = 255;
  colorPick[2] = 200;

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
      setColorDinamic(255, 170, 255, 1);
    }
    if (data == "Pink") {
      setColorDinamic(150, 0, 110, 1);
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
    if (data == "fire") {
      Fire(55, 120, 15);
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
      setColorDinamic(255, 175, 255, 2);
    }
    if (data == "Pink2") {
      setColorDinamic(255, 0, 110, 2);
    }
    if (data == "Purple2") {
      setColorDinamic(130, 0, 255, 2);
    }
    if (data == "DeepPurple2") {
      setColorDinamic(100, 0, 255, 2);
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

    //Fita Led NeoPixel ---------------------------------------------------------------

    if (data == "resetNeo") {
      resetAllNeo();
    }
    if (data == "chromaAllNeo") {
      chromaAll(5);
    }
    if (data == "chromaNeo") {
      chromaNeo(5);
    }
    if (data == "RunningLights") {
      RunningLights(colorPick[0], colorPick[1], colorPick[2], 40);
    }
    if (data == "Cylon") {
      CylonBounce(colorPick[0], colorPick[1], colorPick[2], 2, 25, 125);
    }
    if (data == "pulse") {
      pulse(7, colorPick[0], colorPick[1], colorPick[2]);
    }
    if (data == "pulseLat") {
      pulseLat(40, colorPick[0], colorPick[1], colorPick[2]);
    }
    if (data == "colorWipe") {
      colorWipe(40, colorPick[0], colorPick[1], colorPick[2]);
    }
    if (data == "setFade") {
      setAllDinamic(5, colorPick[0], colorPick[1], colorPick[2]);
    }
    if (data == "setLat") {
      acendeLat(30, colorPick[0], colorPick[1], colorPick[2]);
    }
    if (data == "porcentLat10") {
      porcentLat(3); //quantidade leds acendido da direita pra esquerda
    }
    if (data == "porcentLat20") {
      porcentLat(5);
    }
    if (data == "porcentLat30") {
      porcentLat(7);
    }
    if (data == "porcentLat40") {
      porcentLat(9);
    }
    if (data == "porcentLat50") {
      porcentLat(10);
    }
    if (data == "porcentLat60") {
      porcentLat(11);
    }
    if (data == "porcentLat70") {
      porcentLat(13);
    }
    if (data == "porcentLat80") {
      porcentLat(15);
    }
    if (data == "porcentLat90") {
      porcentLat(16);
    }
    if (data == "porcentLat100") {
      porcentLat(18);
    }
    if (data == "porcent10") {
      porcent(0); //porcentagem real de uso - 0-100
    }
    if (data == "porcent20") {
      porcent(10);
    }
    if (data == "porcent30") {
      porcent(30);
    }
    if (data == "porcent40") {
      porcent(40);
    }
    if (data == "porcent50") {
      porcent(50);
    }
    if (data == "porcent60") {
      porcent(60);
    }
    if (data == "porcent70") {
      porcent(70);
    }
    if (data == "porcent80") {
      porcent(80);
    }
    if (data == "porcent90") {
      porcent(90);
    }
    if (data == "porcent100") {
      porcent(100);
    }
    if (data == "addRedNeo") {
      changeColor("add", "red");
    }
    if (data == "addGreenNeo") {
      changeColor("add", "green");
    }
    if (data == "addBlueNeo") {
      changeColor("add", "blue");
    }
    if (data == "subRedNeo") {
      changeColor("sub", "red");
    }
    if (data == "subGreenNeo") {
      changeColor("sub", "green");
    }
    if (data == "subBlueNeo") {
      changeColor("sub", "blue");
    }
    if (data == "redNeo") {
      pickColor(255, 0, 0);
    }
    if (data == "pinkNeo") {
      pickColor(200, 0, 50);
    }
    if (data == "blueNeo") {
      pickColor(0, 0, 255);
    }
    if (data == "greenNeo") {
      pickColor(0, 255, 0);
    }
    if (data == "purpleNeo") {
      pickColor(155, 0, 255);
    }
    if (data == "deepPurpleNeo") {
      pickColor(100, 0, 255);
    }
    if (data == "whiteNeo") {
      pickColor(maxRed, maxGreen, maxBlue);
    }
    if (data == "indigoNeo") {
      pickColor(0, 255, 155);
    }
    if (data == "cyanNeo") {
      pickColor(0, 255, 25);
    }
    if (data == "tealNeo") {
      pickColor(0, 255, 17);
    }
    if (data == "lightGreenNeo") {
      pickColor(0, 255, 6);
    }
    if (data == "limeNeo") {
      pickColor(0, 230, 0);
    }
    if (data == "yellowNeo") {
      pickColor(150, 255, 0);
    }
    if (data == "lightOrangeNeo") {
      pickColor(255, 60, 0);
    }
    if (data == "orangeNeo") {
      pickColor(255, 200, 0);
    }
    if (data == "printCurrent") {
      printCurrent();
    }
    if (data == "chiron") {
      Chiron();
    }

    //FUNCOES DE CONTROLE GERAL
    if (data == "allChroma") {
      allChroma(3, 20);
    }
    if (data == "2Chroma") {
      allChroma(2, 20);
    }
    if (data == "resetGeral") {
      resetGerals();
    }
    if (data == "pulseAllRed") {
      pulseAllRed();
    }
    if (data == "pulseAllGreen") {
      pulseAllGreen();
    }
    if (data == "pulseAllBlue") {
      pulseAllBlue();
    }
    if (data == "pulseAllRed2") {
      pulseAllRed2();
    }
    if (data == "pulseAllGreen2") {
      pulseAllGreen2();
    }
    if (data == "pulseAllBlue2") {
      pulseAllBlue2();
    }
    if (data == "allRed") {
      setColorDinamic(255, 0, 0, 1);
      setColorDinamic(255, 0, 0, 2);
      setAllDinamic(5, 255, 0, 0);
    }
    if (data == "allPink") {
      setColorDinamic(255, 0, 110, 1);
      setColorDinamic(255, 0, 110, 2);
      setAllDinamic(5, 200, 0, 50);
    }
    if (data == "allPurple") {
      setColorDinamic(130, 0, 255, 1);
      setColorDinamic(130, 0, 255, 2);
      setAllDinamic(5, 115, 0, 255);
    }
    if (data == "allDeepPurple") {
      setColorDinamic(50, 0, 255, 1);
      setColorDinamic(50, 0, 255, 2);
      setAllDinamic(5, 100, 0, 255);
    }
    if (data == "allBlue") {
      setColorDinamic(0, 0, 255, 1);
      setColorDinamic(0, 0, 255, 2);
      setAllDinamic(5, 0, 0, 255);
    }
    if (data == "allGreen") {
      setColorDinamic(0, 255, 0, 1);
      setColorDinamic(0, 255, 0, 2);
      setAllDinamic(5, 0, 255, 0);
    }
    if (data == "allIndigo") {
      setColorDinamic(0, 20, 255, 1);
      setColorDinamic(0, 20, 255, 2);
      setAllDinamic(5, 0, 255, 155);
    }
    if (data == "allCyan") {
      setColorDinamic(0, 150, 255, 1);
      setColorDinamic(0, 150, 255, 2);
      setAllDinamic(5, 0, 255, 25);
    }
    if (data == "allTeal") {
      setColorDinamic(0, 180, 160, 1);
      setColorDinamic(0, 180, 160, 2);
      setAllDinamic(5, 0, 255, 17);
    }
    if (data == "AllLightGreen") {
      setColorDinamic(0, 255, 100, 1);
      setColorDinamic(0, 255, 100, 2);
      setAllDinamic(5, 0, 255, 6);
    }
    if (data == "AllLime") {
      setColorDinamic(50, 200, 80, 1);
      setColorDinamic(50, 200, 80, 2);
      setAllDinamic(5, 0, 230, 0);
    }
    if (data == "AllYellow") {
      setColorDinamic(255, 150, 0, 1);
      setColorDinamic(255, 150, 0, 2);
      setAllDinamic(5, 150, 255, 0);
    }
    if (data == "AllLightOrange") {
      setColorDinamic(255, 25, 0, 1);
      setColorDinamic(255, 25, 0, 2);
      setAllDinamic(5, 255, 60, 0);
    }
    if (data == "AllOrange") {
      setColorDinamic(255, 50, 0, 1);
      setColorDinamic(255, 50, 0, 2);
      setAllDinamic(5, 255, 200, 0);
    }
    if (data == "AllWhite") {
      setColorDinamic(255, 175, 255, 1);
      setColorDinamic(255, 175, 255, 2);
      setAllDinamic(5, maxRed, maxGreen, maxBlue);
    }
    if (data == "AllRP") {
      brilhoRP(1);
      brilhoRP(2);
      changeColor("add", "red");
    }
    if (data == "AllRM") {
      brilhoRM(1);
      brilhoRM(2);
      changeColor("sub", "red");
    }
    if (data == "AllGP") {
      brilhoGP(1);
      brilhoGP(2);
      changeColor("add", "green");
    }
    if (data == "AllGM") {
      brilhoGM(1);
      brilhoGM(2);
      changeColor("sub", "green");
    }
    if (data == "AllBP") {
      brilhoBP(1);
      brilhoBP(2);
      changeColor("add", "blue");
    }
    if (data == "AllBM") {
      brilhoBM(1);
      brilhoBM(2);
      changeColor("sub", "blue");
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

void resetAllNeo() {
  setAllDinamic(5, 0, 0, 0);
  rgb3[0] = 0;
  rgb3[1] = 0;
  rgb3[2] = 0;
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

//acende  esquerda pra direita
void acendeLat(int interval, int r, int g, int b) {
  for (int i = 0; i < numLeds; i++) {
    strip.setPixelColor(i, r, g, b);
    strip.show();
    delay(interval);
  }
  rgb3[0] = r;
  rgb3[1] = g;
  rgb3[2] = b;
}
//apaga da esquerda pra direita
void apagaLat(int interval) {
  for (int i = numLeds - 1; i < numLeds; i++) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
    delay(interval);
  }
  rgb3[0] = 0;
  rgb3[1] = 0;
  rgb3[2] = 0;
}
//funcao setAll num2
void setColor(int r, int g, int b) {
  for (int i = 0; i <= numLeds; i++) {
    strip.setPixelColor(i, r, g, b);
    strip.show();
    delay(40);
  }
}
//funcao pulse da direita pra esquerda
void pulseLat(int interval, int r, int g, int b) {
  while (Serial.available() == 0) {
    for (int i = 0; i < numLeds; i++) {
      strip.setPixelColor(i, r, g, b);
      strip.show();
      delay(interval);
    }
    for (int i = numLeds - 1; i >= 0; i--) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(interval);
    }
  }
}

//cor que enche, esvazia, enche, esvazia
void colorWipe(int interval, int r, int g, int b) {
  while (Serial.available() == 0) {
    for (int i = 0; i < numLeds; i++) {
      strip.setPixelColor(i, r, g, b);
      strip.show();
      delay(interval);
    }
    for (int i = 0; i < numLeds; i++) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(interval);
    }
  }
}
//funcao chroma dinamica, usando os leds enderecaveis
void chromaNeo(int SpeedDelay) {
  while (Serial.available() == 0) {
    byte *c;
    uint16_t i, j;

    for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
      for (i = 0; i < numLeds; i++) {
        if (Serial.available() == 0) {
          c = Wheel(((i * 256 / numLeds) + j) & 255);
          strip.setPixelColor(i, *c, *(c + 1), *(c + 2));
        }
      }
      strip.show();
      delay(SpeedDelay);
    }
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];

  if (WheelPos < 85) {
    c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  } else {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }

  return c;
}
//funcao que seta a porcentagem de forma lateral, esquerda pra direita
void porcentLat(int pos) {

  if (pos > posAtual) {
    for (int i = posAtual; i <= pos; i++) {
      strip.setPixelColor(i, 0 + ((255 / numLeds)*i), 200 - ((200 / numLeds)*i), 0);
      strip.show();
      delay(40);
    }
  }
  else if (pos <= posAtual) {
    for (int i = posAtual; i >= pos; i--) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(40);
    }
  }
  posAtual = pos;
}

//funcao que seta todos os leds com cor correspondente a porcentagem
void porcent(int porcent) {
  setAllDinamic(10, 0 + ((200 / 100)*porcent), 255 - ((255 / 100)*porcent), 0);
}

//funcao que seta as cores dinamicamente em cada led individualmente, com fade
void setDinamicColor(int pos, int r, int g, int b) {
  /*  TROCA DINAMICA NO VERMELHO */
  if (r > rgb3[0]) {
    for (int i = rgb3[0]; i <= r; i++) {
      strip.setPixelColor(pos, i, rgb3[1], rgb3[2]);
      strip.show();
      delay(10);
    }
    rgb3[0] = r;
  }
  else if (r < rgb3[0]) {
    for (int i = rgb3[0]; i >= r; i--) {
      strip.setPixelColor(pos, i, rgb3[1], rgb3[2]);
      strip.show();
      delay(10);
    }
    rgb3[0] = r;
  }

  /*  TROCA DINAMICA NO VERDE */
  if (g > rgb3[1]) {
    for (int i = rgb3[1]; i <= g; i++) {
      strip.setPixelColor(pos, rgb3[0], i, rgb3[2]);
      strip.show();
      delay(10);
    }
    rgb3[1] = g;
  }
  else if (g < rgb3[1]) {
    for (int i = rgb3[1]; i >= g; i--) {
      strip.setPixelColor(pos, rgb3[0], i, rgb3[2]);
      strip.show();
      delay(10);
    }
    rgb3[1] = g;
  }

  /*  TROCA DINAMICA NO AZUL */
  if (b > rgb3[21]) {
    for (int i = rgb3[2]; i <= b; i++) {
      strip.setPixelColor(pos, rgb3[0], rgb3[1], i);
      strip.show();
      delay(10);
    }
    rgb3[2] = b;
  }
  else if (b < rgb3[2]) {
    for (int i = rgb3[2]; i >= b; i--) {
      strip.setPixelColor(pos, rgb3[0], rgb3[1], i);
      strip.show();
      delay(10);
    }
    rgb3[2] = b;
  }
}

//funcao que seta todas as cores de forma dinamica, com fade
void setAllDinamic(int interval, int red, int green, int blue) {

  //DEFININDO VERMELHO
  if (red > rgb3[0]) {
    for (int i = rgb3[0]; i <= red; i++) {
      if (Serial.available() == 0) {
        setAll(i, rgb3[1], rgb3[2]);
        strip.show();
        delay(interval);
        rgb3[0] = i;
      }
    }
  }
  else if (rgb3[0] >= red) {
    for (int i = rgb3[0]; i >= red; i--) {
      if (Serial.available() == 0) {
        setAll(i, rgb3[1], rgb3[2]);
        strip.show();
        delay(interval);
        rgb3[0] = i;
      }
    }
  }

  //DEFININDO VERDE
  if (green > rgb3[1]) {
    for (int j = rgb3[1]; j <= green; j++) {
      if (Serial.available() == 0) {
        setAll(rgb3[0], j, rgb3[2]);
        strip.show();
        delay(interval);
        rgb3[1] = j;
      }
    }
  }
  else if (rgb3[1] >= green) {
    for (int j = rgb3[1]; j >= green; j--) {
      if (Serial.available() == 0) {
        setAll(rgb3[0], j, rgb3[2]);
        strip.show();
        delay(interval);
        rgb3[1] = j;
      }
    }
  }

  //DEFININDO AZUL
  if (blue > rgb3[2]) {
    for (int k = rgb3[2]; k <= blue; k++) {
      if (Serial.available() == 0) {
        setAll(rgb3[0], rgb3[1], k);
        strip.show();
        delay(interval);
        rgb3[2] = k;
      }
    }
  }
  else if (rgb3[2] >= blue) {
    for (int k = rgb3[2]; k >= blue; k--) {
      if (Serial.available() == 0) {
        setAll(rgb3[0], rgb3[1], k);
        strip.show();
        delay(interval);
        rgb3[2] = k;
      }
    }
  }

}

//seta todos os NeoLeds em uma cor, instantaneamente
void setAll(int r, int g, int b) {
  for (int i = 0; i < numLeds; i++) {
    strip.setPixelColor(i, r, g, b);
  }
  rgb3[0] = r;
  rgb3[1] = g;
  rgb3[2] = b;
}

//função Pulse Total
void pulse(int interval, int red, int green, int blue) {
  while (Serial.available() == 0) {
    float r, g, b;

    for (int k = 0; k < 256; k = k + 1) {
      r = (k / 256.0) * red;
      g = (k / 256.0) * green;
      b = (k / 256.0) * blue;
      setAll(r, g, b);
      strip.show();
      delay(interval);
    }

    for (int k = 255; k >= 0; k = k - 2) {
      r = (k / 256.0) * red;
      g = (k / 256.0) * green;
      b = (k / 256.0) * blue;
      setAll(r, g, b);
      strip.show();
      delay(interval);
    }
  }
}

//função "bate volta"
void CylonBounce(int red, int green, int blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  while (Serial.available() == 0) {

    for (int i = 0; i < numLeds - EyeSize - 2; i++) {
      setAll(0, 0, 0);
      strip.setPixelColor(i, red / 10, green / 10, blue / 10);
      for (int j = 1; j <= EyeSize; j++) {
        strip.setPixelColor(i + j, red, green, blue);
      }
      strip.setPixelColor(i + EyeSize + 1, red / 10, green / 10, blue / 10);
      strip.show();
      delay(SpeedDelay);
    }

    delay(ReturnDelay);

    for (int i = numLeds - EyeSize - 2; i > 0; i--) {
      setAll(0, 0, 0);
      strip.setPixelColor(i, red / 10, green / 10, blue / 10);
      for (int j = 1; j <= EyeSize; j++) {
        strip.setPixelColor(i + j, red, green, blue);
      }
      strip.setPixelColor(i + EyeSize + 1, red / 10, green / 10, blue / 10);
      strip.show();
      delay(SpeedDelay);
    }

    delay(ReturnDelay);
  }
}

//Função de cor correndo em ciclo pela fita
void RunningLights(int red, int green, int blue, int WaveDelay) {
  while (Serial.available() == 0) {
    int Position = 0;

    for (int i = 0; i < numLeds * 2; i++)
    {
      Position++; // = 0; //Position + Rate;
      for (int i = 0; i < numLeds; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        strip.setPixelColor(i, ((sin(i + Position) * 127 + 128) / 255)*red,
                            ((sin(i + Position) * 127 + 128) / 255)*green,
                            ((sin(i + Position) * 127 + 128) / 255)*blue);
      }

      strip.show();
      delay(WaveDelay);
    }
  }
}

//Função que simula "fogo" na fita led endereçável
void Fire(int Cooling, int Sparking, int SpeedDelay) {
  while (Serial.available() == 0) {
    byte heat[numLeds];
    int cooldown;

    // Step 1.  Cool down every cell a little
    for ( int i = 0; i < numLeds; i++) {
      cooldown = random(0, ((Cooling * 10) / numLeds) + 2);

      if (cooldown > heat[i]) {
        heat[i] = 0;
      } else {
        heat[i] = heat[i] - cooldown;
      }
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for ( int k = numLeds - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' near the bottom
    if ( random(255) < Sparking ) {
      int y = random(7);
      heat[y] = heat[y] + random(160, 255);
      //heat[y] = random(160,255);
    }
    if (Serial.available() == 0) {
      // Step 4.  Convert heat to LED colors
      for ( int j = 0; j < numLeds; j++) {
        setPixelHeatColor(j, heat[j] );
      }

      strip.show();
      delay(SpeedDelay);
    }
  }
}

//Função auxiliar que atribuir a cor pra cada pixel da função fire
void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);

  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252

  // figure out which third of the spectrum we're in:
  if ( t192 > 0x80) {                    // hottest
    strip.setPixelColor(Pixel, 255, 255, heatramp);
  } else if ( t192 > 0x40 ) {            // middle
    strip.setPixelColor(Pixel, 255, heatramp, 0);
  } else {                               // coolest
    strip.setPixelColor(Pixel, heatramp, 0, 0);
  }
}

//Função chroma para todos os pixels, como uma fita RGB normal
void chromaAll(int interval) {
  while (Serial.available() == 0) {
    setAllDinamic(interval, 255, 0 , 0);
    delay(10);
    setAllDinamic(interval, 255, 255 , 0);
    delay(10);
    setAllDinamic(interval, 0, 255 , 255);
    delay(10);
    setAllDinamic(interval, 0, 0 , 255);
    delay(10);
  }
}

//seta os valores de RGB da fita Neopixel
void pickColor (int r, int g, int b) {
  colorPick[0] = r;
  colorPick[1] = g;
  colorPick[2] = b;
}

void changeColor(String addsub, String cor) {

  if (addsub == "add") {
    if (cor == "red") {
      if (rgb3[0] <= 224) {
        setAllDinamic(5, rgb3[0] + 25, rgb3[1], rgb3[2]);
      }
      else {
        setAllDinamic(5, 255, rgb3[1], rgb3[2]);
      }
    }
    if (cor == "green") {
      if (rgb3[1] <= 224) {
        setAllDinamic(5, rgb3[0], rgb3[1] + 25, rgb3[2]);
      }
      else {
        setAllDinamic(5, rgb3[0], 255, rgb3[2]);
      }
    }
    if (cor == "blue") {
      if (rgb3[2] <= 224) {
        setAllDinamic(5, rgb3[0], rgb3[1], rgb3[2] + 25);
      }
      else {
        setAllDinamic(5, rgb3[0], rgb3[1], 255);
      }
    }
  }
  else if (addsub == "sub") {
    if (cor == "red") {
      if (rgb3[0] >= 26) {
        setAllDinamic(5, rgb3[0] - 25, rgb3[1], rgb3[2]);
      }
      else {
        setAllDinamic(5, 0, rgb3[1], rgb3[2]);
      }
    }
    if (cor == "green") {
      if (rgb3[1] >= 26) {
        setAllDinamic(5, rgb3[0], rgb3[1] - 25, rgb3[2]);
      }
      else {
        setAllDinamic(5, rgb3[0], 0, rgb3[2]);
      }
    }
    if (cor == "blue") {
      if (rgb3[2] >= 26) {
        setAllDinamic(5, rgb3[0], rgb3[1], rgb3[2] - 25);
      }
      else {
        setAllDinamic(5, rgb3[0], rgb3[1], 0);
      }
    }
  }
}

//FUNCOES DE CONTROLE GERAL

void resetGeral () {
  analogWrite(RED1, 0);
  analogWrite(GREEN1, 0);
  analogWrite(BLUE1, 0);

  analogWrite(RED2, 0);
  analogWrite(GREEN2, 0);
  analogWrite(BLUE2, 0);

  setAllDinamic(0, 0, 0 , 0);
}

void allChroma(int num, int interval) {
  int r, g, b;

  while (Serial.available() == 0) {
    // Fade do azul (ja estava aceso) até o violeta, adicionando o vermelho
    for (r = 0; r <= 255; r++) {
      if (Serial.available() == 0) {
        analogWrite(RED1, r);
        analogWrite(RED2, r);
        if (num == 3) {
          setAll(r, rgb3[1], rgb3[2]);
        }
        strip.show();
        delay(interval);
      }
    }

    // Fade do violeta até o vermelho, removendo o azul
    for (b = 255; b >= 0; b--) {
      if (Serial.available() == 0) {
        analogWrite(BLUE1, b);
        analogWrite(BLUE2, b);
        if (num == 3) {
          setAll(rgb3[0], rgb3[1], b);
        }
        strip.show();
        delay(interval);
      }
    }

    // Fade do vermelho até o amarelo, adicionando o verde
    for (g = 0; g <= 255; g++) {
      if (Serial.available() == 0) {
        analogWrite(GREEN1, g);
        analogWrite(GREEN2, g);
        if (num == 3) {
          setAll(rgb3[0], g, rgb3[2]);
        }
        strip.show();
        delay(interval);
      }
    }

    // Fade do amarelo até o verde, removendo o vermelho
    for (r = 255; r >= 0; r--) {
      if (Serial.available() == 0) {
        analogWrite(RED1, r);
        analogWrite(RED2, r);
        if (num == 3) {
          setAll(r, rgb3[1], rgb3[2]);
        }
        strip.show();
        delay(interval);
      }
    }

    // Fade do verde até o turquesa, adicionando o azul
    for (b = 0; b <= 255; b++) {
      if (Serial.available() == 0) {
        analogWrite(BLUE1, b);
        analogWrite(BLUE2, b);
        if (num == 3) {
          setAll(rgb3[0], rgb3[1], b);
        }
        strip.show();
        delay(interval);
      }
    }

    // Fade do turquesa até o azul, removendo o verde
    for (g = 255; g >= 0; g--) {
      if (Serial.available() == 0) {
        analogWrite(GREEN1, g);
        analogWrite(GREEN2, g);
        if (num == 3) {
          setAll(rgb3[0], g, rgb3[2]);
        }
        strip.show();
        delay(interval);
      }
    }
  }
}

void resetGerals () {
  analogWrite(RED1, 0);
  analogWrite(GREEN1, 0);
  analogWrite(BLUE1, 0);

  analogWrite(RED2, 0);
  analogWrite(GREEN2, 0);
  analogWrite(BLUE2, 0);

  setAllDinamic(0, 0, 0 , 0);
}

void printCurrent () {
  Serial.println(rgb3[0]);
  Serial.println(rgb3[1]);
  Serial.println(rgb3[2]);
}

void pulseAllRed() {
  while (Serial.available() == 0) {
    for (int i = 0; i <= 255; i++) {
      analogWrite(RED1, i);
      analogWrite(RED2, i);
      setAll(i, 0, 0);
      strip.show();
      delay(5);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(RED1, i);
      analogWrite(RED2, i);
      setAll(i, 0, 0);
      strip.show();
      delay(5);
    }
  }
}

void pulseAllGreen() {
  while (Serial.available() == 0) {
    for (int i = 0; i <= 255; i++) {
      analogWrite(GREEN1, i);
      analogWrite(GREEN2, i);
      setAll(0, i, 0);
      strip.show();
      delay(5);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(GREEN1, i);
      analogWrite(GREEN2, i);
      setAll(0, i, 0);
      strip.show();
      delay(5);
    }
  }
}

void pulseAllBlue() {
  while (Serial.available() == 0) {
    for (int i = 0; i <= 255; i++) {
      analogWrite(BLUE1, i);
      analogWrite(BLUE2, i);
      setAll(0, 0, i);
      strip.show();
      delay(5);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(BLUE1, i);
      analogWrite(BLUE2, i);
      setAll(0, 0, i);
      strip.show();
      delay(5);
    }
  }
}
void pulseAllRed2() {
  while (Serial.available() == 0) {
    for (int i = 0; i <= 230; i++) {
      analogWrite(RED1, i);
      analogWrite(RED2, i);
      delay(5);
    }

    for (int i = 0; i < numLeds; i++) {
      strip.setPixelColor(i, 255, 0, 0);
      strip.show();
      delay(40);
    }
    for (int i = numLeds - 1; i >= 0; i--) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(40);
    }

    for (int i = 255; i >= 0; i--) {
      analogWrite(RED1, i);
      analogWrite(RED2, i);
      delay(5);
    }
  }
}

void pulseAllGreen2() {
  while (Serial.available() == 0) {
    for (int i = 0; i <= 255; i++) {
      analogWrite(GREEN1, i);
      analogWrite(GREEN2, i);
      delay(5);
    }

    for (int i = 0; i < numLeds; i++) {
      strip.setPixelColor(i, 0, 255, 0);
      strip.show();
      delay(40);
    }
    for (int i = numLeds - 1; i >= 0; i--) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(40);
    }

    for (int i = 255; i >= 0; i--) {
      analogWrite(GREEN1, i);
      analogWrite(GREEN2, i);
      delay(5);
    }
  }
}

void pulseAllBlue2() {
  while (Serial.available() == 0) {
    for (int i = 0; i <= 255; i++) {
      analogWrite(BLUE1, i);
      analogWrite(BLUE2, i);
      delay(5);
    }

    for (int i = 0; i < numLeds; i++) {
      strip.setPixelColor(i, 0, 0, 255);
      strip.show();
      delay(40);
    }
    for (int i = numLeds - 1; i >= 0; i--) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(40);
    }

    for (int i = 255; i >= 0; i--) {
      analogWrite(BLUE1, i);
      analogWrite(BLUE2, i);
      delay(5);
    }
  }
}
void Chiron (){
  strip.setPixelColor(1, 255, 150, 0);
  strip.setPixelColor(2, 255, 150, 0);
  strip.setPixelColor(3, 255, 150, 0);
  strip.setPixelColor(4, 255, 150, 0);
  strip.setPixelColor(12, 255, 150, 0);
  strip.setPixelColor(13, 255, 150, 0);
  strip.setPixelColor(14, 255, 150, 0);
  strip.setPixelColor(15, 255, 150, 0);
  strip.show();
  delay(250);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.setPixelColor(12, 0, 0, 0);
  strip.setPixelColor(13, 0, 0, 0);
  strip.setPixelColor(14, 0, 0, 0);
  strip.setPixelColor(15, 0, 0, 0);
  strip.show();
  delay(250);
  strip.setPixelColor(1, 255, 255, 255);
  strip.setPixelColor(2, 255, 255, 255);
  strip.setPixelColor(3, 255, 255, 255);
  strip.setPixelColor(4, 255, 255, 255);
  strip.setPixelColor(12, 255, 255, 255);
  strip.setPixelColor(13, 255, 255, 255);
  strip.setPixelColor(14, 255, 255, 255);
  strip.setPixelColor(15, 255, 255, 255);
  strip.show();
  delay(250);
  
  for (int i=255; i>=100; i--){
    strip.setPixelColor(1, i, i, i);
    strip.setPixelColor(15, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=255; i>=100; i--){
    strip.setPixelColor(2, i, i, i);
    strip.setPixelColor(14, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=255; i>=100; i--){
    strip.setPixelColor(3, i, i, i);
    strip.setPixelColor(13, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=255; i>=100; i--){
    strip.setPixelColor(4, i, i, i);
    strip.setPixelColor(12, i, i, i);
    strip.show();
    delay(1);
  }
  //------------------------------------------
  for (int i=100; i>=0; i--){
    strip.setPixelColor(4, i, i, i);
    strip.setPixelColor(12, i, i, i);
    strip.show();
    delay(1);
  }

  for (int i=100; i>=0; i--){
    strip.setPixelColor(3, i, i, i);
    strip.setPixelColor(13, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=100; i>=0; i--){
    strip.setPixelColor(2, i, i, i);
    strip.setPixelColor(14, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=100; i>=0; i--){
    strip.setPixelColor(1, i, i, i);
    strip.setPixelColor(15, i, i, i);
    strip.show();
    delay(1);
  }

  delay(1000);
  strip.setPixelColor(1, 255, 150, 0);
  strip.setPixelColor(2, 255, 150, 0);
  strip.setPixelColor(3, 255, 150, 0);
  strip.setPixelColor(4, 255, 150, 0);
  strip.setPixelColor(12, 255, 150, 0);
  strip.setPixelColor(13, 255, 150, 0);
  strip.setPixelColor(14, 255, 150, 0);
  strip.setPixelColor(15, 255, 150, 0);
  strip.show();
  delay(250);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.setPixelColor(12, 0, 0, 0);
  strip.setPixelColor(13, 0, 0, 0);
  strip.setPixelColor(14, 0, 0, 0);
  strip.setPixelColor(15, 0, 0, 0);
  strip.show();
  delay(250);
  strip.setPixelColor(1, 255, 150, 0);
  strip.setPixelColor(2, 255, 150, 0);
  strip.setPixelColor(3, 255, 150, 0);
  strip.setPixelColor(4, 255, 150, 0);
  strip.setPixelColor(12, 255, 150, 0);
  strip.setPixelColor(13, 255, 150, 0);
  strip.setPixelColor(14, 255, 150, 0);
  strip.setPixelColor(15, 255, 150, 0);
  strip.show();
  delay(250);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.setPixelColor(12, 0, 0, 0);
  strip.setPixelColor(13, 0, 0, 0);
  strip.setPixelColor(14, 0, 0, 0);
  strip.setPixelColor(15, 0, 0, 0);
  strip.show();
  delay(250);

  for (int i=0; i<=100; i++){
    strip.setPixelColor(4, i, i, i);
    strip.setPixelColor(12, i, i, i);
    strip.show();
    delay(1);
  }

  for (int i=0; i<=100; i++){
    strip.setPixelColor(3, i, i, i);
    strip.setPixelColor(13, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=0; i<=100; i++){
    strip.setPixelColor(2, i, i, i);
    strip.setPixelColor(14, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=0; i<=100; i++){
    strip.setPixelColor(1, i, i, i);
    strip.setPixelColor(15, i, i, i);
    strip.show();
    delay(1);
  }

  //------------------------------------

  for (int i=100; i<=255; i++){
    strip.setPixelColor(1, i, i, i);
    strip.setPixelColor(15, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=100; i<=255; i++){
    strip.setPixelColor(2, i, i, i);
    strip.setPixelColor(14, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=100; i<=255; i++){
    strip.setPixelColor(3, i, i, i);
    strip.setPixelColor(13, i, i, i);
    strip.show();
    delay(1);
  }
  for (int i=100; i<=255; i++){
    strip.setPixelColor(4, i, i, i);
    strip.setPixelColor(12, i, i, i);
    strip.show();
    delay(1);
  }
  
}

