void ResetGrid() {

  for (int i = 0; i < Hauteur; i++) {
    for (int j = 0; j < Largeur; j++) {
      Grid[i][j] = nulle;
    }
  }

}

void PrintGrid(TypeJeton grid[Hauteur][Largeur]) {

  for (int i = 0; i < Hauteur; i++) {
    for (int j = 0; j < Largeur; j++) {
      Serial.print(grid[i][j]);
    }
    Serial.println();
  }

}

//TypeJeton[][] gridCopy(TypeJeton grid[Hauteur][Largeur]) {
//  TypeJeton gridCopy[Hauteur][Largeur];
//   for (int i = 0; i < Hauteur; i++) {
//    for (int j = 0; j < Largeur; j++) {
//      gridCopy[i][j] = grid[i][j];
//    }
//
//  }
//  return gridCopy;
//}

//Cette variable : FourInARow est a true si on a detecte un jeton
//du meme etat que le precedent
TypeJeton isFinished(TypeJeton Grid[Hauteur][Largeur]) {
  for (int i = 0; i < Hauteur; i++) {
    for (int j = 0; j < Largeur; j++) {
      TypeJeton jeton = Grid[i][j];
      if (jeton == nulle) {
        continue;
      }

      boolean FourInaRow = true;
      //On verifi la hauteur si on a 4 in a row
      for (int k = 1; k < 4; k++) {
        if (i + k <= Hauteur) {
          if (jeton != Grid[i + k][j]) {
            FourInaRow = false;
            break;
          }
        }
        else {
          FourInaRow = false;
        }
      }
      if (FourInaRow == true) {
        return jeton;
      }

      FourInaRow = true;
      //On verifi la largeur si on a 4 in a row
      for (int k = 1; k < 4; k++) {
        if (j + k <= Largeur) {
          if (jeton != Grid[i][j + k]) {
            FourInaRow = false;
            break;
          }
        }
        else {
          FourInaRow = false;
        }
      }
      if (FourInaRow == true) {
        return jeton;
      }

      FourInaRow = true;
      //On verifi la diagonale droite descendante(descend et vas vers la droite) si on a 4 in a row
      for (int k = 1; k < 4; k++) {
        if (j + k <= Largeur && i + k <= Hauteur) {
          if (jeton != Grid[i + k][j + k]) {
            FourInaRow = false;
            break;
          }
        }
        else {
          FourInaRow = false;
        }
      }
      if (FourInaRow == true) {
        return jeton;
      }

      FourInaRow = true;
      //On verifi la diagonale gauche descendante(descend et vas vers la gauche) si on a 4 in a row
      for (int k = 1; k < 4; k++) {
        if (j - k >= 0 && i + k <= Hauteur) {
          if (jeton != Grid[i + k][j - k]) {
            FourInaRow = false;
            break;
          }
        }
        else {
          FourInaRow = false;
        }
      }
      if (FourInaRow == true) {
        return jeton;
      }



    }
  }
  return nulle;
}

//Utiliser cette fonction lorsqu'un jeton doit être placé dans une colonne
//On donne 2 paramètres d'entré soit le # de colonne et le type de jeton (Humain ou AI)
void PlacerJeton(int Colonne, TypeJeton Jeton, TypeJeton grid[Hauteur][Largeur]) {
  int i = Hauteur - 1;
  while (i >= 0 && grid[i][Colonne] != nulle) {
    i -= 1;
  }
  if (i >= 0) {
    grid[i][Colonne] = Jeton;
  }


}
