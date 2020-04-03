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

#define N_MAX 100
int N, M, S;

struct Node {
	int weight;
	vector<int> Child_IDs;
};

// nodes[ID] = 对应node
Node nodes[N_MAX];


vector<int>tmp;
void subset(int cur_ID, int sum_weight) {
	int cur_weight = nodes[cur_ID].weight;
	sum_weight += cur_weight;
	tmp.push_back(cur_weight);

	int child_num = nodes[cur_ID].Child_IDs.size();
	int i;
	if (child_num == 0) {
		if (sum_weight == S) {
			printf("%d", tmp[0]);
			for (i = 1; i < tmp.size(); ++i)
				printf(" %d", tmp[i]);
			printf("\n");
		}
		
		tmp.pop_back();
		return;
	}

	
	for (i = 0; i < child_num; ++i)
		subset(nodes[cur_ID].Child_IDs[i], sum_weight);

	tmp.pop_back();
}

bool cmp(int& ID0, int& ID1) {
	return nodes[ID0].weight > nodes[ID1].weight;
}

int main() {
	scanf("%d %d %d", &N, &M, &S);

	int i, h;
	for (i = 0; i < N; ++i)
		scanf("%d", &(nodes[i].weight));

	int ID, Child_ID, K;
	for (i = 0; i < M; ++i) {
		scanf("%d %d", &ID, &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", &Child_ID);
			nodes[ID].Child_IDs.push_back(Child_ID);
		}
		// 先排序，那么dfs的时候直接就是题目要求的顺序
		sort(nodes[ID].Child_IDs.begin(), nodes[ID].Child_IDs.end(), cmp);
	}

	subset(0, 0);

	system("pause");
	return 0;
}