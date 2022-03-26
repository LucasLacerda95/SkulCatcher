#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

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
int positionX, positionY, keyPressed = 0;
int xFruit = 0;
int yFruit = 0;
int points = 0;


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
    }else if (positionY > 15)
    {
        positionY = 15;
    }
    else if (positionX > 10)
    {
        positionX = 10;
    }
}

void makeMatrix()
{

    int axleX, axleY = 0;

    int rond = 0;
    for (int jogadas = 0; jogadas < 10000; jogadas++)
    {   
        
        header();
        for (int cont0 = 0; cont0 <= 10; ++cont0)
        {
            printf("\n\n   ");
            for (int cont1 = 0; cont1 <= 15; ++cont1)
            {   
                matrixLimit();
                if(rond == 0){
                srand((unsigned)time(NULL));
                xFruit = rand() % 10; 
                yFruit = rand() % 15;
                rond = 20;
                }

                int axleX = cont0;
                int axleY = cont1;

                matrix[xFruit][yFruit] = 'O';

                if(matrix[axleX][axleY] != 'O') matrix[axleX][axleY] = '.';
                if(axleX == positionX && axleY == positionY) matrix[axleX][axleY] = '@';
                       


                printf("%c", matrix[axleX][axleY]);
                printf("      ");
            }
            printf("      ");

        }
        if(positionY == yFruit && positionX == xFruit){
            jogadas++;
            points += 1;
        }    

        printf("\n");
        keyPressed = getch();
        controls(keyPressed);
        system("cls");
    }
}

void header()
{
    printf(ANSI_COLOR_BLUE "   Skul-Catcher 1.0");
    printf("\t  Captured Skulls - " ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\t\tTime - XX:XX:XX" ANSI_COLOR_BLUE);
    printf("\t\t ( %i - %i)  (%i)", positionX, positionY,points);


    return;
}

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
        break;
    case KEY_DOWN:
        positionX += 1;
        break;
    case KEY_LEFT:
        positionY -= 1;
        break;
    case KEY_RIGHT:
        positionY += 1;
        ;
        break;
    }

}

int main()
{

    system("cls");
    makeMatrix();

    return 0;
}
