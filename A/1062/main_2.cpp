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
	// 对应4个分类
	int level;
	int ID_Number;
	int Virtue_Grade;
	int Talent_Grade;
	// V + T
	int total_grade;
};

#define N_MAX 100000
// 注意，至少要全都大于等于 L

int size0 = 0;
Student stus0[N_MAX];

// total_score -> Virtue_Grade -> ID
int cmp(const void* p0, const void* p1) {
	Student* a = (Student*)p0;
	Student* b = (Student*)p1;
	if (a->level != b->level)
		return a->level - b->level;
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
	int level;
	for (i = 0; i < N; ++i) {
		scanf("%d %d %d", &ID_Number, &Virtue_Grade, &Talent_Grade);
		// 分类放入不同的范围里面
		if (Virtue_Grade >= L && Talent_Grade >= L) {
			if (Virtue_Grade >= H && Talent_Grade >= H)
				level = 1;
			else if (Virtue_Grade >= H && Talent_Grade < H)
				level = 2;
			else if (Virtue_Grade < H && Talent_Grade < H && Virtue_Grade >= Talent_Grade)
				level = 3;
			else 
				level = 4;
			stus0[size0].level = level;
			stus0[size0].ID_Number = ID_Number;
			stus0[size0].Virtue_Grade = Virtue_Grade;
			stus0[size0].Talent_Grade = Talent_Grade;
			stus0[size0].total_grade = Virtue_Grade + Talent_Grade;
			++size0;
		}
	}

	qsort(stus0, size0, sizeof(Student), cmp);


	printf("%d\n", size0);
	for (i = 0; i < size0; ++i)
		printf("%08d %d %d\n", stus0[i].ID_Number, stus0[i].Virtue_Grade, stus0[i].Talent_Grade);



	system("pause");
	return 0;
}