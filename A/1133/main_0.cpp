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
#include <unordered_map>

using namespace std;

#define N_MAX 100000
#define Addr_MAX 100000

struct Node {
	int Data;
	int Next;
};

// nodes[Address] = node
Node nodes[Addr_MAX];

int list_orig[N_MAX];
int list_result[N_MAX];


int main() {
	int header, N, K;
	scanf("%d%d%d", &header, &N, &K);

	int i;
	int Address;
	for (i = 0; i < N; ++i) {
		scanf("%d", &Address);
		scanf("%d%d", &(nodes[Address].Data), &(nodes[Address].Next));
	}


	for (i = 0, Address = header; Address != -1; ++i, Address = nodes[Address].Next)
		list_orig[i] = Address;

	// 原输入有孤立点
	N = i;

	int i_for_result = 0;
	for (i = 0; i < N; ++i)
		if (nodes[list_orig[i]].Data < 0)
			list_result[i_for_result++] = list_orig[i];
	for (i = 0; i < N; ++i)
		if (nodes[list_orig[i]].Data >= 0 && nodes[list_orig[i]].Data <= K)
			list_result[i_for_result++] = list_orig[i];
	for (i = 0; i < N; ++i)
		if (nodes[list_orig[i]].Data > K)
			list_result[i_for_result++] = list_orig[i];

	for (i = 0; i < N - 1; ++i)
		printf("%05d %d %05d\n", list_result[i], nodes[list_result[i]].Data, list_result[i + 1]);
	printf("%05d %d -1\n", list_result[N - 1], nodes[list_result[N - 1]].Data);

	system("pause");
	return 0;
}