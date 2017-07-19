/* 1.8-3 */
#include<stdio.h>
int checksum(char *ch);
int main(void) {
	char* str = "Hello, this world!\nI am going to conquer it...";
	// char* str = "Hello world!\n";
	return checksum(str);
}

int checksum(char *ch) {
	signed char sum = -1;
	while(*ch != EOF && *ch) {
		sum = sum + *ch;
		putchar(*ch);
		ch = ch + 1;
	}
	(*(ch-1) == 10)?(printf("%d\n", sum)):(printf("\n%d\n", sum));
	return 1;
}
