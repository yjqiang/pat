#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

using namespace std;


#define N_MAX 100000

int coins[N_MAX];

bool myFind(int wanted, int low, int high) {
	int mid;
	while (low <= high) {
		mid = (high - low) / 2 + low;
		if (coins[mid] == wanted)
			return true;
		if (coins[mid] < wanted)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return false;
}

int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*a) - (*b);
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", coins + i);

	qsort(coins, N, sizeof(int), cmp);

	for (i = 0; i < N; ++i)
		// 若存在，则较小的数肯定先被迭代到
		if (myFind(M - coins[i], i + 1, N -1)) {
			printf("%d %d", coins[i], M - coins[i]);
			system("pause");
			return 0;
		}

	printf("No Solution");

	system("pause");
	return 0;
}