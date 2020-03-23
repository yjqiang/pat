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

// һ��������ab���� a*10000+b �� a+b*10000 ��ʾһ���� 
set<int>counts;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	int v0, v1;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &v0, &v1);
		edges[v0].push_back(v1);
		edges[v1].push_back(v0);
	}

	int K;
	scanf("%d", &K);
	int N_v, v;
	int g, h;
	bool is_ok;

	for (i = 0; i < K; ++i) {
		counts.clear();
		is_ok = true;

		scanf("%d", &N_v);

		for (h = 0; h < N_v; ++h) {
			scanf("%d", &v);

			// ��v�����б߶�������ȥ
			// --g �Ƿ�ֹ  g < edges[v].size()  ÿ��ѭ��������һ��
			for (g = edges[v].size() - 1; g >= 0; --g) {
				v0 = edges[v][g];
				counts.insert(v * 10000 + v0);
				counts.insert(v + v0 * 10000);
			}
		}
		if (counts.size() == 2 * M)
			printf("Yes\n");
		else
			printf("No\n");
	}

	system("pause");
	return 0;
}