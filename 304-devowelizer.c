/* devowelizer / revowelizer
TO DO 1: Extend the program such that it replaces all vowels in the text with other vowels.
TO DO 2: Extend the program such that the replacement vowel is chosen randomly.
Hint: List the vowels in an additional array ...
Use rand() to generate random numbers
TO DO 3: Modify the programm such that it removes all vowels (and shortens the text accordingly)
TO DO 4 (optional): Write an encryption/decryption program which encodes texts by defining
in a table how each character shall be replaced by another one.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
	srand(time(0));
	char txt[1000];
	int i;
	char vowel_lc[5] = { 'a', 'e', 'i', 'o', 'u' }, vowel_uc[5] = { 'A', 'E', 'I', 'O', 'U' };

	printf("Please enter your text:");

	scanf("%[^\n]", txt);

	i = 0;
	while (txt[i] != 0)
	{
		for (int n = 0; n<5; n++) {
			if (txt[i] == vowel_lc[n]) {
				int r = rand() % 5; //auswahl zwischen 5 Möglichkeiten
				txt[i] = vowel_lc[r];
			}
			if (txt[i] == vowel_uc[n]) {
				int r = rand() % 5;
				txt[i] = vowel_uc[r];
			}
		}
		i = i + 1;
	}
	printf("%s", txt);
	printf("\n");
	
		
}