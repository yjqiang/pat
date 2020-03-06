#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int grades[1001] = { 0 };

int main() {
	int N;
	scanf("%d", &N);

	int i;
	int group_id, user_id, grade;
	for (i = 0; i < N; ++i) {
		scanf("%d-%d %d", &group_id, &user_id, &grade);
		grades[group_id] += grade;
	}

	int max_element, max_index;
	max_element = -1;
	for (i = 1; i <= 1000; ++i)
		if (grades[i] > max_element) {
			max_element = grades[i];
			max_index = i;
		}
	printf("%d %d", max_index, max_element);

	system("pause");
	return 0;
}