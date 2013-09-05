/*
 * sum_subset.c
 *
 *  Created on: 2013. 9. 5.
 *      Author: yeoshim
 */

int max_bol( int a, int b )	{
	if( a > b )	return a;
	else	return b;
}

int subset[100][100];

void cal_subset( int set[], int m, int n )	{
	int i, j;
	for (i = 0; i <= n; ++i) {
		subset[0][i] = 1;
	}

	for (i = 1; i <= m; ++i) {
		subset[i][0] = 0;
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			subset[j][i] = 0;
			if( j >= set[i-1] )	{
				if( subset[j-set[i-1]][i-1] == 1 )
					subset[j][i] = 1;
			}

			if( subset[j][i-1] == 1 )
				subset[j][i] = 1;
		}
	}
}

int sum_subset_d( int set[], int m, int n )	{
	cal_subset( set, m, n );
	return subset[m][n];
}

int memo[100][100];

int sum_subset( int set[], int m, int n )	{
	if( n == 0 && m == 0 )	return 1;
	if( n == 0 && m != 0 )	return 0;

	return max_bol( sum_subset(set, m, n-1), sum_subset(set, m-set[n-1], n-1) );

//	int set2[n-1];
//	int i;
//	for (i = 0; i < n-1; ++i) {
//		set2[i] = set[i];
//	}
//	return max_bol( sum_subset(set2, m, n-1), sum_subset(set2, m-set[n-1], n-1) );
}

int sum_subset_m( int set[], int m, int n )	{

	if( n == 0 && m == 0 )	return 2;
	if( n == 0 && m != 0 )	return 1;

	if( memo[m][n] > 1 )	return memo[m][n];

	return memo[m][n] = max_bol( sum_subset_m(set, m, n-1), sum_subset_m(set, m-set[n-1], n-1) );
}
