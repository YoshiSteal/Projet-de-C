/* Projet C */
/* Groupe : 06 */
/* Composition : Antoine Level, Thomas Pouille, Iheb Zekri et Arthur Taillez */

#include "opengl.h"
#include "figure.h"
#include "a_modifier.h"

char choix=-1, choix2, choix3;
int l, L, x, y, xc, yc, rr, d, a, e, b, c, v, r, cga_x, cgo_y;
Droite *premier_droite=NULL;
Cercle *premier_cercle=NULL;
Point *premier_point=NULL;
Rectangle *premier_rectangle=NULL;
Figure *liste_figure=NULL;
Figure *liste_histori=NULL;

// Procédure appelée lors de la création de la fenêtre
// que vous pouvez réappeler de nouveau pour réinitilisation.
// Utile si vous voulez créer un menu ou une interface graphique...

void initialisation_fenetre()
{
    /***********************************/

    /*interface */
    int j;
    int k=530;

    afficher_cercle_plein(20,555,5,0,0,0);
    afficher_rectangle_vide(50,100,50,530,0,0,0,0,0,0,0);
    afficher_rectangle_plein(50,100,200,530,0,0,0,0,0);
    afficher_cercle(0,460,0,555,0,25,0,0,0);
    afficher_cercle_plein(530,555,25,0,0,0);


    afficher_rectangle_vide(75,190,590,520,0,0,0,0,0,0,1);

    afficher_rectangle_plein(25,50,600,565,0,0,1,0,0);
    afficher_rectangle_plein(25,50,660,565,0,0,0,1,0);
    afficher_rectangle_plein(25,50,720,565,0,0,0,0,1);

    afficher_rectangle_plein(25,50,600,525,0,0,1,0,1);
    afficher_rectangle_plein(25,50,660,525,0,0,1,1,0);
    afficher_rectangle_plein(25,50,720,525,0,0,0,1,1);

    afficher_droite(0,500,0,0,1);
    afficher_rectangle_vide(450,799,0,50,0,0,0,0,0,0,1);


        for (j=350; j<400; j++)
        {
            afficher_point(j,k,0,0,0);
            k=k+1;
        }

    afficher_texte(10, 10, "Quitter", 1, 0, 0);
    afficher_texte(10, 30, "Effacer", 1, 0, 0);
    afficher_texte(325, 10, "Cree et realiser par Antoine, Arthur, Thomas et Iheb", 0, 0, 0);

}



// Cette procédure est appelée lorsqu'aucun
// événement clavier/souris n'est détecté
// donc quasiment en continu.
// C'est cette procédure qui doit gèrer l'affichage.

