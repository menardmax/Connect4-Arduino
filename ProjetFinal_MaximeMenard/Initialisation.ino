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

