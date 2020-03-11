// ���԰�Ӳ�ҿ���w = v(������ = ��ֵ)����Ʒ������Ҫѡȡ��Щ��Ʒ���뵽����Ϊm�ı����У�����װ������ֵ��
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

using namespace std;

#define N_MAX 10002
int N;
int c[N_MAX];
// ��̬�滮f[i][v]��ʾ��[1, i]��ѡ�������Ϊv����Ʒ�����ļ�ֵ֮��
// ��ʼ��f[0][v]Ϊ0
int f[N_MAX] = { 0 };

// chosen[i][j]�����ʾ��������������Ϊj��ʱ�����ѡ���Ƿ��е�i����Ʒ������������е������
bool chosen[10010][110] = {false};

int cmp(const void* p0, const void* p1) {
	int* i0 = (int*)p0;
	int* i1 = (int*)p1;
	return (*i1) - (*i0);
}

int main() {
	int M;
	scanf("%d%d", &N, &M);

	int i;
	// Ϊ��dp�����õģ���1��ʼ
	for (i = 1; i <= N; ++i)
		scanf("%d", c + i);
	qsort(c + 1, N, sizeof(int), cmp);

	int v;
	for (i = 1; i <= N; ++i)
		// ��Ϊ��ʡ�ռ䣬��f��ά����ѹ���ˣ���������f[i][v]ʱ������f[i-1][v-c[i]]��f���棬����v�Ӵ�С������
		for (v = M; v >= 0; --v) {
			// ���ڵ�����£�Ҳѡ��i��������Ϊ�����Ҫ����С���ģ���Ϊ�����ǴӴ�С��
			if (v - c[i] >= 0 && f[v - c[i]] + c[i] >= f[v]) {
				f[v] = f[v - c[i]] + c[i];
				// ��Լ��v������£�i��������iΪ����ŵ�·���Ƿ���һ�����·��
				chosen[i][v] = true;
			}
		}

	
	if (f[M] != M) {
		printf("No Solution");
	}
	else {

		vector<int> answer;
		for (v = M, i = N; v > 0; --i)
			if (chosen[i][v]) {
				answer.push_back(c[i]);
				v -= c[i];
			}

		// ��ӡ���
		printf("%d", answer[0]);
		for (i = 1; i < answer.size(); i++)
			printf(" %d", answer[i]);
	}

	system("pause");
	return 0;
}