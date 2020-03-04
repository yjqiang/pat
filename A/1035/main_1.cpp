#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

#define N_MAX 100
int orig[N_MAX];
int sorted[N_MAX];

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
		scanf("%d", sorted + i);

	int the_index;
	// insert排序这里验证时，不用匹配排好序的部分，只匹配后半部分即可。后面一一匹配了，自然前部分的数据集合也一致
	for (i = 1; i < N && sorted[i] >= sorted[i - 1]; ++i);
	the_index = i; // 临界index
	for (; i < N && sorted[i] == orig[i]; ++i);

	int int_tmp;
	if (i == N) {
		printf("Insertion Sort\n");
		// the_index != N 否则该数组全排好序了，那么两个sort type答案了
		int_tmp = sorted[the_index];
		for (i = the_index - 1; i >= 0 && sorted[i] > int_tmp; --i)
			sorted[i + 1] = sorted[i];
		sorted[i + 1] = int_tmp;

		printf("%d", sorted[0]);
		for (i = 1; i < N; ++i)
			printf(" %d", sorted[i]);

	}
	else {
		printf("Merge Sort\n");
		int length;
		int matched_index;
		int k;
		// 在orig上面进行sort，不断比较与sorted的区别，当完全一致时，本次排好序后，停止。
		for (length = 1; length <= N; length *= 2) {
			// 比较与sorted的区别
			for (matched_index = 0; matched_index < N && orig[matched_index] == sorted[matched_index]; ++matched_index);
			// k < N / length是保证每（length）个长度的片段归并后，剩余的长度小于length且大于等于0
			// N / length 是最大片段数目，可能有余数 N%length
			// k * length 是片段起始坐标
			for (k = 0; k < N / length; ++k)
				qsort(orig + k * length, length, sizeof(int), cmp);
			qsort(orig + k * length, N % length, sizeof(int), cmp);

			if (matched_index == N)
				break;

		}

		printf("%d", orig[0]);
		for (i = 1; i < N; ++i)
			printf(" %d", orig[i]);

	}
	

	system("pause");
	return 0;
}