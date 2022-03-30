#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define KEY_ENTER 13 + 256
#define KEY_ESPACO 32 + 256
#define KEY_UP 72 + 256
#define KEY_DOWN 80 + 256
#define KEY_LEFT 75 + 256
#define KEY_RIGHT 77 + 256
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_GRAY "\e[0;37m"
#define ANSI_COLOR_RESET "\x1b[0m"

char matrix[10][15];
char menu[3];
int positionX, positionY = 0;
int positionMenuX, selectMenu, backMenu = 0;
int keyPressed = 0;
int xFruit = 0;
int yFruit = 0;
int points = -1;
char playerName = 'Lucas';
int recordPosition = 0;
int record1, record2, record3 = 0;

void controls(int keyPressed)
{

    if (keyPressed == 0 || keyPressed == 224 || keyPressed == 13 || keyPressed == 32)
    {
        keyPressed = (256 + getch());
    }
    switch (keyPressed)
    {
    case KEY_UP:
        positionX -= 1;
        positionMenuX -= 1;
        break;
    case KEY_DOWN:
        positionX += 1;
        positionMenuX += 1;
        break;
    case KEY_LEFT:
        positionY -= 1;
        break;
    case KEY_RIGHT:
        positionY += 1;
        ;
        break;
    case KEY_ENTER:
        selectMenu += 1;
        break;
    case KEY_ESPACO:
        return 0;
        break;
    }
}

void logo()
{

    printf("   __    ____  ____  _____  ____    __       ___    __    ____   ___  _   _  ____  ____\n");
    printf("  /__\\  (  _ \\(  _ \\(  _  )(  _ \\  /__\\     / __)  /__\\  (_  _) / __)( )_( )( ___)(  _ \\\n");
    printf(" /(__)\\  )   / )   / )(_)(  ) _ < /(__)\\   ( (__  /(__)\\   )(  ( (__  ) _ (  )__)  )   / \n");
    printf("(__)(__)(_)\\_)(_)\\_)(_____)(____/(__)(__)   \\___)(__)(__) (__)  \\___)(_) (_)(____)(_)\\_)\n\n\n\n\n\n");
}

void rootMenu()
{
    for (int contador = 0; contador < 3; contador++)
    {
        if (selectMenu == 1 && positionMenuX == 2) return 0;

        int axleX = contador;

        if (positionMenuX <= 0 || positionMenuX > 2)
        {
            positionMenuX = 0;
            menu[0] = '>';
        }
        else
        {
            menu[0] = ' ';
        }
        if (positionMenuX == 1)
        {
            menu[1] = '>';
        }
        else
        {
            menu[1] = ' ';
        }
        if (positionMenuX == 2)
        {
            menu[2] = '>';
        }
        else
        {
            menu[2] = ' ';
        }

        if (menu[axleX] != '>')
            menu[axleX] = ' ';
        if (contador >= 2)
            contador = 0;

        logo();
        printf("\t\t\t\t\t[%c] Novo Jogo\n", menu[0]);
        printf("\t\t\t\t\t[%c] Recordes\n", menu[1]);
        printf("\t\t\t\t\t[%c] Sair do Jogo\n\n\n\n\n\n\n\n\n\n\n", menu[2]);
        printf("Pressione o enter duas vezes para acessar...\n");
        printf("==========================================================================================\n");

        keyPressed = getch();
        controls(keyPressed);
        system("cls");
        if (selectMenu >= 1 && positionMenuX == 0)
            makeMatrix();
        if (selectMenu >= 1 && positionMenuX == 1)
        {
            scoreScreen();
        }
    }
}

void scoreScreen()
{

    system("cls");

    printf("\t\t\t__________                              .___\n");
    printf("\t\t\t\\______   \\ ____   ____  ___________  __| _/\n");
    printf("\t\t\t|       _// __ \\_/ ___\\/  _ \\_  __ \\/ __ | \n");
    printf("\t\t\t|    |   \\  ___/\\  \\__(  <_> )  | \\/ /_/ | \n");
    printf("\t\t\t|____|_  /\\___  >\\___  >____/|__|  \\____ | \n");
    printf("\t\t\t        \\/     \\/     \\/                 \\/ \n\n\n\n\n\n");

    printf("\t\t\t\t\tPrimeiro Lugar - %i\n", record1);
    printf("\t\t\t\t\tSegundo Lugar - %i\n", record2);
    printf("\t\t\t\t\tTerceiro Lugar - %i\n\n\n\n\n\n\n\n\n\n\n", record3);
    printf("\n\nPressione enter para retornar ao menu principal...\n");
    printf("==========================================================================================\n\n");

    system("pause");
    system("cls");
}

