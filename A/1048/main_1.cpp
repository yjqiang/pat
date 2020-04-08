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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define V_MAX 501

// coins[面额] = 该面额对应的数目
int coins[V_MAX] = { 0 };


int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int i;
	int V;
	for (i = 0; i < N; ++i) {
		scanf("%d", &V);
		++coins[V];
	}

	int V1, V2;
	bool is_ok = false;
	for (i = 0; i < V_MAX; ++i)
		if (coins[i] > 0) {
			V1 = i;
			V2 = M - V1;
			if (V2 >= 0 && V2 < V_MAX) {
				// 可能出现 M = 2 输入为 {1, 1}
				if (V2 == V1 && coins[V2] > 1 || V2 != V1 && coins[V2]) {
					is_ok = true;
					printf("%d %d", V1, V2);
					break;
				}
			}

		}
	if (!is_ok)
		printf("No Solution");

	system("pause");
	return 0;
}