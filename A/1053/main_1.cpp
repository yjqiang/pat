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

// nodes[ID] = ∂‘”¶node
Node nodes[N_MAX];

vector<vector<int>>results;
vector<int>tmp;
void subset(int cur_ID, int sum_weight) {
	int cur_weight = nodes[cur_ID].weight;
	sum_weight += cur_weight;
	tmp.push_back(cur_weight);

	int child_num = nodes[cur_ID].Child_IDs.size();

	if (child_num == 0) {
		if (sum_weight == S)
			results.push_back(tmp);
		tmp.pop_back();
		return;
	}

	int i;
	for (i = 0; i < child_num; ++i)
		subset(nodes[cur_ID].Child_IDs[i], sum_weight);

	tmp.pop_back();
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
	}

	subset(0, 0);

	sort(results.begin(), results.end());
	for (i = results.size() - 1; i >= 0; --i) {
		printf("%d", results[i][0]);
		for (h = 1; h < results[i].size(); ++h)
			printf(" %d", results[i][h]);
		printf("\n");
	}

	system("pause");
	return 0;
}