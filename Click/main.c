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

/*
printf("\n"
           "                                                    \n"
           " _/\______\\__                                              \n"
           "/ ,-. -|-  ,-.`-.                                          \n"
           "`( o )----( o )-'                                             \n"
           "  `-'      `-'                                                    \n");
*/

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

void fram(int nbr){
    for(int i=0;i<nbr;i++){
        printf(" ");
    }
    printf("  ______\n");
    for(int i=0;i<nbr;i++){
        printf(" ");
    }
    printf(" /|_||_\\`.__\n");
    for(int i=0;i<nbr;i++){
        printf(" ");
    }
    printf("(   _    _ _\\\n");
    for(int i=0;i<nbr;i++){
        printf(" ");
    }
    printf("=`-(_)--(_)-'\n");
    //printf("     \n");
}



int main(){
    setlocale(LC_ALL, "");
    srand(time(NULL));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int again ;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    char introd[] = "               Bienvenu au Jeu   \n\n" ;
    int va = strlen(introd);
    for(int i=0;i<va;i++){
        Sleep(10);
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
    int click = 0 ;
    do{
        click = 0 ;
        system("cls");

        start();

        clock_t start_time, end_time;
        double execution_time;

        start_time = clock();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;
        _getch();
        system("cls");
        fram(click);
        click++ ;

        end_time = clock();

        execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        double temps_stocke = execution_time;
        //temps_stocke = temps_stocke / 60 ;
        double vitesse = 40 / temps_stocke ;

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\n\nVotre temps : ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        printf("%.2f sec",temps_stocke);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\n\nVotre vitesse : ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        printf("%.2f click/sec\n\n",vitesse);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


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
