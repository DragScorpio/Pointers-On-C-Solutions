#include <stdio.h>

typedef struct NODE {
	int price;
	char prod_num[10];
	struct NODE *next;
	struct NODE *prev;
} Node;

typedef struct TRANSACTION {
	int quantity;
	Node *node;
} Transaction;
/* operation types */
enum { NEW = 0, DELETE = 1, FORWARD = 2, BACKWARD = 3, SEARCH = 4, EDIT = 5 } Trans_type;

/* function prototype */
void add_new_trans( Node *, Transaction * );
Node *delete_trans( Node *, Node * );
Node *search_trans( Node *, Transaction * );
void edit_trans( Node *, Transaction * );

/* unified function prototype */
void addNewTrans( Node **current, Node *list, Transaction *transaction ) {
	add_new_trans( list, transaction );
}

void delTrans( Node **current, Node *list, Transaction *transaction ) {
	*current = delete_trans( *current, list );
}

void fwdTrans( Node **current, Node *list, Transaction *transaction ) {
	if( *current != NULL )
		current = &(*current)->next;
}

void bwdTrans( Node **current, Node *list, Transaction *transaction ) {
        if( *current != NULL )
                current = &(*current)->prev;
}

void searchTrans( Node **current, Node *list, Transaction *transaction ) {
	*current = search_trans( list, transaction );
}

void editTrans( Node **current, Node *list, Transaction *transaction ) {
		edit_trans( list, transaction );
}

void (*oper_trans[])( Node **, Node *, Transaction * ) = {
	addNewTrans, delTrans, fwdTrans, bwdTrans, searchTrans, editTrans };

int main( void ) {
	Node *list, *current;
	Transaction *transaction;
	...
	oper_trans[Trans_type]( &current, list, transaction );
	return 0;
}
