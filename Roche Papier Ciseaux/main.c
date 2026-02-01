#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

int genererAleatoire(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void print_ciseau(){
    printf("\n  ###                   \n #   #                  \n #   ####     ######### \n  ###   ##  ############\n         ####           \n         ####           \n  ###   ##  ############\n #   ####     ######### \n #   #                  \n  ###                   \n");
}

void print_papier(){
    printf("\n##############\n##############\n##############\n##############\n##############\n##############\n##############\n##############\n##############\n##############\n");
}

void print_roche(){
    printf("\n      ###########      \n    ###############    \n  ###################  \n ##################### \n#######################\n#######################\n ##################### \n  ###################  \n    ###############    \n      ###########      \n");
}
///////////////////////////////////////////////////////////
void ciseau_roche(){
    printf("\n ###                                               \n#   #                          ################    \n#   ####     #########       ####################  \n ###   ##  #############    ###################### \n        ####               ########################\n        ####               ########################\n ###   ##  #############    ###################### \n#   ####     #########       ####################  \n#   #                          ################    \n ###                                               \n");
}

void ciseau_ciseau(){
    printf("\n ###                                           ### \n#   #                                         #   #\n#   ####     #########       #########     ####   #\n ###   ##  #############   #############  ##   ### \n        ####                           ####        \n        ####                           ####        \n ###   ##  #############   #############  ##   ### \n#   ####     #########       #########     ####   #\n#   #                                         #   #\n ###                                           ### \n");
}

void ciseau_papier(){
    printf("\n ###                            ##############     \n#   #                           ##############     \n#   ####     #########          ##############     \n ###   ##  #############        ##############     \n        ####                    ##############     \n        ####                    ##############     \n ###   ##  #############        ##############     \n#   ####     #########          ##############     \n#   #                           ##############     \n ###                            ##############     \n");
}
///////////////////////////////////////////////////////////
void roche_ciseau(){
    printf("\n                                               ### \n    ################                          #   #\n  ####################       #########     ####   #\n ######################    #############  ##   ### \n########################               ####        \n########################               ####        \n ######################    #############  ##   ### \n  ####################       #########     ####   #\n    ################                          #   #\n                                               ### \n");
}

void roche_roche(){
    printf("\n                                                   \n    ################           ################    \n  ####################       ####################  \n ######################     ###################### \n########################   ########################\n########################   ########################\n ######################     ###################### \n  ####################       ####################  \n    ################           ################    \n                                                   \n");
}

void roche_papier(){
    printf("\n                                ##############     \n    ################            ##############     \n  ####################          ##############     \n ######################         ##############     \n########################        ##############     \n########################        ##############     \n ######################         ##############     \n  ####################          ##############     \n    ################            ##############     \n                                ##############     \n");
}
///////////////////////////////////////////////////////////
void papier_ciseau(){
    printf("\n     ##############                            ### \n     ##############                           #   #\n     ##############          #########     ####   #\n     ##############        #############  ##   ### \n     ##############                    ####        \n     ##############                    ####        \n     ##############        #############  ##   ### \n     ##############          #########     ####   #\n     ##############                           #   #\n     ##############                            ### \n");
}

void papier_roche(){
    printf("\n     ##############                                \n     ##############            ################    \n     ##############          ####################  \n     ##############         ###################### \n     ##############        ########################\n     ##############        ########################\n     ##############         ###################### \n     ##############          ####################  \n     ##############            ################    \n     ##############                                \n");
}

void papier_papier(){
    printf("\n     ##############             ##############     \n     ##############             ##############     \n     ##############             ##############     \n     ##############             ##############     \n     ##############             ##############     \n     ##############             ##############     \n     ##############             ##############     \n     ##############             ##############     \n     ##############             ##############     \n     ##############             ##############     \n");
}
///////////////////////////////////////////////////////////

int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "");
    int again;
    int min=1 , max=3 ;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");
    char v[] = "   Bienvenue dans le jeu Roche, Papier, Ciseaux !\n\n--> Règles du jeu :\n\n1. Choisissez une option parmi 'Roche', 'Papier', ou 'Ciseaux'.   \n\n2. L'ordinateur ou votre adversaire fera également  un choix.   \n\n3. Les résultats sont déterminés comme suit :   \n\n   - \"Roche\" écrase \"Ciseaux\".   \n   - \"Ciseaux\" coupent \"Papier\".   \n   - \"Papier\" enveloppe \"Roche\".   \n\n4. En cas de choix identiques, c'est une égalité.   \n\nBonne chance et amusez-vous bien !\n\n";
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

    do{
        system("cls");
        int note_jeu = 0;
        int note_boot = 0;
        int jeu , nbr_tours;

        while(1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\nentrer le nbr de tours : ");

            if(scanf("%d",&nbr_tours) != 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer un nbr positif.\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                while(getchar() != '\n');
                continue;
            }

            if(nbr_tours>0) {
                Sleep(20);
                system("cls");
                break;
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer un nbr positif.\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        for(int i=0;i<nbr_tours;i++){
            system("cls");
            char ma[] = "\nEntrer : \n\n     1 pour roche.\n\n     2 pour papier.\n\n     3 pour ciseau.\n\n";
            int BO = strlen(ma);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
            for(int i=0;i<BO;i++){
                Sleep(5);
                printf("%c",ma[i]);
            }

            while(1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("Votre choix : ");

                if(scanf("%d",&jeu) != 1) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\nentrer '1' ou '2' ou '3'\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    while(getchar() != '\n');
                    continue;
                }

                if(jeu == 1 || jeu == 2 || jeu == 3) {
                    Sleep(20);
                    system("cls");
                    break;
                } else {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("\nentrer '1' ou '2' ou '3'\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("          vous",note_jeu);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("                      boot",note_boot);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            int jeu_boot = genererAleatoire(min,max);

            if(jeu==1 && jeu_boot==1){
                roche_roche();
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                printf("\n                        Nul\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(1000);
            }
            if(jeu==1 && jeu_boot==2){
                roche_papier();
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\n                       Perdu\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                note_boot++;
                Sleep(1000);
            }
            if(jeu==1 && jeu_boot==3){
                roche_ciseau();
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("\n                       Gagne\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                note_jeu++;
                Sleep(1000);
            }
            if(jeu==2 && jeu_boot==1){
                papier_roche();
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("\n                       Gagne\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                note_jeu++;
                Sleep(1000);
            }
            if(jeu==2 && jeu_boot==2){
                papier_papier();
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                printf("\n                        Nul\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(1000);
            }
            if(jeu==2 && jeu_boot==3){
                papier_ciseau();
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\n                       Perdu\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                note_boot++;
                Sleep(1000);
            }
            if(jeu==3 && jeu_boot==1){
                ciseau_roche();
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\n                       Perdu\n");
                note_boot++;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(1000);
            }
            if(jeu==3 && jeu_boot==2){
                ciseau_papier();
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("\n                       Gagne\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                note_jeu++;
                Sleep(1000);
            }
            if(jeu==3 && jeu_boot==3){
                ciseau_ciseau();
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                printf("\n                        Nul\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(1000);
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("\n      vous : %d",note_jeu);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("                  boot : %d\n\n",note_boot);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
            for(int i=0;i<la;i++){
                Sleep(10);
                printf("%c",cont[i]);
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            _getch();
        }
        ///////////////////////////////////////////////////
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
        printf("\nVous : %d pts\n",note_jeu);
        printf("\nBoot : %d pts\n",note_boot);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        if(note_boot<note_jeu){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("\nVous avez gagné !\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }else if(note_boot>note_jeu){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\nVous avez perdu !\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }else{
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("\nMatch nul\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

        printf("\nVoulez-vous rejouer ? (1 pour Oui, 0 pour Non) : \n\n");

        while(1) {
            printf("Votre choix : ");

            if(scanf("%d", &again) != 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer '0' ou '1'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                while(getchar() != '\n');
                continue;
            }

            if(again == 0 || again == 1) {
                break;
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer '0' ou '1'\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }

    }while(again == 1);

    Sleep(700);
    char mad[] = "\n\n                    Ooooookey           \n\n";
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




