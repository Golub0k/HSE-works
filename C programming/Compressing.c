#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100000
int main()
{
	int i = 1;
	int p = 1;
	int d = 1;

	char str[SIZE] = { 0 };
	char s[SIZE] = { 0 };
	fgets(str, SIZE, stdin);
	str[strlen(str) - 1] = '\0';
	s[0] = str[0];
	while (str[i-1] != '\0')
	{
		//if (str[i] ==' ') { s[d] = str[i]; d += 1; }
		if (str[i] == str[i - 1])
		{
			i += 1; p += 1;
		}

		else {
			if (p > 1)
			{

				s[d] = '(';
				d += 1;

				if (p<10){s[d] = p + '0';d+=1;};
				if (p>9 && p<100){int o=p/10;	s[d] = (o% 10) + '0'; d += 1;	s[d] = (p % 10) + '0';	d += 1;};
				if (p>99 && p<1000){s[d] = ((p/100)% 10) + '0'; d += 1;
				s[d] = ((p/10)% 10) + '0'; d += 1;	s[d] = (p % 10) + '0';	d += 1;};
				s[d] = ')'; d +=1; p = 1;

			}

			s[d] = str[i]; d += 1; i += 1;
		}


	}

	printf("%s", s);
	if (p == strlen(str)) { printf("(%d)", p); }
}
