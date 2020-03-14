#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

#define N_MAX 100000

// �ٽӾ���
vector<int> vex[N_MAX];

// ���Ǽ�¼���ڵ����Ʒ�����������Ȩ��ûɶ��ϵ233
int weights[N_MAX];

// It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
// ����һ����
// P�൱������
double result = 0;
void dfs(int root, double P, double r) {
	int n_child = vex[root].size();

	// ������
	if (n_child == 0) {
		result += P * weights[root];
		// printf("=> %d %d %lf\n", node, weights[node], P);
	}

	int h;
		
	P *= (1 + r / 100);
	for (h = 0; h < n_child; ++h)
		dfs(vex[root][h], P, r);
}

int main() {
	int N;
	double P, r;
	scanf("%d %lf %lf", &N, &P, &r);

	int K, ID;
	int i, h;
	for (i = 0; i < N; ++i) {
		scanf("%d", &K);

		// K Ϊ0 => is a retailer
		if (K == 0) {
			scanf("%d", &ID);
			weights[i] = ID;
		}
		else {
			for (h = 0; h < K; ++h) {
				scanf("%d", &ID);
				vex[i].push_back(ID);
			}
		}
	}
	dfs(0, P, r);
	printf("%.1lf", result);
	
	system("pause");
	return 0;
}