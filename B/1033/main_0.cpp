#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

#define N_MAX 100001
char broken[N_MAX];
char normal[N_MAX];
set<char> dict;

int main() {
	cin.getline(broken, N_MAX - 1);
	cin.getline(normal, N_MAX - 1);
	int i;
	char char_tmp;
	bool is_capitalizes = false;  // '+'
	for (i = 0; broken[i] != '\0'; ++i) {
		char_tmp = broken[i];
		if (char_tmp <= 'Z' && char_tmp >= 'A')
			char_tmp = char_tmp - 'A' + 'a';

		if (char_tmp != '+')
			dict.insert(char_tmp);
		else
			is_capitalizes = true;
	}

	
	if (is_capitalizes) {
		for (i = 0; normal[i] != '\0'; ++i) {
			char_tmp = normal[i];
			if (char_tmp <= 'Z' && char_tmp >= 'A')
				continue;
			if (dict.find(char_tmp) == dict.end())
				printf("%c", normal[i]);
		}
	}
	else {
		for (i = 0; normal[i] != '\0'; ++i) {
			char_tmp = normal[i];
			if (char_tmp <= 'Z' && char_tmp >= 'A')
				char_tmp = char_tmp - 'A' + 'a';
			if (dict.find(char_tmp) == dict.end())
				printf("%c", normal[i]);
		}
	}
	


	system("pause");
	return 0;
}