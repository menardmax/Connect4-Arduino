//**************FONCTIONS D'INTERRUPTION ****************************//

void Interruption_LimitSwitch_Droite() {
  //Si limit switch de droite appuyée
  //Éteint 4phases
  //On prend un jetons

}


void Interruption_LimitSwitch_Gauche() {
}

void flash(int pin, int times, int delayMilis) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(delayMilis);
    digitalWrite(pin, LOW);
    delay(delayMilis);
  }
}

//--------Interruption colonnes---------

void InterruptionColonne(int NumeroColonne) {
  int Time = millis();
  //Securite pour empecher l'effet rebond lorsqu'un jetons est place dans la 5e rangée du Grid
  if (Time - timeOfLastMove > 1000) {
    timeOfLastMove = Time;
    PlacerJeton(NumeroColonne, turn);
    PrintGrid();
    TypeJeton winner = isFinished(Grid);
    if (winner == nulle) {

      if (turn == humain) {
        turn = AI;

      }
      else {
        turn = humain;

      }


    } else {
      Serial.println("We have a winner");
      Serial.println(winner);

//      switch (winner) {
//        case humain:
//          flash(DelJaune, 10, 100);
//          break;
//        case AI:
//          flash(DelRouge, 10, 100);
//          break;
//      }
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


