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

#define N_MAX 10000

// �ڽӱ�
vector<int> edges[N_MAX];

// ����ͳ��
bool is_included[N_MAX];

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	int v0, v1;
	// ÿ���߲��ظ���i��Ϊ�����ߵı��
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &v0, &v1);
		edges[v0].push_back(i);
		edges[v1].push_back(i);
	}

	int K;
	scanf("%d", &K);
	int N_v, v, edge_id;
	int g, h;
	bool is_ok;

	for (i = 0; i < K; ++i) {
		// reset
		for (h = 0; h < M; ++h)
			is_included[h] = false;
		is_ok = true;

		scanf("%d", &N_v);

		for (h = 0; h < N_v; ++h) {
			scanf("%d", &v);

			// ��v�����б߶�����
			// --g �Ƿ�ֹ  g < edges[v].size()  ÿ��ѭ��������һ��
			for (g = edges[v].size() - 1; g >= 0; --g) {
				edge_id = edges[v][g];
				is_included[edge_id] = true;
			}
		}
		for (h = 0; h < M; ++h) {
			if (!is_included[h]) {
				printf("No\n");
				is_ok = false;
				break;
			}
		}

		if (is_ok)
			printf("Yes\n");

	}

	system("pause");
	return 0;
}