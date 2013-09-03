/*
 * fibo.c
 *
 *  Created on: 2013. 2. 6.
 *      Author: yeoshim
 */

#define MAX_NUM 10000

unsigned long long fib_f( int n )	{
	int i;
	if( n <= 0 )	{
		printf( "Wrong Param!!!\n" );
		return 0;
	}

	if( n == 1 || n == 2 )	return 1;
//	1 1 2 3 5 ...
	int f1 = 1;
	int f2 = 1;
	int f3 = f1 + f2;
	for( i = 3; i <= n; i++ )	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	return f3;
}

unsigned long long fib_m( int n )	{
	static unsigned long long m[MAX_NUM];

	if( n <= 0 )	{
		printf( "Wrong Param!!!\n" );
		return 0;
	}

	if( m[n] > 0 )	return m[n];

	if( n == 1 || n == 2 )	return m[n] = 1;

	return m[n] = fib_m(n-2) + fib_m(n-1);
}

int fib( int n )	{
//	fib(4) = 1 1 2 3
//	f(1)=1, f(2)=1, f(3)=2, f(4)=3
//	f(1)=1, f(2)=1, f(3)=f(1)+f(2), f(4)=f(2)+f(3)
	if( n <= 0 )	{
		printf( "Wrong Param!!!\n" );
		return 0;
	}

	if( n == 1 || n == 2 )	return 1;

	return fib(n-2) + fib(n-1);
}
