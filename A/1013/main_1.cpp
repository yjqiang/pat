# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

int paths[1000000][2] = { 0 };
int set[1001];


int getRoot(int x) {
	int root = x;
	int tmp;
	while (set[root] != -1)
		root = set[root];
	while (x != root) {
		tmp = set[x];
		set[x] = root;
		x = tmp;
	}
	return root;
}

int func(int occupied, int N, int M) {
	int i;
	// initial
	for (i = 1; i <= N; ++i)
		set[i] = -1;

	// create the set
	int x, y;
	int root0, root1;
	for (i = 0; i < M; ++i) {
		x = paths[i][0];
		y = paths[i][1];
		if (x != occupied && y != occupied) {
			root0 = getRoot(x);
			root1 = getRoot(y);
			if (root1 != root0)
				set[root1] = root0;
		}
	}

	// count the set
	int count = 0;
	for (i = 1; i <= N; ++i)
		if (set[i] == -1)
			++count;

	return count - 2; // we just need to connect the remain cities together.
}

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	int i, x, y;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &x, &y);
		paths[i][0] = x;
		paths[i][1] = y;
	}

	int tmp_int;
	for (i = 0; i < K; ++i) {
		scanf("%d", &tmp_int);
		printf("%d\n", func(tmp_int, N, M));
	}

	system("pause");
	return 0;
}