#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

using namespace std;


int main() {
	int N;
	scanf("%d", &N);

	double result = 0;
	double double_tmp;
	int i;
	for (i = 0; i < N; ++i) {
		scanf("%lf", &double_tmp);
		// 下标为i的元素在所有片段出现次数(i + 1) * (N - i)，i的左侧包含i共有i-0+1种，右侧包含i共有N-1-i+1种，相乘

		//下面这一写法是错的，因为n最大为10的5次方，(i + 1)* (n - i)可能会超出int的存储范围，造成溢出
		//        sum+=(i+1)*(n-i)*double_tmp;
		result += double_tmp * (i + 1) * (N - i);
	}


	
	printf("%.2f", result);

	system("pause");
	return 0;
}