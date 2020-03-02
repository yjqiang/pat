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
	set<char> cache;

	scanf("%s%s", normal, damaged);
	int i, k;
	char char_tmp;
	for (i = 0, k = 0; normal[i] != '\0' && damaged[k] != '\0'; ) {
		if (normal[i] != damaged[k]) {
			char_tmp = normal[i];
			char_tmp = char_tmp <= 'z' && char_tmp >= 'a'? char_tmp - 'a' + 'A': char_tmp;
			if (cache.find(char_tmp) == cache.end())
				printf("%c", char_tmp);
			cache.insert(char_tmp);
			++i;
		}
		else {
			++i;
			++k;
		}
	}
	for (; normal[i] != '\0'; ++i) {
		char_tmp = normal[i];
		char_tmp = char_tmp <= 'z' && char_tmp >= 'a' ? char_tmp - 'a' + 'A' : char_tmp;
		if (cache.find(char_tmp) == cache.end())
			printf("%c", char_tmp);
		cache.insert(char_tmp);
	}


	system("pause");
	return 0;
}