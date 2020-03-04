#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;


int main() {
	int P_Galleon, P_Sickle, P_Knut;
	int A_Galleon, A_Sickle, A_Knut;
	scanf("%d.%d.%d", &P_Galleon, &P_Sickle, &P_Knut);
	scanf("%d.%d.%d", &A_Galleon, &A_Sickle, &A_Knut);

	bool is_negative;
	int Larger_Galleon, Larger_Sickle, Larger_Knut;
	int Smaller_Galleon, Smaller_Sickle, Smaller_Knut;

	// 小数-大数会出问题
	if (A_Galleon > P_Galleon ||
		A_Galleon == P_Galleon && A_Sickle > P_Sickle ||
		A_Galleon == P_Galleon && A_Sickle == P_Sickle && A_Knut >= P_Knut) {
		Larger_Galleon = A_Galleon;
		Larger_Sickle = A_Sickle;
		Larger_Knut = A_Knut;

		Smaller_Galleon = P_Galleon;
		Smaller_Sickle = P_Sickle;
		Smaller_Knut = P_Knut;

		is_negative = false;
	}
		
	else {
		Larger_Galleon = P_Galleon;
		Larger_Sickle = P_Sickle;
		Larger_Knut = P_Knut;

		Smaller_Galleon = A_Galleon;
		Smaller_Sickle = A_Sickle;
		Smaller_Knut = A_Knut;

		is_negative = true;
	}
		

	int Galleon, Sickle, Knut;
	// 从低位开始，不够就借位
	if (Larger_Knut >= Smaller_Knut) {
		Knut = Larger_Knut - Smaller_Knut;
	}
	else {
		--Larger_Sickle;
		Knut = Larger_Knut + 29 - Smaller_Knut;
	}

	if (Larger_Sickle >= Smaller_Sickle) {
		Sickle = Larger_Sickle - Smaller_Sickle;
	}
	else {
		--Larger_Galleon;
		Sickle = Larger_Sickle + 17 - Smaller_Sickle;
	}
	Galleon = Larger_Galleon - Smaller_Galleon;
	if (is_negative)
		printf("-%d.%d.%d", Galleon, Sickle, Knut);
	else
		printf("%d.%d.%d", Galleon, Sickle, Knut);


	system("pause");
	return 0;
}