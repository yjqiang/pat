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
#define ROOT 1

struct Node {
	int ID;
	vector<int> Child_IDs;
};

// nodes[ID] = ��Ӧnode
Node nodes[N_MAX];

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	
	int i, h;
	int ID, K, Child_ID;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &ID, &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", &Child_ID);
			nodes[ID].Child_IDs.push_back(Child_ID);
		}
	}

	// �������
	queue<int>q;
	q.push(ROOT);

	// ÿ��Ľڵ���Ŀ
	int n_size;
	// ��ǰ�ڵ�ID��������Ŀ
	int cur_ID, child_num;
	// ÿ���Ҷ����Ŀ
	int leaf_num_per_level;

	// ���������ʽ
	bool is_first = true;

	while (!q.empty()) {
		n_size = q.size();
		leaf_num_per_level = 0;

		for (i = 0; i < n_size; ++i) {
			cur_ID = q.front();
			q.pop();

			child_num = nodes[cur_ID].Child_IDs.size();
			for (h = 0; h < child_num; ++h)
				q.push(nodes[cur_ID].Child_IDs[h]);

			if (child_num == 0)
				++leaf_num_per_level;
		}

		if (is_first) {
			printf("%d", leaf_num_per_level);
			is_first = false;
		}
		else
			printf(" %d", leaf_num_per_level);

	}

	system("pause");
	return 0;
}