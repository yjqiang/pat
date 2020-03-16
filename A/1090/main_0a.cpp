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

// 前序遍历
void pre(int parent, double cur_price) {
	int n_children = children[parent].size();
	// 叶子节点
	if (n_children == 0) {
		if (max_price == cur_price)
			++count_max_price;
		else if (max_price < cur_price) {
			max_price = cur_price;
			count_max_price = 1;
		}
		return;
	}

	int i;
	for (i = 0; i < n_children; ++i)
		pre(children[parent][i], cur_price * (1 + r / 100));
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
	
	pre(root, P);
	printf("%.2lf %d", max_price, count_max_price);
	
	system("pause");
	return 0;
}