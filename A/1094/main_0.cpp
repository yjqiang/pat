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

#define N_MAX 101
int N, M;

vector<int> vex[N_MAX];

int max_num_per_level = -1;
int max_level;

// 层序遍历 bfs
void bfs(int root) {
	queue<int>q;
	q.push(root);

	int level = 1;
	int num_cur_level;

	int i, h;
	int cur;
	while (!q.empty()) {
		num_cur_level = q.size();
		if (num_cur_level > max_num_per_level) {
			max_num_per_level = num_cur_level;
			max_level = level;
		}

		for (i = 0; i < num_cur_level; ++i) {
			cur = q.front();
			q.pop();

			// 倒着是我乐意（其实是防止h < vex[cur].size() 每次都多执行一点时间）
			for (h = vex[cur].size() - 1; h >= 0; --h)
				q.push(vex[cur][h]);
		}
		++level;
		
	}
}


int main() {
	scanf("%d%d", &N, &M);


	int ID, K, child_ID;
	int i, h;
	for (i = 0; i < M; ++i) {
		scanf("%d %d", &ID, &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", &child_ID);
			vex[ID].push_back(child_ID);
		}
	}

	bfs(1);

	printf("%d %d", max_num_per_level, max_level);
	system("pause");
	return 0;
}