# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

typedef struct Student{
	int id;
	int de;
	int cai;
	int sum;
};

Student students1[100000];
Student students2[100000];
Student students3[100000];
Student students4[100000];

int comp(const void *a1, const void* a2) {
	Student* stu1 = (Student*)a1;
	Student* stu2 = (Student*)a2;
	if (stu1->sum != stu2->sum)
		return stu1->sum - stu2->sum;
	if (stu1->de != stu2->de)
		return stu1->de - stu2->de;
	return -(stu1->id - stu2->id);

}

int main() {
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	
	int i;
	int tmp_id, tmp_de, tmp_cai, tmp_sum;
	int n_students1 = 0, n_students2 = 0, n_students3 = 0, n_students4 = 0;
	Student student;
	for (i = 0; i < N; ++i) {
		scanf("%d%d%d", &tmp_id, &tmp_de, &tmp_cai);
		if (tmp_de >= L && tmp_cai >= L) {
			student.id = tmp_id;
			student.de = tmp_de;
			student.cai = tmp_cai;
			student.sum = tmp_de + tmp_cai;

			if (tmp_de >= H && tmp_cai >= H)
				students1[n_students1++] = student;
			else if (tmp_de >= H && tmp_cai < H)
				students2[n_students2++] = student;
			else if (tmp_de < H && tmp_cai < H && tmp_de >= tmp_cai)
				students3[n_students3++] = student;
			else
				students4[n_students4++] = student;
		}

	}
	qsort(students1, n_students1, sizeof(Student), comp);
	qsort(students2, n_students2, sizeof(Student), comp);
	qsort(students3, n_students3, sizeof(Student), comp);
	qsort(students4, n_students4, sizeof(Student), comp);

	printf("%d\n", n_students1 + n_students2 + n_students3 + n_students4);
	for (int i = n_students1 - 1; i >= 0; --i)
		printf("%d %d %d\n", students1[i].id, students1[i].de, students1[i].cai);
	for (int i = n_students2 - 1; i >= 0; --i)
		printf("%d %d %d\n", students2[i].id, students2[i].de, students2[i].cai);
	for (int i = n_students3 - 1; i >= 0; --i)
		printf("%d %d %d\n", students3[i].id, students3[i].de, students3[i].cai);
	for (int i = n_students4 - 1; i >= 0; --i)
		printf("%d %d %d\n", students4[i].id, students4[i].de, students4[i].cai);

	
	system("pause");
	return 0;
}