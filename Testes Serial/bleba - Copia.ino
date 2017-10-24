String data;
#define GREEN 3
#define RED 7
#define BLUE 11
int rgb[3];
int fav1[3];
int fav2[3];
int fav3[3];

void setup() {
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  rgb[0] = 0;
  rgb[1] = 0;
  rgb[2] = 0;
}

void loop() {

}

void serialEvent() {
  if (Serial.available()) {
    data = Serial.readString();

    if (data == "G") {
      greenON();
    }
    if (data == "g") {
      greenOFF();
    }
    if (data == "R") {
      redON();
    }
    if (data == "r") {
      redOFF();
    }
    if (data == "B") {
      blueON();
    }
    if (data == "b") {
      blueOFF();
    }
    if (data == "Red") {
      setColorDinamic(255, 0, 0);
    }
    if (data == "Green") {
      setColorDinamic(0, 255, 0);
    }
    if (data == "Blue") {
      setColorDinamic(0, 0, 255);
    }
    if (data == "White") {
      setColorDinamic(255, 255, 255);
    }
    if (data == "Pink") {
      setColorDinamic(255, 0, 110);
    }
    if (data == "Purple") {
      setColorDinamic(100, 0, 255);
    }
    if (data == "DeepPurple") {
      setColorDinamic(50, 0, 255);
    }
    if (data == "Indigo") {
      setColorDinamic(0, 20, 255);
    }
    if (data == "Cyan") {
      setColorDinamic(0, 150, 255);
    }
    if (data == "Teal") {
      setColorDinamic(0, 180, 160);
    }
    if (data == "LightGreen") {
      setColorDinamic(0, 255, 100);
    }
    if (data == "Lime") {
      setColorDinamic(50, 200, 80);
    }
    if (data == "Yellow") {
      setColorDinamic(255, 150, 0);
    }
    if (data == "LightOrange") {
      setColorDinamic(255, 25, 0);
    }
    if (data == "Orange") {
      setColorDinamic(255, 50, 0);
    }
    if (data == "DarkOrange") {
      setColorDinamic(255, 25, 0);
    }
    if (data == "chroma") {
      chroma();
    }
    if (data == "testLoop") {
      testLoop();
    }
    if (data == "pulseR") {
      pulseR();
    }
    if (data == "pulseG") {
      pulseG();
    }
    if (data == "pulseB") {
      pulseB();
    }
    if (data == "brilhoRP") {
      brilhoRP();
    }
    if (data == "brilhoRM") {
      brilhoRM();
    }
    if (data == "brilhoGP") {
      brilhoGP();
    }
    if (data == "brilhoGM") {
      brilhoGM();
    }
    if (data == "brilhoBP") {
      brilhoBP();
    }
    if (data == "brilhoBM") {
      brilhoBM();
    }
    if (data == "FreezeChroma") {
      freezeChroma();
    }
    if (data == "setFav1") {
      setFav(1);
    }
    if (data == "showFav1") {
      showFav(1);
    }
    if (data == "setFav2") {
      setFav(2);
    }
    if (data == "showFav2") {
      showFav(2);
    }
    if (data == "setFav3") {
      setFav(3);
    }
    if (data == "showFav3") {
      showFav(3);
    }
    if (data == "10%") {
      setColorDinamic(0, 250, 0);
    }
    if (data == "20%") {
      setColorDinamic(25, 225, 0);
    }
    if (data == "30%") {
      setColorDinamic(50, 200, 0);
    }
    if (data == "40%") {
      setColorDinamic(75, 175, 0);
    }
    if (data == "50%") {
      setColorDinamic(100, 150, 0);
    }
    if (data == "60%") {
      setColorDinamic(125, 125, 0);
    }
    if (data == "70%") {
      setColorDinamic(150, 100, 0);
    }
    if (data == "80%") {
      setColorDinamic(175, 75, 0);
    }
    if (data == "90%") {
      setColorDinamic(200, 50, 0);
    }
    if (data == "100%") {
      setColorDinamic(255, 0, 0);
    }
    if (data == "reset") {
      resetAll();
    }
  }
}

void resetAll() {
  setColorDinamic(0,0,0);
}

void greenON() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(GREEN, i);
    delay(10);
  }
  rgb[1] = 255;
}

void greenOFF() {
  for (int i = rgb[1]; i >= 0; i--) {
    analogWrite(GREEN, i);
    delay(1);
  }
  rgb[1] = 0;
}

void redON() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(RED, i);
    delay(10);
  }
  rgb[0] = 255;
}

void redOFF() {
  for (int i = rgb[0]; i >= 0; i--) {
    analogWrite(RED, i);
    delay(1);
  }
  rgb[0] = 0;
}

void blueON() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(BLUE, i);
    delay(10);
  }
  rgb[2] = 255;
}

void blueOFF() {
  for (int i = rgb[2]; i >= 0; i--) {
    analogWrite(BLUE, i);
    delay(1);
  }
  rgb[2] = 0;
}

void setColor(int r, int g, int b) {
  resetAll();

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

  rgb[0] = r;
  rgb[1] = g;
  rgb[2] = b;
}

void chroma() {
  int pinR = RED;
  int pinG = GREEN;
  int pinB = BLUE;

  resetAll();
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
  resetAll();
}

void testLoop() {
  bool repeat = true;
  while (Serial.available() == 0) {
    chroma();
  }
}

