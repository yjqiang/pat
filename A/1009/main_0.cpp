# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <stdio.h>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>
# include <cmath>

using namespace std;

#define MAX_N 1001
#define D_MAX_N 2002
double p[MAX_N];
double result[D_MAX_N];

int main() {
	int K, N;
	double a;
	int i, k;

	scanf("%d", &K);

	
	for (i = 0; i < K; ++i) {
		scanf("%d%lf", &N, &a);
		p[N] = a;
	}

	scanf("%d", &K);

	for (i = 0; i < K; ++i) {
		scanf("%d%lf", &N, &a);
		for (k = 0; k < MAX_N; ++k)
			result[N + k] += p[k] * a;
	}


	int count = 0;
	for (i = 0; i < D_MAX_N; ++i) {
		if (result[i] != 0.0)
			++count;
	}

	printf("%d", count);
	for (i = D_MAX_N - 1; i >= 0 ; --i) {
		if (result[i] != 0.0)
			printf(" %d %.1lf", i, result[i]);
	}

	system("pause");
	return 0;
}