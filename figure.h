/* Projet C */
/* Groupe : 06 */
/* Composition : Antoine Level, Thomas Pouille, Iheb Zekri et Arthur Taillez */

#ifndef FIGURE__H
#define FIGURE__H
#include <GL/glut.h>
#include "opengl.h"

#define POINT 0
#define LIGNE 1
#define RECTANGLE 2
#define CERCLE 3
#define TEXTE 4

// Mettre en place ici la SD pour les figures

typedef struct Pointe
{
    int x;
    int y;
    struct Pointe *suivant;
} Point, *ptPoint;

typedef struct Cerclee
{
    int x;
    int y;
    int rayon;
    struct Cerclee *suivant;
} Cercle, *ptCercle;

typedef struct Rectanglee
{
    int longueur;
    int largeur;
    int x;
    int y;
    struct Rectanglee *suivant;
} Rectangle, *ptRectangle;

typedef struct Droitee
{
    int coef;
    int ord;
    struct Droitee *suivant;
} Droite, *ptDroite;

typedef struct Figuree
{
     char *typeFigure;
    int x;
    int y;
    int cx;
    int cy;
    int rayon;
    int longueur;
    int largeur;
    int rx;
    int ry;
    int coef;
    int ord;
    int rouge;
    int vert;
    int bleu;
    struct Figuree *suivant;
} Figure, *ptFigure;


// Mettre en place ici la SD pour la (les) liste(s) chainée(s)

void afficher_texte(int x, int y, char *string, double r, double v, double b);

void afficher_point(int x, int y, double r, double v, double b);

void afficher_rectangle_vide(int longueur, int Largeur, int x, int y, int d, int a, int e, int c, double r, double v, double b);

void afficher_rectangle_plein(int longueur, int Largeur, int x, int y, int d, int a, double r, double v, double b);

void afficher_droite(int coefdir, int ordori, double r, double v, double b);

void afficher_cercle(int x, int xc, int y, int yc, int d, int rr, double r, double v, double b);

void afficher_cercle_plein(float xc,float yc,float rr, double r,double v,double b);

void enregistrer_point(int xx, int yy, Point **premier_point);

void afficher_point_liste(ptPoint premier_point);

void enregistrer_cercle(int xc, int yc, int rr, Cercle **premier_cercle);

void afficher_cercle_liste(ptCercle premier_cercle);

void enregistrer_rectangle(int lon, int lar,  int xx, int yy, Rectangle **rectangle);

void afficher_rectangle_liste(ptRectangle premier_rectangle);

void enregistrer_droite(int x, int y, Droite **droite);

void afficher_droite_liste(ptDroite premier_droite);

void enregistrer_figure(char *type,int x, int y, int cx, int cy, int rayon, int longueur, int largeur, int rx, int ry, int coef, int ord, int r, int v, int b, Figure **liste_figure);

void afficher_figure_liste(ptFigure liste_figure);

ptFigure suppression(ptFigure *liste_figure);

ptFigure annuler(ptFigure *liste_histori);

void reafficher(ptFigure *liste_figure);

void abandon(ptFigure *liste_histori);


#endif
