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

#define N_MAX 30

struct Node {
	int value;
	// 完全二叉树编号法(一共30个点，最坏情况下，index也能控制在INT_MAX内)
	int index;

	// 层序遍历顺序与编号一致
	bool operator<(const Node& b)const {
		return index < b.index;
	}
};

vector<Node> result;

int post[N_MAX];
int in[N_MAX];

// root 为该子树的根在post数组的下标
// start end为该子树在in数组的范围
// index 完全二叉树编号法
void check(int root, int start, int end, int index) {
	if (start > end)
		return;

	int i;
	for (i = 0; in[i] != post[root]; ++i);

	result.push_back(Node{ post[root], index });
	// 左子树
	check(i + root - end - 1, start, i - 1, index * 2);
	// 右子树
	check(root -1, i + 1, end, index * 2 + 1);
}


int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", post + i);
	for (i = 0; i < N; ++i)
		scanf("%d", in + i);

	check(N - 1, 0, N - 1, 1);
	
	sort(result.begin(), result.end());
	
	printf("%d", result[0].value);
	for (i = 1; i < N; ++i)
		printf(" %d", result[i].value);




	system("pause");
	return 0;
}