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

	int left = 0, right = K-1, result=INT_MIN;
	long long int dp_i = INT_MIN;
	long long int tmp0, tmp1;
	int tmp_left = 0, tmp_right;
	
	for (i = 0; i < K; ++i) {
		tmp0 = dp_i + a[i];
		tmp1 = a[i];
		if (tmp0 >= tmp1) {
			dp_i = tmp0;
			
			tmp_right = i;
		}
		else {
			dp_i = tmp1;

			tmp_left = i;
			tmp_right = i;
		}
		
		if (dp_i > result) {
			left = tmp_left;
			right = tmp_right;
			result = dp_i;
		}
		printf("i=%d, dp_i=%lld, left=%d, right=%d\n", i, dp_i, left, right);
		
	}
	if(result < 0)
		printf("%d %d %d", 0, a[0], a[K-1]);
	else
		printf("%d %d %d", result, a[left], a[right]);
	system("pause");
	return 0;
}