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

using namespace std;

#define N_MAX 10001
#define K_MAX 10

struct User {
	char name[9];
	int height;
};

// ��һ���������һ�ŵģ���ӡ��˳�򼴿�
User users[N_MAX];
// ÿһ�ŵ���ʼindex��users[stars[0], starts[1])  ����ҿ�����Ϊ���һ��
int starts[K_MAX + 1];

// ���յĽ��
int users_indexes[N_MAX];

int cmp(const void* p0, const void* p1) {
	User* u0 = (User*)p0;
	User* u1 = (User*)p1;

	// ��ߵݼ�
	if (u0->height != u1->height)
		return u1->height - u0->height;
	// �����ͬ����������С����ǰ
	return strcmp(u0->name, u1->name);

}

int main() {
	int N, K;
	
	scanf("%d %d", &N, &K);
	
	int i, h;
	for (i = 0; i < N; ++i)
		scanf("%s %d", users[i].name, &(users[i].height));

	qsort(users, N, sizeof(User), cmp);
	// printf("\n\n");

	// �����������һ�ſ�ʼ��starts[0]�����һ�ŵ���ʼindex������
	int start;
	// �ȷ���ǰ�ŵ�K-1����
	for (i = K - 1, start = N - N / K; i > 0; --i, start -= N / K)
		starts[i] = start;
	// ���һ�Ŵ�0��ʼ
	starts[0] = 0;
	// ���ڱ���
	starts[K] = N;

	int len_row;  // ÿһ�ŵ�����
	int mid, offset;  // �м�index������ƫ����
	for (i = 0; i < K; ++i) {
		start = starts[i];
		// ���ڱ�����i=K-1ʱ������
		len_row = starts[i + 1] - start;

		// ��ߵİ������м�
		mid = (len_row / 2 + 1) - 1 + start;
		users_indexes[mid] = start;

		offset = -1;  // ���ҽ��棨�����߽Ƕȣ�
		for (h = 1; h < len_row; ++h) {
			users_indexes[mid + offset] = start + h;
			if (offset < 0)
				offset *= -1;
			else
				offset = (-offset) - 1;
		}

	}

	int end;
	for (i = 0; i < K; ++i) {
		start = starts[i];
		end = starts[i + 1];
		printf("%s", users[users_indexes[start]].name);
		for (h = start + 1; h < end; ++h)
			printf(" %s", users[users_indexes[h]].name);
		printf("\n");
	}


	system("pause");
	return 0;
}