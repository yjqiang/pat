#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 201
#define M_MAX 201
#define L_MAX 10001

// �ѻ�����ڵ���ɫ��ԭΪfavor����Ķ�Ӧindex
int book[N_MAX] = {0};
int a[L_MAX];

// dp[i]��ʾ��iΪĩβ����󵥵�����������
int dp[L_MAX];

int main() {
	// ����� 5 5 1 2 3 4 5 7 1 1 1 1 1 1 1  ���7���Ǹ�sb��Ŀ
	int N;
	scanf("%d", &N);

	int M;
	scanf("%d", &M);

	int i;
	int num;
	// favor ��ɫunique
	for (i = 1; i <= M; ++i) {
		scanf("%d", &num);
		// ���ڰѡ�L������ɫ��Ӧ��index��0ȱʡ��������Ŀ�ͳ�������󵥵�����������
		book[num] = i;
	}

	int n_a = 0;
	int L;
	scanf("%d", &L);
	for (i = 0; i < L; ++i) {
		scanf("%d", &num);
		// ���˵�����favor�������ɫ
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
			// ������dp[j] ��Ӧ��������������
			if (a[i] >= a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		result = max(dp[i], result);
	}
	printf("%d", result);

	system("pause");
	return 0;
}