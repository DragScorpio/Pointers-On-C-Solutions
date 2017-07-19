/* 1.8-4 */
#include<stdio.h>
#include<string.h>
char* longestInputLine(char line[]);
int main(void) {
	char longestLine[1000];
	printf("%s\n", longestInputLine(longestLine));
	return 0;
}

char* longestInputLine(char line[]) {
	int i = 0;
	int length = 0;
	int longestLength = 0;
	int ch;
	char nextLine[1000];
	char newLine[1000];
	while((ch = getchar()) != EOF) {
		if(ch == 10) {
			nextLine[i] = '\0';
			length = i;
			i = 0;
			if(length > longestLength) {
				longestLength = length;
				strcpy(line, nextLine);
			}
			strcpy(nextLine, newLine);
		}
		else {
			nextLine[i] = ch;
			i = i + 1;
		}
	}
	return line;
}
