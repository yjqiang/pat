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
#include <unordered_set>

using namespace std;

#define L_MAX 1000001

char s[L_MAX];
char piece[10];

long long num;

bool isPrime() {
	if (num < 2)
		return false;
	if (num % 2 == 0 && num != 2)
		return false;
	long long end = (long long)(sqrt(num));
	long long i;
	for (i = 3; i <= end; ++i)
		if (num % i == 0)
			return false;
	return true;
}

int main() {
	int L, K;
	scanf("%d%d", &L, &K);

	scanf("%s", s);
	int n = strlen(s);
	int i, h;
	bool is_ok = false;
	// i, i + 1,... i + K -1 
	for (i = 0; i + K <= n; ++i) {
		strncpy(piece, s + i, K);
		sscanf(piece, "%lld", &num);
		// printf("%lld\n", num);
		if (isPrime()) {
			for (h = i; h < i + K; ++h)
				printf("%c", s[h]);
			is_ok = true;
			break;
		}
			
	}
	if (!is_ok)
		printf("404");
	system("pause");
	return 0;
}