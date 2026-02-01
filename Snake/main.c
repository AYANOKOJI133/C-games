#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 13
#define MAX_SNAKE_LENGTH 100

// Directions
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Snake and game variables
int snakeX[MAX_SNAKE_LENGTH], snakeY[MAX_SNAKE_LENGTH];
int snakeLength;
int foodX, foodY;
int score;
int gameOver;
int direction;
int speed;

// Function prototypes
void initializeGame();
void drawGrid();
void generateFood();
void moveSnake();
int checkCollision();

void sauvegarderHighScore(int high_score) {
    FILE *fichier = fopen("high_score.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier!\n");
        return;
    }
    fprintf(fichier, "%d\n", high_score); // tktb fi le fichier
    fclose(fichier);
}

void sauvegardername(char name[]) {
    FILE *fichier = fopen("name.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier!\n");
        return;
    }
    fprintf(fichier, "%s\n", name); // tktb fi le fichier
    fclose(fichier);
}

int lireHighScore() {
    FILE *fichier = fopen("high_score.txt", "r");
    int highScore = 0;
    if (fichier == NULL) {
        return 0;
    }
    fscanf(fichier, "%d", &highScore); // lire
    fclose(fichier);
    return highScore;
}

/*
char lireHero() {
    FILE *fichier = fopen("name.txt", "r");
    char hero[] = "" ;
    if (fichier == NULL) {
        return 0;
    }
    fscanf(fichier, "%[^\n]s", &hero); // lire
    fclose(fichier);
    return hero;
}
*/
char* lireHero() {
    setlocale(LC_ALL, "");
    FILE *fichier = fopen("name.txt", "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier !\n");
        return NULL;
    }

    char *hero = malloc(100 * sizeof(char));
    if (hero == NULL) {
        printf("Erreur : échec d'allocation mémoire !\n");
        fclose(fichier);
        return NULL;
    }

    if (fgets(hero, 100, fichier) != NULL) {
        size_t longueur = strlen(hero);
        if (longueur > 0 && hero[longueur - 1] == '\n') {
            hero[longueur - 1] = '\0';
        }
    } else {
        printf("Erreur : le fichier est vide ou la lecture a échoué !\n");
        free(hero);
        fclose(fichier);
        return NULL;
    }

    fclose(fichier);
    return hero;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = 0;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void initializeGame() {
    snakeLength = 3;
    for (int i = 0; i < snakeLength; i++) {
        snakeX[i] = WIDTH / 2 - i;
        snakeY[i] = HEIGHT / 2;
    }

    direction = RIGHT;
    score = 0;
    gameOver = 0;

    generateFood();
}

void drawGrid() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");

    // Top border
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("+");
    for (int i = 0; i < WIDTH ; i++) {
        printf("-");
    }
    printf("+");
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    // Grid and snake
    for (int y = 0; y < HEIGHT; y++) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("|");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        for (int x = 0; x < WIDTH; x++) {
            int isSnake = 0;

            // Check if snake is at this position
            for (int i = 0; i < snakeLength; i++) {
                if (snakeX[i] == x && snakeY[i] == y) {
                    isSnake = 1;
                    break;
                }
            }

            if (isSnake) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("O");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else if (x == foodX && y == foodY) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                printf("¤");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                printf(" ");
            }
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("|\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    // Bottom border
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("+");
    for (int i = 0; i < WIDTH ; i++) {
        printf("-");
    }
    printf("+");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\n\nScore: %d\n", score);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void generateFood() {
    while (1) {
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;

        int isOnSnake = 0;
        for (int i = 0; i < snakeLength; i++) {
            if (snakeX[i] == foodX && snakeY[i] == foodY) {
                isOnSnake = 1;
                break;
            }
        }

        if (!isOnSnake) {
            break;
        }
    }
}

void moveSnake() {
    // Move the snake's body
    for (int i = snakeLength - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    // Move the snake's head
    switch (direction) {
        case UP:    snakeY[0]--; break;
        case DOWN:  snakeY[0]++; break;
        case LEFT:  snakeX[0]--; break;
        case RIGHT: snakeX[0]++; break;
    }

    // Check if the snake eats the food
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        snakeLength++;
        score++;
        generateFood();
    }
}

int checkCollision() {
    // Check wall collision
    if (snakeX[0] < 0 || snakeX[0] >= WIDTH || snakeY[0] < 0 || snakeY[0] >= HEIGHT) {
        return 1;
    }

    // Check self-collision
    for (int i = 1; i < snakeLength; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            return 1;
        }
    }

    return 0;
}


int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "");
    hideCursor();
    initializeGame();
    int again;


    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");
    char v[] = "\n            Bienvenue dans le jeu Snake ! \n\n--> Règles du jeu :   \n\n1. Contrôlez un serpent qui se déplace sur l'écran.\n\n2. Mangez la nourriture '¤' pour grandir et gagner  des points.   \n\n3. Évitez les murs et ne vous mordez pas la queue,  sinon c'est la fin de la partie.   \n\n--> Objectif :\n\nObtenez le meilleur score possible en survivant le  plus longtemps et en mangeant le maximum de         nourriture !\n\nBonne chance !\n\n";
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

    //scanf("%c",&o);

    ///////////////////////////////////////////////////////////
    do{
        hideCursor();
        initializeGame();
        system("cls");


        while(1) {
            printf("\nEntrer la vitesse que tu veux : ");

            if(scanf("%d",&speed) != 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer un nbr positive\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                while(getchar() != '\n');
                continue;
                }
            if(speed>=0) {
                break;
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("\nentrer un nbr positive\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }

        Sleep(400);
        system("cls");

        while (!gameOver) {
            if (_kbhit()) {
                switch (_getch()) {
                    case 'z': if (direction != DOWN) direction = UP; break;
                    case 'Z': if (direction != DOWN) direction = UP; break;
                    case 's': if (direction != UP) direction = DOWN; break;
                    case 'S': if (direction != UP) direction = DOWN; break;
                    case 'q': if (direction != RIGHT) direction = LEFT; break;
                    case 'Q': if (direction != RIGHT) direction = LEFT; break;
                    case 'd': if (direction != LEFT) direction = RIGHT; break;
                    case 'D': if (direction != LEFT) direction = RIGHT; break;
                }
            }


            moveSnake();

            if (checkCollision()) {
                gameOver = 1;
                break;
            }

            drawGrid();
            //Sleep(speed); // Control speed
        }


        gotoxy(0, HEIGHT + 2);

        int highScore = lireHighScore();
        //char hero = lireHero();
        char heero[50];
        getchar();
            if (score > highScore) {
                //system("cls");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                printf("\nNouveau high score atteint ! \"%d\"\n\n", score);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                printf("Entrer votre nom : ");
                //getchar();
                scanf("%[^\n]s",&heero);
                getchar();
                printf("\nWelcome ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                puts(heero);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                sauvegardername(heero);
                sauvegarderHighScore(score);
            }else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("Game Over! \n\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("\nThe last record :      ");

                //int record_nbr = lireHighScore();

                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
                printf(" %d pts ",lireHighScore());
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("for ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                puts(lireHero());
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
            printf("\n");
            for(int i=0;i<la;i++){
                Sleep(10);
                printf("%c",cont[i]);
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            _getch();
            system("cls");
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




