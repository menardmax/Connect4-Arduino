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

