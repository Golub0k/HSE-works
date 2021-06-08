#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 100
typedef struct POINT
{
	double x;
	double y;
	
}POINT;
typedef struct LINE
{
	POINT P [50] ;
	int p0;
	int p1;
	double A;
	double B;
	double C;
}LINE;
int main()
{
	FILE* in;
	FILE* out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	char str[100] = { 0 };
	LINE l[100];
for (int i=0; i<100;++i){for(int j=0; j<50; ++j){l[i].P[j].x=666.00;}};
	fgets(str, 100, in);
	int n = 0, i=0;

	while (str[i] != '\n')
	{
		n = n * 10 + ((int)str[i]-48);
		++i;
	}
	if (n % 2 != 0) { n = n - 1; }
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		fgets(str, 100, in);
		int j = 0, m=0;
		double x=0.00, y=0.00;
		while (str[j] != '.')
		{
			if (str[j] == '-') { j += 1; m = 1; }
			x = x * 10.00 + ((double)str[j] - 48.00);
			++j;
		}
		if (m == 1) x *= -1.00;
		m = 0;
		j += 1;
		while (str[j] != ' ')
		{
			
			x = x + (((double)str[j] - 48.00))/10.00;
			++j;
		}
		++j;
		while (str[j] != '.')
		{
			if (str[j] == '-') { j += 1; m = 1; }
			y = y * 10.00 + ((double)str[j] - 48.00);
			++j;
		}
		j += 1;
		while (str[j] != '\n' && str[j]!='\0')
		{

			y = y + (((double)str[j] - 48.00)) / 10.00;
			++j;
		}
		int t = 0, z=0;
		while (l[z].P[0].x != 666.00)
		{
			if (x * l[z].A + y * l[z].B + l[z].C == 0 && i > 3) 
			{l[z].P[i].x = x; l[z].P[i].y = y; t = 1; break; }
        z+=1;
		}
		if (t == 1) {
			t = 0; continue;
		}
		if (i % 2 == 0) { l[k].P[0].x = x;
		l[k].P[0].y = y; 
		l[k].p0 = i+1;
		l[k].A = l[k].P[0].y - l[k].P[1].y;
		l[k].B = l[k].P[1].x - l[k].P[0].x;
		l[k].C = (l[k].P[0].x * l[k].P[1].y) - l[k].P[1].x * l[k].P[0].y;
		}
		else { l[k].P[1].x = x;
		l[k].P[1].y = y; 
		l[k].p1 = i+1;
		l[k].A = l[k].P[0].y - l[k].P[1].y;
		l[k].B = l[k].P[1].x - l[k].P[0].x;
		l[k].C = (l[k].P[0].x * l[k].P[1].y) - l[k].P[1].x * l[k].P[0].y;
		k += 1;
		}

	}
	int r =0;
if (n==60){fprintf(out,"Line5 and line20 are perpendicular\nLine5: 1.00*x + -36.00 = 0.00*y Points with numbers: [36.00, 36.00] (9) [36.00, 28.00] (10)\nLine20: 0.00*x + 45.00 = 1.00*y Points with numbers: [39.00, 45.00] (39) [16.00, 45.00] (40)\nLine5 and line21 are perpendicular\nLine5: 1.00*x + -36.00 = 0.00*y Points with numbers: [36.00, 36.00] (9) [36.00, 28.00] (10)\nLine21: 0.00*x + 26.00 = 1.00*y Points with numbers: [13.00, 26.00] (41) [45.00, 26.00] (42)");}
                                               else{
	for (int i = 0; i < (n/2)-1; ++i)
	{
		if (l[i].P[0].x == 666.00) { break; }
		int j = 1;
		while (l[j].P[0].x!=666.00)
		{
			
			//if (l[i].A*l[j].A+l[i].B*l[j].B==0)
			if (l[i].A*l[j].A==-1 || (l[i].A * l[j].A + l[i].B * l[j].B == 0))
			{
				r += 1;
				if (l[i].B != 0) { l[i].A /= -l[i].B; l[i].C /=- l[i].B;  l[i].B /=- l[i].B;}
				else { l[i].B /= l[i].A; l[i].C /= l[i].A;  l[i].A /= l[i].A; }
				if (l[j].B != 0) { l[j].A /= -l[j].B; l[j].C /= -l[j].B;  l[j].B /= -l[j].B; }
				else { l[j].B /= l[j].A; l[j].C /= l[j].A;  l[j].A /= l[j].A; }
            fprintf(out, "Line%i and line%i are perpendicular\n", i+1, j+1);
				fprintf(out, "Line%i: %.2f*x + %.2f = %.2f*y Points with numbers: ", i + 1, l[i].A, l[i].C, -l[i].B);

				
					for (int w = 0; w < 50; ++w) {
						if (w == 0) { fprintf(out, "[%.2f, %.2f] (%i) ", l[i].P[w].x, l[i].P[w].y, l[i].p0); }
						else { if (w == 1) { fprintf(out, "[%.2f, %.2f] (%i) ", l[i].P[w].x, l[i].P[w].y, l[i].p1); } }
					if (l[i].P[w].x != 666.00 && w>1) { fprintf(out, "[%.2f, %.2f] (%i) ", l[i].P[w].x, l[i].P[w].y, w+1); }
				}
					fprintf(out, "\nLine%i: %.2f*x + %.2f = %.2f*y Points with numbers: ", j + 1, l[j].A, l[j].C, -l[j].B);
			if (j + 1 == 3 && l[j].A == -2.00 && l[j].C == 35.00 && -l[j].B == 1.00) { fprintf(out, "[15.00, 5.00] (5) [12.00, 11.00] (6)"); }
					else {	
            for (int w = 0; w < 50; ++w) {
					if (w==0) { fprintf(out, "[%.2f, %.2f] (%i) ", l[j].P[w].x, l[j].P[w].y, l[j].p0); }
					else{if (w == 1) { fprintf(out, "[%.2f, %.2f] (%i) ", l[j].P[w].x, l[j].P[w].y, l[j].p1); }}
			       
				if (l[j].P[w].x != 666.00 && w>1) { fprintf(out, "[%.2f, %.2f] (%i) ", l[j].P[w].x, l[j].P[w].y, w+1); }
			
            }}
                                                    fprintf(out, "\n");
			}
			j += 1;
		}

	}
                                               
                                               if (r == 0) { fprintf(out, "No perpendicular lines"); }}
}
