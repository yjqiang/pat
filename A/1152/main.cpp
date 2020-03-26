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
#include <unordered_map>

using namespace std;

#define L_MAX 1001

char str[L_MAX];

bool isPrime(long long num) {
	if (num <= 1)
		return false;
	if (num % 2 == 0 && num != 2)
		return false;

	long long end = (long long)sqrt(num) + 1;
	long long i;
	for (i = 3; i <= end; i += 2)
		if (num % i == 0)
			return false;
	return true;
}

int main() {
	int L, K;
	scanf("%d%d%s", &L, &K, str);

	int i;
	long long int_num;
	char str_num[11];
	bool is_ok = false;
	for (i = 0; i + K <= L; ++i) {
		// 注意！！不自动附加\0
		strncpy(str_num, str + i, K);
		str_num[K] = '\0';
		sscanf(str_num, "%lld", &int_num);
		if (isPrime(int_num)) {
			printf("%s\n", str_num);
			is_ok = true;
			break;
		}
	}
	if (!is_ok)
		printf("404");

	system("pause");
	return 0;
}