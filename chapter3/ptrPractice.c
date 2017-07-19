#include <stdio.h>
char* returnstring( char* );
int* returnint( int c );
int main( void ) {
	char string[10] = "a string";
	printf( "%s\n", returnstring( string ) );
	printf( "%i\n", *returnint(20) );
	return 0;
}

char* returnstring( char* string ) {
	char str1[10] = "the string";
//	char* str = str1; //DOES NOT WORK!!!!
	char* str = "the string";
//	char str[10] = "the string"; //DOES NOT WORK!!!!

//	char* str = string; //WORKABLE!
	return str;
}
/*
I can tell you why you can return str, but not str1:
first of all, a string literal, like anyother literals, are stored somewhere in the memory, not the runtime stack!
secondly, when a funtion returns, runtime stack var are destroyed, only the copy of return var is passed to memory.
Ok, let's come to the difference between char str*, and char str1[10]:
the char* str, makes the pointer "str" point to string literal "the string", so that when you return str, it always
points to the literal in memory; in other words, the string literal in memory is always there! A second fact is, you
cannot modify string literal by doing something like: *(str + 3) = 'X'; No!!

the statement char str1[10] = " the strint" actually initialize str1[0] = 't', str1[1] = 'h', str1[2] = 'e',...etc.
meanwhile, str1 NEVER points to the string literal!!! Secondly, we CAN MODIFY the value by saying str[2] = 'X', it
acts like a variable! just like: *(str1 + 2) = 'X';
However, the address str1, or str1 + i, is R-VALUE!!!! meaning when can assign: str = str1 + 3, but we CANNOT assign
str1 = 'some pointer'!!!!!

Finally, when function returns, the str1[i] just is discarded with the runtime stack. So that's why you will see
nothing
*/

int* returnint( int c ) {
/*
	int* value;
	int k = 20;
	value = &k;
	return value;
*/
/*
	int value;
	value = 20;
	return &value;
*/
	int* value = &c;
	return value;
}
