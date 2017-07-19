/* 1.8-2 */
#include<stdio.h>
int readLinesFromStdin(void);
int main(void) {
	return readLinesFromStdin();
}

int readLinesFromStdin(void) {
	int i = 0;
	char ch;
	putchar(i);
	while((ch = getchar()) != EOF) {
		putchar(ch);
		if(ch == '\n') {
			i = i + 1;
			putchar(i);
		}
	}
	return 1;
}
