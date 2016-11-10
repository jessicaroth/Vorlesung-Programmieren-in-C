/* prime sieve of Eratosthenes */
// TO DO 1: The program seems to work, but look carefully at the results -> There is a (typical) bug
// TO DO 2: Extend it such that the maximum number n to be calculated can be entered by the user
//          Use scanf("%d", &n)
// TO DO 3: What does this mean for the array? How should the program be adapted to work reliably? 

#include <stdio.h>

#define Max 100000

unsigned char is_prime[Max];

int main()
{
	int i, j, n;
	printf("Anzahl der zu durchsuchenden Zahlen: ");
	scanf("%d", &n);
	if (n+1 < 100000){//n+1 da informatiker ab 0 zählen und höchste Zahl abgefragt wird
		/* Initialize Array */
		for (i = 0; i <= Max && i < n+1; i = i + 1)
			is_prime[i] = 1; //es wird ausgegangen, dass alle Zahlen Primzahlen sind

		for (i = 2; i < Max && i < n+1; i = i + 1)
		for (j = 2 * i; j < Max; j = j + i) //Vielfache von 2 und j=j+i werden auf 0 gesetzt;
			is_prime[j] = 0;

		printf("Prime numbers are: ");
		for (i = 2; i < Max && i < n+1; i = i + 1) //Alle Zahlen mit Wert 1 werden ausgegeben
		if (is_prime[i]>0)
			printf("%d ", i);
	}
	else
	{
		printf("Error: Zu hohe Zahl /n"); // Falls Nutzereingabe zu hoch, error
	}
}