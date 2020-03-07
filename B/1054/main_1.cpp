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
	char s[100];
	char s_tmp[100];

	int i, k;
	double sum = 0;
	double element;
	int count_verified = 0;
	bool isOk;
	for (i = 0; i < N; ++i) {
		scanf("%s", s);
		
		sscanf(s, "%lf", &element);
		sprintf(s_tmp, "%.2lf", element);
		// printf("%lf", element);
		isOk = true;
		// 若俩人不一样长，s较长时，s_tmp 会先到 \0, break
		for (k = 0; s[k] != '\0'; ++k)
			if (s[k] != s_tmp[k]) {
				isOk = false;
				break;
			}
		if (!isOk || element < -1000 || element > 1000)
			printf("ERROR: %s is not a legal number\n", s);
		else {
			++count_verified;
			sum += element;
		}
	}
	if (count_verified == 0)
		printf("The average of 0 numbers is Undefined");
	else if (count_verified == 1)
		printf("The average of 1 number is %.2lf", sum);
	else
		printf("The average of %d numbers is %.2lf", count_verified, sum / count_verified);

	

	system("pause");
	return 0;
}