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
#include <algorithm>

using namespace std;

#define N_MAX 1001
char s[N_MAX];
int counts[128] = { 0 };

int main() {
	cin.getline(s, 1000);

	int i;
	char c;
	for (i = 0; s[i] != '\0'; ++i) {
		c = s[i];
		if (c <= 'Z' && c >= 'A') {
			c = c - 'A' + 'a';
			++counts[(int)c];
		}
		else if (c <= 'z' && c>= 'a')
			++counts[(int)c];
	}
	
	int max_element, max_index;
	max_element = -1;
	for (i =0; i < 128; ++i)
		if (counts[i] > max_element) {
			max_element = counts[i];
			max_index = i;
		}

	char result = (char)max_index;
	
	printf("%c %d", result, max_element);

	system("pause");
	return 0;
}