# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>
# include <cmath>

using namespace std;

int a[10005];

int main() {
	int K;
	scanf("%d", &K);

	int i;
	for (i = 0; i < K; ++i)
		scanf("%d", a + i);

	int sum = 0;
	int min_sum = 0, min_sum_right = -1;
	int left = 0, right = K-1;
	int dp_i = INT_MIN;

	for (i = 0; i < K; ++i) {
		sum += a[i];
		if (sum - min_sum > dp_i) {
			dp_i = sum - min_sum;
			left = min_sum_right + 1;
			right = i;
		}
		if (sum < min_sum) {
			min_sum = sum;
			min_sum_right = i;
		}
		// printf("i=%d, sum=%d, min_sum=%d, min_sum_right=%d, dp_i=%d, left=%d, right=%d\n", i, sum, min_sum, min_sum_right, dp_i, left, right);
	}
	if(dp_i < 0)
		printf("%d %d %d", 0, a[0], a[K-1]);
	else
		printf("%d %d %d", dp_i, a[left], a[right]);
	system("pause");
	return 0;
}