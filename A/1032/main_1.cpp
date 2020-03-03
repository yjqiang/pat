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
	bool visited;
};

#define N_MAX 100001

Node nodes[N_MAX];

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
		nodes[Address].visited = false;
	}

	for (i = head_a; i != -1; i = nodes[i].Next)
		nodes[i].visited = true;

	for (i = head_b; i != -1; i = nodes[i].Next)
		if (nodes[i].visited) {
			printf("%05d", i);
			system("pause");
			return 0;
		}
	printf("-1");

	system("pause");
	return 0;
}