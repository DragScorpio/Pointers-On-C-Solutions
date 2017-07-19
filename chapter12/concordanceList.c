/* 12.8-7 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MEM_DEFICIT "Memory is insufficient for more allocations."

/* crucial technique: incomplete structure declaration - mutually dependent structs */
typedef struct SECONDARY_LST SecondList;
typedef struct CONCORDANCE_LST {
	char letter;
	struct CONCORDANCE_LST *next;
	SecondList *strList;
} ConcordList;

struct SECONDARY_LST { /* secondary list of concordance list */
	char *string;
	struct SECONDARY_LST *next;
};

/* member functions */
int implement_list( ConcordList **rootPtr );
int insert_list( ConcordList *root, char const *string );
void print_list( ConcordList *root );
void free_list( ConcordList *root );

/* main */
int main( void ) {
	ConcordList *root;
	int flag;
	char string[20];
	if( implement_list( &root ) ) {
		do {
			printf( "Insert a word: " );
			scanf ( "%s", string );
			if( insert_list( root, string ) )
				printf( "Word is inserted\n" );

			printf( "Do you want to continue [1 / 0]: " );
			scanf( "%d", &flag );
		} while( flag );
	}

	print_list( root );
	free_list( root );
	return 0;
}

int implement_list( ConcordList **rootPtr ) {
/* each list starts with an alphabetic; starting from 'a' to 'z' */
	int i;
	for( i = 0; i < 26; i++, rootPtr = &(*rootPtr)->next ) {
		*rootPtr = (ConcordList *)malloc( sizeof( ConcordList ) );
		if( *rootPtr == NULL ) {
			printf( "%s\n", MEM_DEFICIT );
			return 0;
		}

		(*rootPtr)->letter = 'a' + i;
		(*rootPtr)->strList = NULL;
	}

	*rootPtr = NULL;
	return 1;
}

int insert_list( ConcordList *root, char const *string ) {
	int compare;
	char *newString;
	SecondList *current, *previous, *newList;

	while( root != NULL ) {
	/* categorize the word by its first letter */
		if( isalpha( *string ) && root->letter == tolower( *string ) )
			break;

		root = root->next;
	}
	if( root == NULL ) { /* In case string does not start with an alphabet */
		printf( "An illegal word was ignored!\n" );
		return 0;
	}

	current = root->strList;
	newList = (SecondList *)malloc( sizeof( SecondList ) );
	newString = (char *)malloc( strlen( string ) + 1 );
	if( newList == NULL && newString == NULL ) {
		printf( "%s\n", MEM_DEFICIT );
		return 0;
	}

	newList->string = strcpy( newString, string );
	if( current == NULL ) { /* insert into an empty secondary list */
		newList->next = NULL;
		root->strList = newList;
	}
	else { /* insert into a non-empty secondary list */
		while( current != NULL && ( compare = strcmp( current->string, string ) ) < 0 ) {
			previous = current;
			current = current->next;
		}

		newList->next = current;
		if( current == root->strList )
			root->strList = newList;
		else
			previous->next = newList;
	}
	return 1;
}

void print_list( ConcordList *root ) {
/* print format: alphabet: string1 --> string2 --> string3 -->...  */
	SecondList *current;
	while( root != NULL ) {
		printf( "%c: ", root->letter );
		current = root->strList;
		root = root->next;

		if( current == NULL )
			printf( "\n" );
		else {
			while( current->next != NULL ) {
				printf( "%s--->", current->string );
				current = current->next;
			}
			printf( "%s\n", current->string );
		}
	}
}

void free_list( ConcordList *root ) {
	ConcordList *curList, *prevList;
	SecondList *curNode, *prevNode;

	curList = root;
	while( curList != NULL ) {
		curNode = curList->strList;
		while( curNode != NULL ) {
			prevNode = curNode;
			curNode = curNode->next;
			free( prevNode->string );
			free( prevNode );
		}
		prevList = curList;
		curList = curList->next;
		free( prevList );
	}
}
