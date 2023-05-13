#include <time.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Menu.h"
#include "Bourse.h"
using namespace std ;

//Changement de couleur de texte et son fond
void Menu::  SetColorAndBackground(int ForgC, int BackC) {
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

//Deplacer le curseur dans la console a une position donnee (x, y)
void Menu :: gotoxy(int x,int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


//Dessiner ligne selon son type (typeLigne tl) a partir d'une position donnee (int xPosition, int yPosition)
//avec une taille donnee (int width)
void Menu :: dessinerLigne( enum typeLigne tl, char c, int xPosition, int yPosition, int width){


    //Dessin Premier caractere de la ligne
    gotoxy(xPosition,yPosition);
    switch(tl){
        case FIRST_LIG:
            //Dessiner coin haut gauche
            cout << TLC ;
             break;
        case MEDIUM_LIG:
            //Dessiner trait vertical
             cout<< VERTICAL  ;
             break;
        case LAST_LIG:
            //Dessiner coin haut gauche
             cout<< BLC  ;
    }

    //Dessin de la ligne avec comme motif le caractere en parametre (char c)
    for (int i=1; i<=width-2; i++)
        cout << c ;

    //Dessin Dernier caractere de la ligne
    switch(tl){
        //Dessiner coin bas dte
        case FIRST_LIG:
            cout << TRC  ;
            break;
        //Dessiner trait vertical
        case MEDIUM_LIG:
            cout<< VERTICAL  ;
            break;
        //Dessiner coin bas dte
        case LAST_LIG:
            cout<< BRC  ;
    }
}

//Ajouter un ensemble d'occ du meme carctere (char c) a dte
//ou a gauche d'une chaine pour avoir une chaine (char * c) de longuer fixe (int width)
void Menu :: pad(enum typePAD t, char c, char * s, int width){

    char ts[MAX_TITLE];
    switch(t){
        case PAD_RIGHT :
            for(int deb=strlen(s); deb<width; deb++)
                s[deb]=c;
            s[width]='\0';
            break;
        case PAD_LEFT :
            strcpy(ts,s);
            for(int deb=0; deb<width-strlen(s); deb++)
               {
                 s[deb]=c;
                strcat(ts, s);
                strcpy(s,ts);
               }
            break;
    }
}

void Menu :: afficherHeure(int menuWidth){
    time_t t;
    char tch[menuWidth+1];
    time(&t);


    gotoxy((SCREEN_WIDTH - menuWidth)/2, 5);
    SetColorAndBackground(COLOR_GREEN, COLOR_WHITE);
    strcpy(tch, ctime(&t)); tch[strlen(tch)-1]='\0';
    pad(PAD_RIGHT, SPACE,tch, menuWidth);
    cout << tch << endl;
}
void Menu ::  dessinerTitreMenu(char titreMenu[], int menuWidth) {
        system("cls");
        SetColorAndBackground(COLOR_BLACK,
                              COLOR_YELLOW);

        //Titre Menu
        dessinerLigne(FIRST_LIG,HORIZONTAL, (SCREEN_WIDTH - menuWidth)/2, 0, menuWidth);
        dessinerLigne(MEDIUM_LIG,SPACE, (SCREEN_WIDTH - menuWidth)/2, 1, menuWidth);
        dessinerLigne(MEDIUM_LIG,SPACE, (SCREEN_WIDTH - menuWidth)/2, 2, menuWidth);
        gotoxy((SCREEN_WIDTH -(strlen(titreMenu)+5))/2, 2);
        cout<< "Menu " <<  titreMenu << endl ;
        dessinerLigne(MEDIUM_LIG, SPACE, (SCREEN_WIDTH - menuWidth)/2, 3, menuWidth);
        dessinerLigne(LAST_LIG, HORIZONTAL, (SCREEN_WIDTH - menuWidth)/2, 4, menuWidth);
}

void Menu :: desssinerMenu(itemTitle item[], int nbItem, int menuWidth, int choixOption){
    int i ;
    itemTitle q;

    //Dessiner options menu
        SetColorAndBackground(COLOR_BLUE,COLOR_YELLOW);
        dessinerLigne(FIRST_LIG,HORIZONTAL, (SCREEN_WIDTH - (menuWidth - 1))/2, 7, menuWidth);
        for(i=0; i<nbItem; i++){
            if (choixOption == i+1)
                //Selectionner l'option
                SetColorAndBackground(COLOR_BLACK,COLOR_GREEN);
            else
                //annuler selection l'option
                SetColorAndBackground(COLOR_BLUE,COLOR_YELLOW);
            gotoxy((SCREEN_WIDTH - (menuWidth - 1))/2, i+8);
            pad(PAD_RIGHT, SPACE, item[i], menuWidth -5); pad(PAD_RIGHT, VERTICAL, item[i], menuWidth -4);
            cout <<  VERTICAL <<  i+1<< ") " <<  item[i]   ;
    }

    //Affichage option Quitter
    SetColorAndBackground(COLOR_BLUE,COLOR_YELLOW);
    if (choixOption == nbItem +1)
        SetColorAndBackground(COLOR_BLACK, COLOR_GREEN);
    gotoxy((SCREEN_WIDTH - menuWidth)/2, i+8);
    pad(PAD_RIGHT, SPACE, strcpy(q,"Quitter ce menu"), menuWidth-5); pad(PAD_RIGHT, VERTICAL, q, menuWidth -4);
    cout <<  VERTICAL <<  nbItem +1 << ") " << q ;

    SetColorAndBackground(COLOR_BLUE,COLOR_YELLOW);
    dessinerLigne(LAST_LIG, HORIZONTAL, (SCREEN_WIDTH - menuWidth)/2, i+9, menuWidth);
}

void Menu ::  afficherMessageChoix(int nbItem, int menuWidth, int choixOption){
        SetColorAndBackground(COLOR_WHITE,COLOR_BLACK);
        gotoxy((SCREEN_WIDTH - menuWidth)/2, nbItem +11);
        cout << "Choisir une option en tapant :"  ;
        gotoxy((SCREEN_WIDTH - menuWidth)/2, nbItem+12);
        cout << "\t\t\t<1.."<<  nbItem +1 << ">, <+>, <->"   ;

        gotoxy((SCREEN_WIDTH - menuWidth)/2, nbItem+14);
        cout << "Valider une option en tapant :"   ;
        gotoxy((SCREEN_WIDTH - menuWidth)/2, nbItem+15);
        cout << "\t\t\t<Enter>"  ;

        gotoxy((SCREEN_WIDTH + menuWidth -1)/2, nbItem+15);
        SetColorAndBackground(COLOR_BLUE, COLOR_YELLOW);
       cout <<  choixOption  ;
        SetColorAndBackground(COLOR_WHITE,COLOR_BLACK);
}

char Menu ::  determinerChoix(int nbItem, int * choix){
    char c;

    do
        c=getch();
    while(c != PLUS && c!= MINUS && c != ENTER && (c < ONE || c > NINE));

    if(c == PLUS  && *choix <= nbItem)
        *choix = *choix + 1;

    if(c == MINUS && *choix > 1)
        *choix = *choix - 1;

    if(c >= ONE  && c <= NINE && c - ZERO <= nbItem +1)
        *choix = c - ZERO;

    return(c);
}

void Menu ::  messageSortie(int menuWidth){
    SetColorAndBackground(COLOR_BLUE,COLOR_YELLOW);
    dessinerLigne(FIRST_LIG,HORIZONTAL, (SCREEN_WIDTH - (menuWidth - 1))/2, 2, menuWidth);
    dessinerLigne(MEDIUM_LIG,SPACE, (SCREEN_WIDTH - menuWidth)/2, 3, menuWidth);
    dessinerLigne(MEDIUM_LIG,SPACE, (SCREEN_WIDTH - menuWidth)/2, 5, menuWidth);
    dessinerLigne(MEDIUM_LIG,SPACE, (SCREEN_WIDTH - menuWidth)/2, 4, menuWidth);
    gotoxy((SCREEN_WIDTH -9)/2, 4);
    cout << "Au revoir!"  ;
    dessinerLigne(MEDIUM_LIG, SPACE, (SCREEN_WIDTH - menuWidth)/2, 5, menuWidth);
    dessinerLigne(LAST_LIG, HORIZONTAL, (SCREEN_WIDTH - menuWidth)/2, 6, menuWidth);
    SetColorAndBackground(COLOR_WHITE,COLOR_BLACK);
    cout << "\n"  ;
}
int Menu :: menu(char titreMenu[], itemTitle item[], int nbItem, int menuWidth){

    int choixOption=1;

    int carSaisie;

    if((menuWidth > MAX_TITLE || menuWidth < 0) ||
       strlen(titreMenu)>MAX_TITLE - 5)
        return (-1);

    if(nbItem > MAX_OPTIONS || nbItem < 0)
        return (-1);

    dessinerTitreMenu(titreMenu, menuWidth);
    afficherHeure(menuWidth);
    do{
        //Afficher menu avec selection de l'option
        desssinerMenu(item, nbItem, menuWidth, choixOption);
        //Afficher message de saisie
        afficherMessageChoix(nbItem, menuWidth, choixOption);
        //Determiner l'option choisie selon le caractere saisie
        //N'accepte que ('1'...9', '+', '-', <Enter>)
        carSaisie=determinerChoix(nbItem, &choixOption);

    }while(carSaisie != ENTER);
    system("cls");
    return(choixOption);
}
int Menu ::  menuGeneral(){
    itemTitle tMenu="General";
    itemTitle option[]={"Saisir date debut  ", "Saisir date fin ", "Choisir Bourse ","Choisir Trader ", "Choisir le budget" , "Lancer la simulation"};
    return(menu(tMenu, option, 6, 50));}
int Menu ::  menuBourse(){
    itemTitle tMenu="Bourse";
    itemTitle option[]={"Bourse Vecteur ",  "Bourse MultiSet ",
                        "Bourse MultiMap "};
    return(menu(tMenu, option, 3, 50));}
int Menu::menuTrader(){
    itemTitle tMenu="Trader";
    itemTitle option[]={"Trader Aleatoire ",  "Trader Moving Average ",
                        "Trader Comparaison "};
    return(menu(tMenu, option, 3, 50));
}
void Menu :: choixBourse (vector <PrixJournalier> pj, Date ddeb  ){
   int reponse ;
    do{
        Menu menu2;
        reponse=menu2.menuBourse();
        switch (reponse){
            case 1:

              {
                  BourseVecteurOptimisee b2(ddeb,pj);
                vector<PrixJournalier> historiqueAction=b2.getHistoriqueParAction("NKE");
                for(auto pj: historiqueAction)
                    {
                    cout<<pj.getNom()<<","<<pj.getDate()<<","<<pj.getPrix()<<endl;
                    }
                cout<<"***"<<endl;

                system("pause");

                break ;
              }

            case 2:

                cout << " case 2 choix bourse check ";
                break;

            case 3:

                cout << " case 3 choix bourse check ";
                break;
                    };

    }while(reponse!=4);
}

