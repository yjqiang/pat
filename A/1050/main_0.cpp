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

#define N_MAX 100001

// count_S2[c] : if the char "c" appears in S2
bool count_S2[N_MAX] = { false };

char S1[N_MAX], S2[N_MAX];

int main() {
	cin.getline(S1, N_MAX);
	cin.getline(S2, N_MAX);

	int i;
	for (i = 0; S2[i] != '\0'; ++i)
		count_S2[(int)S2[i]] = true;

	for (i = 0; S1[i] != '\0'; ++i)
		if (!count_S2[(int)S1[i]])
			printf("%c", S1[i]);

	system("pause");
	return 0;
}