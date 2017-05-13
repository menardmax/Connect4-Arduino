#include <Servo.h>

#define PhaseMoteur_1 45
#define PhaseMoteur_2 47
#define PhaseMoteur_3 49
#define PhaseMoteur_4 51
#define LimitSwitch_Droite 7 
#define LimitSwitch_Gauche 24
#define Colonne_1 11
#define Colonne_2 10
#define Colonne_3 9
#define Colonne_4 8
#define Colonne_5 7
#define Colonne_6 6
#define Colonne_7 5
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
int NbJetonColonne[] = {0,0,0,0,0,0,0};
TypeJeton Grid[Hauteur][Largeur];
int startPos = 0;
int increment = 1;
boolean flag = 0;



void setup() {
  InitPins();
  ResetGrid();
  Grid[3][0] = AI; Grid[2][1] = AI; Grid[1][2] = AI; Grid[0][3] = AI;
  Serial.print(isFinished(Grid));
}


void loop() {



}//End Void Loop




 














