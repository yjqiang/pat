#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

#define N_MAX 100001
struct Node {
	int Key;
	int Next;
};
Node nodes[100001];
int a[N_MAX];

int cmp(const void* p0, const void* p1) {
	int* i0 = (int*)p0;
	int* i1 = (int*)p1;

	return nodes[*i0].Key - nodes[*i1].Key;
}

int main() {
	int N, head;
	scanf("%d %d", &N, &head);

	int i;
	int Address, Key, Next;
	for (i = 0; i < N; ++i) {
		scanf("%d %d %d", &Address, &Key, &Next);
		nodes[Address].Key = Key;
		nodes[Address].Next = Next;
	}

	int p = head;
	for (i = 0; p != -1; ++i) {
		a[i] = p;
		p = nodes[p].Next;
	}
	// 坑1：可能有散落的节点
	N = i;
	a[i] = -1;
	qsort(a, N, sizeof(int), cmp);
	// 坑2：可能N为0
	if (N)
		printf("%d %05d\n", N, a[0]);
	else
		printf("%d -1\n", N);

	for (i = 0; i < N; ++i) {
		if (a[i + 1] != -1)
			printf("%05d %d %05d\n", a[i], nodes[a[i]].Key, a[i + 1]);
		else
			printf("%05d %d -1\n", a[i], nodes[a[N - 1]].Key);
	}

	system("pause");
	return 0;
}