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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define N_MAX 1001
// 1000通电话，最多2000人
#define USERS_NUM_MAX 2002
int N, K;


// 每个点的权重，每一通电话的两个人，均加上Time；类似于加上了出入度
int weights[USERS_NUM_MAX] = { 0 };

int users_num = 0;
string users[USERS_NUM_MAX];
// 与users互逆
map<string, int> indices;


struct Gang {
	int head;
	int sum_weight;
	int n_size;

	bool operator<(const Gang& b)const {
		return users[head] < users[b.head];
	}
};

int str2int(string& name) {
	int result;
	if (indices.find(name) == indices.end()) {
		result = users_num++;
		indices[name] = result;
		users[result] = name;
	}
	else {
		result = indices[name];
	}
	return result;
}

// 并查集，默认-1
int parents[USERS_NUM_MAX];

int findRoot(int x) {
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
	int root_a = findRoot(a);
	int root_b = findRoot(b);

	if (root_a != root_b)
		parents[root_a] = root_b;
}

int main() {
	int i;
	cin >> N >> K;

	for (i = 0; i < USERS_NUM_MAX; ++i)
		parents[i] = -1;
	
	string Name1, Name2;
	int Time;
	int index1, index2;
	for (i = 0; i < N; ++i) {
		cin >> Name1 >> Name2 >> Time;
		index1 = str2int(Name1);
		index2 = str2int(Name2);

		// 并查集
		myUnion(index1, index2);

		// 权重下放到节点
		weights[index1] += Time;
		weights[index2] += Time;
	}

	int root;
	// roots[根节点] = gang
	map<int, Gang> roots;


	for (i = 0; i < users_num; ++i) {
		root = findRoot(i);
		if (roots.find(root) == roots.end()) {
			// 注意初始化的赋值：设为当前节点的情况，而不是root
			roots[root].n_size = 1;
			roots[root].head = i;
			roots[root].sum_weight = weights[i];
		}
		else {
			++roots[root].n_size;
			roots[root].sum_weight += weights[i];
			if (weights[roots[root].head] < weights[i]) {
				roots[root].head = i;
			}
		}

	}

	vector<Gang> result;

	map<int, Gang>::iterator map_i;
	for (map_i = roots.begin(); map_i != roots.end(); ++map_i) {
		// 注意weight / 2，因为我们相当于出入度都算了，重复计算了
		if (map_i->second.n_size > 2 && map_i->second.sum_weight / 2 > K)
			result.push_back(map_i->second);
	}

	sort(result.begin(), result.end());
	int n_size = result.size();
	printf("%d\n", n_size);
	for (i = 0; i < n_size; ++i)
		printf("%s %d\n", users[result[i].head].c_str(), result[i].n_size);
	

	system("pause");
	return 0;
}