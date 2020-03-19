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

using namespace std;

#define N_MAX 400
int N, K, P;

// pows[i] = i ^ P
int pows[N_MAX];

int makePows() {
	int i;
	for (i = 0; ; ++i) {
		pows[i] = (int)pow(i, P);
		if (pows[i] > N)
			return i;
	}
}

vector<int>tmp;
vector<int>result;

// 因子的和
int max_sum_factors = -1;



// wanted 对接 N
// begin 其实就是subset那里的，这里我们需要倒着check
void func(int begin, int wanted, int sum_factors, int count_factors) {
	// count够了就剪断
	if (count_factors == K) {
		if (max_sum_factors < sum_factors&& wanted == 0) {
			result = tmp;
			max_sum_factors = sum_factors;
		}
		return;
	}

	int i;
	for (i = begin; i > 0; --i) {
		if (pows[i] <= wanted) {
			tmp.push_back(i);
			func(i, wanted - pows[i], sum_factors + i, count_factors+1);
			tmp.pop_back();
		}
	}

}


int main() {
	int i;
	scanf("%d%d%d", &N, &K, &P);
	
	int begin = makePows();

	func(begin, N, 0, 0);

	if (max_sum_factors == -1)
		printf("Impossible\n");
	else {
		printf("%d = %d^%d", N, result[0], P);
		for (i = 1; i < K; ++i)
			printf(" + %d^%d", result[i], P);
	}

	system("pause");
	return 0;
}