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

// �Ƿ�Ϊ������
bool is_leaf[N_MAX];

// It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
// ����һ����
double bfs(int root, double P, double r) {
	double result = 0;

	queue<int>q;
	q.push(root);

	int n_queue, n_child;
	int i, h;
	int node;
	while (!q.empty()) {
		// ��level�Ľڵ����
		n_queue = q.size();
		
		for (i = 0; i < n_queue; ++i) {
			node = q.front();
			q.pop();
			// ������
			if (is_leaf[node]) {
				result += P * weights[node];
				// printf("=> %d %d %lf\n", node, weights[node], P);
			}

			n_child = vex[node].size();
			for (h = 0; h < n_child; ++h)
				q.push(vex[node][h]);

		}


		P *= (1 + r / 100);
	}

	return result;
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
			is_leaf[i] = true;
		}
		else {
			for (h = 0; h < K; ++h) {
				scanf("%d", &ID);
				vex[i].push_back(ID);
			}
			is_leaf[i] = false;
		}
	}
	
	printf("%.1lf", bfs(0, P, r));
	
	system("pause");
	return 0;
}