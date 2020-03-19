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

#define N_MAX 100000
int N;
double P, r;

// 邻接矩阵
vector<int> vex[N_MAX];

void bfs(int root) {
	queue<int>q;
	q.push(root);

	int i, h;
	int cur, n_size, n_children;
	int count_result = 0;
	while (!q.empty()) {
		// 本层的节点个数
		n_size = q.size();

		for (i = 0; i < n_size; ++i) {
			cur = q.front();
			q.pop();

			n_children = vex[cur].size();
			// 统计本层的叶节点数
			if (n_children == 0)
				++count_result;
			for (h = 0; h < n_children; ++h)
				q.push(vex[cur][h]);
		}

		// 本层出现了叶子节点
		if (count_result) {
			printf("%.4lf %d", P, count_result);
			return;
		}

		P *= (1 + r / 100);
	}
}

int main() {
	scanf("%d %lf %lf", &N, &P, &r);

	int i, h;
	int K, child_ID;
	for (i = 0; i < N; ++i){
		scanf("%d", &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", &child_ID);
			vex[i].push_back(child_ID);
		}
	}
	
	bfs(0);
	
	system("pause");
	return 0;
}