void pulseR () {
  resetAll();
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

void pulseG () {
  resetAll();
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

void pulseB () {
  resetAll();
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
void brilhoRP() {
  if (rgb[0] <= 230) {
    for (int i = rgb[0]; i <= rgb[0] + 25; i++) {
      analogWrite(RED, i);
      delay(5);
    }
    rgb[0] = rgb[0] + 25;
  }
  else {
    for (int i = rgb[0]; i < 255; i++) {
      analogWrite(RED, i);
      delay(5);
    }
    rgb[0] = 255;
  }
}
void brilhoRM() {
  if (rgb[0] >= 25) {
    for (int i = rgb[0]; i >= rgb[0] - 25; i--) {
      analogWrite(RED, i);
      delay(5);
    }
    rgb[0] = rgb[0] - 25;
  }
  else {
    for (int i = rgb[0]; i >= 0; i--) {
      analogWrite(RED, i);
      delay(5);
    }
    rgb[0] = 0;
  }
}
void brilhoGP() {
  if (rgb[1] <= 230) {
    for (int i = rgb[1]; i <= rgb[1] + 25; i++) {
      analogWrite(GREEN, i);
      delay(5);
    }
    rgb[1] = rgb[1] + 25;
  }
  else {
    for (int i = rgb[1]; i < 255; i++) {
      analogWrite(GREEN, i);
      delay(5);
    }
    rgb[1] = 255;
  }
}
void brilhoGM() {
  if (rgb[1] >= 25) {
    for (int i = rgb[1]; i >= rgb[1] - 25; i--) {
      analogWrite(GREEN, i);
      delay(5);
    }
    rgb[1] = rgb[1] - 25;
  }
  else {
    for (int i = rgb[1]; i >= 0; i--) {
      analogWrite(GREEN, i);
      delay(5);
    }
    rgb[1] = 0;
  }
}

void brilhoBP() {
  if (rgb[2] <= 230) {
    for (int i = rgb[2]; i <= rgb[2] + 25; i++) {
      analogWrite(BLUE, i);
      delay(5);
    }
    rgb[2] = rgb[2] + 25;
  }
  else {
    for (int i = rgb[2]; i < 255; i++) {
      analogWrite(BLUE, i);
      delay(5);
    }
    rgb[2] = 255;
  }
}
void brilhoBM() {
  if (rgb[2] >= 25) {
    for (int i = rgb[2]; i >= rgb[2] - 25; i--) {
      analogWrite(BLUE, i);
      delay(5);
    }
    rgb[2] = rgb[2] - 25;
  }
  else {
    for (int i = rgb[2]; i >= 0; i--) {
      analogWrite(BLUE, i);
      delay(5);
    }
    rgb[2] = 0;
  }
}
void freezeChroma() {
  resetAll();
  // Declara as variáveis dos loops
  int r, g, b;

  while (Serial.available() == 0) {
    // Fade do azul (ja estava aceso) até o violeta, adicionando o vermelho
    for (r = 0; r <= 255; r++) {
      if (Serial.available() == 0) {
        analogWrite(RED, r);
        rgb[0] = r;
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
        rgb[2] = b;
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
        delay(10);
      }
      else {
        return;
      }
    }

    // Em seguida o loop continua, com o azul aceso
  }
}
void setFav(int num) {
  if (num == 1) {
    fav1[0] = rgb[0];
    fav1[1] = rgb[1];
    fav1[2] = rgb[2];
  }
  if (num == 2) {
    fav2[0] = rgb[0];
    fav2[1] = rgb[1];
    fav2[2] = rgb[2];
  }
  if (num == 3) {
    fav3[0] = rgb[0];
    fav3[1] = rgb[1];
    fav3[2] = rgb[2];
  }
}
void showFav(int num) {
  if (num == 1) {
    setColorDinamic(fav1[0], fav1[1], fav1[2]);
    rgb[0] = fav1[0];
    rgb[1] = fav1[1];
    rgb[2] = fav1[2];
    return;
  }
  if (num == 2) {
    setColorDinamic(fav2[0], fav2[1], fav2[2]);
    rgb[0] = fav2[0];
    rgb[1] = fav2[1];
    rgb[2] = fav2[2];
    return;
  }
  if (num == 3) {
    setColorDinamic(fav3[0], fav3[1], fav3[2]);
    rgb[0] = fav3[0];
    rgb[1] = fav3[1];
    rgb[2] = fav3[2];
    return;
  }
}

void setColorDinamic(int r, int g, int b) {

  /*  TROCA DINAMICA NO VERMELHO */
  if (r > rgb[0]) {
    for (int i = rgb[0]; i <= r; i++) {
      analogWrite(RED, i);
      delay(5);
      rgb[0] = i;
    }
  } else if (r < rgb[0]) {
    for (int i = rgb[0]; i >= r; i--) {
      analogWrite(RED, i);
      delay(5);
      rgb[0] = i;
    }
  } else {
    rgb[0] = r;
  }
  /*  TROCA DINAMICA NO VERDE */
  if (g > rgb[1]) {
    for (int i = rgb[1]; i <= g; i++) {
      analogWrite(GREEN, i);
      delay(5);
      rgb[1] = i;
    }
  } else if (g < rgb[1]) {
    for (int i = rgb[1]; i >= g; i--) {
      analogWrite(GREEN, i);
      delay(5);
      rgb[1] = i;
    }
  } else {
    rgb[1] = g;
  }
   /*  TROCA DINAMICA NO AZUL */
  if (b > rgb[2]) {
    for (int i = rgb[2]; i <= b; i++) {
      analogWrite(BLUE, i);
      delay(5);
      rgb[2] = i;
    }
  } else if (b < rgb[2]) {
    for (int i = rgb[2]; i >= b; i--) {
      analogWrite(BLUE, i);
      delay(5);
      rgb[2] = i;
    }
  } else {
    rgb[2] = b;
  }
  
}

