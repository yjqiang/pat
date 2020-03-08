#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

struct Node {
	int weight;
	// ID 对应了nodes数组的index
	vector<int> children_IDs;
};

#define N_MAX 100
Node nodes[N_MAX];



// 目标S
int S;

// 暂存root到当前节点的路径，上的所有经过的点
vector<int> tmp;

// root(ID:00)->...->当前节点的父节点的路径和为sum
void pre(int parent_ID, int sum) {
	sum += nodes[parent_ID].weight;
	tmp.push_back(nodes[parent_ID].weight);

	int i;
	int n = nodes[parent_ID].children_IDs.size();

	// 为叶节点，就判断一下
	if (n == 0 && sum == S) {
		int n_result, h;
		printf("%d", tmp[0]);
		n_result = tmp.size();
		for (h = 1; h < n_result; ++h)
			printf(" %d", tmp[h]);
		printf("\n");
	}


	for (i = 0; i < n; ++i)
		pre(nodes[parent_ID].children_IDs[i], sum);

	tmp.pop_back();
}


// 从大到小排序
bool cmp(int a, int b) {
	return nodes[a].weight > nodes[b].weight;
}

int main() {
	int N, M;
	int ID, K, child_ID;

	int i, h;

	scanf("%d %d %d", &N, &M, &S);
	// id 从0->(N-1)
	for (i = 0; i < N; ++i)
		scanf("%d", &(nodes[i].weight));

	for (i = 0; i < M; ++i) {
		scanf("%d %d", &ID, &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", &child_ID);
			nodes[ID].children_IDs.push_back(child_ID);
		}
		// 直接对孩子节点先排序，这样保证了dfs的顺序就是从大到小
		sort(nodes[ID].children_IDs.begin(), nodes[ID].children_IDs.end(), cmp);
	}
	int sum = 0;
	pre(0, sum);

		
	system("pause");
	return 0;
}