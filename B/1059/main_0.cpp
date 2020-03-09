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

using namespace std;

#define ID_MAX 10000

// 0 缺省表示没人
// -1 表示领取了
int ranks[ID_MAX] = { 0 };

bool isPrime(int x) {
	int i;
	for (i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	int N, K;
	int ID;
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &ID);
		ranks[ID] = i;
	}

	int rank;
	scanf("%d", &K);
	for (i = 0; i < K; ++i) {
		scanf("%d", &ID);
		rank = ranks[ID];
		if (rank == -1)
			printf("%04d: Checked\n", ID);
		else if (rank == 0)
			printf("%04d: Are you kidding?\n", ID);
		else {
			if (rank == 1)
				printf("%04d: Mystery Award\n", ID);
			else if (isPrime(rank))
				printf("%04d: Minion\n", ID);
			else
				printf("%04d: Chocolate\n", ID);
			// 已领取
			ranks[ID] = -1;
		}
	}

	system("pause");
	return 0;
}