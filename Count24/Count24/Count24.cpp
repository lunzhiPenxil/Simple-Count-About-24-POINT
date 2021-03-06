//main.cpp

#include "pch.h"
#include <iostream>
#include <stdio.h>

int count_try(int a, int b, int c, int d);
int try_A44(int a, int b, int c, int d);
void display(int num1, int num2, int a, int b, int c, int d);
void display_1(int num2, int a, int b, int c, int d);

int try_fin[2] = { 0 };

int main()
{
	int i = 0;
	int in_num[4] = { 0 };

	for (; 1;)
	{
		for (i = 0; i < 4; i++)
		{
			scanf_s("%d", &in_num[i]);
		}
		if (try_A44(in_num[0], in_num[1], in_num[2], in_num[3]))
		{
			printf("%d %d\n", try_fin[0], try_fin[1]);
			display(try_fin[0], try_fin[1], in_num[0], in_num[1], in_num[2], in_num[3]);
		}
		else
		{
			printf("%d %d", try_fin[0], try_fin[1]);
		}
	}
}

int count_try(int a, int b, int c, int d)
{
	int try_num = 0;
	int try_out_num = 0;
	for (try_num = 1; try_num <= 7; try_num++)
	{
		switch (try_num)
		{
			case 1:
			{
				try_out_num = (a - b)*(c + d);
				break;
			}
			case 2:
			{
				try_out_num = (a + b) / c * d;
				if (((a + b) % c) != 0)
				{
					try_out_num = 0;
				}
				break;
			}
			case 3:
			{
				try_out_num = (a - b / c) * d;
				if ((b % c) != 0)
				{
					try_out_num = 0;
				}
				break;
			}
			case 4:
			{
				try_out_num = (a + b - c) * d;
				break;
			}
			case 5:
			{
				try_out_num = a * b + c - d;
				break;
			}
			case 6:
			{
				try_out_num = (a - b) * c + d;
				break;
			}
			case 7:
			{
				try_out_num = (a * c) / (c + d);
				if (((a * c) % (c + d)) != 0)
				{
					try_out_num = 0;
				}
				break;
			}
		}
		if (try_out_num == 24)
		{
			return try_num;
		}
	}
	return 0;
}

int try_A44(int a, int b, int c, int d)
{
	int try_num1 = 0, try_num2 = 0;
	for (try_num1 = 1; try_num1 <= 24; try_num1++)
	{
		switch (try_num1)
		{
			case 1:
			{
				try_num2 = count_try(a, b, c, d);
				break;
			}
			case 2:
			{
				try_num2 = count_try(a, b, d, c);
				break;
			}
			case 3:
			{
				try_num2 = count_try(a, c, b, d);
				break;
			}
			case 4:
			{
				try_num2 = count_try(a, c, d, b);
				break;
			}
			case 5:
			{
				try_num2 = count_try(a, d, b, c);
				break;
			}
			case 6:
			{
				try_num2 = count_try(a, d, c, b);
				break;
			}
			case 7:
			{
				try_num2 = count_try(b, a, c, d);
				break;
			}
			case 8:
			{
				try_num2 = count_try(b, a, d, c);
				break;
			}
			case 9:
			{
				try_num2 = count_try(b, c, a, d);
				break;
			}
			case 10:
			{
				try_num2 = count_try(b, c, d, a);
				break;
			}
			case 11:
			{
				try_num2 = count_try(b, d, a, c);
				break;
			}
			case 12:
			{
				try_num2 = count_try(b, d, c, a);
				break;
			}
			case 13:
			{
				try_num2 = count_try(c, a, b, d);
				break;
			}
			case 14:
			{
				try_num2 = count_try(c, a, d, b);
				break;
			}
			case 15:
			{
				try_num2 = count_try(c, b, a, d);
				break;
			}
			case 16:
			{
				try_num2 = count_try(c, b, d, a);
				break;
			}
			case 17:
			{
				try_num2 = count_try(c, d, a, b);
				break;
			}
			case 18:
			{
				try_num2 = count_try(c, d, b, a);
				break;
			}
			case 19:
			{
				try_num2 = count_try(d, a, b, c);
				break;
			}
			case 20:
			{
				try_num2 = count_try(d, a, c, b);
				break;
			}
			case 21:
			{
				try_num2 = count_try(d, b, a, c);
				break;
			}
			case 22:
			{
				try_num2 = count_try(d, b, c, a);
				break;
			}
			case 23:
			{
				try_num2 = count_try(d, c, a, b);
				break;
			}
			case 24:
			{
				try_num2 = count_try(d, c, b, a);
				break;
			}
		}
		if (try_num2 != 0)
		{
			try_fin[0] = try_num1;
			try_fin[1] = try_num2;
			return 1;
		}
	}
	return 0;
	//count_try(a, b, c, d);
	//count_try(a, b, d, c);
	//count_try(a, c, b, d);
	//count_try(a, c, d, b);
	//count_try(a, d, b, c);
	//count_try(a, d, c, b);
	//count_try(b, a, c, d);
	//count_try(b, a, d, c);
	//count_try(b, c, a, d);
	//count_try(b, c, d, a);
	//count_try(b, d, a, c);
	//count_try(b, d, c, a);
	//count_try(c, a, b, d);
	//count_try(c, a, d, b);
	//count_try(c, b, a, d);
	//count_try(c, b, d, a);
	//count_try(c, d, a, b);
	//count_try(c, d, b, a);
	//count_try(d, a, b, c);
	//count_try(d, a, c, b);
	//count_try(d, b, a, c);
	//count_try(d, b, c, a);
	//count_try(d, c, a, b);
	//count_try(d, c, b, a);
}

