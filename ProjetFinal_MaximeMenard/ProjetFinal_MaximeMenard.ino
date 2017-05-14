#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define PhaseMoteur_1 22
#define PhaseMoteur_2 24
#define PhaseMoteur_3 26
#define PhaseMoteur_4 28
#define LimitSwitch_Droite 7 
#define LimitSwitch_Gauche 24
#define Colonne_1 5
#define Colonne_2 6
#define Colonne_3 7
#define Colonne_4 9
#define Colonne_5 8
#define Colonne_6 10
#define Colonne_7 11
#define Largeur 7
#define Hauteur 6


//1 c'est l'humain qui gagne, 2 le AI et 0 c'est une nulle

enum TypeJeton {
  nulle,
  humain,
  AI  
};

Servo Claw;
int ClawPin = 2;
int d = 1500;
int MoteurPhaseLength = 4;
int PhaseMoteur[] = {PhaseMoteur_1, PhaseMoteur_2, PhaseMoteur_3, PhaseMoteur_4};
TypeJeton Grid[Hauteur][Largeur];
int startPos = 0;
int increment = 1;
TypeJeton turn = humain;
unsigned long timeOfLastMove = 0;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  InitPins();
  ResetGrid();
}


void loop() {


}














