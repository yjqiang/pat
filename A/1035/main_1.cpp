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
	// insert����������֤ʱ������ƥ���ź���Ĳ��֣�ֻƥ���벿�ּ��ɡ�����һһƥ���ˣ���Ȼǰ���ֵ����ݼ���Ҳһ��
	for (i = 1; i < N && sorted[i] >= sorted[i - 1]; ++i);
	the_index = i; // �ٽ�index
	for (; i < N && sorted[i] == orig[i]; ++i);

	int int_tmp;
	if (i == N) {
		printf("Insertion Sort\n");
		// the_index != N ���������ȫ�ź����ˣ���ô����sort type����
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
		// ��orig�������sort�����ϱȽ���sorted�����𣬵���ȫһ��ʱ�������ź����ֹͣ��
		for (length = 1; length <= N; length *= 2) {
			// �Ƚ���sorted������
			for (matched_index = 0; matched_index < N && orig[matched_index] == sorted[matched_index]; ++matched_index);
			// k < N / length�Ǳ�֤ÿ��length�������ȵ�Ƭ�ι鲢��ʣ��ĳ���С��length�Ҵ��ڵ���0
			// N / length �����Ƭ����Ŀ������������ N%length
			// k * length ��Ƭ����ʼ����
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