#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<locale.h>

int genererAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void remplirlettre_01(char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char *j) {
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


void printfbox_0(char a , char b , char c , char d , char e , char f , char g , char h , char i ,char j){
    printf(" _____      _____      _____      _____      _____\n|     |    |     |    |     |    |     |    |     |\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",a,b,c,d,e);
    printf(" _____      _____      _____      _____      _____\n|     |    |     |    |     |    |     |    |     |\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",f,g,h,i,j);
}


void printfboxvide(){
    printf(" _____      _____      _____      _____      _____\n|     |    |     |    |     |    |     |    |     |\n|  1  |    |  2  |    |  3  |    |  4  |    |  5  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n");
    printf(" _____      _____      _____      _____      _____\n|     |    |     |    |     |    |     |    |     |\n|  6  |    |  7  |    |  8  |    |  9  |    |  10 |\n|_____|    |_____|    |_____|    |_____|    |_____|\n");
    printf(" _____      _____      _____      _____      _____\n|     |    |     |    |     |    |     |    |     |\n|  11 |    |  12 |    |  13 |    |  14 |    |  15 |\n|_____|    |_____|    |_____|    |_____|    |_____|\n");
    printf(" _____      _____      _____      _____      _____\n|     |    |     |    |     |    |     |    |     |\n|  16 |    |  17 |    |  18 |    |  19 |    |  20 |\n|_____|    |_____|    |_____|    |_____|    |_____|\n");

}


void printfbox(char t[]){
    printf(" _____      _____      _____      _____      _____\n|    1|    |    2|    |    3|    |    4|    |    5|\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",t[0],t[1],t[2],t[3],t[4]);
    printf(" _____      _____      _____      _____      _____\n|    6|    |    7|    |    8|    |    9|    |   10|\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",t[5],t[6],t[7],t[8],t[9]);
    printf(" _____      _____      _____      _____      _____\n|   11|    |   12|    |   13|    |   14|    |   15|\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n",t[10],t[11],t[12],t[13],t[14]);
    printf(" _____      _____      _____      _____      _____\n|   16|    |   17|    |   18|    |   19|    |   20|\n|  %c  |    |  %c  |    |  %c  |    |  %c  |    |  %c  |\n|_____|    |_____|    |_____|    |_____|    |_____|\n\n",t[15],t[16],t[17],t[18],t[19]);
}


int main(){
    setlocale(LC_ALL, "");
    srand(time(NULL));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int again ;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    char introd[] = "\n            Bienvenu au jeu de mémoire \n\nVous devez retrouver toutes les paires de lettres   cachées dans une grille de 20 cases. \n\n1. Une grille de 20 cases est affichée avec des      lettres cachées. \n\n2. À chaque tour, vous choisissez deux cases en      entrant leurs numéros. \n\n3. Si les lettres sous ces deux cases correspondent, elles restent visibles. \n\n4. Sinon, elles seront cachées à nouveau après un    court instant. \n\n5. Continuez jusqu'à ce que toutes les paires soient trouvées ! \n\n" ;
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
        char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int index;
        int index_1, index_2 ;
        char t[20] = "????????????????????" ;
        int stop ;
        do{
            int d = 0;
            index = genererAleatoire(0, 25);
            for(int i=0;i<20;i++){
                if(t[i]==alphabet[index]){
                    d = 1;
                }
            }

            if(d==1){
                continue;
            }

            index_1 = genererAleatoire(0, 20);
            index_2 = genererAleatoire(0, 20);
            if(index_1==index_2){
                continue;
            }else if(t[index_1]=='?' && t[index_2]=='?'){
                t[index_1] = alphabet[index];
                t[index_2] = alphabet[index];
            }else{
                continue;
            }
            stop = 0 ;
            for(int i=0;i<20;i++){
                if(t[i]=='?'){
                    stop = 1 ;
                }
            }
        }while(stop==1);

        int img_1 , img_2 ;
        int win=0;
        char r[20] = "????????????????????" ;
        char ar[20];
        //getchar();
        do{
            system("cls");
            strcpy(ar,r);
            printfbox(r);

            while(1) {
                printf("\nLe nbr 1 : ");

                if(scanf("%d",&img_1) != 1) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\nentere un nbr entre 1 et 20 !\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    while(getchar() != '\n');
                    continue;
                }

                if(img_1<=20 && img_1>=1) {
                    break;
                } else {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\nentere un nbr entre 1 et 20 !\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            r[img_1-1] = t[img_1-1] ;
            Sleep(100);
            system("cls");
            printfbox(r);

            while(1) {
                printf("\nLe nbr 2 : ");

                if(scanf("%d",&img_2) != 1) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\nentere un nbr entre 1 et 20 !\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    while(getchar() != '\n');
                    continue;
                }

                if(img_2<=20 && img_2>=1 && img_1 != img_2) {
                    break;
                } else {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\nentere un nbr entre 1 et 20 !\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            r[img_2-1] = t[img_2-1] ;
            Sleep(100);
            system("cls");
            printfbox(r);
            Sleep(2500);
            if(r[img_1-1]==r[img_2-1]){
                //continue;
            }else{
                strcpy(r,ar);
            }
            win = 1 ;
            for(int i=0;i<20;i++){
                if(r[i]=='?'){
                    win = 0 ;
                }
            }
        }while(win==0);
        //////////////////////////////////////////////////////////////////////////////////////////
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("\nYouuu win !!!!!\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

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


