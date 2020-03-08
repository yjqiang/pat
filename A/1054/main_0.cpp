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

int main() {
	int N, M;
	
	scanf("%d %d", &N, &M);
	
	int NM = N * M;
	int c, c_element;
	int i;

	c_element = INT_MAX;
	c = 0;

	int element;
	for (i = 0; i < NM; ++i) {
		scanf("%d", &element);
		if (element != c_element) {
			if (c > 0)
				--c;
			else {
				c = 1;
				c_element = element;
			}
		}
		else
			++c;
	}
	printf("%d", c_element);

	system("pause");
	return 0;
}