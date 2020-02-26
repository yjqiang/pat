# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>

using namespace std;


int exist[1000000] = { 0 };
int grades[2000][4] = { 0 };
int num_grades[4][101] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	
	int StudentID;

	char types[] = "ACME";
	int N, M;
	
	int grade_C, grade_M, grade_E, grade_A;

	scanf("%d%d", &N, &M);

	int i, k;
	for (i = 0; i < N; ++i) {
		scanf("%d%d%d%d", &StudentID, &grade_C, &grade_M, &grade_E);
		grade_A = (grade_C + grade_M + grade_E) / 3;

		exist[StudentID] = i + 1;
		grades[i][0] = grade_A;
		grades[i][1] = grade_C;
		grades[i][2] = grade_M;
		grades[i][3] = grade_E;

		++num_grades[0][grade_A];
		++num_grades[1][grade_C];
		++num_grades[2][grade_M];
		++num_grades[3][grade_E];
	}

	for (i = 99; i >0; --i) {
		num_grades[0][i] += num_grades[0][i + 1];
		num_grades[1][i] += num_grades[1][i + 1];
		num_grades[2][i] += num_grades[2][i + 1];
		num_grades[3][i] += num_grades[3][i + 1];
	}


	int rank;
	int index;
	int best_element, best_index;
	int grade;

	for (i = 0; i < M; ++i) {
		scanf("%d", &StudentID);

		index = exist[StudentID] - 1;

		if (index == -1) {
			printf("N/A\n");
		}
		else {
			best_element = INT_MAX;
			
			for (k = 0; k < 4; ++k) {
				grade = grades[index][k];  // get score of a student
				rank = (grade == 100) ? 1 : (num_grades[k][grade + 1] + 1);
				if (rank < best_element) {
					best_element = rank;
					best_index = k;
				}
			}
			printf("%d %c\n", best_element, types[best_index]);
		}
		
	}

	system("pause");
	return 0;
}