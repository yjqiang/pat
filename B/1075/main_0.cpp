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
#define N_MAX 100005

struct Node {
	int Data;
	int Next;
};

// 类似于内存分布的数据，i为内存地址，Node就是对应数据
Node nodes[N_MAX];
// next的连接，顺序依次连接，元素为nodes的下标（内存地址）
int indexes[N_MAX];

int new_indexes[N_MAX];


int main() {
	int head, N, K;

	scanf("%d%d%d", &head, &N, &K);

	int i;
	int Address, Data, Next;
	for (i = 0; i < N; ++i) {
		scanf("%d%d%d", &Address, &Data, &Next);
		nodes[Address].Data = Data;
		nodes[Address].Next = Next;
	}
	
	int  p = head;
	for (i = 0; p != -1; p = nodes[p].Next, ++i)
		indexes[i] = p;
	indexes[i] = -1;
	// 有孤立点不在链表上
	N = i;

	// 分三次迭代，分别选出负数、[0, K]、大于K的地址
	int i_new = 0;
	for (i = 0; i < N; ++i)
		if (nodes[indexes[i]].Data < 0) {
			new_indexes[i_new] = indexes[i];
			++i_new;
		}
	for (i = 0; i < N; ++i)
		if (nodes[indexes[i]].Data >= 0 && nodes[indexes[i]].Data <= K) {
			new_indexes[i_new] = indexes[i];
			++i_new;
		}

	for (i = 0; i < N; ++i)
		if (nodes[indexes[i]].Data > K) {
			new_indexes[i_new] = indexes[i];
			++i_new;
		}
	// printf("%d==%d\n", i_new, N);
	for (i = 0; i < N - 1; ++i)
		printf("%05d %d %05d\n", new_indexes[i], nodes[new_indexes[i]].Data, new_indexes[i + 1]);
	printf("%05d %d -1\n", new_indexes[N -1], nodes[new_indexes[N-1]].Data);


	system("pause");
	return 0;
}