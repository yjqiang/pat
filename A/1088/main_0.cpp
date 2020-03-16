#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

// 最大公约数
long long gcd(long long m, long long n){
	if (m == 0 || n == 0)
		return 0;
	long long r = m;
	while (r != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

// a/b => x y/z 其中y/x最大公约数为1 , 输入非0 且 NA时，x、y、z >= 0；正负号放在is_negative上
// z为0，则NA
void convert(long long a, long long b, long long&x, long long&y, long long&z, bool& is_negative){
	long long the_gcd = gcd(abs(a), abs(b));
	if (the_gcd == 0) {
		is_negative = false;
		x = 0;
		// 原封不动即可
		y = a;
		z = b;
	}
	else {
		is_negative = (a > 0 && b < 0 || a < 0 && b > 0) ? true : false;
		a = abs(a);
		b = abs(b);
		a /= the_gcd;
		b /= the_gcd;

		x = a / b;
		y = a % b;
		z = b;
	}
}


void print_num(long long x, long long y, long long z, bool is_negative) {
	if (z == 0)
		printf("Inf");
	// 结果为0， is_negative == false
	else if (is_negative) {
		printf("(-");
		if (x) {
			printf("%lld", x);
			if (y)
				printf(" %lld/%lld", y, z);
		}
		else
			printf("%lld/%lld", y, z);
		printf(")");
	}
	else {
		if (x) {
			printf("%lld", x);
			if (y)
				printf(" %lld/%lld", y, z);
		}
		else {
			if (y)
				printf("%lld/%lld", y, z);
			else
				printf("0");
		}
			
	}
}

int main() {
	long long a1, b1, a2, b2;
	
	long long result_a, result_b;

	// 对应a1 b1
	long long x1, y1, z1;
	bool is_negative1;

	// 对应a2 b2
	long long x2, y2, z2;
	bool is_negative2;

	// 对应result_a result_b
	long long result_x, result_y, result_z;
	bool result_is_negative;


	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);

	convert(a1, b1, x1, y1, z1, is_negative1);
	convert(a2, b2, x2, y2, z2, is_negative2);

	print_num(x1, y1, z1, is_negative1);
	printf(" + ");
	print_num(x2, y2, z2, is_negative2);
	printf(" = ");
	result_a = a1 * b2 + a2 * b1;
	result_b = b1 * b2;
	convert(result_a, result_b, result_x, result_y, result_z, result_is_negative);
	print_num(result_x, result_y, result_z, result_is_negative);
	printf("\n");

	print_num(x1, y1, z1, is_negative1);
	printf(" - ");
	print_num(x2, y2, z2, is_negative2);
	printf(" = ");
	result_a = a1 * b2 - a2 * b1;
	result_b = b1 * b2;
	convert(result_a, result_b, result_x, result_y, result_z, result_is_negative);
	print_num(result_x, result_y, result_z, result_is_negative);
	printf("\n");

	print_num(x1, y1, z1, is_negative1);
	printf(" * ");
	print_num(x2, y2, z2, is_negative2);
	printf(" = ");
	result_a = a1 * a2;
	result_b = b1 * b2;
	convert(result_a, result_b, result_x, result_y, result_z, result_is_negative);
	print_num(result_x, result_y, result_z, result_is_negative);
	printf("\n");

	print_num(x1, y1, z1, is_negative1);
	printf(" / ");
	print_num(x2, y2, z2, is_negative2);
	printf(" = ");
	result_a = a1 * b2;
	result_b = a2 * b1;
	convert(result_a, result_b, result_x, result_y, result_z, result_is_negative);
	print_num(result_x, result_y, result_z, result_is_negative);
	printf("\n");

	system("pause");
	return 0;
}