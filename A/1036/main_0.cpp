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

using namespace std;


int main() {
	char name[11], ID[11];
	char gender;
	int grade;

	char name0[11], ID0[11];
	int grade0;

	char name1[11], ID1[11];
	int grade1;

	grade0 = INT_MIN;
	grade1 = INT_MAX;

	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i) {
		scanf("%s %c %s %d", name, &gender, ID, &grade);
		if (gender == 'F' && grade > grade0) {
			strcpy(name0, name);
			strcpy(ID0, ID);
			grade0 = grade;
		}
		if (gender == 'M' && grade < grade1) {
			strcpy(name1, name);
			strcpy(ID1, ID);
			grade1 = grade;
		}
	}
	if (grade0 != INT_MIN)
		printf("%s %s\n", name0, ID0);
	else
		printf("Absent\n");

	if (grade1 != INT_MAX)
		printf("%s %s\n", name1, ID1);
	else
		printf("Absent\n");

	if (grade0 != INT_MIN && grade1 != INT_MAX)
		printf("%d", grade0 - grade1);
	else
		printf("NA");

	system("pause");
	return 0;
}