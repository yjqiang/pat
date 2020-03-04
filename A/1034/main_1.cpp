#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

// N个边， 最多2N点
#define N_MAX 2001

struct Gang {
	int count;
	int sum_weight;
	int head;
};

map<int, Gang> gangs;
Gang results[N_MAX];

int parents[N_MAX];

int myFind(int x) {
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
	int root0 = myFind(a);
	int root1 = myFind(b);
	if (root0 != root1)
		parents[root0] = root1;
}

int weights[N_MAX] = { 0 };

map<string, int> str2int;
map<int, string> int2str;

int cmp(const void* p0, const void* p1) {
	Gang* gang0 = (Gang*)p0;
	Gang* gang1 = (Gang*)p1;
	int result = int2str[gang0->head].compare(int2str[gang1->head]);
	return result;
}

int main() {
	int N, K;
	cin >> N >> K;

	int i;
	string Name1, Name2;
	int Time;

	for (i = 0; i < N_MAX; ++i)
		parents[i] = -1;

	for (i = 0; i < N; ++i) {
		cin >> Name1 >> Name2 >> Time;

		// 转化 string 和 int
		if (str2int.find(Name1) == str2int.end()) {
			str2int[Name1] = str2int.size();
			int2str[str2int[Name1]] = Name1;
		}
		if (str2int.find(Name2) == str2int.end()) {
			str2int[Name2] = str2int.size();
			int2str[str2int[Name2]] = Name2;
		}

		// 权重下放到节点
		weights[str2int[Name1]] += Time;
		weights[str2int[Name2]] += Time;

		// 并查集
		myUnion(str2int[Name1], str2int[Name2]);
	}

	int n_vertex = str2int.size();
	int root;

	for (i = 0; i < n_vertex; ++i) {
		root = myFind(i);
		// printf("%d(%s)->%d(%s)\n", i, int2str[i].c_str(), root, int2str[root].c_str());
		if (gangs.find(root) == gangs.end()) {
			// 注意初始化的赋值：设为当前节点的情况，而不是root
			gangs[root].count = 1;
			gangs[root].sum_weight = weights[i];
			gangs[root].head = i;
		}
		else {
			++gangs[root].count;
			gangs[root].sum_weight += weights[i];
			if (weights[i] > weights[gangs[root].head])
				gangs[root].head = i;
		}
	}

	int n_gangs = gangs.size();
	map<int, Gang>::iterator i_map;
	int n_results;
	for (i_map = gangs.begin(), n_results = 0; i_map != gangs.end(); ++i_map)
		// 注意weight / 2，因为我们相当于出入度都算了，重复计算了
		if ((i_map->second).count > 2 && (i_map->second).sum_weight / 2 > K) {
			results[n_results].count = i_map->second.count;
			results[n_results].head = i_map->second.head;
			++n_results;
		}
			
	printf("%d\n", n_results);
	if (n_results) {
		qsort(results, n_results, sizeof(Gang), cmp);
		for (i = 0; i < n_results; ++i)
			printf("%s %d\n", int2str[results[i].head].c_str(), results[i].count);
	}


	system("pause");
	return 0;
}