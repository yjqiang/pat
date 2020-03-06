#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define N_MAX 100001
#define M_MAX 10000

int Ds[N_MAX];

// sums[i] 表示 D1->D2->D3->...->Di 长度
int sums[N_MAX];


int main() {
	int N;
	scanf("%d", &N);

	int i;
	int int_tmp;
	sums[1] = 0;
	for (i = 2; i <= N; ++i) {
		scanf("%d", &int_tmp);
		sums[i] = sums[i-1] + int_tmp;
	}
	scanf("%d", &int_tmp);
	// 环的周长
	int circle_len = sums[N] + int_tmp;
	// printf("circle_len %d\n", circle_len);

	int M;
	int x, y;
	scanf("%d", &M);
	for (i = 0; i < M; ++i) {
		scanf("%d %d", &x, &y);
		// assert x <= y
		if (x > y)
			swap(x, y);
		int_tmp = sums[y] - sums[x];
		printf("%d\n", min(circle_len - int_tmp, int_tmp));
	}

	system("pause");
	return 0;
}