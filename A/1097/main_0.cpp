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

struct Node {
	int Key;
	int Next;
};

// nodes[address] = node
Node nodes[N_MAX];

// node_list[index] = address
// һ�������Ҵ�0��ʼ�ڷ�
int unique_node_list[N_MAX];
int removed_node_list[N_MAX];

// ����
set<int> duplicate_helper;

int main() {
	int header, N;
	scanf("%d %d", &header, &N);

	int i;
	int Address, Key, Next;
	for (i = 0; i < N; ++i) {
		scanf("%d %d %d", &Address, &Key, &Next);
		nodes[Address].Key = Key;
		nodes[Address].Next = Next;
	}

	// i0 ����unique_node_list�� i1����removed_node_list
	int i0, i1;
	for (i0 = 0, i1 = 0, Address = header; Address != -1; Address = nodes[Address].Next) {
		Key = abs(nodes[Address].Key);
		if (duplicate_helper.find(Key) == duplicate_helper.end())
			unique_node_list[i0++] = Address;
		else 
			removed_node_list[i1++] = Address;
		duplicate_helper.insert(Key);
	}

	int n_unique_node_list = i0;
	int n_removed_node_list = i1;
	unique_node_list[i0] = -1;
	removed_node_list[i1] = -1;

	// printf("\n");

	for (i = 0; i < n_unique_node_list; ++i) {
		if (i + 1 < n_unique_node_list)
			printf("%05d %d %05d\n", unique_node_list[i], nodes[unique_node_list[i]].Key, unique_node_list[i + 1]);
		else
			printf("%05d %d -1\n", unique_node_list[i], nodes[unique_node_list[i]].Key);
	}
	// printf("\n");

	for (i = 0; i < n_removed_node_list; ++i) {
		if (i + 1 < n_removed_node_list)
			printf("%05d %d %05d\n", removed_node_list[i], nodes[removed_node_list[i]].Key, removed_node_list[i + 1]);
		else
			printf("%05d %d -1\n", removed_node_list[i], nodes[removed_node_list[i]].Key);
	}

	system("pause");
	return 0;
}