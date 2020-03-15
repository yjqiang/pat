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

struct Student {
	bool is_ok;
	char name[11];
	char ID[11];
};

// students[grade] = student_i
Student students[101];



int main() {
	int N;
	scanf("%d", &N);
	int i;

	char name[11];
	char ID[11];
	int grade;

	// 初始化，清空学生
	for (i = 0; i < 101; ++i)
		students[i].is_ok = false;

	for (i = 0; i < N; ++i) {
		scanf("%s%s%d", name, ID, &grade);
		strcpy(students[grade].name, name);
		strcpy(students[grade].ID, ID);
		students[grade].is_ok = true; // 激活数据
	}

	int grade1, grade2;

	scanf("%d%d", &grade1, &grade2);

	grade1 = max(0, grade1);
	grade2 = min(100, grade2);

	bool is_empty = true;
	for (i = grade2; i >= grade1; --i)
		if (students[i].is_ok) {
			printf("%s %s\n", students[i].name, students[i].ID);
			is_empty = false;
		}

	if (is_empty)
		printf("NONE");


	system("pause");
	return 0;
}