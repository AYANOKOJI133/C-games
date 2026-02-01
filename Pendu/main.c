#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<locale.h>

int genererAleatoire(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main() {
    setlocale(LC_ALL, "");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int again;

    char v[] = "         Introduction au Jeu du Pendu ! \n\nBienvenue dans le monde du \"Pendu\"\nLe but est simple : deviner un mot mystère avant quele dessin du pendu ne soit complètement réalisé. \n\n--> **Règles du jeu** :   \n\n1. Un mot mystère est choisi au hasard. \n\n2. Vous proposez une lettre à chaque tour.   \n\n3. Si la lettre est correcte, elle est ajoutée.   \n\n4. Si la lettre est incorrecte, une partie du pendu est dessinée. \n\n5. La partie se termine lorsque :   \n   - Le mot est découvert (victoire).   \n   - Le dessin du pendu est complet (défaite).   \n\n";
    int lo = strlen(v);
    for(int i=0;i<lo;i++){
        Sleep(10);
        printf("%c",v[i]);
    }
    char o ;
    char cont[] = "Appuyer sur un bouton pour jouer : ";
    int la = strlen(cont);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    for(int i=0;i<la;i++){
        Sleep(10);
        printf("%c",cont[i]);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    _getch();
    system("cls");

    /////////////////////////////////////////
    int chois ;
    do{
        /////////////////////////////////////////////
        system("cls");
        char intro[] = "\nBienvenue dans notre jeu :\n\n";
        int no = strlen(intro);
        for(int i=0;i<no;i++){
            Sleep(10);
            printf("%c",intro[i]);
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

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
        /////////////////////////////////////////////

        char mot_mystere[100] ;
        int nbr_essai = 6 ;
        char essai[10] ;

        int truee ;
        if(chois==1){
            getchar();
            //        printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
            truee = 0 ;
            printf("Entrer le mot mystère : ");
            //getchar();
            char test[100];
            gets(test);
            strcpy(mot_mystere,strupr(test));
            Sleep(1000);
            int taille = strlen(mot_mystere);
            char mot[taille] ;
            for(int i=0;i<taille;i++){
                mot[i] = '_' ;
            }
            system("cls");
            int win ;

            do{
                win = 1 ;
                switch(nbr_essai){
                    case 0 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                             break;
                    case 1 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  /  \n|_______\n");
                             break;
                    case 2 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|   \n|_______\n");
                             break;
                    case 3 : printf("\n_____\n|   | \n|   O \n|  /| \n|   \n|_______\n");
                             break;
                    case 4 : printf("\n_____\n|   | \n|   O \n|   | \n|   \n|_______\n");
                             break;
                    case 5 : printf("\n_____\n|   | \n|   O \n|   \n|   \n|_______\n");
                             break;
                    case 6 : printf("\n_____\n|   | \n|    \n|   \n|   \n|_______\n");
                             break;
                }

                printf("\nLe mot mystère : ");
                for(int i=0;i<taille;i++){
                    printf("%c ",mot[i]);
                }

                char testess[10] ;
                printf("\n\nEssais restant : %d\n\nEntrer une lettre : ",nbr_essai);
                scanf("%[^\n]s",&essai);
                essai[0] = toupper(essai[0]);

                for(int i=0;i<taille;i++){
                    if(mot_mystere[i]==essai[0]){
                        mot[i]=essai[0] ;
                        truee = 1 ;
                    }
                }

                if(truee==1){
                    char bien[] = "\nBien joué !\n";
                    int la = strlen(bien);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    for(int i=0;i<la;i++){
                        Sleep(20);
                        printf("%c",bien[i]);
                    }
                    Sleep(50);
                    printf("Il y a un '%c' dans le mot mystère.\n",essai[0]);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }else{
                    char pas[] = "\nPas de chance !\n";
                    int pa = strlen(pas);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    for(int i=0;i<pa;i++){
                        Sleep(20);
                        printf("%c",pas[i]);
                    }
                    Sleep(50);
                    printf("Il n'y a pas de '%c' dans le mot mystère.\n",essai[0]);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    nbr_essai = nbr_essai - 1 ;
                }
                truee = 0 ;
                win = 1 ;
                for(int i=0;i<taille;i++){
                    if(mot[i]=='_'){
                        win = 0 ;
                    }
                }
                getchar();
                Sleep(1000);
                system("cls");

            }while(nbr_essai>0 && win==0);
            if(win == 0){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                printf("\nTu as perdu. \n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("\nLe résultat : ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                for(int i=0;i<taille;i++){
                    printf("%c ",mot[i]);
                }
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("\n\nle mot est : ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                puts(mot_mystere);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                switch(nbr_essai){
                    case 0 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                             break;
                    case 1 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  /  \n|_______\n");
                             break;
                    case 2 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|   \n|_______\n");
                             break;
                    case 3 : printf("\n_____\n|   | \n|   O \n|  /| \n|   \n|_______\n");
                             break;
                    case 4 : printf("\n_____\n|   | \n|   O \n|   | \n|   \n|_______\n");
                             break;
                    case 5 : printf("\n_____\n|   | \n|   O \n|   \n|   \n|_______\n");
                             break;
                    case 6 : printf("\n_____\n|   | \n|    \n|   \n|   \n|_______\n");
                             break;
                }
                printf("\nTu as gagné. \n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }

        if(chois==2){
            getchar();
            system("cls");
            int lang ;
            printf("entrer la langue : \n\n   1. Pour francais.\n\n   2. Pour anglais.\n\n   3. Pour darija.\n");

            while(1) {
                printf("\nVotre choix : ");

                if(scanf("%d",&lang) != 1) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\nentere '1' ou '2' ou '3'\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    while(getchar() != '\n');
                    continue;
                }

                if(lang == 1 || lang == 2 || lang == 3) {
                    break;
                } else {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\nentere '1' ou '2' ou '3'\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            getchar();
            if(lang==1){
                char mot_mystere[100];

                const char *mots[] = {
                    "VOITURE", "MAISON", "ORDINATEUR", "CHAT", "CHIEN", "LIVRE", "TABLE", "CHAISE", "PORTE", "FENETRE",
                    "PLANTE", "LAMPE", "MOTO", "TELEPHONE", "GUITARE", "COUTEAU", "BOUTEILLE", "VALISE", "PARAPLUIE", "MONTRE",
                    "CHAUSSURE", "VESTE", "CHAPEAU", "STYLO", "CAHIER", "SAC", "CAMERA", "BALLON", "VELO", "CASSEROLE"
                };

                srand(time(NULL));

                int index = genererAleatoire(0, 29);

                strcpy(mot_mystere, mots[index]);

                int taille = strlen(mot_mystere);
                char mot[taille] ;
                for(int i=0;i<taille;i++){
                    mot[i] = '_' ;
                }
                system("cls");
                int win ;

                do{
                    win = 1 ;
                    switch(nbr_essai){
                        case 0 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                                 break;
                        case 1 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  /  \n|_______\n");
                                 break;
                        case 2 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|   \n|_______\n");
                                 break;
                        case 3 : printf("\n_____\n|   | \n|   O \n|  /| \n|   \n|_______\n");
                                 break;
                        case 4 : printf("\n_____\n|   | \n|   O \n|   | \n|   \n|_______\n");
                                 break;
                        case 5 : printf("\n_____\n|   | \n|   O \n|   \n|   \n|_______\n");
                                 break;
                        case 6 : printf("\n_____\n|   | \n|    \n|   \n|   \n|_______\n");
                                 break;
                    }

                    printf("\nLe mot mystère : ");
                    for(int i=0;i<taille;i++){
                        printf("%c ",mot[i]);
                    }

                    char testess[10] ;
                    printf("\n\nEssais restant : %d\n\nEntrer une lettre : ",nbr_essai);
                    scanf("%[^\n]s",&essai);
                    essai[0] = toupper(essai[0]);

                    for(int i=0;i<taille;i++){
                        if(mot_mystere[i]==essai[0]){
                            mot[i]=essai[0] ;
                            truee = 1 ;
                        }
                    }

                    if(truee==1){
                        char bien[] = "\nBien joué !\n";
                        int la = strlen(bien);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        for(int i=0;i<la;i++){
                            Sleep(20);
                            printf("%c",bien[i]);
                        }
                        Sleep(50);
                        printf("Il y a un '%c' dans le mot mystère.\n",essai[0]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }else{
                        char pas[] = "\nPas de chance !\n";
                        int pa = strlen(pas);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        for(int i=0;i<pa;i++){
                            Sleep(20);
                            printf("%c",pas[i]);
                        }
                        Sleep(50);
                        printf("Il n'y a pas de '%c' dans le mot mystère.\n",essai[0]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        nbr_essai = nbr_essai - 1 ;
                    }
                    truee = 0 ;
                    win = 1 ;
                    for(int i=0;i<taille;i++){
                        if(mot[i]=='_'){
                            win = 0 ;
                        }
                    }
                    getchar();
                    Sleep(1000);
                    system("cls");

                }while(nbr_essai>0 && win==0);
                if(win == 0){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                    printf("\nTu as perdu. \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("\nLe résultat : ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    for(int i=0;i<taille;i++){
                        printf("%c ",mot[i]);
                    }
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("\n\nle mot est : ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    puts(mot_mystere);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }else{
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    switch(nbr_essai){
                        case 0 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                                 break;
                        case 1 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  /  \n|_______\n");
                                 break;
                        case 2 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|   \n|_______\n");
                                 break;
                        case 3 : printf("\n_____\n|   | \n|   O \n|  /| \n|   \n|_______\n");
                                 break;
                        case 4 : printf("\n_____\n|   | \n|   O \n|   | \n|   \n|_______\n");
                                 break;
                        case 5 : printf("\n_____\n|   | \n|   O \n|   \n|   \n|_______\n");
                                 break;
                        case 6 : printf("\n_____\n|   | \n|    \n|   \n|   \n|_______\n");
                                 break;
                    }
                    printf("\nTu as gagné. \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            if(lang==2){
                char mot_mystere[100];

                const char *mots[] = {
                    "CAR", "HOUSE", "COMPUTER", "CAT", "DOG", "BOOK", "TABLE", "CHAIR", "DOOR", "WINDOW",
                    "PLANT", "LAMP", "MOTORCYCLE", "PHONE", "GUITAR", "KNIFE", "BOTTLE", "SUITCASE", "UMBRELLA", "WATCH",
                    "SHOE", "JACKET", "HAT", "PEN", "NOTEBOOK", "BAG", "CAMERA", "BALL", "BIKE", "PAN"
                };

                srand(time(NULL));

                int index = genererAleatoire(0, 29);

                strcpy(mot_mystere, mots[index]);

                int taille = strlen(mot_mystere);
                char mot[taille] ;
                for(int i=0;i<taille;i++){
                    mot[i] = '_' ;
                }
                system("cls");
                int win ;

                do{
                    win = 1 ;
                    switch(nbr_essai){
                        case 0 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                                 break;
                        case 1 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  /  \n|_______\n");
                                 break;
                        case 2 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|   \n|_______\n");
                                 break;
                        case 3 : printf("\n_____\n|   | \n|   O \n|  /| \n|   \n|_______\n");
                                 break;
                        case 4 : printf("\n_____\n|   | \n|   O \n|   | \n|   \n|_______\n");
                                 break;
                        case 5 : printf("\n_____\n|   | \n|   O \n|   \n|   \n|_______\n");
                                 break;
                        case 6 : printf("\n_____\n|   | \n|    \n|   \n|   \n|_______\n");
                                 break;
                    }

                    printf("\nLe mot mystère : ");
                    for(int i=0;i<taille;i++){
                        printf("%c ",mot[i]);
                    }

                    char testess[10] ;
                    printf("\n\nEssais restant : %d\n\nEntrer une lettre : ",nbr_essai);
                    scanf("%[^\n]s",&essai);
                    essai[0] = toupper(essai[0]);

                    for(int i=0;i<taille;i++){
                        if(mot_mystere[i]==essai[0]){
                            mot[i]=essai[0] ;
                            truee = 1 ;
                        }
                    }

                    if(truee==1){
                        char bien[] = "\nBien joué !\n";
                        int la = strlen(bien);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        for(int i=0;i<la;i++){
                            Sleep(20);
                            printf("%c",bien[i]);
                        }
                        Sleep(50);
                        printf("Il y a un '%c' dans le mot mystère.\n",essai[0]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }else{
                        char pas[] = "\nPas de chance !\n";
                        int pa = strlen(pas);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        for(int i=0;i<pa;i++){
                            Sleep(20);
                            printf("%c",pas[i]);
                        }
                        Sleep(50);
                        printf("Il n'y a pas de '%c' dans le mot mystère.\n",essai[0]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        nbr_essai = nbr_essai - 1 ;
                    }
                    truee = 0 ;
                    win = 1 ;
                    for(int i=0;i<taille;i++){
                        if(mot[i]=='_'){
                            win = 0 ;
                        }
                    }
                    getchar();
                    Sleep(1000);
                    system("cls");

                }while(nbr_essai>0 && win==0);
                if(win == 0){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                    printf("\nTu as perdu. \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("\nLe résultat : ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    for(int i=0;i<taille;i++){
                        printf("%c ",mot[i]);
                    }
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("\n\nle mot est : ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    puts(mot_mystere);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }else{
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    switch(nbr_essai){
                        case 0 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                                 break;
                        case 1 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  /  \n|_______\n");
                                 break;
                        case 2 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|   \n|_______\n");
                                 break;
                        case 3 : printf("\n_____\n|   | \n|   O \n|  /| \n|   \n|_______\n");
                                 break;
                        case 4 : printf("\n_____\n|   | \n|   O \n|   | \n|   \n|_______\n");
                                 break;
                        case 5 : printf("\n_____\n|   | \n|   O \n|   \n|   \n|_______\n");
                                 break;
                        case 6 : printf("\n_____\n|   | \n|    \n|   \n|   \n|_______\n");
                                 break;
                    }
                    printf("\nTu as gagné. \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            if(lang==3){
                char mot_mystere[100];

                const char *mots[] = {
                    "TOMOBILE", "DAR", "PC", "MOCHA", "KELB", "KTAB", "TABLA", "KORSI", "BAB", "CHRJEM",
                    "TAJIN", "TLFAZA", "MOTOR", "TELEPHONE", "TLAJA", "FORCHITA", "OSTAD", "VALIZA", "MSMAR", "MTARQA",
                    "SBAT", "JAKITA", "KOZINA", "STILO", "CHKARA", "SAK", "CAMIRA", "KORA", "PIKALA", "KOKOT",
                    "TLFAZA", "ZRBIYA", "CHEBKA", "MESNED", "SEDARI", "MEDRASSA", "SENDALA", "MANTA", "CHETABA", "MAGANA",
                };

                srand(time(NULL));

                int index = genererAleatoire(0, 39);

                strcpy(mot_mystere, mots[index]);

                int taille = strlen(mot_mystere);
                char mot[taille] ;
                for(int i=0;i<taille;i++){
                    mot[i] = '_' ;
                }
                system("cls");
                int win ;

                do{
                    win = 1 ;
                    switch(nbr_essai){
                        case 0 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                                 break;
                        case 1 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  /  \n|_______\n");
                                 break;
                        case 2 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|   \n|_______\n");
                                 break;
                        case 3 : printf("\n_____\n|   | \n|   O \n|  /| \n|   \n|_______\n");
                                 break;
                        case 4 : printf("\n_____\n|   | \n|   O \n|   | \n|   \n|_______\n");
                                 break;
                        case 5 : printf("\n_____\n|   | \n|   O \n|   \n|   \n|_______\n");
                                 break;
                        case 6 : printf("\n_____\n|   | \n|    \n|   \n|   \n|_______\n");
                                 break;
                    }

                    printf("\nLe mot mystère : ");
                    for(int i=0;i<taille;i++){
                        printf("%c ",mot[i]);
                    }

                    char testess[10] ;
                    printf("\n\nEssais restant : %d\n\nEntrer une lettre : ",nbr_essai);
                    scanf("%[^\n]s",&essai);
                    essai[0] = toupper(essai[0]);

                    for(int i=0;i<taille;i++){
                        if(mot_mystere[i]==essai[0]){
                            mot[i]=essai[0] ;
                            truee = 1 ;
                        }
                    }

                    if(truee==1){
                        char bien[] = "\nBien joué !\n";
                        int la = strlen(bien);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        for(int i=0;i<la;i++){
                            Sleep(20);
                            printf("%c",bien[i]);
                        }
                        Sleep(50);
                        printf("Il y a un '%c' dans le mot mystère.\n",essai[0]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }else{
                        char pas[] = "\nPas de chance !\n";
                        int pa = strlen(pas);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        for(int i=0;i<pa;i++){
                            Sleep(20);
                            printf("%c",pas[i]);
                        }
                        Sleep(50);
                        printf("Il n'y a pas de '%c' dans le mot mystère.\n",essai[0]);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        nbr_essai = nbr_essai - 1 ;
                    }
                    truee = 0 ;
                    win = 1 ;
                    for(int i=0;i<taille;i++){
                        if(mot[i]=='_'){
                            win = 0 ;
                        }
                    }
                    getchar();
                    Sleep(1000);
                    system("cls");

                }while(nbr_essai>0 && win==0);
                if(win == 0){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                    printf("\nTu as perdu. \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("\nLe résultat : ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    for(int i=0;i<taille;i++){
                        printf("%c ",mot[i]);
                    }
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("\n\nle mot est : ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    puts(mot_mystere);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }else{
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    switch(nbr_essai){
                        case 0 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  / \\ \n|_______\n");
                                 break;
                        case 1 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|  /  \n|_______\n");
                                 break;
                        case 2 : printf("\n_____\n|   | \n|   O \n|  /|\\ \n|   \n|_______\n");
                                 break;
                        case 3 : printf("\n_____\n|   | \n|   O \n|  /| \n|   \n|_______\n");
                                 break;
                        case 4 : printf("\n_____\n|   | \n|   O \n|   | \n|   \n|_______\n");
                                 break;
                        case 5 : printf("\n_____\n|   | \n|   O \n|   \n|   \n|_______\n");
                                 break;
                        case 6 : printf("\n_____\n|   | \n|    \n|   \n|   \n|_______\n");
                                 break;
                    }
                    printf("\nTu as gagné. \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
        }
        //////////////////////////////////////////////////////////////////////////
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
    char mad[] = "\n\n                    Ooooookey\n\n";
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

