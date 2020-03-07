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

// m 1 10 100来表示个位十位百位等
// 小于等于N的且对应位上为1的最大数字x
// 这里要N/m >= 1（即m对应位不会溢出m的位数）
int findX(int N, int m) {
	// N % (m*10) / m表示对应位
	// // 对应位为1，返回N
	if (N % (m * 10) / m == 1)
		return N;
	// 对应位大于1，则把该位改为1即可，低位置为999...999
	if (N % (m * 10) / m > 1)
		return N / (m * 10) * (m * 10) + 1 * m + (1* m-1);

	// 对应位小于1（为0），则把高位减一即可，低位置为999...999
	// 这里可以保证 N / (m * 10) >= 1
	return (N / (m * 10) - 1) * (m * 10) + (1 * m - 1);

}

int main() {
	int N;
	scanf("%d", &N);

	int m = 1;
	int x;
	int sum = 0;
	for (m = 1; N / m >= 1; m *= 10) {
		x = findX(N, m);
		
		sum += (x / (m * 10)) * m + x % m + 1;
		// printf("m=%d  x=%d sum=%d\n", m, x, sum);
	}
	printf("%d", sum);

	

	system("pause");
	return 0;
}