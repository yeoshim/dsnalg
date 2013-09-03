/*
 * combination.c
 *
 *  Created on: 2013. 2. 5.
 *      Author: yeoshim
 */

#define MAX_NUM 10000

int combination( int total, int sub )	{
//	rCr = rC0 = 1
//	rCn = r-1Cn-1 + r-1Cn
//	5C2 = 4C1 + 4C2
//		= (3C0 + 3C1) + (3C1 + 3C2)
//		= (1 + (2C0+2C1)) + ((2C0+2C1) + (2C1+2C2))
//		= (1 + (1+(1C0+1C1)) + ((1+(1C0+1C1)) + ((1C0+1C1)+1)
//		= (1 + (1+(1+1)) + ((1+(1+1)) + ((1+1)+1) =10
//	5C2
//		memo[5][2] = 4C1 + 4C2
//			= memo[4][1]= (3C0 + 3C1) + memo[4][2]=(3C1 + 3C2)
//			= memo[4][1]= 1 + memo[3][1] + memo[4][2]=memo[3][1]+memo[3][2]
//						m[3][1] = m[2][0] + m[2][1] + m[4][2]=m[3][1]+m[2][1]+m[2][2]
//						3 + 6=3+2+1

	static long long memo[MAX_NUM][MAX_NUM];

	if( total < 0 || sub < 0 )	{
		printf( "Wrong Param!!!\n" );
		return 0;
	}

	if( memo[total][sub] > 0 )	return memo[total][sub];

	if( total == sub || sub == 0 )	{
		memo[total][sub] = 1;
		return 1;
	}

	return memo[total][sub] = combination(total-1, sub-1) + combination( total-1, sub );
}

