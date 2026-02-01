#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>


int genererAleatoire(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void print_timer(int s , int sd , int m , int md , int h , int hd){

    printf("\t          ,--.-----.--.\n\t          |--|     |--|\n\t          |  |-----|  |\n\t        __|--|     |--|__\n\t       /  |  |-----|  |  \\\n\t      /   \\__|-----|__/   \\\n\t     /   ______---______   \\/\\\n\t    /   /     timer     \\   \\/\n\t   {   /   /---------\\   \\   }\n\t   |  |   | %d%d:%d%d:%d%ds |   |  |\n\t   {   \\   \\---------/   /   }\n\t    \\   `------___------'   /\\\n\t     \\     __|-----|__     /\\/\n\t      \\   /  |-----|  \\   /\n\t       \\  |--|     |--|  /\n\t        --|  |-----|  |--\n\t          |--|     |--|\n\t          `--'-----`--'\n\t   ",hd,h,md,m,sd,s);

}


int main() {
    setlocale(LC_ALL, "");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int hd=0 ,h=0 ,md=0 ,m=0 ,sd=0 ,s=0 ;
    int chois ;
    char intro[] = "Entrer :\n\n1. pour le chronom�tre.\n\n2. pour le minuteur.\n";
    int rep = strlen(intro);
    for(int i=0;i<rep;i++){
        printf("%c",intro[i]);
        Sleep(20);
    }
    while(1) {
        printf("\nVotre choix : ");

        if(scanf("%d", &chois) != 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\nentere '1' ou '2' \n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            while(getchar() != '\n');
            continue;
        }

        if(chois == 1 || chois == 2) {
            break;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\nentere '1' ou '2' \n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    if(chois==1){
        system("cls");
        char cont[] = "\npress any key to start : ";
        int la = strlen(cont);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        for(int i=0;i<la;i++){
            Sleep(20);
            printf("%c",cont[i]);
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        _getch();
        system("cls");
        while(hd<10){
            print_timer(s,sd,m,md,h,hd);
            s = genererAleatoire(0,9);
            sd++;
            if(sd==6){
                sd=0;
                m++;
            }
            if(m==10){
                m=0;
                md++;
            }
            if(md==6){
                md=0;
                h++;
            }
            if(h==10){
                h=0;
                hd++;
            }
            Sleep(83);
            system("cls");
        }
    }
    if(chois==2){
        system("cls");
        int min ;
        printf("Entrer le nbr des min : ");
        scanf("%d",&min);
        Sleep(300);
        system("cls");
        char cont[] = "\npress any key to start : ";
        int la = strlen(cont);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        for(int i=0;i<la;i++){
            Sleep(20);
            printf("%c",cont[i]);
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        _getch();
        system("cls");
        min-- ;
        hd = min / 10 ;
        h = min % 10 ;
        md = 5 ;
        m = 9 ;
        sd = 5 ;
        while(hd!=0 || h!=0 || md!=0 || m!=0 || sd!=0){
            system("cls");
            print_timer(s,sd,m,md,h,hd);

            s = genererAleatoire(0,9);
            sd--;
            if(sd==0 && m!=0){
                sd=5;
                if(m>0){
                    m--;
                }
            }
            if(m==0 && md!=0){
                m=9;
                if(md>0){
                    md--;
                }
            }
            if(md==0 && h!=0){
                md=5;
                if(h>0){
                    h--;
                }
            }
            if(h==0 && hd!=0){
                h=9;
                hd--;
            }
            Sleep(83);
            system("cls");
        }
            printf("\t          ,--.-----.--.\n\t          |--|     |--|\n\t          |  |-----|  |\n\t        __|--|     |--|__\n\t       /  |  |-----|  |  \\\n\t      /   \\__|-----|__/   \\\n\t     /   ______---______   \\/\\\n\t    /   /     timer     \\   \\/\n\t   {   /   /---------\\   \\   }\n\t   |  |   | 00:00:00s |   |  |\n\t   {   \\   \\---------/   /   }\n\t    \\   `------___------'   /\\\n\t     \\     __|-----|__     /\\/\n\t      \\   /  |-----|  \\   /\n\t       \\  |--|     |--|  /\n\t        --|  |-----|  |--\n\t          |--|     |--|\n\t          `--'-----`--'\n\t   ");

            Beep(261, 400); // C
            Beep(261, 400); // C
            Beep(392, 400); // G
            Beep(392, 400); // G
            Beep(440, 400); // A
            Beep(440, 400); // A
            Beep(392, 800); // G (longer)

            Sleep(200);

            Beep(349, 400); // F
            Beep(349, 400); // F
            Beep(330, 400); // E
            Beep(330, 400); // E
            Beep(294, 400); // D
            Beep(294, 400); // D
            Beep(261, 800); // C (longer)

            Sleep(400);

            Beep(392, 400); // G
            Beep(392, 400); // G
            Beep(349, 400); // F
            Beep(349, 400); // F
            Beep(330, 400); // E
            Beep(330, 400); // E
            Beep(294, 800); // D (longer)

            Sleep(200);

            Beep(392, 400); // G
            Beep(392, 400); // G
            Beep(349, 400); // F
            Beep(349, 400); // F
            Beep(330, 400); // E
            Beep(330, 400); // E
            Beep(294, 800); // D (longer)
    }

    return 0;
}

