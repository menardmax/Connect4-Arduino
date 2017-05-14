//Fonction déterminer un tour a jouer

#define DEPTH_LIMIT 6

int GetMoveAI() {
  //  int Colonne = random(0, 7);
  int Colonne = minmax(Grid, 1);
  return Colonne;
}

int minmax(TypeJeton Grid[Hauteur][Largeur], int depth) {
  int columnToPlay = 0;
  int minScore = 999999;

  for (int i = 0; i < Largeur; i++) {
    // si la colonne est pleine, ne pas la considerer comme une possibilite
    if (Grid[0][i] != nulle) {
      continue;
    }
    // Fait la copie du grid passe
    TypeJeton gridCopy[Hauteur][Largeur];
    for (int i = 0; i < Hauteur; i++) {
      for (int j = 0; j < Largeur; j++) {
        gridCopy[i][j] = Grid[i][j];
      }
    }
    // placer le jeton du AI dans la copie
    PlacerJeton(i, AI, gridCopy);

    // Trouver le score du coup du AI
    int moveScore = minimize(gridCopy, 1);
    // Sil fait plus mal que le dernier meilleur coup, on le remplace
    if (moveScore < minScore) {
      minScore = moveScore;
      columnToPlay = i;
    }
  }
  return columnToPlay;
}


int minimize(TypeJeton Grid[Hauteur][Largeur], int depth) {
  // Regles de score du AI
  if (isFinished(Grid) == AI) {
    return -100 + depth;
  }
  if (depth >= DEPTH_LIMIT) {
    return 0;
  }

  int maxScore = -99999;

  // on simule le coup de l'humain et on garde son meilleur
  for (int i = 0; i < Largeur; i++) {
    // si la colonne est pleine, ne pas la considerer comme une possibilite
    if (Grid[0][i] != nulle) {
      continue;
    }
    // Fait la copie du grid passe
    TypeJeton gridCopy[Hauteur][Largeur];
    for (int i = 0; i < Hauteur; i++) {
      for (int j = 0; j < Largeur; j++) {
        gridCopy[i][j] = Grid[i][j];
      }

    }
    // placer le jeton de l'humain dans la copie
    PlacerJeton(i, humain, gridCopy);
    int moveScore = maximize(gridCopy, depth + 1);
    if (moveScore > maxScore) {
      maxScore = moveScore;
    }
  }

  return maxScore;
}

int maximize(TypeJeton Grid[Hauteur][Largeur], int depth) {
  // Regles de score de l'humain
  if (isFinished(Grid) == humain) {
    return 100 - depth;
  }
  if (depth >= DEPTH_LIMIT) {
    return 0;
  }

  int minScore = 99999;

  // on simule le coup de l'humain et on garde son meilleur
  for (int i = 0; i < Largeur; i++) {
    // si la colonne est pleine, ne pas la considerer comme une possibilite
    if (Grid[0][i] != nulle) {
      continue;
    }
    // Fait la copie du grid passe
    TypeJeton gridCopy[Hauteur][Largeur];
    for (int i = 0; i < Hauteur; i++) {
      for (int j = 0; j < Largeur; j++) {
        gridCopy[i][j] = Grid[i][j];
      }

    }
    // placer le jeton de l'humain dans la copie
    PlacerJeton(i, AI, gridCopy);
    int moveScore = minimize(gridCopy, depth + 1);
    if (moveScore < minScore) {
      minScore = moveScore;
    }
  }

  return minScore;
}
