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
int result = 0;

// 暂存root到当前节点的路径，上的所有经过的点
vector<int> tmp;
vector<vector<int>> results;

// root(ID:00)->...->当前节点的父节点的路径和为sum
void pre(int parent_ID, int sum) {
	sum += nodes[parent_ID].weight;
	tmp.push_back(nodes[parent_ID].weight);

	int i;
	int n = nodes[parent_ID].children_IDs.size();

	// 为叶节点，就判断一下
	if (n == 0 && sum == S)
		results.push_back(tmp);


	for (i = 0; i < n; ++i)
		pre(nodes[parent_ID].children_IDs[i], sum);

	tmp.pop_back();
}


// 从大到小排序
// 这里不可能存在ab不等长且俩人有效元素一样的情况（即一个是另一个的前缀部分）这是题目约束的
bool cmp(vector<int>& a, vector<int>& b) {
	int n = min(a.size(), b.size());
	int i;
	for (i = 0; i < n; ++i) {
		if (a[i] > b[i])
			return true;
		else if (a[i] < b[i])
			return false;
	}
	return false;
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
	}
	int sum = 0;
	pre(0, sum);

	sort(results.begin(), results.end(), cmp);

	int n_results, n;
	n_results = results.size();
	for (i = 0; i < n_results; ++i) {
		printf("%d", results[i][0]);
		n = results[i].size();
		for (h = 1; h < n; ++h)
			printf(" %d", results[i][h]);
		printf("\n");
	}
		
	system("pause");
	return 0;
}