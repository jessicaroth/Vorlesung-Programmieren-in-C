// Ackermann: calculate the Ackermann function 
// The mathematical Ackermann function is defined as follows:
//
//    A(m,n) =   n+1              if m=0
//               A(m-1,1)         if m>0 and n=0
//               A(m-1, A(m,n-1)) if m>0 and n>0
//
// TO DO 1: Write a function that calculates the Ackermann function according to the definition above
//          Test the program with very small values first!
// TO DO 2: Extend the function such that it counts the number of functions calls (use a global variable cnt)
//          Print the function arguments and current count every n function calls. 
// TO DO 3: Count the amount of recursively called functions (which are not yet completed) and print them as well
// TO DO 4: Use static variables in ackermann for counting rather than global variables.
// TO DO 5: Optional: Provide values m and n via the command line
//          Allow in addition the option '-v' (verbose), to switch on output of intermediate results
// TO DO 6: Optional: Visualize the current recursion depth with bars of ascii-characters: xxxxxxxxxxxxxxxxxx

#include <stdio.h>

int ack(int x, int y){
	if (y == 0 && x > 0){
		return ack(x - 1, 1);
	}
	if (x > 0 && y > 0)
	{
		return ack(x - 1, ack(x, y - 1));
	}
	if (x == 0)
	{
		return y + 1;
	}
}

int main()
{
	int n, m;
   printf("Value for m: ");
   scanf("%d", &m);
   printf("Value for n: ");
   scanf("%d", &n);
   int result = ack(m, n);
   printf("Ergebnis ist %d\n", result);
}
