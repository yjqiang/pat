#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	int index, value;
};

int post[30];
int in[30];
int N;
Node nodes[30];
int end_index_of_nodes = -1;


void pre(int root, int start, int end, int index) {
	if (start > end)
		return;

	int i;
	for (i = start; in[i] != post[root]; ++i);

	++end_index_of_nodes;
	nodes[end_index_of_nodes].index = index;
	nodes[end_index_of_nodes].value = post[root];

	pre(root + i - 1 - end, start, i - 1, 2 * index + 1);
	pre(root - 1, i + 1, end, 2 * index + 2);
}

int cmp(const void* p0, const void* p1) {
	Node* node0 = (Node*)p0;
	Node* node1 = (Node*)p1;
	return node0->index - node1->index;
}

int main() {
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", post + i);
	for (i = 0; i < N; ++i)
		scanf("%d", in + i);

	pre(N - 1, 0, N - 1, 0);
	qsort(nodes, N, sizeof(Node), cmp);
	printf("%d", nodes[0].value);
	for (i = 1; i < N; ++i)
		printf(" %d", nodes[i].value);

	system("pause");
	return 0;
}