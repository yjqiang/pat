#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

#define N_MAX 1001

int N, L;

// vex[i][j] == true => i follow j
bool vex[N_MAX][N_MAX] = {false};

bool visited[N_MAX];

void dfs(int root) {
	// level统计；初始化为1，是指本循环（while）加入的节点的level
	int level = 1;

	int i, h;
	// 初始化
	for (i = 1; i <= N; ++i)
		visited[i] = false;

	queue<int> q;

	q.push(root);
	visited[root] = true;
	int size_q;


	while (!q.empty()) {
		if (level > L)
			return;
		// 本level的个数
		size_q = q.size();

		for (i = 0; i < size_q; ++i) {
			root = q.front();
			q.pop();

			// 把root所有邻居加入
			for (h = 1; h <= N; ++h)
				// h follow i
				if (!visited[h] && vex[h][root]) {
					// printf("%d->%d\n", h, root);
					q.push(h);
					visited[h] = true;
				}
		}

		++level;
		
	}

}


int main() {
	
	scanf("%d%d", &N, &L);
	int i, h;

	int UserID;
	int M;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &M);
		for (h = 0; h < M; ++h) {
			// i关注了谁
			scanf("%d", &UserID);
			vex[i][UserID] = true;
		}
	}

	int K;
	int result;
	scanf("%d", &K);
	for (i = 0; i < K; ++i) {
		scanf("%d", &UserID);
		dfs(UserID);
		result = 0;
		for (h = 1; h <= N; ++h)
			if (visited[h])
				++result;
		// 统计的时候，自己不转发自己
		printf("%d\n", result - 1);
	}
	
	

	system("pause");
	return 0;
}