/*
 * bill.c
 *
 *  Created on: 2013. 3. 13.
 *      Author: yeoshim
 */

int pay( int money, int bills[], int bill_types )	{
	if( bill_types == 1 )	{
		if( money%bills[bill_types-1] == 0 )	{
			return 1;
		}
		else	return 0;
	}

	int cnt = 0;
	int t = money / bills[bill_types-1];
	int i;
	for( i = 0; i <= t; i++ )	{
		cnt += pay( money-(bills[bill_types-1]*i), bills, bill_types-1 );
	}

	return cnt;
}
