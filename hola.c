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
    evaluar_esquinas(iteraciones,matriz);

}

void evaluar_esquinas(int iteraciones,int matriz[7][7]){
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
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }



              if(matriz[1][0]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }

              //evaluando la casilla 1,1

            if(matriz[1][1]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
        //termina evaluar casilla 1,1

            //Evaluación de supervivencia
            if(matriz[0][0]==1){
                if(contador_vivas<2){
                    matriz[0][0]=0;

                }

            }if(matriz[0][0]==0]){
                if(contador_vivas==3){
                     matriz[0][0]=1;

                }

            }
             imprimir_matriz(matriz);
            }//fin esquina superior izquierda


//_____________________________________________________________________________________________________________________________________-
//inicio esquina superior derecha
      if(i==0 && j==6){
            printf("esquina ");
            contador_vivas=0;
            if(matriz[0][5]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
            //termina evaluar casilla 0,0


            //evaluando la casilla 1,0

            if(matriz[1][5]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
            //termina evaluar casilla 0,1


              //evaluando la casilla 1,1

            if(matriz[1][6]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
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



            }//fin esquina inferior izquierda



//____________________________________________________________________________________________________________________________________________________
          //------------inicio esquina inferior izquierdaa
            if(i==6 && j==0){
                    printf("esquina ");
                    contador_vivas=0;
            if(matriz[5][0]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
            //termina evaluar casilla 0,0

            //evaluando la casilla 1,0

            if(matriz[5][1]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
            //termina evaluar casilla 0,1


              //evaluando la casilla 1,1

            if(matriz[6][1]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
            //termina evaluar casilla 1,1
              //Evaluación de supervivencia
            if(matriz[6][0]==1){
                if(contador_vivas<2){
                    matriz[6][0]=0;

                }

            }if(matriz[6][0]==0]){
                if(contador_vivas==3){
                     matriz[6][0]=1;

                }

            }
             imprimir_matriz(matriz);
            }

//___________________________________________________________________________________________________________________________________________________________
//------------inicio esquina inferior derecha
             if(i==6 && j==6){
                        printf("esquina ");
                    contador_vivas=0;
            if(matriz[5][6]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
            //termina evaluar casilla 0,0

            //evaluando la casilla 1,0

            if(matriz[5][5]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
            //termina evaluar casilla 0,1


              //evaluando la casilla 1,1

            if(matriz[6][5]==1)
            {
                printf("\ndetecto celula viva\n");
                contador_vivas=contador_vivas+1;
                 printf("vivas:%d",contador_vivas);
            }
            else{
                printf("\ndetecto celula muerta\n");
                contador_muertas=contador_muertas+1;
                printf("muertas:%d",contador_muertas);
            }
            //termina evaluar casilla 1,1
              //Evaluación de supervivencia
            if(matriz[6][6]==1){
                if(contador_vivas<2){
                    matriz[6][6]=0;

                }

            }if(matriz[6][6]==0]){
                if(contador_vivas==3){
                     matriz[6][6]=1;

                }

            }
             imprimir_matriz(matriz);
            }
            }//for

        }


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

