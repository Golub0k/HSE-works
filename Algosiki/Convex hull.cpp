#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<math.h>
#include <vector>
using namespace std;

struct tochka
{
	int x;
	int y;
};

double rasstoianie(tochka a1, tochka a2, tochka A)
{
double result = (double)fabs(((a2.x - a1.x) * (A.y - a1.y) - (a2.y - a1.y) * (A.x - a1.x)) / (sqrt((a2.x - a1.x) * (a2.x - a1.x) + (a2.y - a1.y) * (a2.y - a1.y))));
return result;
}

int polozhenie(tochka a1, tochka a2, tochka A)
{
	int result = (a2.x - a1.x) * (A.y - a1.y) - (A.x - a1.x) * (a2.y - a1.y);
	if (result > 0) return 1;
	if (result == 0) return 0;
	if (result < 0) return -1;
}

void prisutstvie(vector <tochka>& tochki, vector <tochka>& res, tochka a1, tochka a2)
{
	tochka max_t;
	if (tochki.size() < 1)
		return;
	double rasst = 0;
	for (int i = 0; i < tochki.size(); i++)
	{
		if (tochki[i].x == a1.x && tochki[i].y == a1.y || tochki[i].x == a2.x && tochki[i].y == a2.y)
			continue;
		if (rasstoianie(a1, a2, tochki[i]) > rasst)
		{
			rasst = rasstoianie(a1, a2, tochki[i]);
			max_t = tochki[i];
		}

	}

	if (rasst > 0)
		res.push_back(max_t);

	vector <tochka> Up, Down;
	for (int i = 0; i < tochki.size(); i++)
	{
		if (tochki[i].x == max_t.x && tochki[i].y == max_t.y || tochki[i].x == a1.x && tochki[i].y == a1.y)
			continue;
		if (polozhenie(a1, max_t, tochki[i]) > 0)
			Up.push_back(tochki[i]);
		if (polozhenie(max_t, a2, tochki[i]) > 0)
			Down.push_back(tochki[i]);
		if (polozhenie(a1, max_t, tochki[i]) == 0 && tochki[i].x == 0)
			res.push_back(tochki[i]);
	}

	prisutstvie(Up, res, a1, max_t);
	prisutstvie(Down, res, max_t, a2);

}

bool for_sort2(const tochka& a1, tochka& a2)
{
	return a1.x > a2.x;
}

void Obolochka(vector <tochka>& vse_tochki, vector <tochka>& res)
{

	sort(vse_tochki.begin(), vse_tochki.end(), for_sort2);

	int min = vse_tochki[0].x, max = vse_tochki[0].x, min_i = 0, max_i = 0;
	for (int i = 1; i < vse_tochki.size(); i++)
	{
		if (vse_tochki[i].x < min)
		{
			min = vse_tochki[i].x;
			min_i = i;
		}
		if (vse_tochki[i].x > max)
		{
			max = vse_tochki[i].x;
			max_i = i;
		}
	}

	for (int i = 0; i < vse_tochki.size(); i++)
	{
		if (i == min_i || i == max_i)
		continue;
		if (vse_tochki[i].y < vse_tochki[min_i].y && vse_tochki[i].x == min) { min_i = i; }
		if (vse_tochki[i].x == max && vse_tochki[i].y > vse_tochki[max_i].y) { max_i = i; }
	}

	vector <tochka> s1, s2;
	for (int i = 0; i < vse_tochki.size(); i++)
	{
		if (i == min_i || i == max_i)
			continue;
		if (polozhenie(vse_tochki[min_i], vse_tochki[max_i], vse_tochki[i]) > 0)
			s1.push_back(vse_tochki[i]);
		else
			s2.push_back(vse_tochki[i]);
	}

	res.push_back(vse_tochki[min_i]);
	res.push_back(vse_tochki[max_i]);

	prisutstvie(s1, res, vse_tochki[min_i], vse_tochki[max_i]);
	prisutstvie(s2, res, vse_tochki[max_i], vse_tochki[min_i]);

}
bool for_sort(const tochka& a1, tochka& a2)
{
	return a1.x > a2.x;
}
bool for_sort_po_y(const tochka& a1, tochka& a2)
{
	return a1.y > a2.y;
}

int main()
{
	vector <tochka> vse_tochki;
	char str[] = "input.txt";
	FILE* in = fopen(str, "rt");
	while (!feof(in))
	{
		tochka Z;
		int n = fscanf(in, "%d %d", &(Z.x), &(Z.y));
		if (n < 2)
			break;
		vse_tochki.push_back(Z);
	}
	vector <tochka> result;

	Obolochka(vse_tochki, result);

	sort(result.begin(), result.end(), for_sort_po_y);
	sort(result.begin(), result.end(), for_sort);
	std:: cout << "Convex Hull is:\n";
	for (int i = result.size()-1; i >=0; --i)
	{
		std::cout << result[i].x << " " << result[i].y << endl;
	}
}
