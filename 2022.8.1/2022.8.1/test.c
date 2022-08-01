#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>

//int is_yaer(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int arr[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
//	scanf("%d %d", &year, &month);
//	int x = is_yaer(year);
//	if (0 == x)
//	{
//		arr[1] = 29;
//	}
//	else
//	{
//		arr[1] = 28;
//	}
//	for (int i = 0; i < 12; i++)
//	{
//		if (month == i + 1)
//		{
//			printf("%d\n", arr[i]);
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	char input = 0;
//	while ((input = getchar()) != EOF)
//	{
//
//		if ((input <= 'Z' && input >= 'A') || (input <= 'z' && input >= 'a'))
//		{
//			printf("%c is an alphabet.\n", input);
//		}
//		else
//		{
//			printf("%c is not an alphabet.\n", input);
//		}
//		getchar();
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    char input = 0;
//    while (scanf("%c", &input) != EOF)
//    {
//        getchar();
//        if (input <= 'Z' && input >= 'A')
//        {
//            printf("%c\n", input + 32);
//        }
//        else if (input <= 'z' && input >= 'a')
//        {
//            printf("%c\n", input - 32);
//        }
//    }
//    return 0;
//}

#include<stdio.h>

int main()
{
    double price = 0;
    scanf("%lf", &price);
    int month, day;
    scanf("%d %d", &month, &day);
    int card = 0;
    scanf("%d", &card);
    double value = 0;
    if (month == 11 && day == 11)
    {
        if (card == 1)
        {
            value = price * 7 / 10 - 50;
        }
        else
        {
            value = price * 7 / 10;
        }
    }
    else if (month == 12 && day == 12)
    {
        if (card == 1)
        {
            value = price * 8 / 10 - 50;
        }
        else
        {
            value = price * 8 / 10;
        }
    }
    else
    {
        value = price;
    }
    if (value >= 0)
    {
        printf("%.2lf", value);
    }
    else
    {
        value = 0;
        printf("%.2lf", value);
    }
    return 0;
}