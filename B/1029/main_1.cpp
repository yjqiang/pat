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
	char normal[81], damaged[81];

	scanf("%s%s", normal, damaged);

	bool all[128] = { false };
	int i;
	char char_tmp;
	for (i = 0; damaged[i] != '\0'; ++i) {
		char_tmp = damaged[i];
		if (char_tmp >= 'a' && char_tmp <= 'z')
			char_tmp = char_tmp - 'a' + 'A';
		all[(int)char_tmp] = true;
	}

	for (i = 0; normal[i] != '\0'; ++i) {
		char_tmp = normal[i];
		if (char_tmp >= 'a' && char_tmp <= 'z')
			char_tmp = char_tmp - 'a' + 'A';

		if (!all[(int)char_tmp]) {
			printf("%c", char_tmp);
			all[(int)char_tmp] = true;
		}
	}


	system("pause");
	return 0;
}