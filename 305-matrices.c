/* matrices */
// TO DO: Extend the programm such that the result is printed
// TO DO: Extend the programm such that it also calculates the product of the two 3x3 matrices.

#include <stdio.h>

void printMatrix(float f[3][3]) {
	for (int n = 0; n < 3; n++) {
		for (int z = 0; z < 3; z++){
			printf("%f", f[z][n]);
		}
		printf("\n");
	}
}

int main()
{
	float m1[3][3] = { { 12, 5.3, 10.0 }, { 5, 10.2, -2 }, { 1, -1, 3 } };
	float m2[3][3] = { { 2.1, -3, 1.5 }, { 10, -12, 3.1 }, { 4, 8.2, -2 } };
	float sum[3][3];
	float mul[3][3];
	float f[3][3];

	int i, j;

	printf("Addition: \n");
	for (i = 0; i < 3; i = i + 1) {
		for (j = 0; j < 3; j = j + 1) {
			sum[i][j] = m1[i][j] + m2[i][j];
		}
	}

	/*for (int n = 0; n < 3; n++) {
		for (int z = 0; z < 3; z++){
			printf("%f", sum[z][n]);
		}
	}
	*/
	printMatrix(sum);
	printf("\n");
		
	printf("\nMultiplikation: \n");
	for (int x = 0; x < 3; x=x+1) {
		for (int y = 0; y < 3; y= y+1) {
			mul[x][y] = m1[x][y] * m2[x][y];
		}
	}

	/*for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++){
			printf("%f", mul[b][a]); */
		printMatrix(mul);
		printf("\n");
}
	
/* Ulis Code
#include <stdio.h>

int main()
{
float m1[3][3] = { { 12, 5.3, 10.0 }, { 5, 10.2, -2 }, { 1, -1, 3 } };
float m2[3][3] = { { 2.1, -3, 1.5 }, { 10, -12, 3.1 }, { 4, 8.2, -2 } };
float sum[3][3];
float mul[3][3];

int i, j;

printf("3+3\n");
for (i = 0; i < 3; i = i + 1) {
for (j = 0; j < 3; j = j + 1) {
sum[i][j] = m1[i][j] + m2[i][j];
printf("%6.1f", sum[i][j]);
}
printf("\n");
}
printf("\n");

printf("3x3\n");
for (i = 0; i < 3; i = i + 1) {
for (j = 0; j < 3; j = j + 1) {
mul[i][j] = m1[i][j] * m2[i][j];
printf("%6.1f", mul[i][j]);
}
printf("\n");
}

getchar();
}*/
