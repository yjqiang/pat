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


int main() {
	int T, K;
	scanf("%d%d", &T, &K);
	int n1, b, t, n2;

	int i;
	int x = T;
	for (i = 0; i < K; ++i) {
		scanf("%d%d%d%d", &n1, &b, &t, &n2);
		// 玩家下注超过持有的筹码量
		if (t > x)
			printf("Not enough tokens.  Total = %d.\n", x);
		else if (b == 0 && n2 < n1 || b == 1 && n2 > n1) {
			x += t;
			printf("Win %d!  Total = %d.\n", t, x);
		}
		else {
			x -= t;
			printf("Lose %d.  Total = %d.\n", t, x);
			// 玩家输光
			if (x == 0) {
				printf("Game Over.\n");
				break;
			}
		}
	}

	system("pause");
	return 0;
}