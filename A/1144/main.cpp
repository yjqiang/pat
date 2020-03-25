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

#define N_MAX 100002

// 最坏情况  N = 10^5 ，且num从 1、2、3...N， 10^5+1为所求；其余情况所求结果肯定小于这个值
// 所以，输入num大于100001可以忽略的
bool is_exist[N_MAX] = {false};

int main() {
	int N;
	scanf("%d", &N);

	int num;
	int i;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		if (num > 0 && num < 100001)
			is_exist[num] = true;
	}

	for (i = 1; i < N_MAX; ++i)
		if (!is_exist[i]) {
			printf("%d", i);
			break;
		}
	system("pause");
	return 0;
}