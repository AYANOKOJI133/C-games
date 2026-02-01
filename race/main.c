#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<locale.h>

int genererAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/*
printf("\n"
           "                                                    \n"
           " O                                                  \n"
           "/|\\                                                 \n"
           "/ \\                                                 \n"
           "                                                    \n");
*/

void dice(int nbr1 , int nbr2 , int tour){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int a,b;
    for(int i=0;i<10;i++){
        Sleep(10);
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        fram(nbr1);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        fram(nbr2);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        a = genererAleatoire(1,6);
        b = genererAleatoire(1,6);
        if(tour==1){
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n+---+  +---+\n| %d |  | %d |\n+---+  +---+",a,b);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        if(tour==2){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("\n+---+  +---+\n| %d |  | %d |\n+---+  +---+",a,b);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

    }
}

void fram(int nbr){
    printf("\n");
    for(int i=0;i<nbr;i++){
        printf(" ");
    }
    printf(" O\n");
    for(int i=0;i<nbr;i++){
        printf(" ");
    }
    printf("/|\\\n");
    for(int i=0;i<nbr;i++){
        printf(" ");
    }
    printf("/ \\\n");
    //printf("     \n");
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(NULL));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int again ;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    char introd[] = "           Bienvenu au Jeu \"Memory Challenge\"  \n\n" ;
    int va = strlen(introd);
    for(int i=0;i<va;i++){
        //Sleep(10);
        printf("%c",introd[i]);
    }
    char cont[] = "Appuyer sur un bouton pour continuer : ";
    int la = strlen(cont);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    for(int i=0;i<la;i++){
        //Sleep(10);
        printf("%c",cont[i]);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    _getch();
    system("cls");

    do{
        int place1=0 , place2=0 ;
        int here=1 ;
        int tour ;
        do{
            tour = 1 ;
            system("cls");
            Sleep(100);
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            fram(place1);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            fram(place2);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n+---+  +---+\n| ? |  | ? |\n+---+  +---+");
            _getch();
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            //dice(place1,place2,tour);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            system("cls");
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            fram(place1);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            fram(place2);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            int a = genererAleatoire(1,6);
            int b = genererAleatoire(1,6);
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n+---+  +---+\n| %d |  | %d |\n+---+  +---+",a,b);
            Sleep(100);
            here = place1;
            place1 += a + b ;
            if(place1>=49){
                for(int i=here;i<=49;i++){
                    Sleep(100);
                    system("cls");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    fram(i);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    fram(place2);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("\n+---+  +---+\n| %d |  | %d |\n+---+  +---+",a,b);
                    //Sleep(10);
                }
            }else{
                for(int i=here;i<=place1;i++){
                    Sleep(100);
                    system("cls");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    fram(i);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    fram(place2);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("\n+---+  +---+\n| %d |  | %d |\n+---+  +---+",a,b);
                    //Sleep(10);
                }
            }
            if(place1>49){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("\n\n                 Blue won !!!\n");
                break;
            }
            tour = 2 ;
            system("cls");
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            fram(place1);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            fram(place2);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("\n+---+  +---+\n| ? |  | ? |\n+---+  +---+");
            Sleep(100);
            _getch();
            //dice(place1,place2,tour);
            system("cls");
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            fram(place1);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            fram(place2);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            a = genererAleatoire(1,6);
            b = genererAleatoire(1,6);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("\n+---+  +---+\n| %d |  | %d |\n+---+  +---+",a,b);
            Sleep(100);
            here = place2 ;
            place2 += a + b ;
            if(place2>=49){
                for(int i=here;i<=49;i++){
                    Sleep(100);
                    system("cls");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    fram(place1);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    fram(i);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    printf("\n+---+  +---+\n| %d |  | %d |\n+---+  +---+",a,b);
                    //Sleep(10);
                }
            }else{
                for(int i=here;i<=place2;i++){
                    Sleep(100);
                    system("cls");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    fram(place1);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    fram(i);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    printf("\n+---+  +---+\n| %d |  | %d |\n+---+  +---+",a,b);
                    //Sleep(10);
                }
            }
            if(place2>49){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("\n\n                     Yellow won !!!\n");
                break;
            }

        }while(place1<50 && place2<50);

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        /////////////////////////////////////////////////////////////////
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
