/* Projet C */
/* Groupe : 06 */
/* Composition : Antoine Level, Thomas Pouille, Iheb Zekri et Arthur Taillez */

#include "opengl.h"
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char** argv)
{
  creation_fenetre(COIN_HAUT_GAUCHE_X,COIN_HAUT_GAUCHE_Y,TAILLE_X,TAILLE_Y);

  printf("Appuyez sur la touche 1 pour entrer les coordonnées d'un point à afficher\n");
  printf("Appuyez sur la touche 2 pour faire un rectangle vide\n");
  printf("Appuyez sur la touche 3 pour faire un rectangle plein\n");
  printf("Appuyez sur la touche 4 pour faire un cercle vide\n");
  printf("Appuyez sur la touche 5 pour faire un cercle vide\n");
  printf("Appuyez sur la touche 6 pour faire un droite\n");
  printf("Appuyez sur la touche 7 pour definir une liste chainée.\n");
  printf("Appuyez sur la touche 8 pour reinitialiser la fenêtre\n");
  printf("Appuyez sur la touche 9 pour tout effacer\n");
  printf("Appuyez sur la touche 0 pour quitter\n");
  printf("Ou cliquez dans la fenêtre avec la souris\n");
  lancer_application();
  return 0;
}
