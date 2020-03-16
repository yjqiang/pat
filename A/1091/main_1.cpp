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

#define L_MAX 60
#define M_MAX 1286
#define N_MAX 128

int N, M, L, T;

struct Node {
	int x, y, z;  // 分别对应L M N
};

int points[L_MAX][M_MAX][N_MAX] = { 0 };

bool visited[L_MAX][M_MAX][N_MAX] = { false };

int neigbour_offsets[6][3] = { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1} };

int bfs(int x, int y, int z) {
	int colomn = 0;
	queue<Node> q;
	// 注意！！！！！！！！！别漏了
	visited[x][y][z] = true;
	++colomn;

	q.push(Node{ x, y, z });

	Node cur, child;

	

	int i;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (i = 0; i < 6; ++i) {
			child.x = cur.x + neigbour_offsets[i][0];
			child.y = cur.y + neigbour_offsets[i][1];
			child.z = cur.z + neigbour_offsets[i][2];


			if (child.x < L && child.x >= 0 &&
				child.y < M && child.y >= 0 &&
				child.z < N && child.z >= 0 &&
				// 为坏点 1
				points[child.x][child.y][child.z] == 1 &&
				!visited[child.x][child.y][child.z]) {

				visited[child.x][child.y][child.z] = true;
				++colomn;
				q.push(child);
				
			}
		}
	}

	return colomn >= T? colomn: 0;
}


int main() {

	scanf("%d %d %d %d", &M, &N, &L, &T);

	int i, k, h;
	
	for (i = 0; i < L; ++i)
		for (k = 0; k < M; ++k)
			for (h = 0; h < N; ++h)
				scanf("%d", points[i][k] + h);

	int result = 0;

	for (i = 0; i < L; ++i)
		for (k = 0; k < M; ++k)
			for (h = 0; h < N; ++h) {
				if (!visited[i][k][h] && points[i][k][h] == 1)
					result += bfs(i, k, h);
			}
	printf("%d", result);
		
	system("pause");
	return 0;
}