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

#define N_MAX 10000

struct Node {
	int min_ID;
	int count;
	int M_estate;
	int Area;
	double average_M_estate;
	double average_Area;
};

// nodes[i]表示以i为root的并查集的最小ID、大小、房产数量之和、面积之和
Node nodes[N_MAX];

// M_estates[ID]存储ID 的人的房产数量
int M_estates[N_MAX];
// Areas[ID]存储ID 的人的房产面积
int Areas[N_MAX];
// is_real[ID] 表示ID的人是否出现了
bool is_real[N_MAX] = { false };

// 并查集(默认-1)
int parents[N_MAX];


int myFindRoot(int x) {
	int r = x;
	while (parents[r] != -1)
		r = parents[r];

	int tmp;
	while (x != r) {
		tmp = parents[x];
		parents[x] = r;
		x = tmp;
	}
	return r;
}

void myUnion(int a, int b) {
	int root_a = myFindRoot(a);
	int root_b = myFindRoot(b);
	if (root_a != root_b)
		parents[root_a] = root_b;
}


bool cmp(Node& a, Node& b) {
	if (a.average_Area != b.average_Area)
		return a.average_Area > b.average_Area;
	return a.min_ID < b.min_ID;
}

int main() {
	int i, h;
	// 初始化
	for (i = 0; i < N_MAX; ++i) {
		parents[i] = -1;

		nodes[i].min_ID = INT_MAX;
		nodes[i].count = 0;
		nodes[i].M_estate = 0;
		nodes[i].Area = 0;
	}


	int N;
	scanf("%d", &N);

	int ID, Father_ID, Mother_ID, K, child_ID;
	

	for (i = 0; i < N; ++i) {
		scanf("%d %d %d %d", &ID, &Father_ID, &Mother_ID, &K);
		is_real[ID] = true;

		if (Father_ID != -1) {
			myUnion(ID, Father_ID);
			is_real[Father_ID] = true;
		}
		if (Mother_ID != -1) {
			myUnion(ID, Mother_ID);
			is_real[Mother_ID] = true;
		}

		for (h = 0; h < K; ++h) {
			scanf("%d", &child_ID);
			myUnion(ID, child_ID);
			is_real[child_ID] = true;
		}
		scanf("%d %d", M_estates + ID, Areas + ID);
	}

	int root;
	for (i = 0; i < N_MAX; ++i)
		if (is_real[i]) {
			root = myFindRoot(i);
			nodes[root].min_ID = min(nodes[root].min_ID, i);
			++nodes[root].count;
			nodes[root].M_estate += M_estates[i];
			nodes[root].Area += Areas[i];
		}


	// 统计root
	vector<Node> results;
	for (i = 0; i < N_MAX; ++i)
		if (is_real[i] && nodes[i].count) {
			nodes[i].average_M_estate = (double)nodes[i].M_estate / nodes[i].count;
			nodes[i].average_Area = (double)nodes[i].Area / nodes[i].count;
			results.push_back(nodes[i]);
		}
	sort(results.begin(), results.end(), cmp);


	int n_size = results.size();
	printf("%d\n", n_size);
	for (i = 0; i < n_size; ++i)
		printf("%04d %d %.3lf %.3lf\n", results[i].min_ID, results[i].count, results[i].average_M_estate, results[i].average_Area);

	system("pause");
	return 0;
}