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


int main() {
	double e;
	int N, D;
	scanf("%d %lf %d", &N, &e, &D);
	// ø…ƒ‹ø’÷√£¨ø’÷√
	int count_maybe, count_sure;
	count_maybe = 0;
	count_sure = 0;

	int K;
	int i, h;
	double double_tmp;
	int count;
	for (i = 0; i < N; ++i) {
		scanf("%d", &K);
		count = 0;
		for (h = 0; h < K; ++h) {
			scanf("%lf", &double_tmp);
			if (double_tmp < e)
				++count;
		}
		if (count * 2 > K) {
			if (K > D)
				++count_sure;
			else
				++count_maybe;
		}
	}

	printf("%.1lf%% %.1lf%%", count_maybe * 100.0 / N, count_sure * 100.0 / N);

	

	system("pause");
	return 0;
}