#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

int main( int argc, char **argv ) {
	FILE *trans;
	Inventory *Inv;
	char ch, filename[20], desc[20];
	unsigned int quan, partNo;
	float cost, profit;

	switch( argc ) {
	case 1: /* create an empty inventory */
		Inv = create_empty_inventory();
		if( Inv == NULL ) {
			printf( "Failed to initialize the inventory!\n" );
			exit( EXIT_FAILURE );
		}
		break;
	case 2: /* read an inventory from an existing file */
		trans = fopen( *++argv, "rb" );
		Inv = (Inventory *)malloc( sizeof( Inventory ) );

		if( trans == NULL || Inv == NULL ) {
		/* error check: 1.fail to open input file; 2.fail to allocate memory */
			perror( "Error" );
			exit( EXIT_FAILURE );
		}

		if( fread( Inv, sizeof( Inventory ), 1, trans ) != 1 ) {
		/* read binary inventory and check */
			printf( "Error reading inventory from %s\n", *argv );
			exit( EXIT_FAILURE );
		}

		fclose( trans );
		break;
	default: /* illegal argument(s) taken from command line */
		printf( "%s: illegal cmd detected!\n", argv[argc - 1] );
		exit( EXIT_FAILURE );
	}

	do {
		printf( "please choose your transaction:\n" );
		printf( "A/a: add new part to inventory\n" );
		printf( "B/b: buy new parts\n" );
		printf( "D/d: delete a kind of part\n" );
		printf( "P/p: print the basic info of a part\n" );
		printf( "L/l: list the information of all parts\n" );
		printf( "S/s: sell a kind of part\n" );
		printf( "T/t: summarize the total transaction\n" );

		scanf( " %c", &ch );
		switch( ch ) {
		case 'A':
		case 'a':
			printf( "[description quantity cost-each]:\n" );
			scanf( " %s %u %f", desc, &quan, &cost );
			add_new_transaction( Inv, desc, quan, cost );
			break;
		case 'B':
		case 'b':
			printf( "[partNo quantity cost-each]:\n" );
			scanf( "%u %u %f", &partNo, &quan, &cost );
			if( buy_part( Inv, partNo, quan, cost ) )
				printf( "part-%u was successfuly bought.\n", partNo );
			else
				printf( "failed to buy part-%u!\n", partNo );

			break;
		case 'D':
		case 'd':
			printf( "[partNo]:\n" );
			scanf( "%u", &partNo );
			if( delete_part( Inv, partNo ) )
				printf( "part-%u was succesfully deleted.\n", partNo );

			break;
		case 'P':
		case 'p':
			printf( "[partNo]:\n" );
			scanf( "%u", &partNo );
			print_part( Inv, partNo );
			break;
		case 'L':
		case 'l':
			print_all( Inv );
			break;
		case 'S':
		case 's':
			printf( "[partNo quantity price-each]:\n" );
			scanf( " %u %u %f", &partNo, &quan, &cost );
			profit = sell_part( Inv, partNo, quan, cost );
			printf( "Your profit of this transaction is: %f\n", profit );
			break;
		case 'T':
		case 't':
			total_transaction( Inv );
			break;
		default:
			printf( "%c: illegal command input!\n", ch );
		}

		printf( "Do you want to continue? [y/n]: " );
		scanf( " %c", &ch );

	} while( ch == 'y' );

	printf( "Before leaving, please indicate where to store inventory data:" );
	scanf( "%s", filename );
	trans = fopen( filename, "wb" );
	if( fwrite( Inv, sizeof( Inventory ), 1, trans ) != 1 )  /* write inventory to the file named filename */
		perror( filename );

	fclose( trans );
	end_transaction( Inv );
	return 0;
}

Inventory *create_empty_inventory( void ) {
/* initialize the empty inventory and the head of part list */
	Inventory *Inv = (Inventory *)malloc( sizeof( Inventory ) );
	if( Inv == NULL )
		return NULL;

	Inv->types = 0;
	Inv->total_val = 0.00;
	Inv->part = (Part *)malloc( sizeof( Part ) );
	if( Inv->part == NULL )
		return NULL;

	Inv->part->val = 0.00;
	Inv->part->quantity = 0;
	Inv->part->part_number = 0;
	Inv->part->description[0] = '\0';
	Inv->part->next = NULL;

	return Inv;
}