void affichage()
{
    if(cga_x >= 600 && cga_x <= 650 && cgo_y >= 10 && cgo_y <= 35)
    {
        r=1;
        v=0;
        b=0;

        printf("Vous avez selectionnez la couleur Rouge \n");

        cga_x =10;
        cgo_y=10;
    }

    if(cga_x >= 660 && cga_x <= 710 && cgo_y >= 10 && cgo_y <= 35)
    {
        r=0;
        v=1;
        b=0;

        printf("Vous avez selectionnez la couleur Verte \n");

        cga_x =10;
        cgo_y=10;
    }

    if(cga_x >= 720 && cga_x <= 770 && cgo_y >= 10 && cgo_y <= 35)
    {
        r=0;
        v=0;
        b=1;

        printf("Vous avez selectionnez la couleur Bleu Fonce \n");

        cga_x =10;
        cgo_y=10;
    }

    if(cga_x >= 600 && cga_x <= 650 && cgo_y >= 50 && cgo_y <= 75)
    {
        r=1;
        v=0;
        b=1;

        printf("Vous avez selectionnez la couleur Violette \n");

        cga_x =10;
        cgo_y=10;
    }

    if(cga_x >= 660 && cga_x <= 710 && cgo_y >= 50 && cgo_y <= 75)
    {
        r=1;
        v=1;
        b=0;

        printf("Vous avez selectionnez la couleur Jaune \n");

        cga_x =10;
        cgo_y=10;
    }

    if(cga_x >= 710 && cga_x <= 770 && cgo_y >= 50 && cgo_y <= 75)
    {
        r=0;
        v=1;
        b=1;

        printf("Vous avez selectionnez la couleur Bleu Ciel \n");

        cga_x =10;
        cgo_y=10;
    }


    // L'affichage ne peut se faire que ici !
    // Utilisez des variables globales si vous avez besoin de faire communiquer
    // cette procédure et les autres.

    // On affiche 4 points à chaque fois pour que ce soit plus
    // visible qu'un seul pixel - juste plus de confort
    // pour ce programme de test.
    if((cga_x >= 16 && cga_x <= 26 && cgo_y >= 41 && cgo_y <= 51) || (choix=='1'))
    {
        int x, y;
        printf("Vous avez choisi le point !\n");
        printf("Les coordonnées de x doivent etre comprisent entre 0 et 800\n");
        printf("Les coordonnées de y doivent etre comprisent entre 100 et 500\n");
        printf("Entrez la coordonnées X du point à afficher : ");
        scanf(" %d", &x);
        printf("Entrez la coordonnées Y du point à afficher : ");
        scanf(" %d", &y);
        afficher_point(x,y,0,0,0);
        enregistrer_point(x, y, &premier_point);
        enregistrer_figure("point", x, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, &liste_figure);
        cga_x=0;
        cgo_y=0;
        choix=-1;
    }


         /* rectangle vide */
    if ((cga_x >= 50 && cga_x <= 155 && cgo_y >= 20 && cgo_y <= 70) || (choix=='2'))
    {
        printf("Vous avez choisi le rectangle vide !\n");
        printf("Les coordonnées de x doivent etre comprisent entre 0 et 800\n");
        printf("Les coordonnées de y doivent etre comprisent entre 100 et 500\n");
        printf("Quelle est la longueur de votre rectangle ? ");
        scanf("%d", &L);
        printf("Quelle est la largeur de votre rectangle ? ");
        scanf("%d", &l);
        printf("Quelle est l'ordonnee du point du coin gauche bas de votre rectangle ? ");
        scanf("%d", &y);
        printf("Quelle est l'abscisse du point du coin gauche bas de votre rectangle ? ");
        scanf("%d", &x);
        enregistrer_rectangle(l, L, x, y, &premier_rectangle);
        afficher_rectangle_vide(l, L, x, y, d, a, e, c, r, v, b);
        enregistrer_figure("rectangle_vide", 0, 0, 0, 0, 0, l, L, x, y, 0, 0, r, v, b, &liste_figure);
        cga_x=0;
        cgo_y=0;
        choix=-1;
        affichage();
        }


         /*rectangle plein*/
    if ((cga_x >= 200 && cga_x <= 300 && cgo_y >= 20 && cgo_y <= 70) || (choix=='3'))
    {
        printf("Vous avez choisi le rectangle plein !\n");
        printf("Les coordonnées de x doivent etre comprisent entre 0 et 800\n");
        printf("Les coordonnées de y doivent etre comprisent entre 100 et 500\n");
        printf("Quelle est la longueur de votre rectangle ? ");
        scanf(" %d", &L);
        printf("Quelle est la largeur de votre rectangle ? ");
        scanf(" %d", &l);
        printf("Quelle est l'abscisse du point du coin gauche bas de votre rectangle ? ");
        scanf(" %d", &x);
        printf("Quelle est l'ordonnee du point du coin gauche bas de votre rectangle ? ");
        scanf(" %d", &y);
        enregistrer_rectangle(l, L, x, y, &premier_rectangle);
        afficher_rectangle_plein(l, L, x, y, d, a, r, v, b);
        enregistrer_figure("rectangle_plein", 0, 0, 0, 0, 0, l, L, x, y, 0, 0, r, v, b, &liste_figure);
        cga_x=0;
        cgo_y=0;
        choix=-1;

    }

        /*cercle vide*/
    if ((cga_x >= 435 && cga_x <= 485 && cgo_y >= 20 && cgo_y <= 70) || (choix=='4'))
    {
        printf("Vous avez choisi le cercle vide !\n");
        printf("Les coordonnées de x doivent etre comprisent entre 0 et 800\n");
        printf("Les coordonnées de y doivent etre comprisent entre 100 et 500\n");

        printf("Entrer le rayon du cercle : ");
        scanf("%d", &rr);
        printf("entrer x: ");
        scanf("%d", &xc);
        printf("entrer y: ");
        scanf("%d", &yc);
        afficher_cercle(x, xc, y, yc, d, rr, r, v, b);
        enregistrer_cercle(xc, yc, rr, &premier_cercle);
        enregistrer_figure("cercle_vide", 0, 0, xc, yc, rr, 0, 0, 0, 0, 0, 0, r, v, b,  &liste_figure);
        cga_x=0;
        cgo_y=0;
        choix=-1;
    }

        // cercle plein //
    if ((cga_x >= 505 && cga_x <= 555 && cgo_y >= 20 && cgo_y <= 70) || (choix=='5'))
    {
        printf("Vous avez choisi le cercle plein !\n");
        printf("Entrer le rayon du cercle : ");
        scanf("%d", &rr);
        printf("entrer x: ");
        scanf("%d", &x);
        printf("entrer y: ");
        scanf("%d", &y);
        afficher_cercle_plein(x, y, rr, r, v, b);
        enregistrer_figure("cercle_plein", 0, 0, x, y, rr, 0, 0, 0, 0, 0, 0, r, v, b,  &liste_figure);
        cga_x=0;
        cgo_y=0;
        choix=-1;
    }



         /*droite*/
    if ((cga_x >= 350 && cga_x <= 400 && cgo_y >= 20 && cgo_y <= 70) || (choix=='6'))
    {
        float coefdir,ordori;
        printf("Vous avez choisi la droite !\n");
        printf("La droite est d'équation ax+b\n");
        printf("Entrez la valeur de a :");
        scanf("%f",&coefdir);
        printf("Entrez la valeur de b :");
        scanf("%f",&ordori);
        afficher_droite(coefdir, ordori, r, v, b);
        enregistrer_droite(coefdir, ordori, &premier_droite);
        enregistrer_figure("droite",0, 0, 0, 0, 0, 0, 0, 0, 0, coefdir, ordori, r, b, v, &liste_figure);
        cga_x=0;
        cgo_y=0;
        choix=-1;
    }

     //liste chainée
    if(choix=='7'){
        printf("choisissez la liste dont vous voulez. \n");
        printf("1 -> Les points.\n");
        printf("2 -> les droites\n");
        printf("3 -> les Rectangles\n");
        printf("4 -> les Cercles\n");
        printf("5 -> Historique complet\n");
        printf("6 -> Historique supprime\n");
        scanf("%hhd", &choix2);

        if (choix2==1)
        {
            printf("les coordonnées du dernier point sont :\n");
            afficher_point_liste(premier_point);

        } else if(choix2==2) {

            printf("les coordonnées de la derniere droite sont : \n");
            afficher_droite_liste(premier_droite);

        } else if (choix2==3) {

            printf("les coordonnées du dernier rectangle sont :\n");
            afficher_rectangle_liste(premier_rectangle);

        } else if (choix2==4) {

            printf("les coordonnées du dernier cercle sont :\n");
            afficher_cercle_liste(premier_cercle);

        } else if (choix2 == 5) {

            afficher_figure_liste(liste_figure);

        } else if (choix2 == 6) {

            afficher_figure_liste(liste_histori);
        }
           choix=-1;
    }



    if(choix=='8')
    {
        initialisation_fenetre();
        choix=-1;
    }

    if ((cga_x >= 13 && cga_x <= 73 && cgo_y >= 560 && cgo_y <= 572) || (choix=='9'))
    {
        effacer();
        initialisation_fenetre();
        choix=-1;
    }

    if(choix=='s')
    {
     ptFigure figure_supprimer = suppression(&liste_figure);
     printf("suppression de la derniere chaine \n");
            enregistrer_figure(figure_supprimer->typeFigure, figure_supprimer->x, figure_supprimer->y, figure_supprimer->cx, figure_supprimer->cy, figure_supprimer->rayon, figure_supprimer->longueur, figure_supprimer->largeur, figure_supprimer->rx, figure_supprimer->ry, figure_supprimer->coef, figure_supprimer->ord, figure_supprimer->rouge, figure_supprimer->vert, figure_supprimer->bleu, &liste_histori);
        effacer();
        initialisation_fenetre();
        reafficher(&liste_figure);
    
        free(figure_supprimer);
    
     choix=-1;
    }

    if(choix=='a')
    {
        ptFigure figure_annuler = annuler(&liste_histori);
        printf("annulation de la suppression \n");

        enregistrer_figure(figure_annuler->typeFigure, figure_annuler->x, figure_annuler->y, figure_annuler->cx, figure_annuler->cy ,figure_annuler->rayon, figure_annuler->longueur, figure_annuler->largeur, figure_annuler->rx,figure_annuler->ry, figure_annuler->coef, figure_annuler->ord, figure_annuler->rouge, figure_annuler->vert, figure_annuler->bleu, &liste_figure);

         abandon( &liste_histori);
        
        free(figure_annuler);
        
        choix=-1;
    }

    if ((cga_x >= 10 && cga_x <= 70 && cgo_y >= 582 && cgo_y <= 592) || (choix=='0'))
    {
        exit(0);
    }
}


