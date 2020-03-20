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

#define N_MAX 10000

struct Student {
	char name[9];
	int height;
};
Student students[N_MAX];

// 某行的所有学生的index（对应了students[index]）
int one_row[N_MAX];


int cmp(const void* p0, const void* p1) {
	Student* student0 = (Student*)p0;
	Student* student1 = (Student*)p1;

	if (student1->height != student0->height)
		return student1->height - student0->height;
	return strcmp(student0->name, student1->name);
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);


	int i;
	for (i = 0; i < N; ++i)
		scanf("%s%d", students[i].name, &(students[i].height));

	qsort(students, N, sizeof(Student), cmp);

	// 第几排，最后一排为0
	int row;
	// 指示了某一排的学生数目
	int n_row;

	int mid;
	int offset;
	int h;

	// i 指示了students的下标
	for (row = 0, i = 0; row < K; ++row) {
		n_row = (row != 0) ? N / K : N % K + N / K;

		// 距离中心点的偏移量
		offset = 0;
		mid = n_row / 2 + 1;
		for (h = 0; h < n_row; ++h) {
			one_row[mid + offset] = i++;
			if (offset < 0)
				offset = -offset;
			else
				offset = -offset - 1;
		}


		printf("%s", students[one_row[1]].name);
		for (h = 2; h <= n_row; ++h)
			printf(" %s", students[one_row[h]].name);
		printf("\n");
	}


	system("pause");
	return 0;
}