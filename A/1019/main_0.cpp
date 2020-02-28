#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

int result[32];

void myReverse(int n) {
	int i, k;
	int tmp_int;
	for (i = 0, k = n - 1; i < k; ++i, --k) {
		tmp_int = result[i];
		result[i] = result[k];
		result[k] = tmp_int;
	}
}

int decimal2Str(int num, int base) {
	if (!num) {
		result[0] = 0;
		return 1;
	}
	int n = 0;
	while (num) {
		result[n] = num % base;
		num /= base;
		++n;
	}
	myReverse(n);
	return n;
}

bool isPalindromic(int n) {
	int i, k;
	for (i = 0, k = n - 1; i < k; ++i, --k)
		if (result[i] != result[k])
			return false;
	return true;
}

int main() {
	int N, b, n;
	int i;
	scanf("%d%d", &N, &b);
	n = decimal2Str(N, b);
	if (isPalindromic(n))
		printf("Yes\n");
	else
		printf("No\n");
	printf("%d", result[0]);
	for (i = 1; i < n; ++i)
		printf(" %d", result[i]);

	system("pause");
	return 0;
}