int add_new_transaction( Inventory *Inv, char *description, unsigned int quantity, float cost_each ) {
/* the function return 1 if a new type of part is successfully entered into current inventory */
	unsigned int part_number = 0;
	if( Inv == NULL )
		return 0;

	Part *new_part = Inv->part;
	Part **partPtr;

	while( new_part != NULL && part_number == new_part->part_number ) {
	/* search through the part list for the first reusable part_number */
		partPtr = &new_part->next;
		new_part = new_part->next;
		part_number++;
	}

	if( insert_part( partPtr, part_number, description, quantity, cost_each ) ) {
		Inv->types += 1;
		Inv->total_val += cost_each * quantity;
		printf( "new transaction successfully added.\n" );
		return 1;
	}
	else {
		printf( "failed to add new transaction!\n" );
		return 0;
	}
}

int insert_part( Part **partPtr, unsigned int part_number, char *description, unsigned int quantity, float cost_each ) {
/* insert a new part, along with its basic info, to current part list */
	Part *new_part = (Part *)malloc( sizeof( Part ) );
	if( new_part == NULL )
		return 0;

	new_part->val = cost_each * quantity;
	new_part->quantity = quantity;
	new_part->part_number = part_number;
	strcpy( new_part->description, description );

	if( *partPtr == NULL )  /* insert to the end */
		new_part->next = NULL;
	else  /* insert in the middle */
		new_part->next = *partPtr;

	*partPtr = new_part;
	return 1;
}

int buy_part( Inventory *Inv, unsigned int part_number, unsigned int quantity, float cost_each ) {
/* buy transaction add new units of a part to current inventory */
	Part *partPtr = search_part( Inv, part_number );
	if( partPtr == NULL ) {
		printf( "part-%u is not in this inventory!\n", part_number );
		return 0;
	}

	partPtr->quantity += quantity;
	partPtr->val += cost_each * quantity;
	Inv->total_val += cost_each * quantity;
	return 1;
}

float sell_part( Inventory *Inv, unsigned int part_number, unsigned int quantity, float price_each ) {
/* sell transaction remove "quantity" units of a part from current inventory */
	Part *partPtr = search_part( Inv, part_number );
	float profit;

	if( partPtr == NULL ) {
		printf( "part-%u is not in this inventory!\n", part_number );
		return 0.00;
	}

	if( partPtr->quantity < quantity ) {
		printf( "Sorry, there is not enough part-%u left in the inventory!\n", part_number );
		return 0.00;
	}

	profit = ( price_each - partPtr->val / partPtr->quantity ) * quantity;
	partPtr->quantity -= quantity;
	partPtr->val += profit;
	Inv->total_val -= price_each * quantity;
	printf( "part-%u was successfully sold.\n", part_number );

	return profit;
}

Part *search_part( Inventory *Inv, unsigned int part_number ) {
/* this helper function finds and returns a pointer to the part with given part_number */
	Part *partPtr;
	for( partPtr = Inv->part; partPtr != NULL && partPtr->part_number != part_number; partPtr = partPtr->next );

	return partPtr;
}

int delete_part( Inventory *Inv, unsigned int part_number ) {
/* completely delete a specified part from inventory */
	Part *target;
	Part **partPtr;

	for( target = Inv->part; target != NULL && target->part_number != part_number; target = target->next )
		partPtr = &target->next;

	if( target == NULL ) {
		printf( "part-%u doesn't exist.\n", part_number );
		return 0;
	}

	*partPtr = target->next;
	free( target );
	return 1;
}

/* print basic info of a specified part */
void print_part( Inventory *Inv, unsigned int part_number ) {
	Part *partPtr = search_part( Inv, part_number );
	if( partPtr == NULL )
		printf( "part-%u does not exist!\n", part_number );
	else {
		printf( "---%s---\n", partPtr->description );
		printf( "part_number: %03u\n", partPtr->part_number );
		printf( "quantity: %u\n", partPtr->quantity );
		printf( "total worth: %.3f\n\n", partPtr->val );
	}
}

/* prints information for all parts in inventory in a tabular form */
void print_all( Inventory *Inv ) {
	Part *partPtr = Inv->part->next;
	if( partPtr == NULL )
		printf( "the inventory is empty!\n" );

	while( partPtr != NULL ) {
		print_part( Inv, partPtr->part_number );
		partPtr = partPtr->next;
	}
}

/* computes and prints the total value of all parts in inventory */
void total_transaction( Inventory *Inv ) {
	printf( "There are %u types of parts. The total worth of all parts is %.3f\n", Inv->types, Inv->total_val );
}

/* terminates transaction and free allocated memory */
void end_transaction( Inventory *Inv ) {
	Part *partPtr, *previous;
	for( partPtr = Inv->part; partPtr != NULL; ) {
		previous = partPtr;
		partPtr = partPtr->next;
		free( previous );
	}

	free( Inv );
	printf( "All transactions are closed now. See you next time!\n" );
}
