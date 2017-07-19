#ifndef _INVENTORY_H
#define _INVENTORY_H

typedef struct PART Part;
typedef struct INVENTORY {
	/* the number of types of parts */
	unsigned int types;
	/* total value of all parts in current inventory */
	float total_val;
	/* part is a singly-linked-list */
	Part *part;
} Inventory;

struct PART {
	/* the total value of the part */
	float val;
	/* reveals the quantity of a kind of part at hand */
	unsigned int quantity;
	/* identifies the category of a kind of part */
	unsigned int part_number;
	/* gives the description of a part */
	char description[20];
	/* singly-linked part list */
	struct PART *next;
};

/* create an empty inventory and initialize it */
Inventory *create_empty_inventory( void );

/* the function return 1 if a new type of part is successfully entered into current inventory */
int add_new_transaction( Inventory *Inv, char *description, unsigned int quantity, float cost_each );

/* this helper function finds and returns a pointer to the part with given part_number */
Part *search_part( Inventory *Inv, unsigned int part_number );

/* insert a new part, along with its basic info, to current part list */
int insert_part( Part **partPtr, unsigned int part_number, char *description, unsigned int quantity, float cost_each );

/* buy transaction add new units of a part to current inventory */
int buy_part( Inventory *Inv, unsigned int part_number, unsigned int quantity, float cost_each );

/* sell transaction remove "quantity" units of a part from current inventory */
float sell_part( Inventory *Inv, unsigned int part_number, unsigned int quantity, float price_each );

/* completely delete a specified part from inventory */
int delete_part( Inventory *Inv, unsigned int part_number );

/* print basic info of a specified part */
void print_part( Inventory *Inv, unsigned int part_number );

/* prints information for all parts in inventory in a tabular form */
void print_all( Inventory *Inv );

/* computes and prints the total value of all parts in inventory */
void total_transaction( Inventory *Inv );

/* terminates transaction and free allocated memory */
void end_transaction( Inventory *Inv );

#endif
