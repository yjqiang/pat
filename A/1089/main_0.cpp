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
#include <unordered_set>

using namespace std;

#define N_MAX 100

int orig[N_MAX];
int half_sort[N_MAX];

int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*a) - (*b);
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", orig + i);
	for (i = 0; i < N; ++i)
		scanf("%d", half_sort + i);

	int int_tmp;
	int threshold;
	// ���������ǰ����������ź����
	for (i = 1; i < N && half_sort[i] >= half_sort[i - 1]; ++i);

	threshold = i;

	// ������ԭ����һ��
	for (; i < N && half_sort[i] == orig[i]; ++i);

	if (i == N) {
		printf("Insertion Sort\n");

		// ģ�²���������Ѱ�Һ���λ�ã�����
		int_tmp = half_sort[threshold];
		for (i = threshold - 1; i >= 0 && half_sort[i] > int_tmp; --i)
			half_sort[i + 1] = half_sort[i];
		half_sort[i + 1] = int_tmp;

		// ��ӡ
		printf("%d", half_sort[0]);
		for (i = 1; i < N; ++i)
			printf(" %d", half_sort[i]);

	}
	else {
		printf("Merge Sort\n");

		int check_i;
		// orig��ͷ��ʼ��һ��һ��ģ��鲢����
		int k;
		for (k = 2; ; k *= 2) {
			// half_sort������ȫ���ź���ģ�������ǲ��ź͹鲢������
			for (check_i = 0; check_i < N && half_sort[check_i] == orig[check_i]; ++check_i);

			// ÿk��һ�飬�ź���ʣ�µĲ���k���ĵ�������
			// i (i+1) ... (i+k-1) || (i+k)...
			for (i = 0; i + k <= N; i += k)
				qsort(orig + i, k, sizeof(int), cmp);

			// ʣ�µĵ�������
			qsort(orig + i, N % k, sizeof(int), cmp);


			// ��������ʹ������ģ����ͬ������ִ��һ����Ȼ���˳�
			if (check_i == N)
				break;

			// ���ս�������ֻ����һ�������
			if (k >= N)
				break;
		}

		// ��ӡ
		printf("%d", orig[0]);
		for (i = 1; i < N; ++i)
			printf(" %d", orig[i]);
	}
	
	
	
	system("pause");
	return 0;
}