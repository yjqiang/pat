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

using namespace std;

#define N_MAX 51
set<int> my_sets[N_MAX];

int main() {
	int N;

	scanf("%d", &N);

	int i, h;
	int M;
	int int_tmp;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &M);
		for (h = 0; h < M; ++h) {
			scanf("%d", &int_tmp);
			my_sets[i].insert(int_tmp);
		}
	}
	
	int K;
	scanf("%d", &K);
	int set_ID0, set_ID1;
	set<int>::iterator set_i;
	// 交集、并集
	int N_c, N_t;
	for (i = 0; i < K; ++i) {
		scanf("%d%d", &set_ID0, &set_ID1);
		N_c = 0;
		// 固定 set0，遍历set1
		for (set_i = my_sets[set_ID1].begin(); set_i != my_sets[set_ID1].end(); ++set_i)
			if (my_sets[set_ID0].find(*set_i) != my_sets[set_ID0].end())
				++N_c;
		N_t = my_sets[set_ID0].size() + my_sets[set_ID1].size() - N_c;
		// 百分号转义 %%
		printf("%.1lf%%\n", ((double)N_c) * 100 / N_t);
	}
	
	system("pause");
	return 0;
}