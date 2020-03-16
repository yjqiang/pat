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

#define N_MAX 100000

double P, r;
double max_price = -1;
int count_max_price = 0;

// children[i] 表示编号为i的节点的所有孩子
// 邻接表
vector<int> children[N_MAX];

// 层序遍历/bfs
void bfs(int root) {
	double cur_price = P;

	int cur;
	int n_size, n_children;
	queue<int> q;
	q.push(root);

	int i, k;

	while (!q.empty()) {
		// 本level的节点个数
		n_size = q.size();

		for (i = 0; i < n_size; ++i) {
			cur = q.front();
			q.pop();
			n_children = children[cur].size();
			// 叶子节点
			if (n_children == 0) {
				if (max_price == cur_price)
					++count_max_price;
				else if (max_price < cur_price) {
					max_price = cur_price;
					count_max_price = 1;
				}
			}

			for (k = 0; k < n_children; ++k)
				q.push(children[cur][k]);

		}

		cur_price *= (1 + r / 100);

	}
 
}

int main() {
	int N;
	
	scanf("%d%lf%lf", &N, &P, &r);

	int i;
	int child, parent, root;
	for (i = 0; i < N; ++i){
		scanf("%d", &parent);
		child = i;

		if (parent == -1)
			root = child;
		else
			children[parent].push_back(child);
	}
	
	bfs(root);
	printf("%.2lf %d", max_price, count_max_price);
	
	system("pause");
	return 0;
}