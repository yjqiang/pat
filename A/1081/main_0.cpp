#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

// 最大公约数（两个非负数）
long long gcd(long long m, long long n) {
	if (n == 0 || m == 0)
		return 0;

	long long x = n;
	while (x != 0) {
		x = m % n;
		m = n;
		n = x;
	}
	return m;
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	// a/b
	long long a, b;
	long long result_a, result_b;
	long long the_gcd;
	bool is_negative;

	// 初始化为0/1（分数）
	result_a = 0;
	result_b = 1;

	for (i = 0; i < N; ++i) {
		scanf("%lld/%lld", &a, &b);
		result_a = result_a * b + result_b * a;
		result_b = result_b * b;

		// 最大公约数用绝对值
		the_gcd = gcd(abs(result_b), abs(result_a));

		// result_a为0
		if (the_gcd == 0) {
			result_a = 0;
			result_b = 1;
		}
		else {
			result_a /= the_gcd;
			result_b /= the_gcd;
		}

	}

	// 整数部分 剩余真分数的分子 分母
	long long integer, numerator, denominator;

	is_negative = (result_a < 0 && result_b > 0 || result_a > 0 && result_b < 0) ? true : false;
	result_a = abs(result_a);
	result_b = abs(result_b);

	// cpp的除法，正负数都是向0取整
	integer = result_a / result_b;
	numerator = result_a % result_b;
	denominator = result_b;

	// 整数非0 
	if (integer) {
		printf("%lld", is_negative ? -integer : integer);
		if (numerator)
			printf(" %lld/%lld", numerator, denominator);
	}
	else {
		if (numerator)
			printf("%lld/%lld", is_negative ? -numerator : numerator, denominator);
		else
			printf("0");
	}


	system("pause");
	return 0;
}