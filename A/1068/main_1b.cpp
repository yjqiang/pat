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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define N_MAX 10001
#define M_MAX 101

int nums[N_MAX];

// dp[j]��ʵ��dp[i][j]�Ŀռ�Ľ��棬dp[i][j] ��ʾԼ������ţ�nums��С�ڵ���i && ���������j����������������01�������⣩
// ��ʼ��Ϊ0����ʾdp[0][j] ȫΪ0
int dp[M_MAX] = {0};

// results[i][j] ��ʾǡ����jΪ�͵��������У������Ϊi�����������У�ԭ��Ҫ��output the smallest sequence���Ƿ����
bool results[N_MAX][M_MAX] = { false };

// �Ӵ�С����
int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*b) - (*a);
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	int i, j;
	// ��1�����Ϊ�˷���01����
	for (i = 1; i <= N; ++i)
		scanf("%d", nums + i);

	qsort(nums + 1, N, sizeof(int), cmp);


	int cur;
	for (i = 1; i <= N; ++i)
		for (j = M; j >= 0; --j)
			// ��j - nums[i] < 0����˵��i����Ʒ�����Ա�ѡ�в��뵽dp[i][j]��
			if (j - nums[i] >= 0) {
				cur = dp[j - nums[i]] + nums[i]; // ������һ��������i�����ʱ���Ž��Ϊdp[i][j] = dp[i-1][j-V[i]] + m[i]
				if (cur >= dp[j]) {
					results[i][cur] = true;
					dp[j] = cur;
				}
		}

	vector<int> s;

	if (dp[M] != M)
		printf("No Solution");
	else {
		for (i = N; i >= 0 && M > 0;) {
			for (;!results[i][M]; --i);
			s.push_back(nums[i]);
			M -= nums[i];
			// nums[i] �ѱ�ѡ���ˣ������ظ���
			--i;
		}

		printf("%d", s[0]);
		for (i = 1; i < s.size(); ++i)
			printf(" %d", s[i]);
	}
	system("pause");
	return 0;
}