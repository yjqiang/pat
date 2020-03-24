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

#define Nv_MAX 201
int N_v, N_e;

// 200 * 200 邻接矩阵最舒服
bool edges[Nv_MAX][Nv_MAX] = { false };

// 输入
int K;
int inputs[Nv_MAX];

// 用于辅助判断max clique的：从inputs任取一点，找其所有的邻接点，判断该点与inputs的连接情况，
// 而这个数组是为了防止已在inputs里面的点，再被拿出来测试一次
bool vex[Nv_MAX];

// 任意两点均有边
bool isClique() {
	int i, h;
	for (i = 0; i < K; ++i)
		for (h = 0; h < i; ++h)
			if (!edges[inputs[h]][inputs[i]])
				return false;
	return true;
}

// 任选inputs一点，查看其所有邻接点
bool isMaxClique() {
	int cur = inputs[0];
	int i, h;
	bool can_be_added;
	for (i = 1; i <= N_v; ++i)
		// i 表示 cur的邻接点(edges[i][cur])
		// !vex[i] 用于确定邻接点不再已input的点之内
		if (edges[i][cur] && !vex[i]) {
			can_be_added = true;
			for (h = 0; h < K; ++h)
				if (!edges[inputs[h]][i]) {
					can_be_added = false; 
					break;
				}
			if (can_be_added)
				return false;
		}

	return true;

}

int main() {
	
	scanf("%d%d", &N_v, &N_e);

	int i;
	int v0, v1;
	for (i = 0; i < N_e; ++i) {
		scanf("%d %d", &v0, &v1);
		edges[v0][v1] = true;
		edges[v1][v0] = true;
	}

	int M;
	scanf("%d", &M);

	int h;
	for (i = 0; i < M; ++i) {
		for (h = 1; h <= N_v; ++h)
			vex[h] = false;

		scanf("%d", &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", inputs + h);
			vex[inputs[h]] = true;
		}

		if (!isClique())
			printf("Not a Clique\n");
		else if (isMaxClique())
			printf("Yes\n");
		else
			printf("Not Maximal\n");

	}

	system("pause");
	return 0;
}