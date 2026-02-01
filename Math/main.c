#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include <locale.h>

int genererAleatoire(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void multiplication(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    int allo ;
    int min = 1, max = 10;
    int eq ,nbr ,all ,resultat ;
    float note=0;
    system("cls");
    Sleep(700);
    char diffi[] = "\nPour régler la difficulté : \n\n--> entrer le nbr 1-9 que tu veux tester.\n\n--> enter 0 pour tester dans tous les nbr.\n\n";
    int aa = strlen(diffi);
    for(int i=0;i<aa;i++){
        Sleep(20);
        printf("%c",diffi[i]);
    }

    while(1) {
        printf("Votre choix : ");

        if(scanf("%d",&nbr) != 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("entrer un numéro entre '0' et '9'\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            while(getchar() != '\n');
            continue;
        }

        if(nbr <= 9 && nbr >=0 ) {
            break;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("entrer un numéro entre '0' et '9'\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    system("cls");
    printf("\nentrer le nbr des equation : ");

    while(1) {
        if(scanf("%d",&eq) != 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Chois invalide.\nRéessayer : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            while(getchar() != '\n');
            continue;
        }
        if(eq>0) {
            break;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Chois invalide.\nRéessayer : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    system("cls");
    if(nbr != 0){
        for(int i=1;i<=eq;i++){
            all = genererAleatoire(min,max);
            printf("\n %d x %d = ",nbr,all);
            scanf("%d",&resultat);
            if(resultat==nbr*all){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("    true");
                note++ ;
                int mot = genererAleatoire(1,3);
                if(mot==1){
                    printf("        Good '_'\n");
                }
                if(mot==2){
                    printf("        perfect  ^_^\n");
                }
                if(mot==3){
                    printf("        great 0_0\n");
                }
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("    false  -_-");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
                printf("    la repense juste est : %d \n",nbr*all);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
    }else{
        for(int i=1;i<=eq;i++){
            all = genererAleatoire(min,max);
            allo = genererAleatoire(min,max);
            printf("\n %d x %d = ",allo,all);
            scanf("%d",&resultat);
            if(resultat==allo*all){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("    true");
                note++ ;
                int mot = genererAleatoire(1,3);
                if(mot==1){
                    printf("        Good '_'\n");
                }
                if(mot==2){
                    printf("        perfect  ^_^\n");
                }
                if(mot==3){
                    printf("        great 0_0\n");
                }
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("    false  -_-");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                printf("    la repense juste est : %d \n",allo*all);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
    }
    printf("\n\nVotre note est : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    printf("%.2f / 20\n\n",(note/eq)*20);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void addition(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    int min = 1, max = 1000;
    int eq ,nbr ,all ,resultat ;
    float note=0;
    system("cls");
    printf("\nentrer le nbr des equation : ");

    while(1) {
        if(scanf("%d",&eq) != 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Chois invalide.\nRéessayer : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            while(getchar() != '\n');
            continue;
        }
        if(eq>0) {
            break;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Chois invalide.\nRéessayer : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    system("cls");

    for(int i=1;i<=eq;i++){
        all = genererAleatoire(min,max);
        nbr = genererAleatoire(min,max);
        printf(" %d + %d = ",nbr,all);
        scanf("%d",&resultat);
        if(resultat==nbr+all){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("    true");
            note++ ;
            int mot = genererAleatoire(1,3);
            if(mot==1){
                printf("        Good '_'\n");
            }
            if(mot==2){
                printf("        perfect  ^_^\n");
            }
            if(mot==3){
                printf("        great 0_0\n");
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }else{
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("    false  -_-");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
            printf("    la repense juste est : %d \n",nbr+all);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    printf("\n\nVotre note est : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    printf("%.2f / 20\n\n",(note/eq)*20);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void soustraction(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    int min = 1, max = 1000;
    int eq ,nbr ,all ,resultat ;
    float note=0;
    system("cls");
    printf("\nentrer le nbr des equation : ");

    while(1) {
        if(scanf("%d",&eq) != 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Chois invalide.\nRéessayer : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            while(getchar() != '\n');
            continue;
        }
        if(eq>0) {
            break;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Chois invalide.\nRéessayer : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    system("cls");

    for(int i=1;i<=eq;i++){
        do{
            all = genererAleatoire(min,max);
            nbr = genererAleatoire(min,max);
        }while(nbr<all);
        printf(" %d - %d = ",nbr,all);
        scanf("%d",&resultat);
        if(resultat==nbr-all){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("    true");
            note++ ;
            int mot = genererAleatoire(1,3);
            if(mot==1){
                printf("        Good '_'\n");
            }
            if(mot==2){
                printf("        perfect  ^_^\n");
            }
            if(mot==3){
                printf("        great 0_0\n");
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }else{
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("    false  -_-");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
            printf("    la repense juste est : %d \n",nbr-all);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    printf("\n\nVotre note est : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    printf("%.2f / 20\n\n",(note/eq)*20);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void division(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    int min = 1, max = 1000 , eq;
    int all ,nbr ,allo ;
    float resultat ,flooo ;
    float note=0 ;
    system("cls");
    Sleep(700);
    char diffi[] = "\nPour régler la difficulté : \n\n--> entrer le nbr 1-9 que tu veux tester.\n\n--> enter 0 pour tester dans tous les nbr.\n\n";
    int aa = strlen(diffi);
    for(int i=0;i<aa;i++){
        Sleep(20);
        printf("%c",diffi[i]);
    }

    while(1) {
        printf("Votre choix : ");

        if(scanf("%d",&nbr) != 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("entrer un numéro entre '0' et '9'\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            while(getchar() != '\n');
            continue;
        }

        if(nbr <= 9 && nbr >=0 ) {
            break;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("entrer un numéro entre '0' et '9'\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    system("cls");
    printf("\nentrer le nbr des equation : ");

    while(1) {
        if(scanf("%d",&eq) != 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Chois invalide.\nRéessayer : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            while(getchar() != '\n');
            continue;
        }
        if(eq>0) {
            break;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Chois invalide.\nRéessayer : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    system("cls");

    if(nbr != 0){
        for(int i=1;i<=eq;i++){
            all = genererAleatoire(min,max);
            flooo = all*nbr ;
            printf("\n %.0f / %d = ",flooo,nbr);
            scanf("%f",&resultat);
            if(resultat==flooo/nbr){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("    true");
                note++ ;
                int mot = genererAleatoire(1,3);
                if(mot==1){
                    printf("        Good '_'\n");
                }
                if(mot==2){
                    printf("        perfect  ^_^\n");
                }
                if(mot==3){
                    printf("        great 0_0\n");
                }
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("    false  -_-");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
                printf("    la repense juste est : %.2f \n",flooo/nbr);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
    }else{
        for(int i=1;i<=eq;i++){
            all = genererAleatoire(1,9);
            allo = genererAleatoire(min,max);
            flooo = allo*all ;
            printf("\n %.0f / %d = ",flooo,all);
            scanf("%f",&resultat);
            if(resultat==flooo/all){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("    true");
                note++ ;
                int mot = genererAleatoire(1,3);
                if(mot==1){
                    printf("        Good '_'\n");
                }
                if(mot==2){
                    printf("        perfect  ^_^\n");
                }
                if(mot==3){
                    printf("        great 0_0\n");
                }
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("    false  -_-");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                printf("    la repense juste est : %.2f \n",flooo/all);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
    }
    printf("\n\nVotre note est : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    printf("%.2f / 20\n\n",(note/eq)*20);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main(){
    setlocale(LC_ALL, "");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    int again ;
    char v[] = "\n          Bienvenue dans notre programme \n            d'exercices mathématiques!\n\n--> Fonctionnalités principales :\n\n1. Résolvez des équations aléatoires adaptées à     votre niveau.\n\n2. Recevez des corrections instantanées avec des    encouragements personnalisés.\n\n3. Évaluez vos performances grâce à un système de   notation sur 20.\n\nChoisissez une opération, lancez-vous, et mesurez   vos progrès tout en vous amusant. Bonne chance et   bon entraînement!\n\n";
    int lo = strlen(v);
    for(int i=0;i<lo;i++){
        Sleep(5);
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
    int chois ;

    do{
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        char con[] = "\nChoisissez une opération :\n\nentrer 1 pour la multiplication \nentrer 2 pour la division \nentrer 3 pour l'addition \nentrer 4 pour la soustraction \n\n";
        int laa = strlen(con);
        for(int i=0;i<laa;i++){
            Sleep(10);
            printf("%c",con[i]);
        }

        while(1) {
            printf("Votre choix : ");

            if(scanf("%d",&chois) != 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("entrer un numéro entre '1' et '4'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                while(getchar() != '\n');
                continue;
            }

            if(chois==1 || chois==2 || chois==3 || chois==4) {
                break;
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("entrer un numéro entre '1' et '4'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }


        if(chois==1){
            multiplication();
        }
        if(chois==2){
            division();
        }
        if(chois==3){
            addition();
        }
        if(chois==4){
            soustraction();
        }

        printf("\nVoulez-vous rejouer ? (1 pour Oui, 0 pour Non) : \n");

        while(1) {
            printf("Votre choix : ");

            if(scanf("%d", &again) != 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("entrer '0' ou '1'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                while(getchar() != '\n');
                continue;
            }

            if(again == 0 || again == 1) {
                break;
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("entrer '0' ou '1'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }

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
    char made[] = "\n\n              made by Ayanokoji  ^_^             \n\n";
    int by = strlen(made);
    for(int i=0;i<by;i++){
        Sleep(20);
        printf("%c",made[i]);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    Sleep(1000);

    return 0;
}

