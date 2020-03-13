// https://www.liuchuo.net/archives/4216
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

	int start, end;
	int h, g;
	// i + K - 1为本次交换回环的end 
	for (i = 0; i + K - 1 < N; i += K) {
		start = i;
		end = i + K - 1;
		for (h = start, g = end; h < g; ++h, --g)
			swap(indexes[h], indexes[g]);  // 这里只改了index，node的Next数据没改的
	}

	for (i = 0; i < N - 1; ++i)
		printf("%05d %d %05d\n", indexes[i], nodes[indexes[i]].Data, indexes[i + 1]);
	printf("%05d %d -1\n", indexes[N -1], nodes[indexes[N-1]].Data);


	system("pause");
	return 0;
}