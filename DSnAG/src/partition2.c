/*
 * partition2.c
 *
 *  Created on: 2013. 3. 14.
 *      Author: yeoshim
 */

// P(4)
// 1 1 1 1	-> P(3)
// 1 1 2
// 1 2 1
// 1 3
// 2 1 1	-> P(2)
// 2 2
// 3 1		-> P(1)
// 4		-> P(0)

#define MAXN 1000

unsigned long long partition2( int n )	{
//	printf( "P(%d) ", n );
	unsigned long long cnt = 0;
	int i;
	static unsigned long long memo[MAXN];

	if( memo[n] > 0 )	return memo[n];

	if( n == 0 )	{
//		printf("return 1\n");
//		return 1;
		return memo[n] = 1;
	}

	for( i = 1; i <= n; i++ )	{
		cnt += partition2( n - i );
	}


//	return cnt;
	printf( "return: %d\n", cnt );
	return memo[n] = cnt;
}

