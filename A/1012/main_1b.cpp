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

#define N_MAX 2000

struct Student {
	int StudentID;
	// A C M E
	int grades[4];
	int ranks[4];
};

char name_grades[] = "ACME";

Student students[N_MAX];
// indices和students逆反
map<int, int> indices;

// 辅助排序的，每个元素其实是Student（对应于students），但是为了indices，只排序students的下标
int ranks[N_MAX];
// 指示成绩的位置（A C M E）
int flag;

int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;

	return students[*b].grades[flag] - students[*a].grades[flag];
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);


	int i;
	int StudentID, grade_C, grade_M, grade_E;
	for (i = 0; i < N; ++i) {
		scanf("%d %d %d %d", &StudentID, &grade_C, &grade_M, &grade_E);
		students[i].StudentID = StudentID;
		students[i].grades[0] = (grade_C + grade_M + grade_E) / 3;
		students[i].grades[1] = grade_C;
		students[i].grades[2] = grade_M;
		students[i].grades[3] = grade_E;

		indices[StudentID] = i;
		ranks[i] = i;
	}
	
	// 分数一致，rank相同的
	int cur_rank, cur_grade;
	for (flag = 0; flag < 4; ++flag) {
		qsort(ranks, N, sizeof(int), cmp);

		cur_rank = 0;
		cur_grade = -1;
		for (i = 0; i < N; ++i) {
			if (students[ranks[i]].grades[flag] != cur_grade) {
				cur_grade = students[ranks[i]].grades[flag];
				cur_rank = students[ranks[i]].ranks[flag] = i + 1;
			}
			else
				students[ranks[i]].ranks[flag] = cur_rank;
		}
	}

	int best_flag, best_rank;
	int index;
	for (i = 0; i < M; ++i) {
		scanf("%d", &StudentID);
		if (indices.find(StudentID) == indices.end())
			printf("N/A\n");
		else {
			index = indices[StudentID];
			
			best_rank = INT_MAX;
			for (flag = 0; flag < 4; ++flag)
				if (students[index].ranks[flag] < best_rank) {
					best_rank = students[index].ranks[flag];
					best_flag = flag;
				}

			printf("%d %c\n", best_rank, name_grades[best_flag]);
		}
	}

	system("pause");
	return 0;
}