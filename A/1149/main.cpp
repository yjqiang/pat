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

#define ID_MAX 100000
#define K_MAX 1000

int inputs[K_MAX];

// 邻接表
vector<int> incompatibles[ID_MAX];

// 比set快
bool is_exist[ID_MAX];

bool isOk(int K) {
	int good;
	int i, h;
	
	for (i = 0; i < K; ++i) {
		good = inputs[i];
		// 遍历其所有不相容的货物(incompatibles[good][g])，看看是否已经input了
		for (h = incompatibles[good].size() - 1; h >= 0; --h)
			if (is_exist[incompatibles[good][h]])
				return false;
	}
	return true;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	int good0, good1;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &good0, &good1);
		incompatibles[good0].push_back(good1);
		incompatibles[good1].push_back(good0);
	}

	int h;
	int K;
	
	for (i = 0; i < M; ++i) {
		// initial
		for (h = 0; h < ID_MAX; ++h)
			is_exist[h] = false;

		scanf("%d", &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", inputs + h);
			is_exist[inputs[h]] = true;
		}
		
		if (isOk(K))
			printf("Yes\n");
		else
			printf("No\n");

	}

	system("pause");
	return 0;
}