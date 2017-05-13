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

void InterruptionColonne(int NumeroColonne){
   flag = 1;
}

void InterruptionColonne1(){
  InterruptionColonne(0);
}

void InterruptionColonne2(){
  InterruptionColonne(1);
}
void InterruptionColonne3(){
  InterruptionColonne(2);
}
void InterruptionColonne4(){
  InterruptionColonne(3);
}

void InterruptionColonne5(){
  InterruptionColonne(4);
}

void InterruptionColonne6(){
  InterruptionColonne(5);
}
void InterruptionColonne7(){
  InterruptionColonne(6);
}


