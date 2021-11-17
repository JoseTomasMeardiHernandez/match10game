#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void startmatrix(int n, int m, int matrix[n][m]);
void new_matrix(int n, int m, int matrix[n][m]);

int main()
{

    printf("Reglas del juego. \nEl jugador tiene que buscar pareja de numeros. Las parejas deben ser del mismo valor o sumar 10.\n");
    printf("Las parejas pueden formarse con numeros adyacentes de forma horizontal, vertical o diagonal.\n");
    printf("Se pueden formar parejas entre numeros separados con celdas vacias y tambi�n son validas todas las direcciones.\n");
    printf("El valor final de una linea (lado derecho) puede hacer pareja con el valor inicial de la siguiente linea(lado izquierdo)");
    printf("Si ya no quedan m�s opciones, se puede agregar m�s lineas que contendran los mismos numeros, que aun se encuentran en la matriz.\n");
    printf("El objetivo es despejar el tablero o matriz, cuando se eliminan todos los numeros de una fila, esta se elimina\n\n");
    printf("Al eliminar todos los numeros, el jugador avanza de fase y el tablero se vuelve a llenar con numeros.");
    printf("El juego termina cuando en el tablero no se pueden crear parejas y no se pueden agregar mas lineas.\n\n");

    int guess1, guess2, guess3, guess4;

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
    printf("Escoga el nivel de dificultad(1=facil, 2=media, 3=dificil)\n(1) 7 turnos 2) 5 turnos 3) 3 turnos): ");
    scanf("%d", &difficulty);
    int turns;
    bool emptyrow;

    if (difficulty == 1)
    {
        turns = 7;
        printf("Cada jugador tendra 7 turnos\n");
    }

    else if (difficulty == 2)
    {
        turns = 5;
        printf("Cada jugador tendra 5 turnos\n");
    }

    else if (difficulty == 3)
    {
        turns = 3;
        printf("Cada jugador tendra 3 turnos\n");
    }

    startmatrix(row, column, matrix);
    do
    {

        printf("Ingrese su primera eleccion, teniendo en cuenta que la matriz empieza desde y,x\n");
        scanf("%d", &guess1);
        scanf("%d", &guess2);
        int slot1 = matrix[guess2][guess1];
        printf("Su eleccion es :%d", slot1);
        printf("\n");

        printf("Ingrese su segunda eleccion, teniendo en cuenta que la matriz empieza desde y,x\n");
        scanf("%d", &guess3);
        scanf("%d", &guess4);
        int slot2 = matrix[guess4][guess3];
        printf("\n");

        printf("Su eleccion es :%d \n", slot2);

        if ((slot1 + slot2) == 10)
        {
            matrix[guess2][guess1] = 0;
            matrix[guess4][guess3] = 0;
            printf("Suman 10, porfavor escoja otra pareja de numeros.\n");
            new_matrix(row, column, matrix);
            printf("\n");
        }
        else if (slot1 == slot2)
        {
            printf("Porfavor, escoja otras casillas ya que escogio la misma");
            printf("\n");
        }
        else
        {
            printf("Los numeros ingresados no suma 10 o suman mas que 10.\n Porfavor ingrese otra eleccion. Tiene %d turnos\n", turns - 1);
            turns--;
        }

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
