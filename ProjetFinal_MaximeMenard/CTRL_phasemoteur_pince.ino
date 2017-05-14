//*****************Déplacement*************************//


void tourAI() {
  CloseClaw();
  int Colonne = GetMoveAI();
  //Pour obtenir une chiffre de 1 a 7
  int ColonnePhysique = Colonne + 1;
  //Pas entre chaque colonne[NBsteps1Colonne]*ColonnePhysique + PositionInitiale
  int NBsteps1Colonne = 75;
  int Positioninitiale = 50;
  int steps = NBsteps1Colonne * ColonnePhysique + Positioninitiale;
  bougerGauche(steps);
  Serial.print("Colonne Physique : ");
  Serial.println(ColonnePhysique);
}



void bougerGauche(int steps) {

  for (int i = 0; i < steps ; i++) {

    for (int i = startPos; i < MoteurPhaseLength && i >= 0; i = i + increment) {
      digitalWrite(PhaseMoteur[i], HIGH);

      if (i + increment < MoteurPhaseLength && i + increment >= 0 ) {
        digitalWrite(PhaseMoteur[i + increment], HIGH);
      }
      else {
        digitalWrite(PhaseMoteur[startPos], HIGH);

      }
      delayMicroseconds(d);
      digitalWrite(PhaseMoteur[i], LOW);
      delayMicroseconds(d);

    }
  }
  ShutdownAllPhases();
}
//EtatLimitSW doit etre remit false apres chaque coup sinon il resterait a true apres un deplacement
//On met EtatLimitSW a false dans le cas où la pince serait deja sur la limitSW de droite
void bougerExtremeDroite() {
  Serial.println("Bougeons a droite");
  EtatLimitSW = false;
  //tant quon a pas entre dans la limitSW de droite
  int i = 3;
  while (!EtatLimitSW) {
    Serial.println(i);
    digitalWrite(PhaseMoteur[i], HIGH);
    if (i > 0) {
      digitalWrite(PhaseMoteur[i - 1], HIGH);
    }
    else {
      digitalWrite(PhaseMoteur[3], HIGH);

    }
    delayMicroseconds(d);
    digitalWrite(PhaseMoteur[i], LOW);
    delayMicroseconds(d);
    i--;
    if (i < 0) {
      i = 3;
    }
  }
  ShutdownAllPhases();
  Serial.println("Fuck la droite");
}



//*******************Éteindre Phases Moteur********************//

void ShutdownAllPhases() {
  for (int i = 0 ; i < 4 ; i++) {
    digitalWrite(PhaseMoteur[i], LOW);
  }
}


//*******************Claw control *********************//

void OpenClaw() {
  Claw.write(10);
}// Make claw go to 0 degrees


void CloseClaw() {
  Claw.write(90);
}// Make claw go to 100 degrees
