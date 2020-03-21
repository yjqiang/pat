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

#define N_MAX 10000

// ranks[ID]表示了rank
// -1表示已经领奖了
// 0 为初始化的值，表示没这个人
// >0为rank
int ranks[N_MAX] = { 0 };

bool isPrime(int x) {
	if (x % 2 == 0 && x != 2)
		return false;
	int end = (int)sqrt(x) + 1;
	int i;
	for (i = 3; i <= end; i += 2)
		if (x % i == 0)
			return false;
	return true;
}


int main() {
	int N;
	scanf("%d", &N);
	
	int i;
	int ID;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &ID);
		ranks[ID] = i;
	}
	
	int K;
	scanf("%d", &K);
	for (i = 0; i < K; ++i) {
		scanf("%d", &ID);
		printf("%04d: ", ID);
		// 已经领取过了
		if (ranks[ID] == -1)
			printf("Checked\n");
		// 没这人
		else if (ranks[ID] == 0)
			printf("Are you kidding?\n");
		else {
			if (ranks[ID] == 1)
				printf("Mystery Award\n");
			else if (isPrime(ranks[ID]))
				printf("Minion\n");
			else
				printf("Chocolate\n");
			// 标为已经领取
			ranks[ID] = -1;
		}
	}
	
	system("pause");
	return 0;
}