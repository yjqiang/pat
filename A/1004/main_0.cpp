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

	queue<int> q;
	int p, num, count_noleaf_nodes, level=0;
	bool have_leaf;
	q.push(1);
	while (!q.empty()) {
		count_noleaf_nodes = 0;
		++level;

		num = q.size();
		for (i = 0; i < num; ++i){
			p = q.front();
			q.pop();

			have_leaf = false;
			for (k = 0; k < MAX_N; ++k)
				if (edges[p][k]) {
					q.push(k);
					have_leaf = true;
				}
			if (!have_leaf)
				++count_noleaf_nodes;
		}
		if (level == 1)
			printf("%d", count_noleaf_nodes);
		else
			printf(" %d", count_noleaf_nodes);
	}


	system("pause");
	return 0;
}