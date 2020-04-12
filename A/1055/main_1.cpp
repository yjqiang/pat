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

#define N_MAX 100000
#define AGE_MAX 201

struct Person {
	char Name[9];
	int Age;
	int Net_worth;
};


Person people[N_MAX];
// 统计每个年龄段的人
int n_per_age[AGE_MAX] = { 0 };

int cmp(const void* p0, const void* p1) {
	Person* a = (Person*)p0;
	Person* b = (Person*)p1;

	if (a->Net_worth != b->Net_worth)
		return b->Net_worth - a->Net_worth;

	if (a->Age != b->Age)
		return a->Age - b->Age;

	return strcmp(a->Name, b->Name);
}



int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int i;
	
	for (i = 0; i < N; ++i)
		scanf("%s %d %d", people[i].Name, &people[i].Age, &people[i].Net_worth);

	qsort(people, N, sizeof(Person), cmp);

	
	// M最大100，每个年龄段指保留前100人即可
	int h, Age;
	for (i = 0, h = 0; i < N; ++i) {
		Age = people[i].Age;
		if (n_per_age[Age] < 100) {
			strcpy(people[h].Name, people[i].Name);
			people[h].Age = people[i].Age;
			people[h].Net_worth = people[i].Net_worth;

			++h;
			++n_per_age[Age];
		}
	}
	// 更新N
	N = h;

	int M, Amin, Amax;
	int count;
	for (i = 1; i <= K; ++i) {
		scanf("%d %d %d", &M, &Amin, &Amax);
		printf("Case #%d:\n", i);

		for (count = 0, h = 0; h < N && count < M; ++h) {
			Age = people[h].Age;
			if (Age <= Amax && Age >= Amin) {
				printf("%s %d %d\n", people[h].Name, people[h].Age, people[h].Net_worth);
				++count;
			}

		}
		if (count == 0)
			printf("None\n");
	}
	
	system("pause");
	return 0;
}