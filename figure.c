/* Projet C */
/* Groupe : 06 */
/* Composition : Antoine Level, Thomas Pouille, Iheb Zekri et Arthur Taillez */

#include "figure.h"
#include "a_modifier.h"

void afficher_texte(int x, int y, char *string, double r, double v, double b){
  glColor4f(r,v,b,1.0);
  texte(x, y, string);
}

void afficher_point(int x, int y, double r, double v, double b)
{
  /* r, v et b sont trois reels entre 0 et 1 correspondant aux trois composantes rouge, vert et bleu de la couleur*/
  glColor4f(r,v,b,1.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void afficher_rectangle_vide(int l, int L, int x, int y, int d, int a, int e, int c, double r, double v, double b)
{

        for( d=x; d<L+x; d++)
        {
            afficher_point(d,y,r,v,b);
        }

        for( a=y; a<l+y; a++)
        {
            afficher_point(x,a,r,v,b);
        }

        for( e=x; e<L+x; e++)
        {
             afficher_point(e,l+y,r,v,b);
        }

        for( c=y; c<l+y; c++)
        {
            afficher_point(L+x,c,r,v,b);
        }

}

void afficher_rectangle_plein(int l, int L, int x, int y, int d, int a, double r, double v, double b)
{

            for( a=y; a<l+y; a++)
            {
                for( d=x; d<L+x; d++)
                    afficher_point(d,a,r,v,b);
            }
}

void afficher_droite(int coefdir, int ordori, double r, double v, double b)
{
    int i,j;
    float y=0,x=0;
    if (coefdir<=1)
    {
      for (i=0;i<=800;i++)
      {
        y=coefdir*i+ordori;
        afficher_point(i,y,r,v,b);
      }
    }
    else
    {
      for (j=0;j<600;j++)
      {
        x=(j-b)/coefdir;
        afficher_point(x,j,r,v,b);
      }
    }
}
void afficher_cercle(int x, int xc, int y, int yc, int d, int rr, double r, double v, double b)
{

        x = 1;
        y = rr;
        d = rr;

            while (y >= x)
            {
                afficher_point(xc + x, yc + y, r, v, b);
                afficher_point(xc + x, yc - y, r, v, b);
                afficher_point(xc - x + 1, yc + y, r, v, b);
                afficher_point(xc - x + 1, yc - y + 1, r, v, b);
                afficher_point(xc + y, yc + x, r, v, b);
                afficher_point(xc + y, yc - x, r, v, b);
                afficher_point(xc - y + 1, yc + x, r, v, b);
                afficher_point(xc - y + 1, yc - x + 1, r, v, b);

                if (d > x)
                {
                    d = d - x;
                    x = x + 1;

                } else if (d < rr + 1 - y)
                {
                    d = d + y -1;
                    y = y - 1;

                } else
                {
                    d = d + y - x - 1;
                    x = x + 1;
                    y = y - 1;
                }
            }
}

void afficher_cercle_plein(float xc,float yc,float rr, double r,double v,double b)
{
  float x,y,longueur;
  for (x=xc-rr;x<xc+rr;x++)
  {
    for (y=yc+rr;y>yc-rr;y--)
    {
      longueur=sqrt(pow(x-xc,2)+pow(y-yc,2));
      if (longueur<=rr)
      {
        afficher_point(x,y,r,v,b);
      }
    }
  }
}


void enregistrer_point(int xx, int yy, Point **premier_point)
{
  Point *nouveau_point=malloc(sizeof(Point));
  nouveau_point->x=xx;
  nouveau_point->y=yy;
  nouveau_point->suivant=*premier_point;
  *premier_point=nouveau_point;
}

void afficher_point_liste(ptPoint premier_point)
{
  int i=1;
  ptPoint parcours=premier_point;
  while (parcours!=NULL)
  {
    printf("POINT %d \n",i);
    printf("Le point a pour coordonnées x=%d ; y=%d \n",parcours->x,parcours->y);
    parcours=parcours->suivant;
    i=i+1;
  }
}

void enregistrer_cercle(int xc, int yc, int rr, Cercle **premier_cercle)
{
  Cercle *nouveau_cercle=malloc(sizeof(Cercle));
  nouveau_cercle->x=xc;
  nouveau_cercle->y=yc;
  nouveau_cercle->rayon=rr;
  nouveau_cercle->suivant=*premier_cercle;
  *premier_cercle=nouveau_cercle;
}


void afficher_cercle_liste(ptCercle premier_cercle)
{
  int i=1;
  ptCercle parcours=premier_cercle;
  while (parcours!=NULL)
  {
    printf("Cercle %d \n",i);
    printf("Le cercle a pour centre les coordonnées x=%d ; y=%d \n",parcours->x,parcours->y);
    printf("Le cercle a pour rayon rayon=%d \n",parcours->rayon);
    parcours=parcours->suivant;
    i=i+1;
  }
}

void enregistrer_rectangle(int lar, int lon,  int xx, int yy, Rectangle **premier_rectangle)
{
  Rectangle *nouveau_rectangle=malloc(sizeof(Rectangle));
  nouveau_rectangle->largeur=lar;
  nouveau_rectangle->longueur=lon;
  nouveau_rectangle->x=xx;
  nouveau_rectangle->y=yy;
  nouveau_rectangle->suivant=*premier_rectangle;
  *premier_rectangle=nouveau_rectangle;
}


void afficher_rectangle_liste(ptRectangle premier_rectangle)
{
  int i=1;
  ptRectangle parcours=premier_rectangle;
  while (parcours!=NULL)
  {
    printf("Rectangle %d \n",i);
    printf("Le rectangle a pour bas_gauche les coordonnées x=%d ; y=%d \n",parcours->x,parcours->y);
    printf("Le rectangle a pour largeur largeur=%d ; longueur longueur=%d \n",parcours->largeur,parcours->longueur);
    parcours=parcours->suivant;
    i=i+1;
  }
}


void enregistrer_droite(int x, int y, Droite **premier_droite)
{
  Droite *nouveau_droite=malloc(sizeof(Droite));
  nouveau_droite->coef=x;
  nouveau_droite->ord=y;
  nouveau_droite->suivant=*premier_droite;
  *premier_droite=nouveau_droite;
}


void afficher_droite_liste(ptDroite premier_droite)
{
  int i=1;
  ptDroite parcours=premier_droite;
  while (parcours!=NULL)
  {
    printf("Droite %d \n",i);
    printf("La droite a pour bas_gauche les coordonnées x=%d ; y=%d \n",parcours->coef,parcours->ord);
    parcours=parcours->suivant;
    i=i+1;
  }
}

void enregistrer_figure(char *type, int x, int y, int cx, int cy, int rayon, int longueur, int largeur, int rx, int ry, int coef, int ord, int r, int v, int b, Figure **liste_figure)
{
  Figure *nouveau_figure=malloc(sizeof(Figure));
  nouveau_figure->typeFigure=type;
  nouveau_figure->x=x;
  nouveau_figure->y=y;
  nouveau_figure->cx=cx;
  nouveau_figure->cy=cy;
  nouveau_figure->rayon=rayon;
  nouveau_figure->longueur=longueur;
  nouveau_figure->largeur=largeur;
  nouveau_figure->rx=rx;
  nouveau_figure->ry=ry;
  nouveau_figure->coef=coef;
  nouveau_figure->ord=ord;
  nouveau_figure->rouge=r;
  nouveau_figure->vert=v;
  nouveau_figure->bleu=b;
  nouveau_figure->suivant=*liste_figure;
  *liste_figure=nouveau_figure;
}a

void afficher_figure_liste(ptFigure liste_figure)
{
      int i=1;
  ptFigure parcours=liste_figure;
  while (parcours != NULL)
  {

      if(parcours->typeFigure == "point")
      {
           printf("Figure %d \n",i);
    printf("Le point a pour coordonnées x=%d ; y=%d ; typeFigure=%s \n",parcours->x,parcours->y,parcours->typeFigure);
      }
      else if (parcours->typeFigure == "cercle_vide")
      {
           printf("Figure %d \n",i);
     printf("Le cercle vide a pour centre les coordonnées x=%d ; y=%d \n",parcours->cx,parcours->cy);
    printf("Le cercle a pour rayon rayon=%d \n",parcours->rayon);
           printf("et a pour couleur rouge=%d ; vert=%d ; bleu=%d \n", parcours->rouge, parcours->vert, parcours->bleu);
      }
       else if (parcours->typeFigure == "cercle_plein")
      {
           printf("Figure %d \n",i);
     printf("Le cercle plein a pour centre les coordonnées x=%d ; y=%d \n",parcours->cx,parcours->cy);
    printf("Le cercle a pour rayon rayon=%d \n",parcours->rayon);
     printf("et a pour couleur rouge=%d ; vert=%d ; bleu=%d \n", parcours->rouge, parcours->vert, parcours->bleu);
      }
      else if (parcours->typeFigure == "rectangle_vide")
      {
           printf("Figure %d \n",i);
     printf("Le rectangle vide a pour bas_gauche les coordonnées x=%d ; y=%d \n",parcours->rx,parcours->ry);
    printf("Le rectangle a pour largeur largeur=%d ; longueur longueur=%d \n",parcours->largeur,parcours->longueur);
           printf("et a pour couleur rouge=%d ; vert=%d ; bleu=%d \n", parcours->rouge, parcours->vert, parcours->bleu);
      }
      else if (parcours->typeFigure == "rectangle_plein")
      {
           printf("Figure %d \n",i);
     printf("Le rectangle plein a pour bas_gauche les coordonnées x=%d ; y=%d \n",parcours->rx,parcours->ry);
    printf("Le rectangle a pour largeur largeur=%d ; longueur longueur=%d \n",parcours->largeur,parcours->longueur);
     printf("et a pour couleur rouge=%d ; vert=%d ; bleu=%d \n", parcours->rouge, parcours->vert, parcours->bleu);
      }
     else if (parcours->typeFigure == "droite")
      {
          printf("Figure %d \n",i);
    printf("La droite a pour bas_gauche les coordonnées x=%d ; y=%d \n",parcours->coef,parcours->ord);
          printf("et a pour couleur rouge=%d ; vert=%d ; bleu=%d \n", parcours->rouge, parcours->vert, parcours->bleu);
      }
        parcours=parcours->suivant;
    i=i+1;
  }
}


 ptFigure suppression(ptFigure *liste_figure)
{
     ptFigure premier = *liste_figure;
    if (premier == NULL)
    {
        exit(EXIT_FAILURE);
    }
        ptFigure aSupprimer = premier;
return aSupprimer;
}

 ptFigure annuler(ptFigure *liste_histori)
{
     ptFigure premier = *liste_histori;
    if (premier == NULL)
    {
        exit(EXIT_FAILURE);
    }
        ptFigure aAnnuler = premier;
return aAnnuler;
}

void reafficher(ptFigure *liste_figure)
{
      ptFigure figure_nouv = *liste_figure;
    figure_nouv = figure_nouv->suivant;
    
    while(figure_nouv !=NULL){
  if(figure_nouv->typeFigure == "cercle_vide")
        {
            afficher_cercle(0, figure_nouv->cx, 0, figure_nouv->cy, 0, figure_nouv->rayon, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
        figure_nouv = figure_nouv->suivant;
        }
        else if(figure_nouv->typeFigure == "cercle_plein")
        {
            afficher_cercle_plein(figure_nouv->cx, figure_nouv->cy, figure_nouv->rayon, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
              figure_nouv = figure_nouv->suivant;
            //x, y, rr, r, v, b
        }
        else if (figure_nouv->typeFigure == "point")
        {
             afficher_point(figure_nouv->x, figure_nouv->y,0,0,0);
              figure_nouv = figure_nouv->suivant;
        }
        else if (figure_nouv->typeFigure == "droite")
        {
             afficher_droite(figure_nouv->coef, figure_nouv->ord, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
              figure_nouv = figure_nouv->suivant;
        }
        else if (figure_nouv->typeFigure == "rectangle_vide")
        {
             afficher_rectangle_vide(figure_nouv->longueur, figure_nouv->largeur, figure_nouv->rx, figure_nouv->ry, 0, 0, 0, 0, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
              figure_nouv = figure_nouv->suivant;
        }//l, L, x, y, d, a, e, c, r, v, b
         else if (figure_nouv->typeFigure == "rectangle_plein")
        {
             afficher_rectangle_plein(figure_nouv->longueur, figure_nouv->largeur, figure_nouv->rx, figure_nouv->ry, 0, 0, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
               figure_nouv = figure_nouv->suivant;
        }
    }
}



void abandon(ptFigure *liste_histori)
    {
      ptFigure figure_nouv = *liste_histori;
    if (figure_nouv == NULL)
    {
         exit(EXIT_FAILURE);
    }
    
          if(figure_nouv->typeFigure == "cercle_vide")
        {
            afficher_cercle(0, figure_nouv->cx, 0, figure_nouv->cy, 0, figure_nouv->rayon, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
        }
        else if(figure_nouv->typeFigure == "cercle_plein")
        {
            afficher_cercle_plein(figure_nouv->cx, figure_nouv->cy, figure_nouv->rayon, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
        }
        else if (figure_nouv->typeFigure == "point")
        {
             afficher_point(figure_nouv->x, figure_nouv->y,0,0,0);
        }
        else if (figure_nouv->typeFigure == "droite")
        {
             afficher_droite(figure_nouv->coef, figure_nouv->ord, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
        }
        else if (figure_nouv->typeFigure == "rectangle_vide")
        {
             afficher_rectangle_vide(figure_nouv->longueur, figure_nouv->largeur, figure_nouv->rx, figure_nouv->ry, 0, 0, 0, 0,figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
        }
         else if (figure_nouv->typeFigure == "rectangle_plein")
        {
             afficher_rectangle_plein(figure_nouv->longueur, figure_nouv->largeur, figure_nouv->rx, figure_nouv->ry, 0, 0, figure_nouv->rouge, figure_nouv->vert, figure_nouv->bleu);
        }
      }

        
