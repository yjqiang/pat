#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

#define N_MAX 10001
char S1[N_MAX];
char S2[N_MAX];

bool should_del[128] = { false };

int main() {
	cin.getline(S1, N_MAX);
	cin.getline(S2, N_MAX);
	int i;
	for (i = 0; S2[i] != '\0'; ++i)
		// ±ê¼ÇÉ¾³ý
		should_del[(int)S2[i]] = true;

	int actual_i;
	for (i = 0, actual_i = 0; S1[i] != '\0'; ++i)
		if (!should_del[(int)S1[i]]) {
			S1[actual_i] = S1[i];
			++actual_i;
		}
	S1[actual_i] = '\0';

	printf("%s", S1);

	system("pause");
	return 0;
}