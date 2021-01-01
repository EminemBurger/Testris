#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

int brr[7][4][4][4] = {
	{
		0,0,0,0,
		0,1,1,0,
	0,0,1,0,
	0,0,1,0,


	0, 0, 0, 0,
	0, 0, 1, 0,
	1, 1, 1, 0,
	0, 0, 0, 0,

	0, 1, 0, 0,
	0, 1, 0, 0,
	0, 1, 1, 0,
	0, 0, 0, 0,

	0,0,0,0,
	0,1,1,1,
	0,1,0,0,
	0,0,0,0
	},

	{
		0,0,0,0,
		1,1,1,1,
	0,0,0,0,
	0,0,0,0,

	0,0,1,0,
	0,0,1,0,
	0,0,1,0,
	0,0,1,0,

	0,0,0,0,
	1,1,1,1,
	0,0,0,0,
	0,0,0,0,

	0,0,1,0,
	0,0,1,0,
	0,0,1,0,
	0,0,1,0

	},

	{
		0,0,0,0,
		0,1,1,0,
	0,1,0,0,
	0,1,0,0,

	0,0,0,0,
	1,1,1,0,
	0,0,1,0,
	0,0,0,0,

	0,0,1,0,
	0,0,1,0,
	0,1,1,0,
	0,0,0,0,

	0,0,0,0,
	0,1,0,0,
	0,1,1,1,
	0,0,0,0


	},

	{
		0,0,0,0,
		0,1,1,0,
	1,1,0,0,
	0,0,0,0,

	0,0,0,0,
	0,1,0,0,
	0,1,1,0,
	0,0,1,0,

	0,0,0,0,
	0,1,1,0,
	1,1,0,0,
	0,0,0,0,

	0,0,0,0,
	0,1,0,0,
	0,1,1,0,
	0,0,1,0


	},

	{
		0,0,0,0,
		0,0,1,0,
	0,1,1,0,
	0,1,0,0,

	0,0,0,0,
	1,1,0,0,
	0,1,1,0,
	0,0,0,0,

	0,0,0,0,
	0,0,1,0,
	0,1,1,0,
	0,1,0,0,

	0,0,0,0,
	1,1,0,0,
	0,1,1,0,
	0,0,0,0


	},
	{
		0,0,0,0,
		0,0,1,0,
	0,1,1,1,
	0,0,0,0,

	0,0,0,0,
	0,0,1,0,
	0,0,1,1,
	0,0,1,0,

	0,0,0,0,
	0,0,0,0,
	0,1,1,1,
	0,0,1,0,

	0,0,0,0,
	0,0,1,0,
	0,1,1,0,
	0,0,1,0


	},

	{
		0,0,0,0,
		0,1,1,0,
	0,1,1,0,
	0,0,0,0,

	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0,

	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0,

	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0


	},

};

int Trr[22][12] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1 }
};

#define GameSetX 26
#define GameSetY 2


#define CenterX 28
#define CenterY -1

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서숨기는 함수에 사용되는 열거형 

void setcursortype(CURSOR_TYPE c) { //커서숨기는 함수 

	CONSOLE_CURSOR_INFO CurInfo;



	switch (c) {

	case NOCURSOR:

		CurInfo.dwSize = 1;

		CurInfo.bVisible = FALSE;

		break;

	case SOLIDCURSOR:

		CurInfo.dwSize = 100;

		CurInfo.bVisible = TRUE;

		break;

	case NORMALCURSOR:

		CurInfo.dwSize = 20;

		CurInfo.bVisible = TRUE;

		break;

	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

COORD getXY()
{
	COORD Cur;
	CONSOLE_SCREEN_BUFFER_INFO a;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
	Cur.X = a.dwCursorPosition.X;
	Cur.Y = a.dwCursorPosition.Y;
	return Cur;
}


/*
{
key = getch();
if (key == 224 || key == 0)
{
key = _getch();
switch (key)
{
case 72:
return 1;
//printf("↑\n");
break;
case 75:
return 2;
//printf("←\n");
break;
case 77:
return 3;
//printf("→\n");
break;
case 80:
return 4;
//printf("↓\n");
break;
default:
break;
}
}
else
{
if (key == 13)
return 5;
//printf("Enter\n");
else if (key == 32)
return 6;
//printf("Space\n");
else if (key == 27)
return 7;
//printf("ESC\n");


*/

int RandomBlock()
{

}

void PrintGame(int m, int x)
{
	gotoxy(m, x);
	int a = m;
	int i, j;

	for (i = 0; i < 22; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (Trr[i][j] == 1)
				printf("▥");

			else if (Trr[i][j] == 2)
				printf("■");


			else if (Trr[i][j] == 3)
				printf("□");
			else
			{
				printf("  ");
			}
		}
		m = a;
		gotoxy(m, ++x);
	}
}

int CheckCollision(int arr[][4][4][4], int m, int x, int p, int o)
{
	int a = m;
	int b = x;
	int i, j;

	if (x < 1)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1)
				{
					if (Trr[x + 1][m] == 3)
					{
							return 5;
					}

					else
						m++;
				}
				else
					m++;
			}
			m = a;
			x++;
		}
		m = a;
		x = b;
		
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1)
				{
					 if (Trr[x][m - 1] == 3 || Trr[x][m - 1] == 1)
						return 6;

					else if (Trr[x][m + 1] == 3 || Trr[x][m + 1] == 1)
						return 7;


					else
						m++;
				}
				else
					m++;
			}
			m = a;
			x++;
		}

		return 4;
	}

	else
	{
		m = a;
		x = b;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1)
				{
					if (Trr[x + 1][m] == 3 || Trr[x + 1][m] == 1)
					{
						return 2;
					}
					else
						m++;
				}
				else
					m++;
			}
			m = a;
			x++;
		}

		m = a;
		x = b;

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1)
				{
					if (Trr[x][m - 1] == 3 || Trr[x][m - 1] == 1)
						return 1;

					else if (Trr[x][m + 1] == 3 || Trr[x][m + 1] == 1)
						return 3;
					else
						m++;
				}
				else
					m++;
			}
			m = a;
			x++;
		}


	}

	return 0;
}


