/* 14.10-2 */
#include <stdio.h>
#define CPU_VAX 0
#define CPU_68000 1
#define CPU_68020 2
#define CPU_80386 3
#define CPU_6809 4
#define CPU_6502 5
#define CPU_3B2 6
#define CPU_UNKNOWN 7
#define K68020

int cpu_type( void ) {
	int result;
#ifdef VAX
	result = CPU_VAX;
#elif defined(M68000)
        result = CPU_68000;
#elif defined(K68020)
        result = CPU_68020;
#elif defined(I80386)
        result = CPU_80386;
#elif defined(X6809)
        result = CPU_6809;
#elif defined(X6502)
        result = CPU_6502;
#elif defined(U3B2)
        result = CPU_3B2;
#else
	result = CPU_UNKNOWN;
#endif
	return result;
}

int main( void ) {
	printf( "%d\n", cpu_type() );
	return 0;
}
