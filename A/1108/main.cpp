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
#include <unordered_set>

using namespace std;

bool isOk(char* str_num, char* tmp) {
	int i;
	// str_num 精度过高（eg 8位小数），则tmp先到了\0
	// 否则，两者前面相同
	for (i = 0; str_num[i] != '\0'; ++i)
		if (str_num[i] != tmp[i])
			return false;
	return true;
}

int main() {
	int N;
	scanf("%d", &N);

	char str_num[100], tmp[100];

	// num初始化为0，这样即使sscanf没有赋值，也不会炸掉array
	double num = 0;
	double sum_legal_num = 0;
	int count_legal_num = 0;

	int i;
	for (i = 0; i < N; ++i) {
		scanf("%s", str_num);

		sscanf(str_num, "%lf", &num);
		// 保留两位小数输出出来
		sprintf(tmp, "%.2lf", num);

		if (isOk(str_num, tmp) && num <= 1000 && num >= -1000) {
			++count_legal_num;
			sum_legal_num += num;
		}
		else
			printf("ERROR: %s is not a legal number\n", str_num);
	}

	if (count_legal_num > 1)
		printf("The average of %d numbers is %.2lf", count_legal_num, sum_legal_num / count_legal_num);
	else if (count_legal_num == 1)
		printf("The average of 1 number is %.2lf", sum_legal_num);
	else
		printf("The average of 0 numbers is Undefined");
	system("pause");
	return 0;
}