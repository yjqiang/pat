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
	double  R1, P1, R2, P2;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);

	double A = R1 * R2 * cos(P1 + P2);
	double B = R1 * R2 * sin(P1 + P2);
	// sb°É£¬¸øÀÏ×ÓÍÚ¿Ó£¿
	if (fabs(A) < 0.005)
		A = 0;
	if (fabs(B) < 0.005)
		B = 0;

	if (B < 0) {
		printf("%.2lf%.2lfi", A, B);
	}
	else {
		printf("%.2lf+%.2lfi", A, B);
	}
	system("pause");
	return 0;
}