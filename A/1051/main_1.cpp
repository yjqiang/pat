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
	int i, j;
	stack.clear();
	for (i = 0, j = 1; j <= N; ++j) {
		stack.push_back(j);
		if (stack.size() > M)
			return false;
		while (!stack.empty() && stack[stack.size() - 1] == a[i]) {
			stack.pop_back();
			++i;
		}
			
	}
	if (i == N)
		return true;
	return false;
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