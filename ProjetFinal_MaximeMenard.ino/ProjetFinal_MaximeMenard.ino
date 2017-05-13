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


#define VIDE   ((char)'V')
#define ROUGE  ((char)'R')
#define JAUNE  ((char)'J')



Servo Claw;
int ClawPin = 2;
int d = 1500;
int MoteurPhaseLength = 4;
int PhaseMoteur[] = {PhaseMoteur_1, PhaseMoteur_2, PhaseMoteur_3, PhaseMoteur_4};
int NbJetonColonne[] = {0,0,0,0,0,0,0};
int startPos = 0;
int increment = 1;
boolean flag = 0;
char GrilleJeu[5][8];


void setup() {
  InitPins();
  //clrGrilleJeu();
  //Serial.println('V');
}


void loop() {

  if(flag == 1){
  flag = 0;
  //Fermer pince
  Claw.write(90); 
  ShutdownAllPhases();
  Claw.write(0);
    for(int i=0; i<7; i++){
    Serial.print(i);  
    Serial.print("NB jetons      ");
    Serial.println(NbJetonColonne[i]);
    
    }
    Serial.println(" ");
}

delay(1000);
OpenClaw();

}//End Void Loop







//**************FONCTIONS D'INTERRUPTION ****************************//

void Interruption_LimitSwitch_Droite(){
  //Si limit switch de droite appuyée
  //Éteint 4phases
  //On prend un jetons
  flag = 1;
}


void Interruption_LimitSwitch_Gauche(){
}



//--------Interruption colonnes---------


void InterruptionColonne1(){
   flag = 1;
   if(NbJetonColonne[0] < 6){
   NbJetonColonne[0] += 1; 
   }
   else{
   NbJetonColonne[0] = 6; 
   }
}

void InterruptionColonne2(){
   flag = 1;
   if(NbJetonColonne[1] < 6){
   NbJetonColonne[1] += 1; 
   }
   else{
   NbJetonColonne[1] = 6; 
   }
}
void InterruptionColonne3(){
   flag = 1;
   if(NbJetonColonne[2] < 6){
   NbJetonColonne[2] += 1; 
   }
   else{
   NbJetonColonne[2] = 6; 
   }
}
void InterruptionColonne4(){
   flag = 1;
   if(NbJetonColonne[3] < 6){
   NbJetonColonne[3] += 1; 
   }
   else{
   NbJetonColonne[3] = 6; 
   }
}

void InterruptionColonne5(){
   flag = 1;
   if(NbJetonColonne[4] < 6){
   NbJetonColonne[4] += 1; 
   }
   else{
   NbJetonColonne[4] = 6; 
   }
}

void InterruptionColonne6(){
   flag = 1;
   if(NbJetonColonne[5] < 6){
   NbJetonColonne[5] += 1; 
   }
   else{
   NbJetonColonne[5] = 6; 
   }
}
void InterruptionColonne7(){
   flag = 1;
   if(NbJetonColonne[6] < 6){
   NbJetonColonne[6] += 1; 
   }
   else{
   NbJetonColonne[6] = 6; 
   }
}


 


//****************Void Setup***********************//
void InitPins(){
  
    Serial.begin(9600);
   
      pinMode(PhaseMoteur_1, OUTPUT);
      pinMode(PhaseMoteur_2, OUTPUT);
      pinMode(PhaseMoteur_3, OUTPUT);
      pinMode(PhaseMoteur_4, OUTPUT);
      Claw.attach(ClawPin);
      
      digitalWrite(PhaseMoteur_1, LOW);
      digitalWrite(PhaseMoteur_2, LOW);
      digitalWrite(PhaseMoteur_3, LOW);
      digitalWrite(PhaseMoteur_4, LOW);

      pinMode(LimitSwitch_Droite,INPUT);
      attachInterrupt(LimitSwitch_Droite, Interruption_LimitSwitch_Droite, FALLING);
      pinMode(LimitSwitch_Gauche,INPUT);
      attachInterrupt(LimitSwitch_Gauche, Interruption_LimitSwitch_Gauche, FALLING);

      pinMode(Colonne_1,INPUT);
      attachInterrupt(Colonne_1, InterruptionColonne1, FALLING);
      pinMode(Colonne_2,INPUT);
      attachInterrupt(Colonne_2, InterruptionColonne2, FALLING);
      pinMode(Colonne_3,INPUT);
      attachInterrupt(Colonne_3, InterruptionColonne3, FALLING);
      pinMode(Colonne_4,INPUT);
      attachInterrupt(Colonne_4, InterruptionColonne4, FALLING);
      pinMode(Colonne_5,INPUT);
      attachInterrupt(Colonne_5, InterruptionColonne5, FALLING);
      pinMode(Colonne_6,INPUT);
      attachInterrupt(Colonne_6, InterruptionColonne6, FALLING);
      pinMode(Colonne_7,INPUT);
      attachInterrupt(Colonne_7, InterruptionColonne7, FALLING);
      
      OpenClaw();


      //Quick fix forcer les colonnes à 0 jetons
      for(int i=0; i<7; i++){
      NbJetonColonne[i] = 0;        
      }
      
      

}


//*******************Éteindre Phases Moteur********************//

void ShutdownAllPhases(){
  for(int i=0 ; i<4 ; i++){
   digitalWrite(PhaseMoteur[i], LOW);
  }
}

//*******************Claw control *********************//

void OpenClaw(){
Claw.write(0);
}// Make claw go to 0 degrees 


void CloseClaw(){
Claw.write(90);  
}// Make claw go to 100 degrees




//  if (!isClockwise) {
//    startPos = MoteurPhaseLength - 1;
//    increment = -1;
//  }


//*****************Déplacement*************************//


void bougerGauche(){
  
  for(int i=0; i< 100 ; i++){
  

  for (int i = startPos; i < MoteurPhaseLength && i >= 0; i = i + increment) {
    digitalWrite(PhaseMoteur[i], HIGH);
  
    if (i + increment < MoteurPhaseLength && i + increment >= 0 ) {
      digitalWrite(PhaseMoteur[i + increment], HIGH);
    }
    else{
    digitalWrite(PhaseMoteur[startPos], HIGH);
 
    }
    delayMicroseconds(d);
    digitalWrite(PhaseMoteur[i], LOW);
    delayMicroseconds(d);

   
      }
    }
  ShutdownAllPhases();   
}

void bougerDroite(){
    
  for(int i=0; i< 100 ; i++){
  
    for(int i = 3; i >= 0; i--) {
      digitalWrite(PhaseMoteur[i], HIGH);
      
      if(i + 1 > 1) {
      digitalWrite(PhaseMoteur[i-1], HIGH);
      }
      else{
      digitalWrite(PhaseMoteur[3], HIGH);
   
      }
      delayMicroseconds(d);
      digitalWrite(PhaseMoteur[i], LOW);
      delayMicroseconds(d);  
    }
  }
  ShutdownAllPhases();
}


//****************************Affichage********************************//

void clrGrilleJeu()
{
  for(int y=0; y<=5; y++) {
    for(int x=0; x<=6; x++) {
      GrilleJeu[y][x]= VIDE;
    }
    GrilleJeu[y][7] = 0 ;
  }
}
/*
void prntGrille()
{
  for(int y=0; y<=5; y++){
    Serial.println((char*)GrilleJeu[y]);
    }
}

*/










