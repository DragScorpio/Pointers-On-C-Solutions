/* 1.8-1 */
#include<stdio.h>
int hello1(void);
int hello2(char str[], int n);
char Hello[14] = "Hello, world!";

int main(void) {
	// return hello1();
	return hello2(Hello, 14);
}

int hello1(void) {
	printf("%s", "Hello, world!");
	return 0;
}

int hello2(char str[], int n) {
	int i = 0;
	while(i < n && str[i] != '\0') {
		putchar(str[i]);
		i = i + 1;
	}
	return 1;
}
