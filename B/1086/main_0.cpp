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
#include <set>

using namespace std;


int main() {
	int a, b;
	int result;

	scanf("%d%d", &a, &b);
	result = a * b;

	// a b 均为整数，所以result非0
	int reversed_result = 0;
	while (result) {
		reversed_result = reversed_result * 10 + result % 10;
		result /= 10;
	}
	printf("%d", reversed_result);
	system("pause");
	return 0;
}