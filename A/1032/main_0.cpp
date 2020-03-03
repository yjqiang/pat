#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	char Data;
	int Next;
};

#define N_MAX 100001

Node nodes[N_MAX];
int indexes_a[N_MAX];
int indexes_b[N_MAX];

int main() {
	int head_a, head_b, N;
	scanf("%d%d%d", &head_a, &head_b, &N);

	int i;
	int Next, Address;
	char Data;
	for (i = 0; i < N; ++i) {
		scanf("%d %c %d", &Address, &Data, &Next);
		nodes[Address].Data = Data;
		nodes[Address].Next = Next;
	}

	int len_a;
	for (len_a = 0, i = head_a; i != -1; i = nodes[i].Next, ++len_a)
		indexes_a[len_a] = i;
	indexes_a[len_a] = -1;

	int len_b;
	for (len_b = 0, i = head_b; i != -1; i = nodes[i].Next, ++len_b)
		indexes_b[len_b] = i;
	indexes_b[len_b] = -1;

	int* longer, * shorter;
	int difference;
	if (len_a < len_b) {
		difference = len_b - len_a;
		longer = indexes_b;
		shorter = indexes_a;
	}
	else {
		difference = len_a - len_b;
		longer = indexes_a;
		shorter = indexes_b;
	}

	int k;
	for (i = difference, k = 0; longer[i] != shorter[k]; ++i, ++k);
	if (longer[i] == -1)
		printf("-1\n");
	else
		printf("%05d\n", longer[i]);


	system("pause");
	return 0;
}