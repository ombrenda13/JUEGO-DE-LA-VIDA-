#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main (){
    int opcion;
    int opcion2;
    int matriz[6][6];

        switch(menu_principal()){
        case 1:
            printf("1.- Reglas del juego");
             switch(reglas()){
                case 1:
                    system("cls");
                 menu_principal();
                break;

            }

            break;
        case 2:
            printf("2.-Iniciar Juego\n\n ");
            iniciar_juego( matriz[6][6]);
            break;
        case 3:

            switch(creditos()){
                case 1:
                    system("cls");
                 menu_principal();
                break;

            }
            break;
        }


return 0;
}
int reglas(){
    int opcion2;
     system("cls");

     printf("\n\nregla 1: Para que una celula siga viva, tiene que tener 2 o 3 vecinas. Si tiene mas, muere de SUPERPOBLACION.\n\tSi tiene menos,muere de SOLEDAD");
     printf("\nn regla 2: Si una celula esta MUERTA y tiene 3 vecinas vivas. REVIVE");
     printf("\n\n ¿Desea volver al menu principal?");
            printf("\t1.- si\t 2.- no\n");
            scanf("%d",&opcion2);
    return opcion2;

}

int creditos(){
    int opcion2;
    system("cls");
            printf("=================UNIVERSIDAD NACIONAL AUTÓNOMA DE MEXICO=================\n");
            printf("=========================FACULTAD DE INGENIERIA==========================\n");
            printf("=========================BRENDA ORTIZ MARTINEZ===========================\n");
            printf("======================Proyecto final primera parte=======================\n");

            printf("\n ¿Desea volver al menu principal?");
            printf("1.- si\t 2.- no\n");
            scanf("%d",&opcion2);
    return opcion2;

}

int menu_principal(){
    int opcion;
     printf("----------JUEGO DE LA VIDA----------");
        printf("\n\tMENU\n");
        printf("\n\t1.-Reglas del juego");
        printf("\n\t2.-Iniciar Juego");
        printf("\n\t3.-Creditos");

        printf("\n\tElige una opcion:");
        scanf("%d",&opcion);

return opcion;
}


void iniciar_juego(int matriz[7][7]){

    int i,j,iteraciones;
    int numero;
    srand(time(NULL));
    printf("TABLERO INICIAL");
    printf("\n");

    for(i=0; i<7;i++){
            for(j=0;j<7;j++){
                  matriz[i][j]=0+rand()%2;
                  printf("|%d|",matriz[i][j]);
                   }
            printf("\n");
            }
    printf("Ingresa las iteraciones que quieres realizar:");
    scanf("%d",&iteraciones);
    //for(iteraciones){}

    int matriz2=evaluar_esquinas(iteraciones,matriz);
    int matriz3=evaluar_lineas_externas(iteraciones,matriz2);
    evaluar_centro(iteraciones,matriz3);
}

