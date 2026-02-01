#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
//    int grille[9][9] = {{1,2,3,4,5,6,7,8,9},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};

int estValide(int grille[9][9], int ligne, int colonne, int chiffre) {
    // Verifier la ligne
    for (int i = 0; i < 9; i++) {
        if (grille[ligne][i] == chiffre)
            return 0;
    }
    // Verifier la colonne
    for (int i = 0; i < 9; i++) {
        if (grille[i][colonne] == chiffre)
            return 0;
    }
    // Verifier 3x3
    int debutLigne = (ligne / 3) * 3;
    int debutColonne = (colonne / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grille[debutLigne + i][debutColonne + j] == chiffre)
                return 0;
        }
    }
    return 1;
}

int resoudreSudoku(int grille[9][9]) {
    for (int ligne = 0; ligne < 9; ligne++) {
        for (int colonne = 0; colonne < 9; colonne++) {
            if (grille[ligne][colonne] == 0) { // l9a case vide
                for (int chiffre = 1; chiffre <= 9; chiffre++) {
                    if (estValide(grille, ligne, colonne, chiffre)) {
                        grille[ligne][colonne] = chiffre;
                        if (resoudreSudoku(grille)){
                            return 1; // Resolu
                        }
                        grille[ligne][colonne] = 0;
                    }
                }
                return 0; // Pas de solution
            }
        }
    }
    //return 1; // Resolu
}

// Fct afficher la grille
void afficherGrille(int grille[9][9]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("+-------+-------+-------+");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            Sleep(20);
            if (j==0){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("| ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            if (grille[i][j] == 0){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf(". ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }else{
                printf("%d ", grille[i][j]);
            }
            if (j==2||j==5){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("| ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            if (j==8){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("| ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        printf("\n");
        if (i==2||i==5){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("+");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("-------+-------+-------");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("+");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n");
        }
        if (i==8){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("+-------+-------+-------+");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n");
        }
    }
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char v[] = "\n       les regles generale du Sudoku : \n\n\n1. Remplire grille 9x9 avec chiffres 1-9.\n\n2. Chaque ligne, colonne et region 3x3 doit avoir    chiffre unique.\n\n3. Pas de doublons.\n\n4. Cases pre-remplies non modifiables.\n\n--> Gagner : grille complete et sans erreurs.\n\n\n";
    int lo = strlen(v);
    for(int i=0;i<lo;i++){
        Sleep(10);
        printf("%c",v[i]);
    }
    char o ;
    char cont[] = "Appuyer sur un bouton pour continuer : ";
    int la = strlen(cont);
    for(int i=0;i<la;i++){
        Sleep(10);
        printf("%c",cont[i]);
    }
    _getch();
    system("cls");

    char intro[] = "\nBonjour ! \n\nCe progamme va vous aider pour resoudre les sudoku.\n\n-> Entrer les valeure 1-9 suivant les coordonnees.\n\n-> Entrer 0 pour les case vide.\n\n";
    int no = strlen(intro);
    for(int i=0;i<no;i++){
        Sleep(10);
        printf("%c",intro[i]);
    }
    int again;
    int grille[9][9] = {{1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
    do{

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                while(1) {
                    printf("t[%d][%d] = ",i,j);
                    if(scanf("%d",&grille[i][j]) != 1) {

                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf("entre un nbr entre '0' et '9' : \n");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


                        while(getchar() != '\n');
                            continue;
                    }
                    if(grille[i][j]>=0&&grille[i][j]<=9){
                        break;
                    } else {

                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf("entre un nbr entre '0' et '9' : \n");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    }

                }
            }
        }



        printf("\nGrille initiale :\n\n");
        afficherGrille(grille);

        if (resoudreSudoku(grille)) {
            printf("\nSolution trouvee :\n");
            afficherGrille(grille);
        } else {
            printf("\nAucune solution n'a ete trouvee.\n");
        }

        printf("\nVoulez-vous rejouer ? (1 pour Oui, 0 pour Non) : \n");

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

    }while(again == 1);

    Sleep(700);
    char mad[] = "\n\n             Ooooookey\n\n";
        int b = strlen(mad);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
        for(int i=0;i<b;i++){
            Sleep(25);
            printf("%c",mad[i]);
        }
    Sleep(700);


    system("cls");


    for(int a=0;a<3;a++){

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
        char made[] = "\n\n               made by Ayanokoji :)                   \n\n";
        int by = strlen(made);
        for(int i=0;i<by;i++){
            Sleep(20);
            printf("%c",made[i]);
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return 0;
}

