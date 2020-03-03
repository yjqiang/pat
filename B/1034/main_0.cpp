#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

int gcd(int m, int n) {
	int r = m;
	while (r != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

void changeValue(long long orig_a, long long orig_b, long long&a, long long&b, long long&k, bool &is_negative) {  // orig_a/orig_b
	if (orig_b == 0) {
		b = 0;
		return;
	}
		

	is_negative = (orig_a >= 0 && orig_b > 0 || orig_a <= 0 && orig_b < 0) ? false : true;  // result >= 0  <=> is_negative == false
	orig_a = orig_a >= 0 ? orig_a : -orig_a;
	orig_b = orig_b >= 0 ? orig_b : -orig_b;

	k = orig_a / orig_b;
	a = orig_a % orig_b;
	b = orig_b;

	if (a == 0)
		return;
	int gcd_ab = gcd(a, b);
	a /= gcd_ab;
	b /= gcd_ab;
	return;
}

void printValue(long long a, long long b, long long k, bool is_negative) {  // a, b, k >= 0
	if (b == 0) {
		printf("Inf");
		return;
	}
	if (a == 0 && k == 0) {
		printf("0");
		return;
	}
	if (is_negative)
		printf("(-");
	if (k != 0) {
		printf("%lld", k);
		if (a != 0) {
			printf(" %lld", a);
			if (b != 1)
				printf("/%lld", b);
		}
	}
	else {
		if (a != 0) {
			printf("%lld", a);
			if (b != 1)
				printf("/%lld", b);
		}
	}
	if (is_negative)
		printf(")");
	
}

int main() {
	long long orig_a1, orig_b1, orig_a2, orig_b2;
	scanf("%lld/%lld %lld/%lld", &orig_a1, &orig_b1, &orig_a2, &orig_b2);

	long long k1, a1, b1, k2, a2, b2;
	bool is_negative1, is_negative2;
	changeValue(orig_a1, orig_b1, a1, b1, k1, is_negative1);
	changeValue(orig_a2, orig_b2, a2, b2, k2, is_negative2);

	long long result_orig_a, result_orig_b;
	long long result_a, result_b, result_k;
	bool result_is_negative;

	result_orig_a = orig_a1 * orig_b2 + orig_b1 * orig_a2;
	result_orig_b = orig_b1 * orig_b2;
	changeValue(result_orig_a, result_orig_b, result_a, result_b, result_k, result_is_negative);
	printValue(a1, b1, k1, is_negative1);
	printf(" + ");
	printValue(a2, b2, k2, is_negative2);
	printf(" = ");
	printValue(result_a, result_b, result_k, result_is_negative);
	printf("\n");

	result_orig_a = orig_a1 * orig_b2 - orig_b1 * orig_a2;
	result_orig_b = orig_b1 * orig_b2;
	changeValue(result_orig_a, result_orig_b, result_a, result_b, result_k, result_is_negative);
	printValue(a1, b1, k1, is_negative1);
	printf(" - ");
	printValue(a2, b2, k2, is_negative2);
	printf(" = ");
	printValue(result_a, result_b, result_k, result_is_negative);
	printf("\n");

	result_orig_a = orig_a1 * orig_a2;
	result_orig_b = orig_b1 * orig_b2;
	changeValue(result_orig_a, result_orig_b, result_a, result_b, result_k, result_is_negative);
	printValue(a1, b1, k1, is_negative1);
	printf(" * ");
	printValue(a2, b2, k2, is_negative2);
	printf(" = ");
	printValue(result_a, result_b, result_k, result_is_negative);
	printf("\n");

	result_orig_a = orig_a1 * orig_b2;
	result_orig_b = orig_b1 * orig_a2;
	changeValue(result_orig_a, result_orig_b, result_a, result_b, result_k, result_is_negative);
	printValue(a1, b1, k1, is_negative1);
	printf(" / ");
	printValue(a2, b2, k2, is_negative2);
	printf(" = ");
	printValue(result_a, result_b, result_k, result_is_negative);
	printf("\n");


	system("pause");
	return 0;
}