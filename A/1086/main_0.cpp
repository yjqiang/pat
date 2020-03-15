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

using namespace std;

char options[2][6] = { "Push", "Pop" };
char the_input[6];

// 前序中序后的遍历结果序列
vector<int> mid;
vector<int> pre;

vector<int> post;


// root 为 pre中该子树片段的父节点的下标
// start end为 mid 中该子树的左右下标
void func(int root, int start, int end) {
	if (start > end)
		return;

	int i;
	for (i = start; mid[i] != pre[root]; ++i);

	func(root + 1, start, i - 1);
	func(root + i + 1 - start, i + 1,  end);
	post.push_back(pre[root]);
}

int main() {
	int N;
	
	scanf("%d", &N);

	int i;
	int num;
	bool is_first = true;

	vector<int> my_stack;
	for (i = 2*N - 1; i >= 0; --i) {
		scanf("%s", the_input);
		// push
		if (strcmp(the_input, options[0]) == 0) {
			scanf("%d", &num);
			my_stack.push_back(num);

			pre.push_back(num);
		}
		// pop
		else {
			mid.push_back(my_stack.back());
			my_stack.pop_back();
		}
	}


	func(0, 0, N - 1);

	printf("%d", post[0]);
	for (i = 1; i < N; ++i)
		printf(" %d", post[i]);
	
	system("pause");
	return 0;
}