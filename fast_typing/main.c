#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include <locale.h>

int genererAleatoire(int min, int max){
    return (rand() % (max - min + 1)) + min;
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

int main(){
    setlocale(LC_ALL, "");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    int again ;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    char introd[] = "       Bienvenue dans Fast Typing Challenge.\n\nCe jeu mettra a l'epreuve votre rapidité et votre   precision en dactylographie. \nVotre objectif est de taper correctement les mots   qui s'affichent a l'écran aussi vite que possible. \nA la fin du test, votre vitesse en mots par minute  (WPM) sera calculée.\n\nRégles du jeu : \n\n1. Un mot aleatoire apparait a l'écran. \n\n2. Tapez-le et appuyez sur ENTREE. \n\n3. Chaque mot juste augmente votre score.\n\n4. Votre vitesse sera évaluée a la fin du test.\n\nPréparez-vous et tentez d'améliorer votre record.\n\n" ;
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
    int lang ;
    do{
        system("cls");
        char langu[] = "\nSélectionner la langue :\n\n   1 Pour la langue française\n\n   2 Pour la langue anglaise\n\n";
        int aa = strlen(langu);
        for(int i=0;i<aa;i++){
            Sleep(30);
            printf("%c",langu[i]);
        }
        while(1) {
            printf("\nVotre choix : ");

            if(scanf("%d", &lang) != 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentere '1' ou '2' \n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                while(getchar() != '\n');
                continue;
            }

            if(lang == 1 || lang == 2) {
                break;
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentere '1' ou '2' \n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        getchar();
        if(lang==1){
            system("cls");
            start();
            char mot_mystere[100];
            char word[100];
            float note=0 ;

            const char *mots[] = {
                "CHAT", "CHIEN", "TABLE", "LAMPE", "PORTE", "SAC", "FLEUR", "CARTE", "LIVRE", "MAISON",
                "MOTO", "CASQUE", "STYLO", "MONTRE", "CAMERA", "BALLON", "PLANTE", "CHAIR", "COUTEAU", "FENETRE",
                "BOUTEILLE", "VESTE", "CHAISE", "CHAUSSURE", "CHAPEAU", "VALISE", "VELO", "PARAPLUIE", "GUITARE", "LAMPE"
            };

            srand(time(NULL));

            int index = genererAleatoire(0, 29);

            strcpy(mot_mystere, mots[index]);

            clock_t start_time, end_time;
            double execution_time;

            start_time = clock();
            for(int i=0;i<30;i++){
                int index = genererAleatoire(0, 29);
                strcpy(mot_mystere, mots[index]);
                printf("\n\t\t\t");
                puts(mot_mystere);
                printf("\n\n\t\t\t");
                gets(word);
                if(strcmp(word,mot_mystere)==0){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    printf("\n\t\t\tGood!");
                    Sleep(30);
                    note++;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }else{
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\n\t\t\tWrong!");
                    Sleep(30);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                system("cls");
            }

            end_time = clock();

            execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

            double temps_stocke = execution_time - 1;
            temps_stocke = temps_stocke / 60 ;
            double vitesse = note / temps_stocke ;

            printf("\nLes mots justes : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("%.0f /30",note);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n\nVotre temps : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
            printf("%.2f min",temps_stocke);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n\nVotre vitesse : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("%.2f mots/min\n\n",vitesse);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }


        if(lang==2){
            system("cls");
            start();
            char mot_mystere[100];
            char word[100];
            float note=0 ;

            const char *mots[] = {
                "CAT", "DOG", "BOOK", "TABLE", "CHAIR", "DOOR", "HOUSE", "PLANT", "CAR", "PHONE",
                "LAMP", "MOUSE", "WATER", "CLOCK", "SHOE", "BOTTLE", "KEY", "WATCH", "PAPER", "BAG",
                "PEN", "CUP", "GLASS", "BOX", "BALL", "TRAIN", "PLANE", "FORK", "KNIFE", "BRUSH"
            };

            srand(time(NULL));

            int index = genererAleatoire(0, 29);

            strcpy(mot_mystere, mots[index]);

            clock_t start_time, end_time;
            double execution_time;

            start_time = clock();
            for(int i=0;i<30;i++){
                int index = genererAleatoire(0, 29);
                strcpy(mot_mystere, mots[index]);
                printf("\n\t\t\t");
                puts(mot_mystere);
                printf("\n\n\t\t\t");
                gets(word);
                if(strcmp(word,mot_mystere)==0){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    printf("\n\t\t\tGood!");
                    Sleep(30);
                    note++;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }else{
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\n\t\t\tWrong!");
                    Sleep(30);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                system("cls");
            }

            end_time = clock();

            execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

            double temps_stocke = execution_time - 1;
            temps_stocke = temps_stocke / 60 ;
            double vitesse = note / temps_stocke ;

            printf("\nThe right words : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("%.0f /30",note);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n\nYour time : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
            printf("%.2f min",temps_stocke);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\n\nYour speed : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("%.2f mots/min\n\n",vitesse);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        }
        /////////////////////////////////////////////////////////////////////
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