void clic_gauche(int x, int y)
{
    // Code exécuté lors d'un clic gauche
    // Attention ! Pas de dessin dans cette fonction/procédure.
    // Utilisez des variables globales si vous avez besoin de faire communiquer
    // cette procédure et celles du dessous.
    printf("Clic gauche en %d %d\n",x,y);
	cga_x = x;
	cgo_y = y;
}


void clic_droit(int x, int y)
{
    // Code exécuté lors d'un clic droit
    // Attention ! Pas de dessin dans cette fonction/procédure
    // Utilisez des variables globales si vous avez besoin de faire communiquer
    // cette procédure et celles du dessous.
    printf("Clic droit en %d %d\n",x,y);
}

void clavier(unsigned char key, int x, int y)
{
    // Code exécuté lors d'un
    // Attention ! Pas de dessin dans cette fonction/procédure
    // Utilisez des variables globales si vous avez besoin de faire communiquer
    // cette procédure et celles du dessous.

    printf("Appui sur la touche %c du clavier lorsque la souris est en %d %d\n",key,x,y);

    // Si la touche appuyée est un chiffre entre 1 et 6,
    // la case correspondante dans le tableau choix est mise à vrai.
    // Si une autre touche est appuyée, le programme se ferme.
    if ((key>='0' && key<='9') || (key == 's') ||(key == 'a'))
        choix=key;
    else
        exit(0);
}

