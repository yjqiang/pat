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

// 第一人排在最后一排的，打印按顺序即可
User users[N_MAX];
// 每一排的起始index。users[stars[0], starts[1])  左闭右开区间为最后一排
int starts[K_MAX + 1];

// 最终的结果
int users_indexes[N_MAX];

int cmp(const void* p0, const void* p1) {
	User* u0 = (User*)p0;
	User* u1 = (User*)p1;

	// 身高递减
	if (u0->height != u1->height)
		return u1->height - u0->height;
	// 身高相同，名字排序，小的在前
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

	// 分区，从最后一排开始，starts[0]是最后一排的起始index。。。
	int start;
	// 先分完前排的K-1个区
	for (i = K - 1, start = N - N / K; i > 0; --i, start -= N / K)
		starts[i] = start;
	// 最后一排从0开始
	starts[0] = 0;
	// “哨兵”
	starts[K] = N;

	int len_row;  // 每一排的人数
	int mid, offset;  // 中间index和左右偏移量
	for (i = 0; i < K; ++i) {
		start = starts[i];
		// “哨兵”在i=K-1时起作用
		len_row = starts[i + 1] - start;

		// 最高的安排在中间
		mid = (len_row / 2 + 1) - 1 + start;
		users_indexes[mid] = start;

		offset = -1;  // 左右交替（拍照者角度）
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