/* matrices - example solution*/

#include <stdio.h>

int main()
{
   float m1[3][3]= { { 12, 5.3, 10.0 }, { 5, 10.2, -2 },  { 1, -1, 3 } };
   float m2[3][3]= { { 2.1, -3, 1.5 },  { 10, -12, 3.1 }, { 4, 8.2, -2 } };
   float sum[3][3];
   float prod[3][3];

   int i, j;

   for(i=0; i<3; i=i+1)
      for(j=0; j<3; j=j+1)
         sum[i][j]=m1[i][j]+m2[i][j];
   
   for(i=0; i<3; i=i+1)
      for(j=0; j<3; j=j+1)
		 prod[i][j]=m1[i][0]*m2[0][j] + m1[i][1]*m2[1][j] + m1[i][2]*m2[2][j];
   // Note, the calculation of the three products could also be done with an additional loop

   // i denotes the line, j the column of the matrix
   for(i=0; i<3; i=i+1) {
      for(j=0; j<3; j=j+1) 
		  printf("%6.1f ", m1[i][j]);
	  printf(i==1? "  *  ": "     ");
	  for(j=0; j<3; j=j+1) 
		  printf("%6.1f ", m2[i][j]);
	  printf(i==1? "  =  ": "     ");
      for(j=0; j<3; j=j+1) 
		  printf("%6.1f ", prod[i][j]);
	  printf("\n");
   }
   getchar();
}