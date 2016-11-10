/* Shuffles a string */
// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled 
//          (a name may consist of several parts separated by spaces).
// TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two 
// TO DO 4: How can a user make the program crash? What could be done against that problem?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   srand(time(0));
   char name[100], c;
   int i= 0, p1, p2;

   printf("Please enter your name:\n");
   scanf("%[^\n]",name);
	
   while(i<10) 
   {
      p1=rand()%strlen(name);
      p2=rand()%strlen(name);
	  if (p1 && p2 && name[p1] != ' ' && name[p1 - 1] != ' ' && name[p2 - 1] != ' '){
		  c = name[p1];
		  name[p1] = name[p2];
		  name[p2] = c;
		  printf("Hello %s\n", name);
		  i++; //Nur bei Tausch Loopcounter erhöhen
	  }
      
   }
   getchar(); getchar();
}  