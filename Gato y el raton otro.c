//JUEGO DEL GATO Y EL RATÓN. INTELIGENCIA ARTIFICIAL
#include <stdio.h>

void turnos (char c[3][3]);
void opciones (char c[3][3]);
void tablero (char c[3][3]);
void jugadaHumana (char c[3][3]);
void jugadaIA (char c[3][3]);
int ganar (char c[3][3]);

int main ()
{
    char c [3][3]; //Matriz de tres por tres para el tablero
    turnos (c); //Función que repite las funciones fundamentales y usa la matriz como parámetro de entrada
    system("pause");
    return 0;
}

void turnos (char c[3][3]){
//Esta función permnite que eñl juego sea por turnos
    int j; //para guardar la funcion de ganar
    char opcion;
    opciones (c);//Función que imprime los números en el tablero
    do{
        int i = 0;//Valor que define los turnos que en este caso son 9
        do{
                system("cls");//Limpia la consola para que no se vean muchos tableros por cada jugada
                tablero(c);//Imprime el tablero
                if(i % 2 == 0)//Si el turno es impar le toca al humano
                {
                    jugadaHumana(c);
                }else//Si es par le toca a la IA
                {
                    jugadaIA(c);
                }
                j = ganar(c);
                i++;

        }while (i<9 && j == 2);
        system("cls");
        tablero(c);
        //Compara el valor de J para saber quien gana
        if(j == 0){
            printf("Ganaste\n\n");
        }else if (j == 1){
            printf("Te gano la IA\n\n");
        }else{
            printf("Nadie gano\n\n");
        }
        printf("Desea jugar de nuevo?\n 1 = SI, 2 = NO\n");
        fflush(stdin);
        scanf ("%c", &opcion); //Lee el caracter que introdujo el usuario
        system("cls");
        opciones(c);
    }while (opcion == '1');

}

void opciones (char c[3][3]){
//En este void lo que quiero que le salga al jugador son las opciones que tiene en el tablero para jugar
//Se reflejan en la misma mátriz del tablero por lo que aparece lleno, lo que hará el jugador es elegir un número y ese
//número se intercambiará por su ficha, eso representa un movimiento.
    int i, j;
    char aux;
    aux = '1';

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            c[i][j] = aux++;
        }
    }
}

void tablero (char c[3][3]){
//Este void es para hacer las líneas que delimitan el tablero del gato y el ratón
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (j < 2){
                printf(" %c |", c[i][j]);
            }
            else{
                printf(" %c ", c[i][j]);
            }
        }
        if (i < 2){
        printf("\n-----------\n");
        }
    }
    printf("\n\n");

}

void jugadaHumana (char c[3][3]){
    int i, j, v;
    char aux;

    do{
        do{
            printf("Elije un numero para colocar tu ficha: \n");
            fflush(stdin);
            scanf ("%c", &aux); //Lee el caracter que introdujo el usuario

        }while(aux < '1' || aux > '9');
        v = 0;

        switch (aux){
            case '1': {
                i = 0;
                j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;
            }

            case '2': {
                i = 0;
                j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;

            }

            case '3': {
                i = 0;
                j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;

            }

            case '4': {
                i = 1;
                j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;

            }

            case '5': {
                i = 1;
                j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;

            }

            case '6': {
                i = 1;
                j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;

            }

            case '7': {
                i = 2;
                j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;

            }

            case '8': {
                i = 2;
                j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;

            }

            case '9': {
                i = 2;
                j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O' || c[i][j] == 'x' || c[i][j] == 'o'){
                    v = 1;
                    printf ("Casilla ocupada, intenta con otro numero\n");

                }break;

            }
        }
    }while (v == 1);

    c[i][j] = 'X';
}

void jugadaIA (char c[3][3]){
    int i, j, v;
    srand (time(NULL)); //funcion para usar numeros random
    do{
        i = rand() % 3; //Elije un numero random entre el 0 y el tres
        j = rand () % 3;
        v = 0;

        if (c[i][j] == 'X' || c[i][j] == 'O')
        {
            v = 1;
        }
    }while (v ==1);

    c[i][j] = 'O';
}

int ganar (char c[3][3]){
//Compara las posibles jugadas ganadoras con la casilla en la que haya elegido uno de los jugadores
    //Si tira en la casilla 1 ya sea la IA o el humano
    if(c[0][0] == 'X' || c[0][0] == 'O'){
        //Compara que las siguientes casillas en j sean iguales a la 1
        if (c[0][0] == c[0][1] && c[0][0] == c[0][2]){
            //Si lo son y es una X entonces...
            if (c[0][0] == 'X'){
                return 0; //Jugador humano gana
            }else if (c[0][0] == 'O'){
                return 1; // IA gana
            }
        }
        //Compara que las siguientes casillas en i sean iguales a la 1
        if (c[0][0] == c[1][0] && c[0][0] == c[2][0]){
            //Si lo son y es una X entonces...
            if (c[0][0] == 'X'){
                return 0; //Jugador humano gana
            }else if (c[0][0] == 'O'){
                return 1; // IA gana
            }
        }
    }
    //Si tira en la casilla 5 ya sea la IA o el humano
    if(c[1][1] == 'X' || c[1][1] == 'O'){
        //Compara si son iguales las casillas en diagonal
        if(c[1][1] == c[0][0] && c[1][1] == c[2][2]){
            //Si lo son y es una X entonces...
            if (c[1][1] == 'X'){
                return 0; //Jugador humano gana
            }else if (c[1][1] == 'O'){
                return 1; // IA gana
            }
        }
        //Compara si son iguales las casillas en vertical
        if(c[1][1] == c[0][1] && c[1][1] == c[2][1]){
            //Si lo son y es una X entonces...
            if (c[1][1] == 'X'){
                return 0; //Jugador humano gana
            }else if (c[1][1] == 'O'){
                return 1; // IA gana
            }
        }
        //Compara si son iguales las casillas en horizontal
        if(c[1][1] == c[1][0] && c[1][1] == c[1][2]){
            //Si lo son y es una X entonces...
            if (c[1][1] == 'X'){
                return 0; //Jugador humano gana
            }else if (c[1][1] == 'O'){
                return 1; // IA gana
            }
        }
        //Compara si son iguales las casillas en la otra diagonal
        if(c[1][1] == c[0][2] && c[1][1] == c[2][0]){
            //Si lo son y es una X entonces...
            if (c[1][1] == 'X'){
                return 0; //Jugador humano gana
            }else if (c[1][1] == 'O'){
                return 1; // IA gana
            }
        }
    }
    //Si tira en la casilla 9 ya sea la IA o el humano
    if (c[2][2] == 'X' || c[2][2] == 'O'){
        //Compara si son iguales las casillas en i
        if(c[2][2] == c[0][2] && c[2][2] == c[1][2]){
            //Si lo son y es una X entonces...
            if (c[2][2] == 'X'){
                return 0; //Jugador humano gana
            }else if (c[2][2] == 'O'){
                return 1; // IA gana
            }
        }
        //Compara si son iguales las casillas en j
        if (c[2][2] == c[2][0] && c[2][2] == c[2][1]){
            //Si lo son y es una X entonces...
            if (c[2][2] == 'X'){
                return 0; //Jugador humano gana
            }else if (c[2][2] == 'O'){
                return 1; // IA gana
            }
        }
    }
    return 2;
}
