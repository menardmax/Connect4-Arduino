//**************FONCTIONS D'INTERRUPTION ****************************//

void Interruption_LimitSwitch_Droite() {
LimitSW();
}


void Interruption_LimitSwitch_Gauche() {
LimitSW(); 
}


void LimitSW(){
  //Antirebond
  EtatLimitSW = true;
  int Time = millis();
  if(Time - timeOfLastLimitSW > 1000){
    timeOfLastLimitSW = Time;
    ShutdownAllPhases();
    Serial.println("limitSW");
  }
}

//--------Interruption colonnes---------

void InterruptionColonne(int NumeroColonne) {
  int Time = millis();
  //Securite pour empecher l'effet rebond lorsqu'un jetons est place dans la 5e rangée du Grid
  if (Time - timeOfLastMove > 1000) {
    timeOfLastMove = Time;
    PlacerJeton(NumeroColonne, turn, Grid);
    PrintGrid(Grid);
    TypeJeton winner = isFinished(Grid);
    if (winner == nulle) {

      if (turn == humain) {
        turn = AI;
        lcd.clear();
        lcd.print("Tour Robot");
      }
      else {
        turn = humain;
        lcd.clear();
        lcd.print("Tour Joueur");
      }
    } else {
      Serial.println("We have a winner");
      Serial.println(winner);

      switch (winner) {
        case humain:

          break;
        case AI:

          break;
      }
    }
  }
}

void InterruptionColonne1() {
  InterruptionColonne(0);
}

void InterruptionColonne2() {
  InterruptionColonne(1);
}
void InterruptionColonne3() {
  InterruptionColonne(2);
}
void InterruptionColonne4() {
  InterruptionColonne(3);
}

void InterruptionColonne5() {
  InterruptionColonne(4);
}

void InterruptionColonne6() {
  InterruptionColonne(5);
}
void InterruptionColonne7() {
  InterruptionColonne(6);
}


