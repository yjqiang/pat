#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;


int main() {
	int N;
	int year, month, day, birth;
	int oldest_birth = INT_MAX, youngest_birth = -1;
	char oldest_name[6], youngest_name[6];
	char name[6];

	scanf("%d", &N);

	int i;
	int counts = 0;
	for (i = 0; i < N; ++i) {
		scanf("%s %d/%d/%d", name, &year, &month, &day);
		birth = year * 10000 + month * 100 + day;
		if (birth > 20140906 || birth < 18140906)
			continue;

		++counts;
		if (birth < oldest_birth) {
			oldest_birth = birth;
			strcpy(oldest_name, name);
		}
		if (birth > youngest_birth) {
			youngest_birth = birth;
			strcpy(youngest_name, name);
		}

	}
	if (!counts) {
		printf("%d", counts);
		return 0;
	}
	printf("%d %s %s", counts, oldest_name, youngest_name);


	// system("pause");
	return 0;
}