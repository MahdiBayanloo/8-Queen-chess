//poroje 8 vazir (mahdi bayanloo).cpp
//Mahdi bayanloo
// Shomare daneshjo: 98442113
//reshte bargh  term yek

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

// tabe (bool check) baraye check kardane makane vazir ha
bool check(int x, int y, int v, int B[][3])//x=satr y=sotsn v=tedad vazir haye ghabl B=makane vazir ha
{
	int A[9][9];
	int i, j, k, sa, so;

	if (x == 1)//aghar satr = 1 shod , araye 0 shavad
	{
		for (i = 1; i <= 8; i++)
		{
			for (j = 1; j <= 8; j++)
			{
				A[i][j] = 0;
			}
		}
		A[x][y] = 1;
		return true;
	}
	A[x][y] = 1;
	for (i = 1; i <= v; i++)// satae v sotsn vazir ha dar sa v so zakhire mishavad
	{
		sa = B[i][1];
		so = B[i][2];

		//if aval baraye check kardane satar ya soton barkhord
		if (x == sa || y == so)
		{
			A[x][y] = 0;
			return false;
		}

		//for dovom baraye check kardane halate zarbdary(bazooie chap) barkhord
		for (j = x - 1, k = y - 1; j > 0 || k > 0; j--, k--)
		{
			if (j == sa && k == so)
			{
				A[x][y] = 0;
				return false;
			}
		}

		//for sevom baraye check kardane halate zarbdary(bazooie raast) barkhord
		for (int j = x - 1, k = y + 1; j > 0 || k <= 8; j--, k++)
		{
			if (j == sa && k == so)
			{
				A[x][y] = 0;
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int B[9][3];
	int s = 0;
	int i, j, a, b, c, d, e, f, g, h, satr;
	for (a = 1; a <= 8; a++)
	{
		satr = 1;
		if (!check(satr, a, satr - 1, B))
			continue;
		else
		{
			B[satr][1] = satr;
			B[satr][2] = a;
		}
		for (b = 1; b <= 8; b++)
		{
			satr = 2;
			if (!check(satr, b, satr - 1, B))
				continue;
			else
			{
				B[satr][1] = satr;
				B[satr][2] = b;
			}
			for (c = 1; c <= 8; c++)
			{
				satr = 3;
				if (!check(satr, c, satr - 1, B))
					continue;
				else
				{
					B[satr][1] = satr;
					B[satr][2] = c;
				}
				for (d = 1; d <= 8; d++)
				{
					satr = 4;
					if (!check(satr, d, satr - 1, B))
						continue;
					else
					{
						B[satr][1] = satr;
						B[satr][2] = d;
					}
					for (e = 1; e <= 8; e++)
					{
						satr = 5;
						if (!check(satr, e, satr - 1, B))
							continue;
						else
						{
							B[satr][1] = satr;
							B[satr][2] = e;
						}
						for (f = 1; f <= 8; f++)
						{
							satr = 6;
							if (!check(satr, f, satr - 1, B))
								continue;
							else
							{
								B[satr][1] = satr;
								B[satr][2] = f;
							}
							for (g = 1; g <= 8; g++)
							{
								satr = 7;
								if (!check(satr, g, satr - 1, B))
									continue;
								else
								{
									B[satr][1] = satr;
									B[satr][2] = g;
								}
								for (h = 1; h <= 8; h++)
								{
									satr = 8;
									if (!check(satr, h, satr - 1, B))
										continue;
									else
									{
										//avalin halat peyda shod ... chap shavad
										B[satr][1] = satr;
										B[satr][2] = h;
										s++;
										cout << s << ": ";
										for (i = 1; i <= 8; i++)
										{
											cout << "(" << B[i][1] << "," << B[i][2] << ")  ";
										}
										cout << endl;

									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "tedad halat haie momken: " << s;
	_getch();
	return 0;
}

