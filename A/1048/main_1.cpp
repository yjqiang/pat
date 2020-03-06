#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

using namespace std;


int counts[1001] = { 0 };


int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	int coin;
	for (i = 0; i < N; ++i) {
		scanf("%d", &coin);
		++counts[coin];
	}

	for (i = 1; i <= 1000; ++i)
		if (counts[i] > 0) {
			// 防止M=2  coins = {1,} 这种情况
			--counts[i];
			// M-i >= 1 && M-i <= 1000防止越界
			if (M - i >= 1 && M - i <= 1000 && counts[M - i] > 0) {
				printf("%d %d", i, M - i);
				system("pause");
				return 0;
			}
			--counts[i];
		}

	printf("No Solution");

	system("pause");
	return 0;
}