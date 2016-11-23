/* number_puzzle.c
Write a number puzzle program by completing the TO DOs
TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly distributed in the array.
-1 should mark the empty field.
TO DO 2: get key and move pieces accordingly (if keystroke is valid)
TO DO 3: Check, if puzzle is in correct order -> set sorted=1
TO DO 4: Create a more fancy output, e.g. by creating frames around the numbers
(Use a special character e.g. a block rather than '*')
(Also, mark the empty field rather than showing -1)

*********************
*  1 *  2 *  3 *  4 *
*********************
*  5 *  6 *  7 *  8 *
*********************
*  9 * 10 * 11 * 12 *
*********************
* 13 * 14 * 15 ******
*********************

TO DO 5, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user interaction.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int puzzle[4][4];
char key;
int emptyFieldX = 0;
int emptyFieldY = 0;

char keys[4] = "wasd";

void clearPuzzle(){
	for (int x = 0; x < 4; x++){
		for (int y = 0; y < 4; y++){
			puzzle[x][y] = 0;
		}
	}
}
void setPuzzleRandom(){
	clearPuzzle();

	srand(time(0));
	emptyFieldX = rand() % 4;
	emptyFieldY = rand() % 4;
	puzzle[emptyFieldX][emptyFieldY] = -1;

	int num = 1;
	while (num <= 15){
		int randPosX = rand() % 4;
		int randPosY = rand() % 4;
		if (puzzle[randPosX][randPosY] == 0){
			puzzle[randPosX][randPosY] = num;
			num++;
		}
	}
}

void showPuzzle(){
	printf("%2d %2d\n", emptyFieldX, emptyFieldY);
	for (int y = 0; y < 4; y++){
		for (int x = 0; x < 4; x++){
			printf("%2d ", puzzle[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

int isSorted(){
	int correct = 1;
	for (int x = 0; x < 4; x++){
		for (int y = 0; y < 4; y++){
			if (correct != puzzle[x][y] && x != 4 && y != 4) //wrong
				return 0;
			correct++;
		}
	}
	return 1;
}

int isKeyValid(){
	switch (key){
	case 'w': if (emptyFieldY < 3) return 1; break;
	case 'a': if (emptyFieldX < 3) return 1; break;
	case 's': if (emptyFieldY > 0) return 1; break;
	case 'd': if (emptyFieldX > 0) return 1; break;
	default: return 0;
	}
	return 0;
}

int transformKeyToMovementX(){
	switch (key){
	case 'a': return 1;
	case 'd': return -1;
	default: return 0;
	}
}

int transformKeyToMovementY(){
	switch (key){
	case 'w': return 1;
	case 's': return -1;
	default: return 0;
	}
}

void move(int mx, int my){
	int moveFieldX = emptyFieldX + mx;
	int moveFieldY = emptyFieldY + my;

	int moveNum = puzzle[moveFieldX][moveFieldY];

	puzzle[moveFieldX][moveFieldY] = -1;
	puzzle[emptyFieldX][emptyFieldY] = moveNum;

	emptyFieldX = moveFieldX;
	emptyFieldY = moveFieldY;
}


int solutionWithMove(char k){
	//try the new move with key = k
	printf("try new move with key = %c", k);
	key = k;
	if (isKeyValid() == 1) move(transformKeyToMovementX(), transformKeyToMovementY());
	else return 0;
	showPuzzle();
	if (isSorted() == 1)return 1;
	else{
		//first undo move with key = k;
		printf("undo move with key = %c", k);
		move(-transformKeyToMovementX(), -transformKeyToMovementY());
		//then try other moves !(key = k)
		for (int i = 0; keys[i] != 0; i++){
			if (keys[i] != k){
				if (solutionWithMove(keys[i])) return 1;
			}
		}
	}
	return 0;
}

int main()
{
	setPuzzleRandom();
	showPuzzle();

	

	  while(!isSorted()) {
	     printf("move into direction?");
         key=getchar();
	      printf("\n");
	      if (isKeyValid() == 1){
	    	  move(transformKeyToMovementX(), transformKeyToMovementY());
	    	  showPuzzle();
	      }
	      else{
	    	  printf("please enter a valid direction (w,a,s,d)!\n");
	      }
	   }
}
