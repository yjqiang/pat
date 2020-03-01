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
	char c;

	scanf("%d %c", &N, &c);
	int counts = 1;
	int max_len = 1;
	while (counts <= N) {
		max_len += 2;
		counts += 2 * max_len;
	}

	counts -= 2 * max_len;
	max_len -= 2;

	
	int h;
	int blank_counts, asterisk_count;
	for (asterisk_count = max_len; asterisk_count >= 1; asterisk_count -= 2) {
		blank_counts = (max_len - asterisk_count) / 2;
		for (h = 0; h < blank_counts; ++h)
			printf(" ");
		for (h = 0; h < asterisk_count; ++h)
			printf("%c", c);
		printf("\n");
	}
	for (asterisk_count = 3; asterisk_count <= max_len; asterisk_count += 2) {
		blank_counts = (max_len - asterisk_count) / 2;
		for (h = 0; h < blank_counts; ++h)
			printf(" ");
		for (h = 0; h < asterisk_count; ++h)
			printf("%c", c);
		printf("\n");
	}
	printf("%d", N - counts);

	system("pause");
	return 0;
}