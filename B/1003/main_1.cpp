# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <cstring>

using namespace std;


bool check(char *s){
	char tmp;
	int pos_P=0, pos_T=0, count_T=0, count_P=0;

	int i;
	
	for(i = 0;s[i]!='\0'; ++i){
		tmp = s[i];

		
		if (tmp == 'P'){
			pos_P = i;
			++count_P;
		}
		else if (tmp == 'T'){
			pos_T = i;
			++count_T;
		}
		else if (tmp != 'A')
			return false;
	}

	int len_left = pos_P;                        //(AA) P AAA  T AAAAAA
	int len_mid = pos_T - len_left - 1;          // AA  P(AAA) T AAAAAA
	int len_right = i - 2 - len_left - len_mid;  // AA  P AAA  T(AAAAAA)


	return count_P == 1 && count_T == 1 && len_mid * len_left == len_right && len_mid;
}

int main(){
	int count, i;
	char s[101];
	scanf("%d", &count);
	for (i = 0; i < count; ++i)
	{
		scanf("%s", s);
		if (check((s)))
			printf("YES\n");
		else
			printf("NO\n");
	}
		
		


	system("pause");
	return 0;
}