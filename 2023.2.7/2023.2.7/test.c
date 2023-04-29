#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

int Is_LeapYear(int year)
{
    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int year = 0;
    scanf("%d ", &year);
    int x = Is_LeapYear(year);
    int month = 0;
    int day = 0;
    scanf("%d %d", &month, &day);
    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (x)
    {
        arr[2] = 29;
    }
    int sum = 0;
    for (int i = 0; i < month; i++)
    {
        sum += arr[i];
    }
    sum += day;
    printf("%d", sum);
    return 0;
}

#include <stdio.h>

int Is_LeapYear(int year)
{
    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int GetMonthDay(int year, int month)
{
    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && Is_LeapYear(year))
    {
        ++arr[2];
    }
    return arr[month];
}

int GetYearDay(int year)
{
    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    {
        return 366;
    }
    return 365;
}

int GetReDay(int year, int month, int day)
{
    int sum = 0;
    int x = GetYearDay(year);
    for (int i = 1; i < month; i++)
    {
        sum += GetMonthDay(year, i);
    }
    sum += day;
    return x - sum;
}

int Getday(int year, int month, int day)
{
    int sum = 0;
    for (int i = 1; i < month; i++)
    {
        sum += GetMonthDay(year, i);
    }
    sum += day;
    return sum;
}

int main()
{
    int year1 = 0, year2 = 0;
    int month1 = 0, month2 = 0;
    int day1 = 0, day2 = 0;
    int dec = 0;
    while (scanf("%d %d %d %d %d %d", &year1, &month1, &day1, &year2, &month2, &day2) != EOF)
    {
        if (year1 == year2 && month1 == month2)
        {
            dec = day2 - day1;
        }
        else if (year1 == year2 && month1 != month2)
        {
            int temp = GetMonthDay(year1, month1) - day1;
            dec = temp + day2;
            for (int i = month1 + 1; i < month2; i++)
            {
                dec += GetMonthDay(year1, i);
            }
        }
        else
        {
            int re = GetReDay(year1, month1, day1);
            for (int i = year1 + 1; i < year2; i++)
            {
                re += GetYearDay(i);
            }
            re += Getday(year2, month2, day2);
            dec = re;
        }
        printf("%d", dec);
    }
}