int CheckCollision2(int arr[][4][4][4], int m, int x, int p, int o)
{

	int a = m;
	int b = x;
	int i, j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (arr[p][o][i][j] == 1)
			{
				if (Trr[x][m] == 3 || Trr[x][m] == 1)
				{
					return 1;
				}
				else
					m++;
			}
			else
				m++;
		}
		m = a;
		x++;
	}
	return 0;
}


void CreateBlock(int arr[][4][4][4], int m, int x, int mode, int p, int o)
{
	int a = m;
	int b = x;
	int i, j;

	if (mode == 0 || mode == 1 || mode == 3)
	{

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1)
				{


					Trr[x][m++] = 2;

				}
				else
					m++;
			}
			m = a;
			x++;
		}
	}




	else if (mode == 2)
	{
		m = a;
		x = b;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1)
				{
					Trr[x][m++] = 3;
				}
				else
					m++;
			}
			m = a;
			x++;
		}

	}


	else if (mode == 4 || mode == 6 || mode == 7)
	{
		m = a;
		x = b;
		for (i = 0; i< 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1 && x >-2)
				{

					Trr[x][m++] = 2;

				}
				else
					m++;
			}
			m = a;
			x++;
		}
	}

	else
	{
		m = a;
		x = b;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1 && x > -2)
				{
					Trr[x][m++] = 3;
				}
				else
					m++;
			}
			m = a;
			x++;
		}
	}
}

void DeleteBlock(int arr[][4][4][4], int m, int x, int p, int o)
{
	int a = m;
	int b = x;
	int i, j;

	if (x < 0)
	{
		m = a;
		x = b;
		for (i = 0; i< 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1 && x > -2)
				{
					Trr[x][m++] = 0;
				}
				else
					m++;
			}
			m = a;
			x++;

		}
	}
	else
	{
		m = a;
		x = b;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (arr[p][o][i][j] == 1)
					Trr[x][m++] = 0;
				else
					m++;
			}
			m = a;
			x++;
		}
	}


}

