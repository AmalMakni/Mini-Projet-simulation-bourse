#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include "PrixJournalier.h"

//Les codes couleurs
#define COLOR_BLACK     0
#define COLOR_BLUE      1
#define COLOR_GRAY      2
#define COLOR_GREEN     10
#define COLOR_WHITE     255
#define COLOR_YELLOW    14

//Le caractere utilise pour valider une saisie
const unsigned char ENTER       = 13;   //
//Utile pour choisir une option dans les menus
const unsigned char PLUS = '+';
const unsigned char MINUS = '-';
const unsigned char ZERO = '0';
const unsigned char ONE = '1';
const unsigned char NINE = '9';

//Le caractere le + utilise pour completer une chaine pour avoir une taille fixe
//Utile pour les menus
const unsigned char SPACE       = 32;   //

//Les caracteres utilises pour dessiner des encadres
const unsigned char HORIZONTAL  = 196;  //─
const unsigned char VERTICAL    = 124;  //|
const unsigned char BLC         = 192;  //└
const unsigned char TRC         = 191;  //┐
const unsigned char TLC         = 218;  //┌
const unsigned char BRC         = 217;  //┘

enum typeLigne{ FIRST_LIG=0,MEDIUM_LIG,LAST_LIG };
enum typePAD {PAD_LEFT,PAD_RIGHT };

//On suppose qu'un menu ne depasse jamais 9 options/rubriques
#define MAX_OPTIONS 9
//On suppose que le plus grand menu a dessiner est de largeur 100
#define MAX_TITLE 100
typedef char itemTitle[MAX_TITLE + 1];

//Taille de la console
#define SCREEN_WIDTH 120

class Menu {
public :
    void SetColorAndBackground(int ForgC, int BackC);
    void gotoxy(int x,int y);

    void pad(typePAD t, char c, char * s, int width);

    void afficherHeure(int menuwidth);

    void dessinerLigne(typeLigne tl, char c, int xPosition, int yPosition, int width);
    void dessinerTitreMenu(char titreMenu[], int menuWidth);
    void desssinerMenu(itemTitle item[], int nbItem, int menuWidth, int choixOption);
    void afficherMessageChoix(int nbItem, int menuWidth, int choixOption);
    char determinerChoix(int nbItem, int * choix);
    int menu(char titreMenu[], itemTitle item[], int nbItem, int menuWidth);

    void messageSortie(int menuWidth);
    int menuGeneral();
    int menuBourse();
    int menuTrader();
    void choixBourse (vector <PrixJournalier> pj, Date ddeb  );


};

#endif // MENU_H_INCLUDED
