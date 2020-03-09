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

using namespace std;


int main() {
	int A_Galleon, A_Sickle, A_Knut;
	int B_Galleon, B_Sickle, B_Knut;
	int result_Galleon, result_Sickle, result_Knut;

	scanf("%d.%d.%d", &A_Galleon, &A_Sickle, &A_Knut);
	scanf("%d.%d.%d", &B_Galleon, &B_Sickle, &B_Knut);

	int sum;
	sum = A_Knut + B_Knut;
	result_Knut = sum % 29;
	sum /= 29;

	sum += A_Sickle + B_Sickle;
	result_Sickle = sum % 17;
	sum /= 17;

	sum += A_Galleon + B_Galleon;
	result_Galleon = sum;

	printf("%d.%d.%d", result_Galleon, result_Sickle, result_Knut);

	system("pause");
	return 0;
}