void DropBlock(int arr[][4][4][4], int m, int x, int random, int random2)
{
	int key;
	int i;


	clock_t t;




	while (1)
	{
		CreateBlock(brr, m, x, CheckCollision(brr, m, x, random, random2), random, random2);
		PrintGame(26, 2);



		for (i = 0; i < 5; i++)
		{
			t = clock();
			if (kbhit())
			{
				key = getch();
				if (key == 224 || key == 0)
				{
					key = _getch();



					if (key == 75)
					{
						if (CheckCollision(brr, m, x, random, random2) == 1 || CheckCollision(brr, m, x, random, random2) == 6)
						{

							PrintGame(26, 2);
						}

						else if (CheckCollision(brr, m, x, random, random2) == 2 || CheckCollision(brr, m, x, random, random2) == 5)
							return;

						else
						{
							DeleteBlock(brr, m, x, random, random2);
							m--;
							CreateBlock(brr, m, x, CheckCollision(brr, m, x, random, random2), random, random2);
							PrintGame(26, 2);
							Sleep(50);
						}
					}

					else if (key == 77)
					{
						if (CheckCollision(brr, m, x, random, random2) == 3 || CheckCollision(brr, m, x, random, random2) == 7)
						{
							PrintGame(26, 2);
						}

						else if (CheckCollision(brr, m, x, random, random2) == 2 || CheckCollision(brr, m, x, random, random2) == 5)
							return;


						else
						{
							DeleteBlock(brr, m, x, random, random2);
							m++;
							CreateBlock(brr, m, x, CheckCollision(brr, m, x, random, random2), random, random2);
							PrintGame(26, 2);
							Sleep(50);
						}
					}

					else if (key == 80)
					{


						if (CheckCollision(brr, m, x, random, random2) == 2 || CheckCollision(brr, m, x, random, random2) == 5)
							return;


						else
						{
							DeleteBlock(brr, m, x, random, random2);
							x++;
							CreateBlock(brr, m, x, CheckCollision(brr, m, x, random, random2), random, random2);
							PrintGame(26, 2);
							Sleep(50);
						}
					}

					else
					{


						if (CheckCollision(brr, m, x, random, random2) == 2 || CheckCollision(brr, m, x, random, random2) == 5)
							return;

						else
						{


							if (CheckCollision2(brr, m, x, random, (random2 + 1) % 4))
							{

								PrintGame(26, 2);

							}



							else
							{
								DeleteBlock(brr, m, x, random, random2);
								random2 = (random2 + 1) % 4;
								CreateBlock(brr, m, x, CheckCollision(brr, m, x, random, random2), random, random2);
								PrintGame(26, 2);
								Sleep(50);
							}
						}
					}

				}

				else
				{

					if (key == 32)
					{
						DeleteBlock(brr, m, x, random, random2);
						if (x < 0)
						{
							while (CheckCollision(brr, m, x, random, random2) != 5)
							{
								x++;
								if (x > 0)
								{
									while (CheckCollision(brr, m, x, random, random2) != 2)
										x++;
									break;
								}

							}


						}
						else
						{
							while (CheckCollision(brr, m, x, random, random2) != 2)
								x++;
						}
							CreateBlock(brr, m, x, CheckCollision(brr, m, x, random, random2), random, random2);
							PrintGame(26, 2);
					}
				}

			}

			else
			{
				t = clock() - t;
				if (t / CLOCKS_PER_SEC > 5)
					break;
			}
		}
		Sleep(170);

		if (CheckCollision(brr, m, x, random, random2) == 2 || CheckCollision(brr, m, x, random, random2) == 5)
			break;
		else
		{
			DeleteBlock(brr, m, x++, random, random2);
			if (CheckCollision(brr, m, x, random, random2) == 2)
			{
				CreateBlock(brr, m, x, 2, random, random2);
				PrintGame(26, 2);
				break;
			}
			else if (CheckCollision(brr, m, x, random, random2) == 5)
			{
				CreateBlock(brr, m, x, 5, random, random2);
				PrintGame(26, 2);
				break;

			}
		}
	}

}

int CheckEnd()
{
	int i;
	for (i = 1; i < 12; i++)
	{
		if (Trr[1][i] == 3)
			return 1;
	}
	return 0;
}

void DropArray(int v)
{
	int i, j;

	for (i = v; i > 1; i--)
	{
		for (j = 1; j < 11; j++)
		{
			Trr[i][j] = Trr[i - 1][j];
		}
	}

	for (i = 1; i < 11; i++)
		Trr[1][i] = 0;
}

void CheckFull()
{
	int i, j;
	int k = 0;
	for (i = 21; i > 1; i--)
	{
		for (j = 1; j < 11; j++)
		{
			if (Trr[i][j] == 3)
			{
				k++;
			}
		}
		if (k == 10)
		{
			DropArray(i);
			i = 21;
		}
		k = 0;
	}
}





int main()
{
	setcursortype(NOCURSOR); //커서 없앰 

							 /*
							 DropBlock(brr, CenterX - 12, CenterY);
							 DropBlock(brr, CenterX - 8, CenterY);
							 DropBlock(brr, CenterX - 4, CenterY);
							 DropBlock(brr, CenterX - 16, CenterY);
							 */


	int b = 26;
	int g = 2;

	//CreateBlock(brr, CenterX, CenterY);

	srand(time(NULL));

	int random = rand() % 7;
	int random2 = rand() % 4;

	PrintGame(b, g);

	while (CheckEnd() != 1)
	{

		DropBlock(brr, 28, -4, random, random2);
		CheckFull();
		PrintGame(b, g);
		random = rand() % 7;
		random2 = rand() % 4;
	}

	gotoxy(60, 5);
	printf("GAME OVER");





	//CreateBlock(brr, 28, 3, CheckCollision(brr, 28, 3));

	//PrintGame(b, g);



	//gotoxy(10, 2);
	//gotoxy(68, 2);
	//gotoxy(10, 22);
	_getch();

	return 0;

}