#include <stdlib.h>
#include <stdio.h>
#include "Util.h"
#include <math.h>

int main(int argc, char* argv[])
    {
    FILE* ifp;

    int ich1, ich2, rows, cols, maxval=255;
    int i, j;
    int min,max;
    min = max = 0;



    /* Arguments */
    if ( argc != 2 ){
      printf("\nUsage: %s file \n\n", argv[0]);
      exit(0);
    }

    /* Opening */
    ifp =  fopen(argv[1],"r");
    if (ifp == NULL) {
      printf("error in opening file %s\n", argv[1]);
      exit(1);
    }

    /*  Magic number reading */
    ich1 = getc( ifp );
    if ( ich1 == EOF )
        pm_erreur( "EOF / read error / magic number" );
    ich2 = getc( ifp );
    if ( ich2 == EOF )
        pm_erreur( "EOF /read error / magic number" );
    if(ich2 != '2')
      pm_erreur(" wrong file type ");

    /* Reading image dimensions */
    cols = pm_getint( ifp );
    rows = pm_getint( ifp );
    maxval = pm_getint( ifp );
    int n,k;
    n=4;
    gray* graymapList[n];
/* Memory allocation  */
    for(k=0; k<n ;k++)
    {
     graymapList[k]= (gray *) malloc(cols * rows * sizeof(gray));
    }

    /* Reading */
    for(i=0; i < rows; i++)
      for(j=0; j < cols ; j++)
          graymapList[0][i * cols + j] = pm_getint(ifp);

    /* Writing */
    printf("P2\n");

    printf("%d %d \n", cols, rows);
    printf("%d\n",maxval);

    for(i=0; i < rows; i++){
      for(j=0; j < cols ; j++){
        if( i-1 == (-1)){
              graymapList[1][i*cols+j]= abs((  graymapList[0][i * cols + j]*0 +   graymapList[0][i * cols + j + 1]*0 +   graymapList[0][i * cols + j - 1]*(-10)  +   graymapList[0][(i+1) * cols + j]*0 +   graymapList[0][(i+1) * cols + j + 1]*3+   graymapList[0][(i+1) * cols + j - 1]*(-3) )/16 );
              graymapList[2][i*cols+j]= abs((graymapList[0][i * cols + j]*0 + graymapList[0][i * cols + j + 1]*0 + graymapList[0][i * cols + j - 1]*0  + graymapList[0][(i+1) * cols + j]*10 + graymapList[0][(i+1) * cols + j + 1]*3+ graymapList[0][(i+1) * cols + j - 1]*3 )/16 );

            }
            else if( j-1 == (-1) ){
              graymapList[1][i*cols+j]= abs((  graymapList[0][i * cols + j]*0 +   graymapList[0][i * cols + j + 1]*10 +   graymapList[0][(i-1) * cols + j]*0 +   graymapList[0][(i+1) * cols + j]*0  +   graymapList[0][(i-1) * cols + j + 1]*3 +    graymapList[0][(i+1) * cols + j + 1]*3 )/16 );
              graymapList[2][i*cols+j]= abs((graymapList[0][i * cols + j]*0 + graymapList[0][i * cols + j + 1]*0 + graymapList[0][(i-1) * cols + j]*(-10) + graymapList[0][(i+1) * cols + j]*10  + graymapList[0][(i-1) * cols + j + 1]*(-3) +  graymapList[0][(i+1) * cols + j + 1]*3 )/16);

            }
            else if ( i+1 == rows ){
              graymapList[1][i*cols+j]= abs((  graymapList[0][i * cols + j]*0 +   graymapList[0][i * cols + j + 1]*10 +  graymapList[0][i * cols + j - 1]*(-10) +   graymapList[0][(i-1) * cols + j]*0+   graymapList[0][(i-1) * cols + j - 1]*(-3) +   graymapList[0][(i-1) * cols + j + 1]*3 )/16 );
              graymapList[2][i*cols+j]= abs((graymapList[0][i * cols + j]*0 + graymapList[0][i * cols + j + 1]*0 +graymapList[0][i * cols + j - 1]*0 + graymapList[0][(i-1) * cols + j]*(-10)+ graymapList[0][(i-1) * cols + j - 1]*(-3) + graymapList[0][(i-1) * cols + j + 1]*(-3) )/16 );

            }
            else if( j+1 == cols){
              graymapList[1][i*cols+j]= abs((  graymapList[0][i * cols + j]*0 +   graymapList[0][i * cols + j - 1]*(-10) +   graymapList[0][(i-1) * cols + j]*0 +   graymapList[0][(i+1) * cols + j]*0 +   graymapList[0][(i-1) * cols + j - 1]*(-3)+   graymapList[0][(i+1) * cols + j - 1]*(-3) )/16 );
              graymapList[2][i*cols+j]= abs((graymapList[0][i * cols + j]*0 + graymapList[0][i * cols + j - 1]*0 + graymapList[0][(i-1) * cols + j]*(-10) + graymapList[0][(i+1) * cols + j]*10 + graymapList[0][(i-1) * cols + j - 1]*(-3)+ graymapList[0][(i+1) * cols + j - 1]*3 )/16 );

            }
            else{
              graymapList[1][i*cols+j]= abs((  graymapList[0][i * cols + j]*0 +  graymapList[0][i * cols + j + 1]*10 +  graymapList[0][i * cols + j - 1]*(-10) +   graymapList[0][(i-1) * cols + j]*0 +   graymapList[0][(i+1) * cols + j]*0 +   graymapList[0][(i-1) * cols + j - 1]*(-3) +   graymapList[0][(i-1) * cols + j + 1]*3 +    graymapList[0][(i+1) * cols + j + 1]*3+   graymapList[0][(i+1) * cols + j - 1]*(-3) )/16 );
              graymapList[2][i*cols+j]= abs((graymapList[0][i * cols + j]*0 + graymapList[0][i * cols + j + 1]*0 +graymapList[0][i * cols + j - 1]*0 + graymapList[0][(i-1) * cols + j]*(-10) + graymapList[0][(i+1) * cols + j]*10 + graymapList[0][(i-1) * cols + j - 1]*(-3) + graymapList[0][(i-1) * cols + j + 1]*(-3) +  graymapList[0][(i+1) * cols + j + 1]*3+ graymapList[0][(i+1) * cols + j - 1]*3 )/16 );
          }
        }

      }
      int result;

      for(i=0; i < rows; i++){
        for(j=0; j < cols ; j++){
          result = pow(graymapList[1][i*cols+j],2) + pow(graymapList[2][i*cols+j],2);
          graymapList[3][i*cols+j]=sqrt(result);
          if (graymapList[3][i*cols+j] > max)
             max = graymapList[3][i*cols+j];
          if(graymapList[3][i*cols+j] < min)
            min = graymapList[3][i*cols+j];
          }
        }

        for(i=0; i < rows; i++){
          for(j=0; j < cols ; j++){
            printf("%d ", 255*((graymapList[3][i * cols + j])-min)/(max - min) );
            }
          }


      /* Closing */
      fclose(ifp);
      return 0;
}
