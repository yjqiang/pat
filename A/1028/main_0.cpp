#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

struct Student {
	int ID;
	char name[9];
	int grade;
};

Student students[100000];

int cmp1(const void* p0, const void* p1) {
	Student* student0 = (Student*)p0;
	Student* student1 = (Student*)p1;
	return student0->ID - student1->ID;
}

int cmp2(const void* p0, const void* p1) {
	Student* student0 = (Student*)p0;
	Student* student1 = (Student*)p1;
	int result = strcmp(student0->name, student1->name);
	if(result)
		return result;
	return student0->ID - student1->ID;
}

int cmp3(const void* p0, const void* p1) {
	Student* student0 = (Student*)p0;
	Student* student1 = (Student*)p1;
	int result = student0->grade - student1->grade;
	if (result)
		return result;
	return student0->ID - student1->ID;
}

int main() {
	int N, C;
	scanf("%d%d", &N, &C);
	
	int i;
	for (i = 0; i < N; ++i)
		scanf("%d%s%d", &(students[i].ID), &(students[i].name), &(students[i].grade));

	switch (C) {
		case 1: qsort(students, N, sizeof(Student), cmp1); break;
		case 2: qsort(students, N, sizeof(Student), cmp2); break;
		case 3: qsort(students, N, sizeof(Student), cmp3); break;
	}

	for (i = 0; i < N; ++i)
		printf("%06d %s %d\n", students[i].ID, students[i].name, students[i].grade);

	system("pause");
	return 0;
}