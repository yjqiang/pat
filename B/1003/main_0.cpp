# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <cstring>

using namespace std;


bool check(char *s){
	int n = strlen(s);
	char tmp;
	int len_left;   //(AA) P AAA  T AAAAAA
	int len_mid;    // AA  P(AAA) T AAAAAA
	int len_right;  // AA  P AAA  T(AAAAAA)
	int i;
	
	for(i = 0; i < n; ++i){
		tmp = s[i];
		if (tmp == 'A')
			continue;
		
		if (tmp == 'P')
			break;
		else
			return false;
	}
	if (i==n)
		return false;
	len_left = i;

	for (i+=1; i < n;++i){
		tmp = s[i];
		if (tmp == 'A')
			continue;

		if (tmp == 'T')
			break;
		else
			return false;
	}
	if (i == n)
		return false;
	len_mid = i - len_left - 1;

	for (i+=1; i < n;++i){
		tmp = s[i];
		if (tmp == 'A')
			continue;
		else
			return false;
	}
	len_right = n - 2 - len_left - len_mid;

	return len_mid * len_left == len_right && len_mid;
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