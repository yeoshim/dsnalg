/*
 * pathFind.c
 *
 *  Created on: 2013. 3. 21.
 *      Author: yeoshim
 */

//int map[5][5] = {
//	{1, 1, 1, 1, 1},
//	{1, 1, 0, 0, 1},
//	{1, 1, 1, 1, 1},
//	{1, 1, 1, 0, 1},
//	{0, 0, 1, 1, 1}
//};

int map[10][10] = {
//int map[9][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 1}
};

int adv_map[5][5] = {
		{1, 2, 2, 1, 5},
		{1, 4, 4, 3, 1},
		{2, 1, 1, 1, 2},
		{1, 3, 5, 1, 1},
		{1, 5, 1, 2, 2}
};

long long path[10][10];

void cal_path( int m, int n )	{
	int i, j;

	path[0][0] = map[0][0];
	for( i = 1; i < m; i ++ )	{
		if( map[i][0] == 0 )	{
			path[i][0] = 0;
		}
		else	{
			path[i][0] = path[i-1][0];
		}
	}

	for( i = 1; i < n; i ++ )	{
		if( map[0][i] == 0 )	{
			path[0][i] = 0;
		}
		else	{
			path[0][i] = path[0][i-1];
		}
	}

	for( i = 1; i < m; i ++ )	{
		for( j = 1; j < n; j++ )	{
			if( map[i][j] == 0 )	{
				path[i][j] = 0;
			}
			else	{
				path[i][j] = path[i-1][j] + path[i][j-1];
			}
		}
	}
}

long long max( long long x, long long y )	{
	if( x > y )	return x;
	return y;
}

long long num_path_adv( int m, int n )	{
	if( m == 0 && n == 0 )	return adv_map[0][0];
	if( m == 0 )	return num_path_adv( m, n-1 ) + adv_map[m][n];
	if( n == 0 )	return num_path_adv( m-1, n ) + adv_map[m][n];

	return max( num_path_adv(m-1, n), num_path_adv(m, n-1) ) + adv_map[m][n] ;
}

long long num_path2( int m, int n )	{
	cal_path( m, n );

	return path[m-1][n-1];
}

long long num_path( int m, int n )	{
//	printf( "map[%d][%d]: %d\n", m, n, map[m][n] );
	if( map[m][n] == 0 )	return 0;
	if( m == 0 && n == 0 )	return 1;

	return ( (m>0) ? num_path(m-1, n) : 0 )
			+ ( (n>0) ? num_path(m, n-1) : 0 );
}

//int num_path2( int m, int n )	{
//
//
//	return 0;
//}
