/*
 * pathJoy.c
 *
 *  Created on: 2013. 3. 21.
 *      Author: yeoshim
 */

int joy_map[5][5] = {
		{1, 2, 2, 1, 5},
		{1, 4, 4, 3, 1},
		{2, 1, 1, 1, 2},
		{1, 3, 5, 1, 1},
		{1, 5, 1, 2, 2}
};

int joy[5][5];
int from[5][5];
enum	{LEFT, UP};

int max_int( int x, int y )	{
	if( x > y )	return x;
	return y;
}

void print_path()	{
	int i, j;
	for (i = 0; i < 5; ++i) {
		for (j = 0; j < 5; ++j) {
			printf( "%d ", from[i][j]);
		}
		printf( "\n" );
	}
}

void draw_path( int m, int n )	{
	if( m == 0 && n == 0 )	return;

	printf( "(%d, %d)\n", n+1, m+1 );
//	printf( "(%d, %d)\n", m+1, n+1 );

	if( from[m][n] == LEFT )	{
		draw_path( m-1, n );
	}
	else	{
		draw_path( m, n-1 );
	}
}

void joy_draw( int m, int n )	{
	joy[0][0] = joy_map[0][0];

	int i, j;
	for (i = 1; i <= m; ++i) {
		joy[i][0] = joy[i-1][0] + joy_map[i][0];
		from[i][0] = LEFT;
	}

	for (j = 1; j <= n; ++j) {
		joy[0][j] = joy[0][j-1] + joy_map[0][j];
		from[0][j] = UP;
	}

	for (i = 1; i <= m; ++i) {
		for (j = 1; j <= n; ++j) {
			if( joy[i-1][j] > joy[i][j-1] )	{
				from[i][j] = LEFT;
			}
			else	{
				from[i][j] = UP;
			}
			joy[i][j] = max_int( joy[i-1][j], joy[i][j-1] ) + joy_map[i][j];
		}
	}
}

void cal_joy( int m, int n )	{
	int x = m-1;
	int y = n-1;

	if( x < 0 || y < 0 )	{
		printf( "Input bigger number!!!\n" );
		return;
	}

	joy[0][0] = joy_map[0][0];

	int i, j;
	for( i = 1; i <= x; i++ )	{
		joy[i][0] = joy[i-1][0] + joy_map[i][0];
	}

	for( j = 1; j <= y; j++ )	{
		joy[0][j] = joy[0][j-1] + joy_map[0][j];
	}

	for( i = 1; i <= x; i++ )	{
		for( j = 1; j <= y; j++ )	{
			joy[i][j] = max_int( joy[i-1][j], joy[i][j-1] ) + joy_map[i][j];
		}
	}
}

int max_joy( int m, int n )	{
	int x = m-1;
	int y = n-1;

	if( x < 0 || y < 0 )	{
		printf( "Input bigger number!!!\n" );
		return -1;
	}

	if( x == 0 && y == 0 )	return joy_map[0][0];
	if( x > 0 && y == 0 )	return max_joy(m-1, n) + joy_map[x][y];
	if( x == 0 && y > 0 )	return max_joy(m, n-1) + joy_map[x][y];
	if( x > 0 && y > 0 )	return max_int( max_joy(m-1, n), max_joy(m, n-1) ) + joy_map[x][y];
}

int max_joy_d( int m, int n )	{
	cal_joy( m, n );

	return joy[m-1][n-1];
}
