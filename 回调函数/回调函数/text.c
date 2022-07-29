#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define PRINT(S) printf("你选择的是%s\n",S)

int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("***************************\n");
	printf("*****  1.add   2.sub  *****\n");
	printf("*****  3.mul   4.div  *****\n");
	printf("*****      0.exit     *****\n");
	printf("***************************\n");
}

int cul(int (*pf)(int, int),char s[])
{
	int x, y;
	PRINT(s);
	printf("请输入两个数:\n");
	scanf("%d %d", &x, &y);
	return pf(x, y);
}

int main()
{
	int input = 0;
	do
	{
		char s[4] = { '加法','减法','乘法','除法'};
		int math = 0;
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			
			math = cul(add,s[0]);
			printf("math=%d\n", math);
			break;
		case 2:
			math = cul(sub,s[1]);
			printf("math=%d\n", math);
			break;
		case 3:
			math = cul(mul,s[2]);
			printf("math=%d\n", math);
			break;
		case 4:
			math = cul(div,s[3]);
			printf("math=%d\n", math);
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
		}
		
	} while (input);
	return 0;
}