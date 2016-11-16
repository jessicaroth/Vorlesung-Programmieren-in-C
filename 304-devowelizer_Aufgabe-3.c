/*
 ============================================================================
 Name        : aufgabe_304_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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
   char vowel[10];
   vowel[0]='a';
   vowel[1]='e';
   vowel[2]='i';
   vowel[3]='o';
   vowel[4]='u';
   vowel[5]='A';
   vowel[6]='E';
   vowel[7]='I';
   vowel[8]='O';
   vowel[9]='U';


   printf("Please enter your text:");

   scanf("%[^\n]", txt);

   i=0;
   for(int i=0; txt[i]!=0; i++) { //geht alle Buchstaben des Worts durch
	   for(int n=0; n<10; n++) { // geht alle Vokale durch
		   if(txt[i]==vowel[n]) { // Überprüft ob Buchstabe ein Vokal
		       for(int z=i; txt[z]!=0; z++) { 
		    		 txt[z]=txt[z+1]; // Ersetzt für den Fall Vokal jeden Buchstaben des Wortes ab dem Vokal mit dem jeweils nächsten Buchstaben
		    	  }
		       i--; //Verkleinert i, damit das Wort in der neuen Reihenfolge nochmals durchgenommen wird (überprüft, ob an derselben Stelle wieder ein Vokal vorkommt)
		       }
		   }
   }
   printf("%s", txt);
   printf("\n");
}

