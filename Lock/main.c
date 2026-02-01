#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <math.h>

int genererAleatoire(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "");
    int again;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");
    char v[] = "\n             Bienvenue dans notre jeu !\n\n\n\n\nMa3rftche chno nktb   '_' \n\n\n\n\n\n";
    int lo = strlen(v);
    for(int i=0;i<lo;i++){
        Sleep(30);
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

    do{
        system("cls");
        int min=0, max=9 ;
        int chiffre ;

        while(1) {
            printf("Entrer le nbr des chiffre : ");

            if(scanf("%d", &chiffre) != 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer un nbr positif.\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                while(getchar() != '\n');
                continue;
            }

            if(chiffre>0) {
                break;
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer un nbr positif.\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        getchar();
        system("cls");
        char the_code[chiffre] ;
        for(int i=0;i<chiffre;i++){
            the_code[i] = genererAleatoire(min,max) + '0';
        }
        char test[50];
        int win=0 ;
        int score = 0 ;
        int yes_yes , yes_no ;
        do{
            yes_no = 0;
            yes_yes = 0;
            score++ ;
            system("cls");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\n\n     .--------.\n    / .------. \\\n   / /        \\ \\\n   | |        | |\n  _| |________| |_\n.' |_|        |_| '.\n'._____ ____ _____.'\n|     .'____'.     |\n'.__.'.'    '.'.__.'\n'.__  | ???? |  __.'\n|   '.'.____.'.'   |\n'.____'.____.'____.'\n'.________________.'\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\nEntrer votre code : ");
            gets(test);
            while(strlen(test)!=chiffre){
                printf("\nVous avez dit %d chiffres !\n",chiffre);
                printf("\nEntrer votre code : ");
                gets(test);
            }
            /*
            for(int i=0;i<chiffre;i++){
                for(int j=0;j<chiffre;j++){
                    if(){
                        continue;
                    }
                    if(test[i]==the_code[j]){
                        yes_no++ ;
                    }
                }
            }
            */
            for(int i=0;i<chiffre;i++){
                if(test[i]==the_code[i]){
                    yes_yes++ ;
                }
            }
            if(yes_yes==chiffre){
                break;
            }
            printf("\n%d correct.\n",yes_yes);

            char co[] = "\nOK ?";
            int a = strlen(co);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
            for(int i=0;i<a;i++){
                Sleep(10);
                printf("%c",co[i]);
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            _getch();
        }while(win==0);
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("     .--------.\n    / .------. \\\n   / /        \\ \\\n   | |        | |\n   | |        | |\n   |_|        | |\n  ____________| |_\n.'  _         |_| '.\n'._____ ____ _____.'\n|     .'____'.     |\n'.__.'.'    '.'.__.'\n'.__  | OPEN |  __.'\n|   '.'.____.'.'   |\n'.____'.____.'____.'\n'.________________.'\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nYouuuuu Win !!!!            ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
        printf("Your score : %d\n",score);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("The code is : ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        for(int i=0;i<chiffre;i++){
            printf("%c",the_code[i]);
            Sleep(20);
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        /////////////////////////////////////////////////////////////////////////////////////

        printf("\n\nVoulez-vous rejouer ? (1 pour Oui, 0 pour Non) : \n\n");

        while(1) {
            printf("Votre choix : ");

            if(scanf("%d", &again) != 1) {
                system("cls");
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("     .--------.\n    / .------. \\\n   / /        \\ \\\n   | |        | |\n   | |        | |\n   |_|        | |\n  ____________| |_\n.'  _         |_| '.\n'._____ ____ _____.'\n|     .'____'.     |\n'.__.'.'    '.'.__.'\n'.__  | OPEN |  __.'\n|   '.'.____.'.'   |\n'.____'.____.'____.'\n'.________________.'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("\nYouuuuu Win !!!!\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("The code is : ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                for(int i=0;i<chiffre;i++){
                    printf("%c",the_code[i]);
                    Sleep(50);
                }
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("\n\nVoulez-vous rejouer ? (1 pour Oui, 0 pour Non) : ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer '0' ou '1'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                while(getchar() != '\n');
                continue;
            }

            if(again == 0 || again == 1) {
                break;
            } else {
                system("cls");
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("     .--------.\n    / .------. \\\n   / /        \\ \\\n   | |        | |\n   | |        | |\n   |_|        | |\n  ____________| |_\n.'  _         |_| '.\n'._____ ____ _____.'\n|     .'____'.     |\n'.__.'.'    '.'.__.'\n'.__  | OPEN |  __.'\n|   '.'.____.'.'   |\n'.____'.____.'____.'\n'.________________.'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("\nYouuuuu Win !!!!\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("The code is : ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                for(int i=0;i<chiffre;i++){
                    printf("%c",the_code[i]);
                    Sleep(50);
                }
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("\n\nVoulez-vous rejouer ? (1 pour Oui, 0 pour Non) : ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer '0' ou '1'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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




