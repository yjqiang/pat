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

#define N_MAX 501
int N, M;

int degrees[N_MAX] = { 0 };
// 并查集
int parents[N_MAX];

int myFindRoot(int x) {
	int root = x;
	while (parents[root] != -1)
		root = parents[root];

	int tmp;
	while (x != root) {
		tmp = parents[x];
		parents[x] = root;
		x = tmp;
	}
	return root;
}

void myUnion(int a, int b) {
	int root_a, root_b;
	root_a = myFindRoot(a);
	root_b = myFindRoot(b);
	if (root_a != root_b)
		parents[root_a] = root_b;
}

// 是否连通
bool isConnected(){
	int root = myFindRoot(1);
	int i;
	for (i = 2; i <= N; ++i)
		if (root != myFindRoot(i))
			return false;
	return true;

}


int main() {
	
	scanf("%d%d", &N, &M);

	int i;
	// 初始化并查集
	for (i = 1; i <= N; ++i)
		parents[i] = -1;

	int v0, v1;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &v0, &v1);
		++degrees[v0];
		++degrees[v1];
		myUnion(v0, v1);
	}

	printf("%d", degrees[1]);
	for (i = 2; i <= N; ++i)
		printf(" %d", degrees[i]);
	printf("\n");

	// 统计有奇数度的顶点数
	int count_odd_degree = 0;
	for (i = 1; i <= N; ++i)
		if (degrees[i] % 2)
			++count_odd_degree;
	
	if (!isConnected()) {
		printf("Non-Eulerian");
	}
	else {

		if (count_odd_degree == 0)
			printf("Eulerian");
		else if (count_odd_degree == 2)
			printf("Semi-Eulerian");
		else
			printf("Non-Eulerian");
	}

	system("pause");
	return 0;
}