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

using namespace std;

struct Student {
	int ID_Number;
	int Virtue_Grade;
	int Talent_Grade;
	// V + T
	int total_grade;
};

#define N_MAX 100000
// 注意，至少要全都大于等于 L

// V >= H && T >= H
int size1 = 0;
Student stus1[N_MAX];

// V >= H && T < H
int size2 = 0;
Student stus2[N_MAX];

// V < H && T < H && V >= T
int size3 = 0;
Student stus3[N_MAX];

// others
int size4 = 0;
Student stus4[N_MAX];

// total_score -> Virtue_Grade -> ID
int cmp(const void* p0, const void* p1) {
	Student* a = (Student*)p0;
	Student* b = (Student*)p1;

	if (a->total_grade != b->total_grade)
		return b->total_grade - a->total_grade;
	if (a->Virtue_Grade != b->Virtue_Grade)
		return b->Virtue_Grade - a->Virtue_Grade;
	return a->ID_Number - b->ID_Number;
}

int main() {
	int N, L, H;
	scanf("%d %d %d", &N, &L, &H);

	int i;
	int ID_Number, Virtue_Grade, Talent_Grade;
	for (i = 0; i < N; ++i) {
		scanf("%d %d %d", &ID_Number, &Virtue_Grade, &Talent_Grade);
		// 分类放入不同的范围里面
		if (Virtue_Grade >= L && Talent_Grade >= L) {
			if (Virtue_Grade >= H && Talent_Grade >= H) {
				stus1[size1].ID_Number = ID_Number;
				stus1[size1].Virtue_Grade = Virtue_Grade;
				stus1[size1].Talent_Grade = Talent_Grade;
				stus1[size1].total_grade = Virtue_Grade + Talent_Grade;
				++size1;
			}
			else if (Virtue_Grade >= H && Talent_Grade < H) {
				stus2[size2].ID_Number = ID_Number;
				stus2[size2].Virtue_Grade = Virtue_Grade;
				stus2[size2].Talent_Grade = Talent_Grade;
				stus2[size2].total_grade = Virtue_Grade + Talent_Grade;
				++size2;
			}
			else if (Virtue_Grade < H && Talent_Grade < H && Virtue_Grade >= Talent_Grade) {
				stus3[size3].ID_Number = ID_Number;
				stus3[size3].Virtue_Grade = Virtue_Grade;
				stus3[size3].Talent_Grade = Talent_Grade;
				stus3[size3].total_grade = Virtue_Grade + Talent_Grade;
				++size3;
			}
			else {
				stus4[size4].ID_Number = ID_Number;
				stus4[size4].Virtue_Grade = Virtue_Grade;
				stus4[size4].Talent_Grade = Talent_Grade;
				stus4[size4].total_grade = Virtue_Grade + Talent_Grade;
				++size4;
			}
		}
	}

	qsort(stus1, N, sizeof(Student), cmp);
	qsort(stus2, N, sizeof(Student), cmp);
	qsort(stus3, N, sizeof(Student), cmp);
	qsort(stus4, N, sizeof(Student), cmp);

	printf("%d\n", size1 + size2 + size3 + size4);
	for (i = 0; i < size1; ++i)
		printf("%08d %d %d\n", stus1[i].ID_Number, stus1[i].Virtue_Grade, stus1[i].Talent_Grade);
	for (i = 0; i < size2; ++i)
		printf("%08d %d %d\n", stus2[i].ID_Number, stus2[i].Virtue_Grade, stus2[i].Talent_Grade);
	for (i = 0; i < size3; ++i)
		printf("%08d %d %d\n", stus3[i].ID_Number, stus3[i].Virtue_Grade, stus3[i].Talent_Grade);
	for (i = 0; i < size4; ++i)
		printf("%08d %d %d\n", stus4[i].ID_Number, stus4[i].Virtue_Grade, stus4[i].Talent_Grade);


	system("pause");
	return 0;
}