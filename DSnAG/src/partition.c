/*
 * partition.c
 *
 *  Created on: 2013. 3. 13.
 *      Author: yeoshim
 */

//	5/3
//	1 1 1 1 1	=> 4/1
//	2 1 1 1		=> 3/2 -> 2/1 + 1/2(1/1)
//	2 2 1
//	3 1 1		=> 2/2 -> 1/1 + 0/2(0/0)
//	3 2

//	5/2			=> 4/1 + 3/2 -> 3
//4/1
//	1 1 1 1 1	=> 4/1 -> 1
//3/2
//	2 1 1 1		=> 3/2 -> 2/1 + 1/2(1/1)
//	2 2 1
#define MAXN 200

int partition( int m, int n )	{
//	printf( "P(%d, %d):", m, n );
	int i;
	int cnt = 0;
	static int memo[MAXN][MAXN];

//	if( m < 0 )	return 0;
	if( m < n )	n = m;

	if( memo[m][n] > 0 )	{
		return memo[m][n];
	}

//	if( n == 1 || n == 0 )	{
	if( n == 0 )	{
		return memo[m][n] = 1;
	}

	for( i = 1; i <= n; i++ )	{
		cnt += partition( m-i, i );
	}

//	return cnt;
	return memo[m][n] = cnt;
}
