#include <stdlib.h>
#include <stdio.h>
#include "Util.h"


int main(int argc, char* argv[])
    {
    FILE* ifp;
    gray* graymap;
    gray* gx;

    int ich1, ich2, rows, cols, maxval=255;
    int i, j;
    /* Arguments */
    if ( argc != 2 ){
      printf("\nUsage: %s file \n\n", argv);
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

    /* Memory allocation  */
    graymap = malloc( cols * rows * sizeof(gray));
    gx = malloc( cols * rows * sizeof(gray));

    /* Reading */
    for(i=0; i < rows; i++)
      for(j=0; j < cols ; j++){
          graymap[i * cols + j] = pm_getint(ifp);
      }
    /* Writing */
    printf("P2\n");
    printf("%d %d \n", cols, rows);
    printf("%d\n",maxval);

    for(i = 0; i < rows; i++)
      for(j = 0; j < cols ; j++)
         gx[i * cols + j] = ((graymap[i * cols + j + 1]*10 +graymap[i * cols + j - 1]*(-10) + graymap[(i-1) * cols + j - 1]*(-3) + graymap[(i-1) * cols + j + 1]*3 +  graymap[(i+1) * cols + j + 1]*3+ graymap[(i+1) * cols + j - 1]*(-3)) /16);

    for(i=0; i < rows; i++)
      for(j=0; j < cols ; j++)
        printf("%d ", gx[i * cols + j]);
        

      /* Closing */
      fclose(ifp);
      return 0;
}
