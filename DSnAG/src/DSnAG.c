/*
 ============================================================================
 Name        : DSnAG.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//#include "bill.c"

#define MAXN 100

void testSumSSD()	{
	int m = 110;
	int n = 10;
	int set[] = { 6, 9, 13, 14, 20, 21, 22, 30, 49, 55 };
	printf( "m: %d n:%d is %d\n", m, n, sum_subset_d(set, m, n) );

	m = 100;
	n = 6;
	int set2[] = { 1, 2, 3, 4, 5, 6 };
	printf( "m: %d n:%d is %d\n", m, n, sum_subset_d(set2, m, n) );
}

void testSumSSM()	{
	int m = 110;
	int n = 10;
	int set[] = { 6, 9, 13, 14, 20, 21, 22, 30, 49, 55 };
	printf( "m: %d n:%d is %d\n", m, n, sum_subset_m(set, m, n) );

	m = 101;
	n = 10;
	int set2[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	printf( "m: %d n:%d is %d\n", m, n, sum_subset_m(set2, m, n) );
}


void testSumSS()	{
	int m = 110;
	int n = 10;
	int set[] = { 6, 9, 13, 14, 20, 21, 22, 30, 49, 55 };
	printf( "m: %d n:%d is %d\n", m, n, sum_subset(set, m, n) );

	m = 101;
	n = 10;
	int set2[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	printf( "m: %d n:%d is %d\n", m, n, sum_subset(set2, m, n) );
}

void testJoyPathG()	{
	int m = 5;
	int n = 5;

	joy_draw( m-1, n-1 );
//	print_path();
	draw_path( m-1, n-1 );
}

void testJoyPathD()	{
	int m = 5;
	int n = 5;
	printf( "Max JoyD: %d\n", max_joy_d(m, n) );
}

void testJoyPath()	{
	int m = 5;
	int n = 5;
	printf( "Max Joy: %d\n", max_joy(m, n) );
}

void testPathAdv()	{
	int m = 5;
	int n = 5;
	printf( "path Adv: %ld\n", num_path_adv(m, n) );
}

void testPath2()	{
	int m = 5;
	int n = 5;
	printf( "path2: %ld\n", num_path2(m, n) );
}

void testPath()	{
	int m = 5;
	int n = 5;
	printf( "path: %ld\n", num_path(m-1, n-1) );
	printf( "path2: %d\n", num_path2(m-1, n-1) );
}

void testgCode()	{
	int code[10];
	int n;
	printf( "Input bit: " );
	scanf( "%d", &n );
	print_gray( code, n, 0 );
	printf( "==================\n" );
	print_gray2( code, n, 0, 0 );
}

void testNumDiv2()	{
	int n = 35;
	printf( "Order Partition(%d): %d\n", n, partition2(n) );
}

void testNumDiv()	{
	int m = 5;
	int n = 2;
	printf( "Partition(%d, %d): %d\n", m, n, partition(m, n) );
}

void testBill()	{
	int m = 100;
//	int n[] = {1, 2, 5, 10, 20, 50};
	int n[MAXN];
	int len = 6;
	printf( "Num of bills: " );
	scanf( "%d", &len );
	printf( "Input bills: " );
	int i = 0;
	for( i = 0; i < len; i++ )	{
		scanf( "%d", &n[i] );
	}
	printf( "Input money: " );
	scanf( "%d", &m );

	printf( "Pay(%d, {%d}): %d\n", m, len, pay(m, n, len) );	//	4562
}

void testFib()	{
	printf( "Test Fib!!!\n" );
	int n = 46;
//	int retVal = fib( n );
//	unsigned long long retVal = fib_m( n );
	unsigned long long retVal = fib_f( n );
	printf( "Fib(%d): %llu\n", n, retVal );
}

void testCombination()	{
	printf( "Test 2 Hang!!!\n" );
	int total = 8000;
	int sub = 7000;
	int retVal = combination( total, sub );
	printf( "Combination(%d, %d): %d\n", total, sub, retVal );
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
//	printf( "Hello World!!!\n" );

	testSumSSD();
	testSumSSM();
	testSumSS();
//	testJoyPathG();
//	testJoyPathD();
//	testJoyPath();
//	testPathAdv();
//	testPath2();
//	testPath();
//	testgCode();
//	testNumDiv2();
//	testNumDiv();
//	testBill();
//	testFib();
//	testCombination();

	return EXIT_SUCCESS;
}
