#include<stdio.h>
int Arr[101][101][101] = {0, };
int main(void)
{
	FILE * fp1 = fopen("coin.inp", "r");
	FILE * fp2 = fopen("coin.out", "w");

	int One, Two, Three;
	int z, y, x, q;
	int Num;

	Arr[0][0][1] = -1;
	Arr[0][1][0] = -1;
	Arr[1][0][0] = -1;

	for (z = 0; z < 102; z++)
	{
		for (y = 0; y < 102; y++)
		{
			for (x = 0; x < 102; x++)
			{
				Arr[z][y][x] = -1;
				if (x >= 3)
				{
					if (Arr[z][y][x - 1] == -1 || Arr[z][y][x - 2] == -1 || Arr[z][y][x - 3] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}
				else if (x >= 2)
				{
					if (Arr[z][y][x - 1] == -1 || Arr[z][y][x - 2] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}

				else if (x >= 1)
				{
					if (Arr[z][y][x - 1] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}

				if (y >= 3)
				{
					if (Arr[z][y - 1][x] == -1 || Arr[z][y - 2][x] == -1 || Arr[z][y - 3][x] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}
				else if (y >= 2)
				{
					if (Arr[z][y - 1][x] == -1 || Arr[z][y - 2][x] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}
				else if (y >= 1)
				{
					if (Arr[z][y - 1][x] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}


				if(z >= 3)
				{
					if (Arr[z - 1][y][x] == -1 || Arr[z - 2][y][x] == -1 || Arr[z - 3][y][x] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}
				else if (z >= 2)
				{
					if (Arr[z - 1][y][x] == -1 || Arr[z - 2][y][x] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}
				else if (z >= 1)
				{
					if (Arr[z - 1][y][x] == -1)
					{
						Arr[z][y][x] = 1;
					}
				}


				Arr[0][0][0] = 0;


			}
		}
	}

	fscanf(fp1, "%d", &Num);
	for (q = 0; q < Num; q++)
	{
		fscanf(fp1, "%d %d %d", &One, &Two, &Three);
		fprintf(fp2, "(%d %d %d) : %d\n", One, Two, Three, Arr[One][Two][Three]);
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}