void matrixLimit()
{
    // limita parte de cima e esquerda da matriz
    if (positionY < 0)
    {
        positionY = 0;
    }
    else if (positionX < 0)
    {
        positionX = 0;
    }
    else if (positionY > 15)
    {
        positionY = 15;
    }
    else if (positionX > 10)
    {
        positionX = 10;
    }
}

void randonSkul()
{
    if (positionY == yFruit && positionX == xFruit)
    {
        srand((unsigned)time(NULL));
        xFruit = rand() % 10;
        yFruit = rand() % 15;
        points += 1;
    }
}

void makeMatrix()
{
    int axleX, axleY = 0;
    int rond = 0;
    for (int jogadas = 0; jogadas < 10000; jogadas++)
    {

        header();
        randonSkul();
        for (int cont0 = 0; cont0 <= 10; ++cont0)
        {
            printf("\n\n   ");
            for (int cont1 = 0; cont1 <= 15; ++cont1)
            {
                matrixLimit();
                if (rond == 0)
                {
                    srand((unsigned)time(NULL));
                    xFruit = rand() % 10;
                    yFruit = rand() % 15;
                    rond = 20;
                }

                int axleX = cont0;
                int axleY = cont1;

                matrix[xFruit][yFruit] = 'O';

                if (matrix[axleX][axleY] != 'O')
                    matrix[axleX][axleY] = '.';
                if (axleX == positionX && axleY == positionY)
                    matrix[axleX][axleY] = '@';

                printf(ANSI_COLOR_BLUE "%c", matrix[axleX][axleY]);
                printf("      ");
            }
            printf("      ");
        }

        printf("\n\n\nPara sair do jogo tecle enter...(Nao Salva)\n");
        printf("Para finalizar a partida atual e salvar o jogo, tecle espaco...\n");
        keyPressed = getch();
        controls(keyPressed);
        system("cls");
    }
}

void header()
{

    printf(ANSI_COLOR_BLUE "Skul-Catcher 1.0");
    if (points <= 0)
    {
        printf(ANSI_COLOR_RED "\tCaptured Skulls - ");
    }
    else
    {
        printf(ANSI_COLOR_RED "\tCaptured Skulls - %i" ANSI_COLOR_BLUE, points);
    }
}

void saveGame()
{

    printf("________$$$$\n");
    printf("_______$$__$\n");
    printf("_______$___$$\n");
    printf("_______$___$$\n");
    printf("_______$$___$$\n");
    printf("________$____$$\n");
    printf("________$$____$$$\n");
    printf("_________$$_____$$\n");
    printf("_________$$______$$\n");
    printf("__________$_______$$\n"); //\t\t\t\t\t     Congradulations %s your score was %i\n", playerName , points);
    printf("____$$$$$$$________$$\n");
    printf("__$$$_______________$$$$$$\n");
    printf("_$$____$$$$____________$$$\n");
    printf("_$___$$$__$$$____________$$\n");
    printf("_$$________$$$____________$\n");
    printf("__$$____$$$$$$____________$\n");
    printf("__$$$$$$$____$$___________$\n");
    printf("__$$_______$$$$___________$\n");
    printf("___$$$$$$$$$__$$_________$$\n");
    printf("____$________$$$$_____$$$$\n");
    printf("____$$____$$$$$$____$$$$$$\n");
    printf("_____$$$$$$____$$__$$\n");
    printf("_______$_____$$$_$$$\n");
    printf("________$$$$$$$$$$\n");

    FILE *pont_arq;

    pont_arq = fopen("record.txt", "w");
    fprintf(pont_arq, "Deu certo !");
    fclose(pont_arq);
}

int main()
{

    setlocale(LC_ALL, "Portuguese");
    SetConsoleTitle("@Catcher");

    rootMenu();

    return 0;
}