void display(int num1, int num2, int a, int b, int c, int d)
{
	switch (num1)
	{
		case 1:
		{
			display_1(num2 , a, b, c, d);
				break;
		}
		case 2:
		{
			display_1(num2 , a, b, d, c);
				break;
		}
		case 3:
		{
			display_1(num2 , a, c, b, d);
			break;
		}
		case 4:
		{
			display_1(num2 , a, c, d, b);
			break;
		}
		case 5:
		{
			display_1(num2 , a, d, b, c);
			break;
		}
		case 6:
		{
			display_1(num2 , a, d, c, b);
			break;
		}
		case 7:
		{
			display_1(num2 , b, a, c, d);
			break;
		}
		case 8:
		{
			display_1(num2 , b, a, d, c);
			break;
		}
		case 9:
		{
			display_1(num2 , b, c, a, d);
			break;
		}
		case 10:
		{
			display_1(num2 , b, c, d, a);
			break;
		}
		case 11:
		{
			display_1(num2 , b, d, a, c);
			break;
		}
		case 12:
		{
			display_1(num2 , b, d, c, a);
		break;
		}
		case 13:
		{
			display_1(num2 , c, a, b, d);
			break;
		}
		case 14:
		{
			display_1(num2 , c, a, d, b);
			break;
		}
		case 15:
		{
			display_1(num2 , c, b, a, d);
			break;
		}
		case 16:
		{
			display_1(num2 , c, b, d, a);
			break;
		}
		case 17:
		{
			display_1(num2 , c, d, a, b);
			break;
		}
		case 18:
		{
			display_1(num2 , c, d, b, a);
			break;
		}
		case 19:
		{
			display_1(num2 , d, a, b, c);
			break;
		}
		case 20:
		{
			display_1(num2 , d, a, c, b);
			break;
		}
		case 21:
		{
			display_1(num2 , d, b, a, c);
			break;
		}
		case 22:
		{
			display_1(num2 , d, b, c, a);
			break;
		}
		case 23:
		{
			display_1(num2 , d, c, a, b);
			break;
		}
		case 24:
		{
			display_1(num2 , d, c, b, a);
			break;
		}
	}
}

void display_1(int num2, int a, int b, int c, int d)
{
	switch (num2)
	{
		case 1:
		{
			printf("(%d-%d)*(%d+%d)\n", a, b, c, d);
			break;
		}
		case 2:
		{
			printf("(%d+%d)/%d*%d\n", a, b, c, d);
			break;
		}
		case 3:
		{
			printf("(%d-%d/%d)*%d\n", a, b, c, d);
			break;
		}
		case 4:
		{
			printf("(%d+%d-%d)*%d\n", a, b, c, d);
			break;
		}
		case 5:
		{
			printf("%d*%d+%d-%d\n", a, b, c, d);
			break;
		}
		case 6:
		{
			printf("(%d-%d)*%d+%d\n", a, b, c, d);
			break;
		}
		case 7:
		{
			printf("(%d*%d)/(%d+%d)\n", a, b, c, d);
			break;
		}
	}
}
