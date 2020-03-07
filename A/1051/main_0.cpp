#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

#define N_MAX 1000
vector<int> stack;
int a[1000];
int M, N, K;

bool isOk() {
	int i, min_remain;
	stack.clear();
	// min_remain 下一个入栈的数据，即未入栈的最小数
	for (i = 0, min_remain = 1; i < N;) {
		if (min_remain <= a[i] && min_remain <= N) {
			// printf("push %d\n", min_remain);
			stack.push_back(min_remain);
			if (stack.size() > M)
				return false;
			++min_remain;
		}
		// 否则尝试匹配栈顶元素
		else if (!stack.empty() && stack[stack.size()-1] == a[i]) {
			// printf("pop %d\n", a[i]);
			stack.pop_back();
			++i;
		}
		else
			return false;
			
	}
	return true;
}

int main() {

	scanf("%d %d %d", &M, &N, &K);

	int i, h;
	for (i = 0; i < K; ++i) {
		for (h = 0; h < N; ++h)
			scanf("%d", a + h);
		if (isOk())
			printf("YES\n");
		else
			printf("NO\n");

	}
	system("pause");
	return 0;
}