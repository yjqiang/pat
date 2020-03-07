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


int main() {
	int N;
	scanf("%d", &N);
	// m=1 10 100  个位十位百位
	int m = 1;
	// 当前位的左侧，当前位，右侧
	int left, mid, right;
	int sum = 0;
	for (m = 1; N / m >= 1; m *= 10) {
		left = N / (m * 10);
		mid = N / m % 10;
		right = N % m;

		if (mid == 1)
			// (0-(left-1))1(0-999..99) 这样的数字 left * m个；(left)1(0-right) 一共right + 1个
			sum += left * m + (right + 1);
		else if (mid == 0)
			// (0-(left-1))1(0-999..99) 这样的数字 left * m个
			sum += left * m;
		else
			// (0-left)1(0-999..99) 这样的数字 (left+1) * m个
			sum += (left + 1) * m;
	
	}
	printf("%d", sum);

	

	system("pause");
	return 0;
}