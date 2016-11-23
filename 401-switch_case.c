// Switch case: Order your burger...
// TO DO 1: Replace the if-statements with switch case and add a default case for invalid input
// TO DO 2: Add support for extra-large and fish burgers
// TO DO 3: Extend the program such that is executed in a loop, which can be aborted by entering 'q' as size
// TO DO 4: If there is a much longer list of options: How can long if-else-chains / switch-case-statements be avoided?
// TO DO 5: Optional: Any further ideas for additional sizes and options?

#include <stdio.h>

 main() {
	char size, specials, equal;
	int height = 0;
	int loop = 1;
	int c = 1;
	int b = 0;
	float price = 0;

	while (loop){
		while (!b){
			printf("Which size you want your burger (s=small, m=medium, l=large, x=extra-large)?");
			scanf("%c", &size);

			switch (size){
			case 's': height = 1; price = 2.5f; b++; break;
			case 'm': height = 2; price = 3.5f; b++;  break;
			case 'l': height = 4; price = 5.9f; b++; break;
			case 'x': height = 8; price = 7.9f; b++;  break;
			case 'q': b++; b++; loop--; c--; break;
			default: printf("\nPlease use s,m,l,x."); break;
			}
		}

		/*if (size == 's')
		{
		height = 1;
		price = 2.5f;
		}
		else if (size == 'm')
		{
		height = 2;
		price = 3.5f;
		}
		else if (size == 'l')
		{
		height = 4;
		price = 5.9f;
		}
		else if (size == 'x') {
		height = 8;
		price = 7.9f;
		}*/
		if (c){
			printf("Any specials (r=regular: beef, v=veggie, c=cheese, f=fish)?");
			scanf("\n%c", &specials);
			printf("\n\n.-\"\"\"\"-.\n");
			while (height--) {
				switch (specials){
				case 'c': printf(" ------ \n"); break;
				case 'v': printf("(xxxxxx)\n"); break;
				case 'r': printf("(mmmmmm)\n"); break;
				case 'f': printf("(~~~~~~)\n"); break;
				}
			}
			/*   if(specials=='c') printf(" ------ \n");
			   if(specials=='v') printf("(xxxxxx)\n");
			   if (specials== 'r') printf("(mmmmmm)\n");
			   if (specials == 'f') printf("(~~~~~~)\n"); */

			// TODO: add options for fish burgers...
			printf("\\______/\n");
			printf("\n\n%.2f Euro - Enjoy!", price);
			b--;
			getchar();
		}
	}
} 