#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<locale.h>

int genererAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void start(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n\n                         3");
    Sleep(600);
    system("cls");
    printf("\n\n                         2");
    Sleep(600);
    system("cls");
    printf("\n\n                         1");
    Sleep(600);
    system("cls");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("\n\n                       Go!!!");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    Sleep(800);
    system("cls");
}

void remplirlettre(char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char *j) {
    srand(time(NULL));
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index;

    index = genererAleatoire(0, 25);
    *a = alphabet[index];

    index = genererAleatoire(0, 25);
    *b = alphabet[index];

    index = genererAleatoire(0, 25);
    *c = alphabet[index];

    index = genererAleatoire(0, 25);
    *d = alphabet[index];

    index = genererAleatoire(0, 25);
    *e = alphabet[index];

    index = genererAleatoire(0, 25);
    *f = alphabet[index];

    index = genererAleatoire(0, 25);
    *g = alphabet[index];

    index = genererAleatoire(0, 25);
    *h = alphabet[index];

    index = genererAleatoire(0, 25);
    *i = alphabet[index];

    index = genererAleatoire(0, 25);
    *j = alphabet[index];
}

void remplirnbr(char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char *j) {
    srand(time(NULL));
    char alphabet[] = "1234567890";
    int index;

    index = genererAleatoire(0, 10);
    *a = alphabet[index];

    index = genererAleatoire(0, 10);
    *b = alphabet[index];

    index = genererAleatoire(0, 10);
    *c = alphabet[index];

    index = genererAleatoire(0, 10);
    *d = alphabet[index];

    index = genererAleatoire(0, 10);
    *e = alphabet[index];

    index = genererAleatoire(0, 10);
    *f = alphabet[index];

    index = genererAleatoire(0, 10);
    *g = alphabet[index];

    index = genererAleatoire(0, 10);
    *h = alphabet[index];

    index = genererAleatoire(0, 10);
    *i = alphabet[index];

    index = genererAleatoire(0, 10);
    *j = alphabet[index];
}

void printfbox_0(char t[] , char a , char b , char c , char d , char e , char f , char g , char h , char i ,char j){
    printf(" _____      _____      _____      _____      _____\n|    %c|    |    %c|    |    %c|    |    %c|    |    %c|\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",t[0],t[1],t[2],t[3],t[4],a,b,c,d,e);
    printf(" _____      _____      _____      _____      _____\n|    %c|    |    %c|    |    %c|    |    %C|    |    %c|\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",t[5],t[6],t[7],t[8],t[9],f,g,h,i,j);
}

void printfbox(char t[] , char go[]){
    printf(" _____      _____      _____      _____      _____\n|    %c|    |    %c|    |    %c|    |    %c|    |    %c|\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",t[0],t[1],t[2],t[3],t[4],go[0],go[1],go[2],go[3],go[4]);
    printf(" _____      _____      _____      _____      _____\n|    %c|    |    %c|    |    %c|    |    %C|    |    %c|\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",t[5],t[6],t[7],t[8],t[9],go[5],go[6],go[7],go[8],go[9]);
}

void printfboxvide(){
    printf(" _____      _____      _____      _____      _____\n|     |    |     |    |     |    |     |    |     |\n|  ?  |    |  ?  |    |  ?  |    |  ?  |    |  ?  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n");
    printf(" _____      _____      _____      _____      _____\n|     |    |     |    |     |    |     |    |     |\n|  ?  |    |  ?  |    |  ?  |    |  ?  |    |  ?  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n");
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(NULL));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int again ;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    char introd[] = "           Bienvenu au Jeu \"Memory Challenge\"   \n\n\"Memory Challenge\" est un jeu simple pour tester et améliorer la mémoire.Comment jouer ? \n\n1. Une série de 10 lettres aléatoires apparaît à    l’écran pendant quelques secondes.\n\n2. Une fois disparue, vous devez les saisir dans le bon ordre.\n\n3. Le jeu indique si chaque lettre est correcte (\"V\" pour Vrai, \"F\" pour Faux). \n\n4. À la fin, votre score sur 10 s'affiche.\n\n5. Vous pouvez rejouer ou quitter le jeu.\n\nCe jeu est idéal pour entraîner votre mémoire tout  en vous amusant !\n\n" ;
    int va = strlen(introd);
    for(int i=0;i<va;i++){
        Sleep(10);
        printf("%c",introd[i]);
    }
    char cont[] = "Appuyer sur un bouton pour continuer : ";
    int la = strlen(cont);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    for(int i=0;i<la;i++){
        Sleep(10);
        printf("%c",cont[i]);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    _getch();
    system("cls");

    do{
        system("cls");
        char a,b,c,d,e,f,g,h,i,j ;
        a = '_' ;
        b = '_' ;
        c = '_' ;
        d = '_' ;
        e = '_' ;
        f = '_' ;
        g = '_' ;
        h = '_' ;
        i = '_' ;
        j = '_' ;
        char t[20] = "????????????????????" ;
        remplirlettre(&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
        char go[10];
        go[0] = a ;
        go[1] = b ;
        go[2] = c ;
        go[3] = d ;
        go[4] = e ;
        go[5] = f ;
        go[6] = g ;
        go[7] = h ;
        go[8] = i ;
        go[9] = j ;

        char to[] = "__________" ;
        char tvide[] = "          " ;

        start();
        printfbox(tvide,go);
        Sleep(10000);
        system("cls");
        printfbox(t,to);
        char add[20] ;
        for(int i=0;i<10;i++){
            printf("\n\nbox %d : ",i+1);
            scanf("%s",&add);
            to[i] = add[0] ;
            getchar();

            if(go[i] == to[i]){
                t[i] = 'V' ;
            }else{
                t[i] = 'F' ;
            }
            system("cls");
            printfbox(t,to);
        }
        int note = 0 ;
        for(int i=0;i<10;i++){
            if(go[i] == to[i]){
                note++ ;
            }
        }
        if(note==10){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("\n         ____            __           _   \n        |  _ \\ ___ _ __ / _| ___  ___| |_ \n        | |_) / _ \\ '__| |_ / _ \\/ __| __|\n        |  __/  __/ |  |  _|  __/ (__| |_ \n        |_|   \\___|_|  |_|  \\___|\\___|\\__|");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
            printf("\n\n\n               Votre score : %d/10 \n",note);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }else{
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
            printf("\n                Votre score : %d/10 \n",note);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printfbox(tvide,go);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

        //////////////////////////////////////////////////////////////////////////////////////////

        printf("\n\nVoulez-vous rejouer ? (1 pour Oui, 0 pour Non) : \n");

        while(1) {
            printf("\nVotre choix : ");

            if(scanf("%d", &again) != 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentere '0' ou '1' \n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                while(getchar() != '\n');
                continue;
            }

            if(again == 0 || again == 1) {
                break;
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentere '0' ou '1' \n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        getchar();
    }while(again == 1);

    Sleep(700);
    char mad[] = "\n\n                   Ooooookey\n\n";
        int b = strlen(mad);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
        for(int i=0;i<b;i++){
            Sleep(25);
            printf("%c",mad[i]);
        }
    Sleep(700);


    system("cls");


    for(int a=0;a<4;a++){

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\n\n               made by Ayanokoji :)");
        system("cls");
    }

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        char made[] = "\n\n              made by Ayanokoji  ^_^                   \n\n";
        int by = strlen(made);
        for(int i=0;i<by;i++){
            Sleep(20);
            printf("%c",made[i]);
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        Sleep(1000);

    return 0;
}
