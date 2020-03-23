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

#define N_MAX 50000

int pre[N_MAX];
int mid[N_MAX];

bool is_first = true;

// root 为子树根在pre的下标
// [start, end] 为子树在mid的下标范围
void post(int root, int start, int end) {
	if (start > end)
		return;

	int i;
	for (i = start; mid[i] != pre[root]; ++i);
	post(root + 1, start, i - 1);
	post(root + i - start + 1, i + 1, end);
	if (is_first) {
		printf("%d", pre[root]);
		is_first = false;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", pre + i);
	for (i = 0; i < N; ++i)
		scanf("%d", mid + i);

	post(0, 0, N - 1);
	system("pause");
	return 0;
}