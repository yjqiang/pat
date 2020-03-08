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

using namespace std;

#define N_MAX 100000

struct User {
	char Name[9];
	int Age;
	int Net_worth;
};

User users[N_MAX];

int cmp(const void* p0, const void* p1) {
	User* u0 = (User*)p0;
	User* u1 = (User*)p1;
	if (u0->Net_worth != u1->Net_worth)
		return u1->Net_worth - u0->Net_worth;
	if (u0->Age != u1->Age)
		return u0->Age - u1->Age;
	return strcmp(u0->Name, u1->Name);
}

int main() {
	int N, K;
	int M, Amin, Amax;
	
	scanf("%d%d", &N, &K);
	
	int i, h;
	for (i = 0; i < N; ++i)
		scanf("%s %d %d", users[i].Name, &(users[i].Age), &(users[i].Net_worth));

	qsort(users, N, sizeof(User), cmp);

	int count;
	bool none;
	for (i = 1; i <= K; ++i) {
		scanf("%d %d %d", &M, &Amin, &Amax);
		printf("Case #%d:\n", i);
		for (h = 0, count = 0, none = true; h < N; ++h)
			if (users[h].Age <= Amax && users[h].Age >= Amin) {
				printf("%s %d %d\n", users[h].Name, users[h].Age, users[h].Net_worth);
				none = false;
				++count;
				if (count == M)
					break;
			}
		if (none)
			printf("None\n");

	}

	system("pause");
	return 0;
}