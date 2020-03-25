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

#define N_MAX 10000

int pre[N_MAX];
// ����ȷ���Ƿ���UV
set<int>is_exist;


int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	int i;
	for (i = 0; i < N; ++i) {
		scanf("%d", pre + i);
		is_exist.insert(pre[i]);
	}


	int U, V;
	bool is_exist_U, is_exist_V;
	int h;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &U, &V);
		
		is_exist_U = is_exist.find(U) != is_exist.end();
		is_exist_V = is_exist.find(V) != is_exist.end();

		if (!is_exist_U && !is_exist_V)
			printf("ERROR: %d and %d are not found.\n", U, V);
		else if (!is_exist_U)
			printf("ERROR: %d is not found.\n", U);
		else if (!is_exist_V)
			printf("ERROR: %d is not found.\n", V);
		else {
			for (h = 0; h < N; ++h)
				// ����������������е����LCA�����ڵ�����
				// pre�Ķ���ʹ�������������ȱ���������
				if (U <= pre[h] && pre[h] <= V || V <= pre[h] && pre[h] <= U) {
					if (pre[h] == U)
						printf("%d is an ancestor of %d.\n", U, V);
					else if (pre[h] == V)
						printf("%d is an ancestor of %d.\n", V, U);
					else
						printf("LCA of %d and %d is %d.\n", U, V, pre[h]);
					break;
				}
		}
	}

	system("pause");
	return 0;
}