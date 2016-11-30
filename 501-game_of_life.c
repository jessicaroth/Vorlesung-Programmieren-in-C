// TO DO: Complete the programm such that it simulates the game of life.
//        Do this as teamwork (e.g. in teams with 2 or 3)
//        and benefit from the fact the functions can developed separately and then integrated into the final program.
// TO DO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states.
// TO DO optional 2: let the program find a start state, such that the system stays alive and unstable for as long as possible
// TO DO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
// TO DO optional 4: extend the program, such that the content of the cells can be edited by the user.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAXX 20
#define MAXY 30

// Global 2-dim-array which contains the cells
char cells[MAXX][MAXY];

// TO DO: initialize cells, set most to 0, some to 1
void initialize_cells()
{
	srand(time(0));
	int i, j, rd;
	   for(i=0; i<MAXX; i++) {
		   for(j=0; j<MAXY; j++) {
			 rd=rand()%10;
			 if (rd<8) {
				 cells[i][j]=0;
			 } else {
				 cells[i][j]=1;
			 }
	   }
   }
}

// TO DO: Write output function to show the cells
void display_cells()
{
   system("CLS");
   printf("________________________________");
   for (int z1=0; z1<MAXX; z1++) {
	   printf("\n|");
	   for (int z2=0; z2<MAXY; z2++) {
		   switch(cells[z1][z2]) {
		   case 0: printf(" "); break;
		   case 1: printf("%c", 3); break;
		   }
	   }
	   printf("|");
   }
   printf("\n________________________________");
}

// TO DO: Write a function to calculate the next evolution step
void evolution_step()
{
   int alive;
   char cells_helper[MAXX][MAXY];

   //Geht alle Zellen durch
   for (int n1=0; n1<MAXX; n1++) {
	   for (int n2=0; n2<MAXY; n2++) {
		   alive=0;

		   //Zählt alle lebenden Nachbarzellen
		   for (int x=-1; x<=1; x++) {
			   for (int y=-1; y<=1; y++) {

				   if (cells[n1+x][n2+y]==1) {
					   //Damit Zelle selbst nicht mitgezahlt wird
					   if (!(x==0 && y==0)) {
						   //Damit Rand nicht mitgezählt wird
						   if(!(n1+x<0 || n2+y<0 || n1+x>=MAXX || n2+y>MAXY)) {
							   alive++;
						   }
					   }
				   }
			   }
		   }

		   //Wenn Zelle bereits lebt bei 2 oder 3 Nachbarn weiterleben, sonst sterben
		   if (cells[n1][n2]) {
			   if(alive==2 || alive==3) {
				   cells_helper[n1][n2]=1;
			    } else {
			    	cells_helper[n1][n2]=0;
			    }
		   }
		   //Wenn Zelle tot bei 3 neu geboren, sonst bleibt sie tot
		   else {
			   if(alive==3) {
				   cells_helper[n1][n2]=1;
			   } else {
				   cells_helper[n1][n2]=0;
			   }
		   }

	   }
   }

   //Beschreibt Zellen mit Inhalt aus Zellen-Hilfe (damit vorher immer mit aktuellen Zellen weiter gerechnet wird und nicht bereits mit der nächsten Generation
   for (int m1=0; m1<MAXX; m1++) {
	   for (int m2=0; m2<MAXY; m2++) {
		   cells[m1][m2]=cells_helper[m1][m2];
	   }
   }

}

int count_cells()
{
	int counter=0;
	for(int n=0; n<MAXX; n++) {
		for(int m=0; m<MAXY; m++) {
			if (cells[n][m]==1) {
				counter++;
			}
		}
	}
	return counter;
}

// Main program
int main()
{
setvbuf(stdout, NULL, _IONBF, 0);
   initialize_cells();

   while(1) {
      display_cells();

      // Leave loop if there are no more occupied cells
      if(count_cells()==0)
	     EXIT_FAILURE;

      printf("\nLebende Zellen: %d", count_cells());
      printf("\nPress enter");
	  getchar();

	  Sleep(25);
      evolution_step();
   }
}
