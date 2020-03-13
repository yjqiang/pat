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
	// levelͳ�ƣ���ʼ��Ϊ1����ָ��ѭ����while������Ľڵ��level
	int level = 1;

	int i, h;
	// ��ʼ��
	for (i = 1; i <= N; ++i)
		visited[i] = false;

	queue<int> q;

	q.push(root);
	visited[root] = true;
	int size_q;


	while (!q.empty()) {
		if (level > L)
			return;
		// ��level�ĸ���
		size_q = q.size();

		for (i = 0; i < size_q; ++i) {
			root = q.front();
			q.pop();

			// ��root�����ھӼ���
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
			// i��ע��˭
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
		// ͳ�Ƶ�ʱ���Լ���ת���Լ�
		printf("%d\n", result - 1);
	}
	
	

	system("pause");
	return 0;
}