int evaluar_esquinas(int iteraciones,int matriz[7][7]){
    int i,j,contador_vivas=0,contador_muertas=0;
    //esquina superior izquierda
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
//______________________________________________________________________________________________________________________________________________
            if(i==0 && j==0){
            printf("esquina ");
            contador_vivas=0;
            if(matriz[0][1]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
              if(matriz[1][0]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
            if(matriz[1][1]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
            //Evaluación de supervivencia
            if(matriz[0][0]==1){
                if(contador_vivas<2){
                    matriz[0][0]=0;

                }

            }if(matriz[0][0]==0){
                if(contador_vivas==3){
                     matriz[0][0]=1;

                }

            }
             imprimir_matriz(matriz);
            }//fin esquina superior izquierda


//_____________________________________________________________________________________________________________________________________-
//inicio esquina superior derecha
      if(i==0 && j==6){
            contador_vivas=0;
            if(matriz[0][5]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
            if(matriz[1][5]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
            if(matriz[1][6]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
            //termina evaluar casilla 1,1

                  //Evaluación de supervivencia
            if(matriz[0][6]==1){
                if(contador_vivas<2){
                    matriz[0][6]=0;

                }

            }
            if(matriz[0][6]==0){
                if(contador_vivas==3){
                     matriz[0][6]=1;

                }

            }
             imprimir_matriz(matriz);
            }
//____________________________________________________________________________________________________________________________________________________
          //------------inicio esquina inferior izquierdaa
            if(i==6 && j==0){
                    contador_vivas=0;
            if(matriz[5][0]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
            if(matriz[5][1]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
            //termina evaluar casilla 0,1


              //evaluando la casilla 1,1

            if(matriz[6][1]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
              //Evaluación de supervivencia
            if(matriz[6][0]==1){
                if(contador_vivas<2){
                    matriz[6][0]=0;

                }

            }if(matriz[6][0]==0){
                if(contador_vivas==3){
                     matriz[6][0]=1;

                }

            }
             imprimir_matriz(matriz);
            }

//___________________________________________________________________________________________________________________________________________________________
//------------inicio esquina inferior derecha
             if(i==6 && j==6){
                    contador_vivas=0;
            if(matriz[5][6]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }

            if(matriz[5][5]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
            if(matriz[6][5]==1)
            {
                contador_vivas=contador_vivas+1;
            }
            else{
                contador_muertas=contador_muertas+1;
            }
              //Evaluación de supervivencia
            if(matriz[6][6]==1){
                if(contador_vivas<2){
                    matriz[6][6]=0;

                }

            }if(matriz[6][6]==0){
                if(contador_vivas==3){
                     matriz[6][6]=1;

                }

            }
             imprimir_matriz(matriz);
            }
            }//for

        }

    return matriz;
    }


int evaluar_lineas_externas(int iteraciones,int matriz[7][7]){
printf("\n");
printf("EMPEZANDO LINEAS...");
int i,j,contador_vivas=0,contador_muertas=0;
int aux,aux2,aux3;
    printf("\n");
    //para la primera fila superior...
//----------------------------------------------------------------------------------------------------------------
    for(i=1;i<6;i++){
        aux=1;//indica la fila siguiente
        contador_muertas=0;
        contador_vivas=0;

        if(matriz[0][i-1]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[0][i+1]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }

        //evaluando fila de abajo
       if(matriz[aux][i]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[aux][i-1]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[aux][i+1]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }

      if(matriz[0][i]==1){
        if(contador_vivas>3){
            matriz[0][i]=0;
        }
        if(contador_vivas<2){
            matriz[0][i]=0;
        }

        }
        if(matriz[0][i]==0){
            if(contador_vivas==3){
                matriz[0][i]=1;
        }

        }
    }
        imprimir_matriz(matriz);

    //EXTREMO INFERIOR-----------------------------------
      for(i=1;i<6;i++){
        aux=5;//indica la fila para comparar
        contador_muertas=0;
        contador_vivas=0;

        if(matriz[6][i-1]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[6][i+1]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }

        //evaluando fila de abajo
       if(matriz[aux][i]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[aux][i-1]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[aux][i+1]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }

      if(matriz[6][i]==1){
        if(contador_vivas>3){
            matriz[6][i]=0;
        }
        if(contador_vivas<2){
            matriz[6][i]=0;
        }

        }
        if(matriz[6][i]==0){
            if(contador_vivas==3){
                matriz[6][i]=1;
        }

        }
    }
     imprimir_matriz(matriz);


     //EXTREMO Izquierdo-----------------------------------
      for(i=1;i<6;i++){
        aux=1;//indica la fila para comparar
        contador_muertas=0;
        contador_vivas=0;

        if(matriz[i-1][0]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[i+1][0]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }

        //evaluando fila de abajo
       if(matriz[i][aux]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[i-1][aux]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[i+1][aux]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }

      if(matriz[i][0]==1){
        if(contador_vivas>3){
            matriz[i][0]=0;
        }
        if(contador_vivas<2){
            matriz[i][0]=0;
        }

        }
        if(matriz[i][0]==0){
            if(contador_vivas==3){
                matriz[i][0]=1;
        }

        }
    }

    //EXTREMO derecho-----------------------------------
      for(i=1;i<6;i++){
        aux=1;//indica la fila para comparar
        contador_muertas=0;
        contador_vivas=0;

        if(matriz[i-1][0]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[i+1][0]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }

        //evaluando fila de abajo
       if(matriz[i][aux]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[i-1][aux]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }
        if(matriz[i+1][aux]==1){
            contador_vivas=contador_vivas+1;
        }else{
            contador_muertas=contador_muertas+1;
            }

      if(matriz[i][0]==1){
        if(contador_vivas>3){
            matriz[i][0]=0;
        }
        if(contador_vivas<2){
            matriz[i][0]=0;
        }

        }
        if(matriz[i][0]==0){
            if(contador_vivas==3){
                matriz[i][0]=1;
        }

        }
    }
 imprimir_matriz(matriz);
return matriz;
}


void evaluar_centro(int iteraciones,int matriz[7][7]){
    int i,j,k;
    int aux,aux2;
    int contador_vivas,contador_muertas;
    printf("\nCENTRO\n");
    imprimir_matriz(matriz);
      contador_vivas=0;
        contador_muertas=0;
    for(i=1;i<6;i++){
        for(j=1;j<6;j++){
          //  printf("\n");
           /* printf("soy i:%d",i);
            printf("\nsoy j:%d",j);
            printf("\n%d",matriz[i][j]);*/
            aux=j;
            aux2=j;
           contador_vivas=0;
            contador_muertas=0;

            if(matriz[i-1][aux]==1){
                contador_vivas=contador_vivas+1;
            }else{
                contador_muertas=contador_muertas+1;
            }
             if( matriz[i-1][aux-1]==1){
                contador_vivas=contador_vivas+1;
            }else{
                contador_muertas=contador_muertas+1;
            }
             if( matriz[i-1][aux+1]==1){
                contador_vivas=contador_vivas+1;
            }else{
                contador_muertas=contador_muertas+1;
            }
             if( matriz[i+1][aux]==1){
                contador_vivas=contador_vivas+1;
            }else{
                contador_muertas=contador_muertas+1;
            }
             if( matriz[i+1][aux-1]==1){
                contador_vivas=contador_vivas+1;
            }else{
                contador_muertas=contador_muertas+1;
            }
             if( matriz[i+1][aux+1]==1){
                contador_vivas=contador_vivas+1;
            }else{
                contador_muertas=contador_muertas+1;
            }
             if( matriz[i][j-1]==1){
                contador_vivas=contador_vivas+1;
            }else{
                contador_muertas=contador_muertas+1;
            }
             if( matriz[i][j+1]==1){
                contador_vivas=contador_vivas+1;
            }else{
                contador_muertas=contador_muertas+1;
            }

            //evaluando superviencia

            if(matriz[i][j]==1){
            if(contador_vivas>3){
                matriz[i][j]=0;
            }
            if(contador_vivas<2){
                matriz[i][j]=0;
            }

            }
            if(matriz[i][j]==0){
                if(contador_vivas==3){
                    matriz[i][j]=1;
            }

            }



        }
    }

    imprimir_matriz(matriz);
}

void imprimir_matriz(int matriz[7][7]){
    int i,j;
    printf("\n");
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            printf("|%d|",matriz[i][j]);
                   }
            printf("\n");
            }
}


