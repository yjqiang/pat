#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>

using namespace std;


int main() {
	int C1, C2;
	scanf("%d%d", &C1, &C2);

	int result = int((C2 - C1) / 100.0 + 0.5);

	int second = result % 60;
	result /= 60;
	int minute = result % 60;
	result /= 60;
	int hour = result;
	printf("%02d:%02d:%02d", hour, minute, second);

	system("pause");
	return 0;
}