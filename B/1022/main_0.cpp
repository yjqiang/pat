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

char result_str[32];

void reverse(int n) {
	int i, j;
	char tmp;
	for (i = 0, j = n - 1; i < j; ++i, --j) {
		tmp = result_str[i];
		result_str[i] = result_str[j];
		result_str[j] = tmp;
	}
}

void decimal2Str(int num, int base) {
	if (!num) {
		result_str[0] = '0';
		result_str[1] = '\0';
		return;
	}
	int n = 0;
	while (num) {
		result_str[n] = num % base + '0';
		num /= base;
		++n;
	}
	reverse(n);
}

int main() {
	int A, B, base;
	scanf("%d%d%d", &A, &B, &base);
	int result_int = A + B;
		
	decimal2Str(result_int, base);
	printf("%s", result_str);
	system("pause");
	return 0;
}