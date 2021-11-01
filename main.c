#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int randomnum();


int main()
{
srand(time(0));
int num_players;
int difficulty;
printf("Cuantos jugadores hay: ");
scanf("%d", &num_players);
printf("Escoga el nivel de dificultad(1=facil, 2=media, 3=dificil)\n(1) 7 turnos 2) 5 turnos 3) 3 turnos): ");
scanf("%d", &difficulty);

if(difficulty=1){
    printf("Cada jugador tendra 7 turnos\n");
}
else if(difficulty=2){
    printf("Cada jugador tendra 5 turnos\n");
}
else if(difficulty=3){
    printf("Cada jugador tendra 3 turnos\n");
}

 int matrix[9][9];
int columns,rows;
for(columns=0;columns<=8;columns++){
    for(rows=0;rows<=8;rows++){
            matrix[columns][rows]= rand()%9+1;
            printf(" |%d|" ,matrix[columns][rows]);
    }
    printf("\n");
}
return 0;
}


int randomnum(){
srand(time(0));
printf("%d ",(rand() %9) + 1);
printf("\n");
}

