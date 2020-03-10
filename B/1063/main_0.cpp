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

using namespace std;

int main() {
	int N;
	int a, b;
	scanf("%d", &N);

	double result = -1, double_tmp;
	int i;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &a, &b);
		double_tmp = sqrt((double)(a * a + b * b));
		if (double_tmp > result)
			result = double_tmp;
	}
	printf("%.2lf", result);


	system("pause");
	return 0;
}