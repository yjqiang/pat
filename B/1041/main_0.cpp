#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define N_MAX 1001
struct Student {
	char ID[17];
	// int pc_num;
	int exam_num;
};

Student students[N_MAX];


int main() {
	int N;
	scanf("%d", &N);

	int i;
	int pc_num;
	char ID[17];
	int exam_num;
	for (i = 0; i < N; ++i) {
		scanf("%s%d%d", ID, &pc_num, &exam_num);
		strcpy(students[pc_num].ID, ID);
		students[pc_num].exam_num = exam_num;
	}

	int M;
	scanf("%d", &M);
	for (i = 0; i < M; ++i) {
		scanf("%d", &pc_num);
		printf("%s %d\n", students[pc_num].ID, students[pc_num].exam_num);
	}
	system("pause");
	return 0;
}