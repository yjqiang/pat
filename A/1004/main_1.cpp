# define _CRT_SECURE_NO_WARNINGS
# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <climits>
# include <queue>

using namespace std;

#define MAX_N 101

bool edges[MAX_N][MAX_N] = {false};
int counts[MAX_N] = { 0 };
int max_level = -1;  // 0st, 1st,2rd ...

void func(int root, int level) {
	max_level = max(max_level, level);
	int i;
	bool have_leaf = false;
	for (i = 0; i < MAX_N; ++i)
		if (edges[root][i]) {
			have_leaf = true;
			func(i, level + 1);
		}

	if (!have_leaf)
		++counts[level];
}

int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	
	if (!N)
		return 0;

	int i, k;
	int ID, K, child;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &ID, &K);
		for (k = 0; k < K; ++k) {
			scanf("%d", &child);
			edges[ID][child] = true;
		}
	}
	func(1, 0);
	printf("%d", counts[0]);
	for (i = 1; i <= max_level; i++)
		printf(" %d", counts[i]);

	system("pause");
	return 0;
}