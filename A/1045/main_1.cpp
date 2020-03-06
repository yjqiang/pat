#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 201
#define M_MAX 201
#define L_MAX 10001

// 把花里胡哨的颜色还原为favor里面的对应index
int book[N_MAX] = {0};
int a[L_MAX];

// dp[i]表示以i为末尾的最大单调不降子序列
int dp[L_MAX];

int main() {
	// 这道题 5 5 1 2 3 4 5 7 1 1 1 1 1 1 1  输出7，是个sb题目
	int N;
	scanf("%d", &N);

	int M;
	scanf("%d", &M);

	int i;
	int num;
	// favor 颜色unique
	for (i = 1; i <= M; ++i) {
		scanf("%d", &num);
		// 用于把“L”个颜色对应回index，0缺省；这样题目就成了找最大单调不降子序列
		book[num] = i;
	}

	int n_a = 0;
	int L;
	scanf("%d", &L);
	for (i = 0; i < L; ++i) {
		scanf("%d", &num);
		// 过滤掉不在favor里面的颜色
		if (book[num] > 0) {
			a[n_a] = book[num];
			++n_a;
		}
	}

	int result = -1;
	int j;
	for (i = 0; i < n_a; ++i) {
		dp[i] = 1;
		for (j = 0; j < i; ++j)
			// 可以在dp[j] 对应的子序列上扩充
			if (a[i] >= a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		result = max(dp[i], result);
	}
	printf("%d", result);

	system("pause");
	return 0;
}