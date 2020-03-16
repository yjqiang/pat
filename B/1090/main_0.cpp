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

#define G_MAX 100000

vector<int> collisions[G_MAX];



int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i, h, p;
	int G0, G1;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &G0, &G1);
		collisions[G0].push_back(G1);
		collisions[G1].push_back(G0);
	}
	
	int G;
	int K;
	bool result;

	// unordered_set<int> cache;
	set<int> cache;
	for (i = 0; i < M; ++i) {
		scanf("%d", &K);

		result = true;
		cache.clear();
		for (h = 0; h < K; ++h) {
			scanf("%d", &G);
			for (p = 0; p < collisions[G].size(); ++p)
				if (cache.find(collisions[G][p]) != cache.end())
					result = false;
			cache.insert(G);
		}

		if (result)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	system("pause");
	return 0;
}