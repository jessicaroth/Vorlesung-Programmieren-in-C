/*
TO DO 1: Use the preprocessor #define directive and modify your previous programs, 
         - e.g. define constants such as maximum values / array sizes, shortcuts for special ascii characters etc.
         - Optionally, try to define macros by using parameters with #define.
         - What problems might occur with such macros (and how can they be solved?):
           example: #define square(x)  x*x
                    result=square(5+4);
					Das Problem wäre, dass als Ergebnis 29 rauskommen würde, der Preprocessor beachtet keine Prioritäten, und deshalb rechnet er
					folgendes Szenario: 5+4*5+4 und das wäre 29 und nicht 81.
					Wenn man dies solven will, dann muss man Klammern setzen: entweder sq((5+4)) oder #define square(x) ((x)*(x))
                    y=1;
					result=square(++y); 
					Das rechnet der Preprozessor: ++y * ++y --> bei dem Beispiel y=1 würde das Ergebnis 2*3=6 sein und nicht 1.
		   Deshalb wichtig: Bei sowas immer viele Klammern setzen!
				

TO DO 2: Have a look at <stdio.h> and other standard header files and see how preprocessor directives are used there


Preprocessor directives:
# include  	include a source file
# define 	define a macro
# undef 	undefine a macro
# if 	    conditional compilation
# ifdef 	conditional compilation
# ifndef 	conditional compilation
# elif 	    conditional compilation
# else 	    conditional compilation
# endif 	conditional compilation

*/