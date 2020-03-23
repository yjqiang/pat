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
map<int, int>indices4mid;

// root 为子树根在pre的下标
// [start, end] 为子树在mid的下标范围
void post(int root, int start, int end) {
	int i = indices4mid[pre[root]];
	// 有左子树，则post序列第一个元素一定在左子树里面
	if(start <= i -1)
		post(root + 1, start, i - 1);
	// 否则，若有右子树，则一定在右子树
	else if (i + 1 <= end)
		post(root + i - start + 1, i + 1, end);
	// 否则，父节点即为所求
	else
		printf("%d", pre[root]);
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", pre + i);
	for (i = 0; i < N; ++i) {
		scanf("%d", mid + i);
		indices4mid[mid[i]] = i;
	}

	post(0, 0, N - 1);
	system("pause");
	return 0;
}