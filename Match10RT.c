#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//cosas incluidas
//declaracion de funciones
void startmatrix(int n, int m, int matrix[n][m]);
void new_matrix(int n, int m, int matrix[n][m]);

int main()
{

    printf("Reglas del juego. \nEl jugador tiene que buscar pareja de numeros. Las parejas deben ser del mismo valor o sumar 10.\n");
    printf("Las parejas pueden formarse con numeros adyacentes de forma horizontal, vertical o diagonal.\n");
    printf("Se pueden formar parejas entre numeros separados con celdas vacias y tambi�n son validas todas las direcciones.\n");
    printf("El valor final de una linea (lado derecho) puede hacer pareja con el valor inicial de la siguiente linea(lado izquierdo)");
    printf("Si ya no quedan mas opciones, se puede agregar m�s lineas que contendran los mismos numeros, que aun se encuentran en la matriz.\n");
    printf("El objetivo es despejar el tablero o matriz, cuando se eliminan todos los numeros de una fila, esta se elimina\n\n");
    printf("Al eliminar todos los numeros, el jugador avanza de fase y el tablero se vuelve a llenar con numeros.");
    printf("El juego termina cuando en el tablero no se pueden crear parejas y no se pueden agregar mas lineas.\n\n");

    int guess1, guess2, guess3, guess4;
// definicion de variables
    int row, column;
    row = 9;
    column = 9;
    int matrix[row][column];
    int game_over = 0;
    int game_loop = 1;
    srand(time(0));
    int num_players;
    int difficulty;
    printf("Cuantos jugadores hay: ");
    scanf("%d", &num_players);
    printf("Escoga el nivel de dificultad\n1=facil\n2=media\n3=dificil\n1) 7 vidas 2) 5 vidas 3) 3 vidas): ");
    scanf("%d", &difficulty);
    int turns;
    bool emptyrow;
// numero de vidas
    if (difficulty == 1)
    {
        turns = 7;
        printf("Cada jugador tendra 7 vidas\n");
    }

    else if (difficulty == 2)
    {
        turns = 5;
        printf("Cada jugador tendra 5 vidas\n");
    }

    else if (difficulty == 3)
    {
        turns = 3;
        printf("Cada jugador tendra 3 vidas\n");
    }
//main game
    startmatrix(row, column, matrix);
    do
    {

        printf("Ingrese su primera eleccion\n");
        scanf("%d", &guess1);
        scanf("%d", &guess2);
        int slot1 = matrix[guess1][guess2];
        printf("Su eleccion es :%d", slot1);
        printf("\n");

        printf("Ingrese su segunda eleccion\n");
        scanf("%d", &guess3);
        scanf("%d", &guess4);
        int slot2 = matrix[guess3][guess4];
        printf("\n");

        printf("Su eleccion es :%d \n", slot2);

        if ((slot1 + slot2) == 10)
        {
            matrix[guess2][guess1] = 0;
            matrix[guess4][guess3] = 0;
            printf("Suman 10, porfavor escoja otra pareja de numeros.\n");
            printf("Tiene %d turnos", turns);
            printf("\n");
            new_matrix(row, column, matrix);
        }
        else if (slot1==slot2)
            {
            matrix[guess1][guess2] = 0;
            matrix[guess3][guess4] = 0;
            printf("Son parejas .\n");
            printf("Tiene %d turnos", turns);
            printf("\n");
            new_matrix(row, column, matrix);
        }
        else(((slot1+slot2) < 10));
        {   printf("Los numeros ingresados no suma 10, ni son parejas.\n Porfavor ingrese otra eleccion. Tiene %d vidas\n", turns - 1);
            turns--;
            new_matrix(row, column, matrix);
            if(turns==0){
                exit(1);
            }
        }

//revision de filas 0000000
        for (int rows = 0; rows < 8; rows++)
        {
            bool empty = true;
            for (int col = 0; col < 8; col++) {
                if (matrix[rows][col] != 0)
                {
                    empty = false;
                    break;
                }
            }

            if (empty) {
                for (int j = rows; j < 8; j++)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        matrix[j][k] = matrix[j + 1][k];
                    }
                }
            }
        }
        for(int n=1; n<=9; n++){
            int found=0;
            for(row=0;row<=8;row++){
                for(column=0;column<=8;column++){
                    if(matrix[row][column]== n){
                        found= found+1;
                    }
                }
                if(found==1){
                    for(row=0;row<=8;row++){
                        for(column=0;column<=8;column++){
                            if(matrix[row][column]==0){
                                matrix[row][column]==n;
                            }
                        }
                    }
                }
            }
        }
    } while (turns > 0);

    return 0;
}
// funciones
void startmatrix(int n, int m, int matrix[n][m])
{
    int columns, rows;
    for (columns = 0; columns <= 8; columns++)
    {
        for (rows = 0; rows <= 8; rows++)
        {
            matrix[rows][columns] = rand() % 9 + 1;
            printf(" |%d|", matrix[rows][columns]);
        }

        printf("\n");
    }
}
void new_matrix(int n, int m, int matrix[n][m])
{
    int columns = 9;
    int rows = 9;
    for (columns = 0; columns <= 8; columns++)
    {
        for (rows = 0; rows <= 8; rows++)
        {
            printf("|%d|", matrix[rows][columns]);
        }

        printf("\n");
    }
}
