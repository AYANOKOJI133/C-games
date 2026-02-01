#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>


int genererAleatoire(int min, int max){
    return (rand() % (max - min + 1)) + min;
}


int check_winner(char ta[]) {

    for (int i = 0; i < 9; i += 3) {
        if (ta[i] == ta[i+1] && ta[i+1] == ta[i+2]) return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (ta[i] == ta[i+3] && ta[i+3] == ta[i+6]) return 1;
    }

    if ((ta[0] == ta[4] && ta[4] == ta[8]) || (ta[2] == ta[4] && ta[4] == ta[6])) return 1;

    return 0;
}


int main() {
    setlocale(LC_ALL, "");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    int boot;
    int chois ,again ,adil=0;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");
    char v[] = "       Introduction au Jeu de Tic-Tac-Toe ! \n\nBienvenue dans le monde du \" Tic-Tac-Toe \"\nLe but est simple : être le premier à aligner trois symboles identiques horizontalement, verticalement  ou en diagonale sur une grille de 3x3. \n\n--> Règles du jeu : \n\n1. Deux joueurs participent au jeu : l'un joue avec \"X\" et l'autre avec \"O\".  \n\n2. Les joueurs jouent chacun à leur tour en plaçant leur symbole dans une case vide de la grille.   \n\n3. Le jeu se termine lorsqu'un joueur aligne trois  symboles ou lorsque toutes les cases sont remplies  sans vainqueur, ce qui entraîne un match nul. \n\nPrêt à relever le défi ?\n\n";
    int lo = strlen(v);
    for(int i=0;i<lo;i++){
        Sleep(10);
        printf("%c",v[i]);
    }
    char o ;
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
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        char con[] = "entrer 1 pour jouer avec ton ami.\nentrer 2 pour jouer avec un boot.\n\n";
        int laa = strlen(con);
        for(int i=0;i<laa;i++){
            Sleep(10);
            printf("%c",con[i]);
        }

        while(1) {
            printf("Votre choix : ");

            if(scanf("%d", &chois) != 1) {

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("entrer '1' ou '2' \n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


                while(getchar() != '\n');
                    continue;
            }

            if(chois == 1 || chois == 2) {
                break;
            } else {

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("entrer '1' ou '2' \n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
        }
        system("cls");

        ////////////
        if(chois==2){
            char cona[] = "Choisissez la difficulté :\n\nentrer 1 pour jouer avec un boot facile.\nentrer 2 pour jouer avec un boot difficile.\nentrer 3 pour jouer avec un boot impossible.\n\n";
            int laaa = strlen(cona);
            for(int i=0;i<laaa;i++){
                Sleep(10);
                printf("%c",cona[i]);
            }

            while(1) {
                printf("Votre choix : ");

                if(scanf("%d", &boot) != 1) {

                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("entrer '1' ou '2' ou '3' \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


                    while(getchar() != '\n');
                        continue;
                }

                if(boot == 1 || boot == 2 || boot == 3) {
                    break;
                } else {

                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("entrer '1' ou '2' ou '3' \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                }
            }
        }

        if(chois==1){
            char ta[9] = {'1','2','3','4','5','6','7','8','9'};
            int x;
            int turn = 0;
            char player;
            int notePlayer1=0 , notePlayer2=0 , rond=0;


            while(1) {
                printf("entrer le nbr de ronds : ");

                if (scanf("%d", &rond) != 1) {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                    printf("entrer un nbr supérieur à 0.\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    while (getchar() != '\n');
                    continue;
                }

                if (rond > 0) {
                    break;
                } else {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                    printf("entrer un nbr supérieur à 0.\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }

            for(int i=0;i<rond;i++){

                while (1) {

                    player = turn == 0 ? 'X' : 'O';
                    //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                    //       ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);
                    /////////////////////////////////
                    system("cls");
                    printf("\n");
                    for(int i=0;i<2;i++){
                        if(ta[i]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[i]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("|");
                        }else if(ta[i]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[i]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("|");
                        }else{
                            printf(" %c |",ta[i]);
                        }
                    }

                    if(ta[2]=='X'){
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf(" %c ",ta[2]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("\n --+---+--\n");
                    }else if(ta[2]=='O'){
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf(" %c ",ta[2]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("\n --+---+--\n");
                    }else{
                        printf(" %c \n --+---+--\n",ta[2]);
                    }

                    for(int i=3;i<5;i++){
                        if(ta[i]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[i]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("|");
                        }else if(ta[i]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[i]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("|");
                        }else{
                            printf(" %c |",ta[i]);
                        }
                    }

                    if(ta[5]=='X'){
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf(" %c ",ta[5]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("\n --+---+--\n");
                    }else if(ta[5]=='O'){
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf(" %c ",ta[5]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("\n --+---+--\n");
                    }else{
                        printf(" %c \n --+---+--\n",ta[5]);
                    }

                    for(int i=6;i<8;i++){
                        if(ta[i]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[i]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("|");
                        }else if(ta[i]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[i]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("|");
                        }else{
                            printf(" %c |",ta[i]);
                        }
                    }

                    if(ta[8]=='X'){
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf(" %c \n",ta[8]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }else if(ta[8]=='O'){
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf(" %c \n",ta[8]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }else{
                        printf(" %c \n",ta[8]);
                    }

                    /////////////////////////////////
                    while(1) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("le tour pour joueur %d (%c)\nChoisissez un numero : ", turn + 1, player);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        if (scanf("%d", &x) != 1) {
                            printf("Choix invalide. Khas dkhel chi ra9m mn 1 tal 9.\n");

                            while (getchar() != '\n');
                            continue;
                        }

                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        if (x < 1 || x > 9 || ta[x - 1] == 'X' || ta[x - 1] == 'O') {
                            printf("Choix invalide. Essayez encore.\n");
                            continue;
                        } else {
                            break;
                        }
                    }

                    if (x < 1 || x > 9 || ta[x-1] == 'X' || ta[x-1] == 'O') {
                        printf("Choix invalide. Essayez encore.\n");
                        continue;
                    }

                    ta[x-1] = player;

                    if (check_winner(ta)) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                        //       ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        printf("player %d win\n\n", turn+1);
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        for (int i = 0; i < 9; i++) {
                        ta[i] = '1' + i;
                        }
                        if(player=='X'){
                            notePlayer1++ ;
                        }

                        if(player=='O'){
                            notePlayer2++ ;
                        }

                        Sleep(1500);
                        break;

                    }

                    int draw = 1;
                    for (int i = 0; i < 9; i++) {
                        if (ta[i] != 'X' && ta[i] != 'O') {
                            draw = 0;
                            break;
                        }
                    }
                    if (draw) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                        //       ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf("Match nul!\n\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        for (int i = 0; i < 9; i++) {
                        ta[i] = '1' + i;
                        }
                        Sleep(1500);
                        break;
                    }

                    turn = 1 - turn;
                }
            }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        printf("joueur 1 a %d pts \n",notePlayer1);
        printf("joueur 2 a %d pts \n",notePlayer2);

        if(notePlayer1<notePlayer2){
            printf("player 2 win \n");
            printf("------------------------------------ \n\n");

        }else if(notePlayer1==notePlayer2){
            printf("match null \n");
            printf("------------------------------------ \n\n");

        }else{
            printf("player 1 win \n");
            printf("------------------------------------ \n\n");

        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        }


        if(boot==1){
            int rond ,notePlayer=0 ,noteBoot=0 ;


            while(1) {
                printf("entrer le nbr de ronds : ");

                if (scanf("%d", &rond) != 1) {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                    printf("entrer un nbr supérieur à 0.\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    while (getchar() != '\n');
                    continue;
                }

                if (rond > 0) {
                    break;
                } else {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                    printf("entrer un nbr supérieur à 0.\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }

            for(int i=0;i<rond;i++){
                char ta[9] = {'1','2','3','4','5','6','7','8','9'};
                int x;
                char player;

                while (1) {

                    //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                    //       ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                    ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                    while(1) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("le tour pour vous\nChoisissez un numero : ");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        if (scanf("%d", &x) != 1) {
                            printf("Choix invalide. Khas dkhel chi ra9m mn 1 tal 9.\n");

                            while (getchar() != '\n');
                            continue;
                        }

                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        if (x < 1 || x > 9 || ta[x - 1] == 'X' || ta[x - 1] == 'O') {
                            printf("Choix invalide. Essayez encore.\n");
                            continue;
                        } else {
                            break;
                        }
                    }

                    ta[x-1] = 'X';

                    if (check_winner(ta)) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        printf("you win\n\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        notePlayer++ ;
                        Sleep(1500);
                        break;
                    }

                    int draw = 1;
                    for (int i = 0; i < 9; i++) {
                        if (ta[i] != 'X' && ta[i] != 'O') {
                            draw = 0;
                            break;
                        }
                    }
                    if (draw) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf("Match nul!\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        Sleep(1500);
                        break;
                    }

                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    printf("le tour pour le boot : \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    int min = 1, max = 9;
                    x = genererAleatoire(min,max);

                    while(ta[x-1] == 'X' || ta[x-1] == 'O') {
                        x = genererAleatoire(min,max);
                    }

                    ta[x-1] = 'O';

                    if (check_winner(ta)) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf("you lose\n\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        noteBoot++ ;
                        Sleep(1500);
                        break;
                    }

                    draw = 1;
                    for (int i = 0; i < 9; i++) {
                        if (ta[i] != 'X' && ta[i] != 'O') {
                            draw = 0;

                            break;
                        }
                    }
                    if (draw) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        printf("Match nul!\n");
                        Beep(750, 300);
                        printf("------------------------------------ \n\n");
                        Sleep(1500);
                        break;
                    }

                }
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        printf("le boot a %d pts \n",noteBoot);
        printf("vous avez %d pts \n",notePlayer);
        if(noteBoot<notePlayer){

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("you win \n");

            printf("------------------------------------ \n\n");
        }else if(noteBoot==notePlayer){

            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("match null \n");

            printf("------------------------------------ \n\n");
        }else{

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("you lose \n");

            printf("------------------------------------ \n\n");
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        }


        if(boot==2){
            int rond ,notePlayer=0 ,noteBoot=0 ;


            while(1) {
                printf("entrer le nbr de ronds : ");

                if (scanf("%d", &rond) != 1) {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                    printf("entrer un nbr supérieur à 0.\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    while (getchar() != '\n');
                    continue;
                }

                if (rond > 0) {
                    break;
                } else {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                    printf("entrer un nbr supérieur à 0.\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }

            for(int i=0;i<rond;i++){
                char ta[9] = {'1','2','3','4','5','6','7','8','9'};
                int x;
                char player;

                while (1) {

                    //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                      //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                    ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                    while(1) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("le tour pour vous\nChoisissez un numero : ");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        if (scanf("%d", &x) != 1) {
                            printf("Choix invalide. Khas dkhel chi ra9m mn 1 tal 9.\n");

                            while (getchar() != '\n');
                            continue;
                        }

                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        if (x < 1 || x > 9 || ta[x - 1] == 'X' || ta[x - 1] == 'O') {
                            printf("Choix invalide. Essayez encore.\n");
                            continue;
                        } else {
                            break;
                        }
                    }

                    if (x < 1 || x > 9 || ta[x-1] == 'X' || ta[x-1] == 'O') {
                        printf("Choix invalide. Essayez encore.\n");
                        continue;
                    }

                    ta[x-1] = 'X';

                    if (check_winner(ta)) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                        //       ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        printf("you win\n\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        notePlayer++ ;
                        Sleep(1500);
                        break;
                    }

                    int draw = 1;
                    for (int i = 0; i < 9; i++) {
                        if (ta[i] != 'X' && ta[i] != 'O') {
                            draw = 0;
                            break;
                        }
                    }
                    if (draw) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf("Match nul!\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        Sleep(1500);
                        break;
                    }

                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    printf("le tour pour le boot : \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    int min = 1, max = 9;
                    x=0 ;

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == ta[i+1]){
                                if (ta[i+2] != 'X' && ta[i+2] != 'O'){
                                    x = i+3;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == ta[i+2]){
                                if (ta[i+1] != 'X' && ta[i+1] != 'O'){
                                    x = i+2;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i+1] == ta[i+2]){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == ta[i+3]){
                                if (ta[i+6] != 'X' && ta[i+6] != 'O'){
                                    x = i+7;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == ta[i+6]){
                                if (ta[i+3] != 'X' && ta[i+3] != 'O'){
                                    x = i+4;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i+6] == ta[i+3]){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        if (ta[0] == ta[4]){
                            if (ta[8] != 'X' && ta[8] != 'O'){
                                x = 9;
                            }
                        }

                        if (ta[0] == ta[8]){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == ta[8]){
                            if (ta[0] != 'X' && ta[0] != 'O'){
                                x = 1;
                            }
                        }

                        if (ta[2] == ta[4]){
                            if (ta[6] != 'X' && ta[6] != 'O'){
                                x = 7;
                            }
                        }

                        if (ta[2] == ta[6]){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == ta[6]){
                            if (ta[2] != 'X' && ta[2] != 'O'){
                                x = 3;
                            }
                        }


                        // baraka 3lk gha hna

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == 'O' && ta[i+1] == 'O'){
                                if (ta[i+2] != 'X' && ta[i+2] != 'O'){
                                    x = i+3;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == 'O' && ta[i+2] == 'O'){
                                if (ta[i+1] != 'X' && ta[i+1] != 'O'){
                                    x = i+2;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i+1] == 'O' && ta[i+2] == 'O'){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == 'O' && ta[i+3] == 'O'){
                                if (ta[i+6] != 'X' && ta[i+6] != 'O'){
                                    x = i+7;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == 'O' && ta[i+6] == 'O'){
                                if (ta[i+3] != 'X' && ta[i+3] != 'O'){
                                    x = i+4;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i+6] == 'O' && ta[i+3] == 'O'){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        if (ta[0] == 'O' && ta[4] == 'O'){
                            if (ta[8] != 'X' && ta[8] != 'O'){
                                x = 9;
                            }
                        }

                        if (ta[0] == 'O' && ta[8] == 'O'){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == 'O' && ta[8] == 'O'){
                            if (ta[0] != 'X' && ta[0] != 'O'){
                                x = 1;
                            }
                        }

                        if (ta[2] == 'O' && ta[4] == 'O'){
                            if (ta[6] != 'X' && ta[6] != 'O'){
                                x = 7;
                            }
                        }

                        if (ta[2] == 'O' && ta[6] == 'O'){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == 'O' && ta[6] == 'O'){
                            if (ta[2] != 'X' && ta[2] != 'O'){
                                x = 3;
                            }
                        }


                        if(x==0){
                        x = genererAleatoire(min,max);
                        }


                    while(ta[x-1] == 'X' || ta[x-1] == 'O') {
                        x=0 ;
                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == ta[i+1]){
                                if (ta[i+2] != 'X' && ta[i+2] != 'O'){
                                    x = i+3;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == ta[i+2]){
                                if (ta[i+1] != 'X' && ta[i+1] != 'O'){
                                    x = i+2;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i+1] == ta[i+2]){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == ta[i+3]){
                                if (ta[i+6] != 'X' && ta[i+6] != 'O'){
                                    x = i+7;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == ta[i+6]){
                                if (ta[i+3] != 'X' && ta[i+3] != 'O'){
                                    x = i+4;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i+6] == ta[i+3]){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        if (ta[0] == ta[4]){
                            if (ta[8] != 'X' && ta[8] != 'O'){
                                x = 9;
                            }
                        }

                        if (ta[0] == ta[8]){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == ta[8]){
                            if (ta[0] != 'X' && ta[0] != 'O'){
                                x = 1;
                            }
                        }

                        if (ta[2] == ta[4]){
                            if (ta[6] != 'X' && ta[6] != 'O'){
                                x = 7;
                            }
                        }

                        if (ta[2] == ta[6]){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == ta[6]){
                            if (ta[2] != 'X' && ta[2] != 'O'){
                                x = 3;
                            }
                        }


                        // baraka 3lk gha hna

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == 'O' && ta[i+1] == 'O'){
                                if (ta[i+2] != 'X' && ta[i+2] != 'O'){
                                    x = i+3;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == 'O' && ta[i+2] == 'O'){
                                if (ta[i+1] != 'X' && ta[i+1] != 'O'){
                                    x = i+2;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i+1] == 'O' && ta[i+2] == 'O'){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == 'O' && ta[i+3] == 'O'){
                                if (ta[i+6] != 'X' && ta[i+6] != 'O'){
                                    x = i+7;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == 'O' && ta[i+6] == 'O'){
                                if (ta[i+3] != 'X' && ta[i+3] != 'O'){
                                    x = i+4;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i+6] == 'O' && ta[i+3] == 'O'){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        if (ta[0] == 'O' && ta[4] == 'O'){
                            if (ta[8] != 'X' && ta[8] != 'O'){
                                x = 9;
                            }
                        }

                        if (ta[0] == 'O' && ta[8] == 'O'){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == 'O' && ta[8] == 'O'){
                            if (ta[0] != 'X' && ta[0] != 'O'){
                                x = 1;
                            }
                        }

                        if (ta[2] == 'O' && ta[4] == 'O'){
                            if (ta[6] != 'X' && ta[6] != 'O'){
                                x = 7;
                            }
                        }

                        if (ta[2] == 'O' && ta[6] == 'O'){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == 'O' && ta[6] == 'O'){
                            if (ta[2] != 'X' && ta[2] != 'O'){
                                x = 3;
                            }
                        }


                        if(x==0){
                        x = genererAleatoire(min,max);
                        }
                    }

                    ta[x-1] = 'O';

                    if (check_winner(ta)) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf("you lose\n\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        noteBoot++ ;
                        Sleep(1500);
                        break;
                    }

                    draw = 1;
                    for (int i = 0; i < 9; i++) {
                        if (ta[i] != 'X' && ta[i] != 'O') {
                            draw = 0;
                            break;
                        }
                    }
                    if (draw) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf("Match nul!\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");

                        Sleep(1500);
                        break;
                    }

                }
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        printf("le boot a %d pts \n",noteBoot);
        printf("vous avez %d pts \n",notePlayer);
        if(noteBoot<notePlayer){

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("you win \n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            printf("------------------------------------ \n\n");
        }else if(noteBoot==notePlayer){

            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("match null \n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            printf("------------------------------------ \n\n");
        }else{

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("you lose \n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            printf("------------------------------------ \n\n");
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        }


        if(boot==3){
            int rond ,notePlayer=0 ,noteBoot=0 ;


            while(1) {
                printf("entrer le nbr de ronds : ");

                if (scanf("%d", &rond) != 1) {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                    printf("entrer un nbr supérieur à 0.\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    while (getchar() != '\n');
                    continue;
                }

                if (rond > 0) {
                    break;
                } else {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                    printf("entrer un nbr supérieur à 0.\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }

            for(int i=0;i<rond;i++){
                char ta[9] = {'1','2','3','4','5','6','7','8','9'};
                int x;
                char player;

                while (1) {
                    adil++;

                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    printf("le tour pour le boot : \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    int min = 1, max = 9;
                    x=0 ;

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == ta[i+1]){
                                if (ta[i+2] != 'X' && ta[i+2] != 'O'){
                                    x = i+3;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == ta[i+2]){
                                if (ta[i+1] != 'X' && ta[i+1] != 'O'){
                                    x = i+2;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i+1] == ta[i+2]){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == ta[i+3]){
                                if (ta[i+6] != 'X' && ta[i+6] != 'O'){
                                    x = i+7;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == ta[i+6]){
                                if (ta[i+3] != 'X' && ta[i+3] != 'O'){
                                    x = i+4;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i+6] == ta[i+3]){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        if (ta[0] == ta[4]){
                            if (ta[8] != 'X' && ta[8] != 'O'){
                                x = 9;
                            }
                        }

                        if (ta[0] == ta[8]){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == ta[8]){
                            if (ta[0] != 'X' && ta[0] != 'O'){
                                x = 1;
                            }
                        }

                        if (ta[2] == ta[4]){
                            if (ta[6] != 'X' && ta[6] != 'O'){
                                x = 7;
                            }
                        }

                        if (ta[2] == ta[6]){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == ta[6]){
                            if (ta[2] != 'X' && ta[2] != 'O'){
                                x = 3;
                            }
                        }

                        // baraka 3lk gha hna

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == 'O' && ta[i+1] == 'O'){
                                if (ta[i+2] != 'X' && ta[i+2] != 'O'){
                                    x = i+3;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i] == 'O' && ta[i+2] == 'O'){
                                if (ta[i+1] != 'X' && ta[i+1] != 'O'){
                                    x = i+2;
                                }
                            }
                        }

                        for (int i = 0; i < 9; i += 3) {
                            if (ta[i+1] == 'O' && ta[i+2] == 'O'){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == 'O' && ta[i+3] == 'O'){
                                if (ta[i+6] != 'X' && ta[i+6] != 'O'){
                                    x = i+7;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i] == 'O' && ta[i+6] == 'O'){
                                if (ta[i+3] != 'X' && ta[i+3] != 'O'){
                                    x = i+4;
                                }
                            }
                        }

                        for (int i = 0; i < 3; i++) {
                            if (ta[i+6] == 'O' && ta[i+3] == 'O'){
                                if (ta[i] != 'X' && ta[i] != 'O'){
                                    x = i+1;
                                }
                            }
                        }

                        if (ta[0] == 'O' && ta[4] == 'O'){
                            if (ta[8] != 'X' && ta[8] != 'O'){
                                x = 9;
                            }
                        }

                        if (ta[0] == 'O' && ta[8] == 'O'){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == 'O' && ta[8] == 'O'){
                            if (ta[0] != 'X' && ta[0] != 'O'){
                                x = 1;
                            }
                        }

                        if (ta[2] == 'O' && ta[4] == 'O'){
                            if (ta[6] != 'X' && ta[6] != 'O'){
                                x = 7;
                            }
                        }

                        if (ta[2] == 'O' && ta[6] == 'O'){
                            if (ta[4] != 'X' && ta[4] != 'O'){
                                x = 5;
                            }
                        }

                        if (ta[4] == 'O' && ta[6] == 'O'){
                            if (ta[2] != 'X' && ta[2] != 'O'){
                                x = 3;
                            }
                        }

                        if(x==0){

                            if(ta[0] != 'X' && ta[0] != 'O'){
                                x = 1 ;
                            }

                            if(ta[2] == 'X' && adil==2 || ta[6] == 'X' && adil==2){
                                x = 9 ;
                            }

                            if(ta[1] == 'X' && adil==2 || ta[3] == 'X' && adil==2 || ta[5] == 'X' && adil==2 || ta[7] == 'X' && adil==2){
                                x = 5 ;
                            }

                            if(ta[4] == 'X' && adil == 2){
                                x = 9 ;
                            }

                            if(ta[3] == 'X' && ta[8] == 'X' && adil == 3){
                                x = 2 ;
                            }

                            if(ta[1] == 'X' && ta[8] == 'X' && adil == 3){
                                x = 4 ;
                            }

                            if(ta[8] == 'X' && adil == 2){
                                x = 7;
                            }

                            if(ta[8] == 'X' && ta[3] == 'X' && ta[6] == 'O' && adil == 3){
                                x = 3;
                            }

                            if(ta[2] == 'X' && ta[3] == 'X' && ta[7] == 'X' && ta[8] == 'X' && adil == 5){
                                x = 2;
                            }

                            if(ta[1] == 'X' && ta[5] == 'X' && ta[6] == 'X' && ta[8] == 'X' && adil == 5){
                                x = 4;
                            }


                        }


                    ta[x-1] = 'O';

                    if (check_winner(ta)) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf("you lose\n\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        noteBoot++ ;
                        Sleep(1500);
                        break;
                    }

                    int draw = 1;
                    for (int i = 0; i < 9; i++) {
                        if (ta[i] != 'X' && ta[i] != 'O') {
                            draw = 0;
                            break;
                        }
                    }
                    if (draw) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf("Match nul!\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");

                        Sleep(1500);
                        break;
                    }

                    //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                      //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                    ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                    while(1) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("le tour pour vous\nChoisissez un numero : ");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        if (scanf("%d", &x) != 1) {
                            printf("Choix invalide. Khas dkhel chi ra9m mn 1 tal 9.\n");

                            while (getchar() != '\n');
                            continue;
                        }

                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        if (x < 1 || x > 9 || ta[x - 1] == 'X' || ta[x - 1] == 'O') {
                            printf("Choix invalide. Essayez encore.\n");
                            continue;
                        } else {
                            break;
                        }
                    }

                    ta[x-1] = 'X';

                    if (check_winner(ta)) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        printf("you win\n\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");
                        notePlayer++ ;

                        Sleep(1500);
                        break;
                    }

                    draw = 1;
                    for (int i = 0; i < 9; i++) {
                        if (ta[i] != 'X' && ta[i] != 'O') {
                            draw = 0;
                            break;
                        }
                    }
                    if (draw) {
                        //printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",
                          //     ta[0], ta[1], ta[2], ta[3], ta[4], ta[5], ta[6], ta[7], ta[8]);

                        ////////////////////////////////////
                        system("cls");
                        printf("\n");
                        for(int i=0;i<2;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[2]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[2]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[2]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[2]);
                        }

                        for(int i=3;i<5;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[5]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else if(ta[5]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c ",ta[5]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("\n --+---+--\n");
                        }else{
                            printf(" %c \n --+---+--\n",ta[5]);
                        }

                        for(int i=6;i<8;i++){
                            if(ta[i]=='X'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else if(ta[i]=='O'){
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                printf(" %c ",ta[i]);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                printf("|");
                            }else{
                                printf(" %c |",ta[i]);
                            }
                        }

                        if(ta[8]=='X'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else if(ta[8]=='O'){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                            printf(" %c \n",ta[8]);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }else{
                            printf(" %c \n",ta[8]);
                        }
                        ////////////////////////////////////
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf("Match nul!\n");
                        Beep(750, 300);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        printf("------------------------------------ \n\n");

                        Sleep(1500);
                        break;
                    }


                }
                adil = 0;
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        printf("le boot a %d pts \n",noteBoot);
        printf("vous avez %d pts \n",notePlayer);
        if(noteBoot<notePlayer){

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("you win \n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            printf("------------------------------------ \n\n");
        }else if(noteBoot==notePlayer){

            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("match null \n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            printf("------------------------------------ \n\n");
        }else{

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("you lose \n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            printf("------------------------------------ \n\n");
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        }


        printf("\nVoulez-vous rejouer ? (1 pour Oui, 0 pour Non) : \n");

        while(1) {
            printf("Votre choix : ");

            if(scanf("%d", &again) != 1) {
                printf("ra glna khas dkhel chi ra9m ola '0' ola '1'\n");

                while(getchar() != '\n');
                continue;
            }

            if(again == 0 || again == 1) {
                break;
            } else {
                printf("ra glna khas dkhel '0' ola '1'\n");
            }
        }

    }while(again == 1);

    Sleep(700);
    char mad[] = "\n\n                  Ooooookey           \n\n";
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
    char made[] = "\n\n               made by Ayanokoji  ^_^          \n\n";
    int by = strlen(made);
    for(int i=0;i<by;i++){
        Sleep(20);
        printf("%c",made[i]);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    Sleep(1000);

    return 0;
}


