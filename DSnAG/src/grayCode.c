/*
 * grayCode.c
 *
 *  Created on: 2013. 3. 14.
 *      Author: yeoshim
 */
void print_code( int code[], int n )	{
	int i;
	for( i = 0; i < n; i++ )	{
		printf( "%d", code[i] );
	}
	printf( "\n" );
}

void print_gray2( int code[], int n, int index, int cur_code )	{
	if( index == n )	{
		print_code( code, n );
		return;
	}

	code[index] = cur_code;
	print_gray2( code, n, index+1, 0 );

	code[index] = (cur_code+1) % 2;	//	0 -> 1, 1 -> 0
	print_gray2( code, n, index+1, 1 );
}

void print_gray( int code[], int n, int index )	{
	if( index == n )	{
//		printf( "print gray\n" );
		print_code( code, n );
		return;
	}

	code[index] = 0;
	print_gray( code, n, index+1 );

	code[index] = 1;
	print_rgray( code, n, index+1 );
}

void print_rgray( int code[], int n, int index )	{
	if( index == n )	{
//		printf( "print R gray\n" );
		print_code( code, n );
		return;
	}

	code[index] = 1;
	print_gray( code, n, index+1 );

	code[index] = 0;
	print_rgray( code, n, index+1 );
}
