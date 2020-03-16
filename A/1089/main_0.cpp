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
	// 插入排序的前半段序列是排好序的
	for (i = 1; i < N && half_sort[i] >= half_sort[i - 1]; ++i);

	threshold = i;

	// 后半段与原序列一致
	for (; i < N && half_sort[i] == orig[i]; ++i);

	if (i == N) {
		printf("Insertion Sort\n");

		// 模仿插排那样，寻找合适位置，插入
		int_tmp = half_sort[threshold];
		for (i = threshold - 1; i >= 0 && half_sort[i] > int_tmp; --i)
			half_sort[i + 1] = half_sort[i];
		half_sort[i + 1] = int_tmp;

		// 打印
		printf("%d", half_sort[0]);
		for (i = 1; i < N; ++i)
			printf(" %d", half_sort[i]);

	}
	else {
		printf("Merge Sort\n");

		int check_i;
		// orig从头开始，一步一步模拟归并排序
		int k;
		for (k = 2; ; k *= 2) {
			// half_sort不可能全部排好序的，否则就是插排和归并均可了
			for (check_i = 0; check_i < N && half_sort[check_i] == orig[check_i]; ++check_i);

			// 每k个一组，排好序，剩下的不满k个的单独排序
			// i (i+1) ... (i+k-1) || (i+k)...
			for (i = 0; i + k <= N; i += k)
				qsort(orig + i, k, sizeof(int), cmp);

			// 剩下的单独排序
			qsort(orig + i, N % k, sizeof(int), cmp);


			// 这里的设计使得序列模拟相同后，仍再执行一步，然后退出
			if (check_i == N)
				break;

			// 最终结束，即只进行一组的排序
			if (k >= N)
				break;
		}

		// 打印
		printf("%d", orig[0]);
		for (i = 1; i < N; ++i)
			printf(" %d", orig[i]);
	}
	
	
	
	system("pause");
	return 0;
}