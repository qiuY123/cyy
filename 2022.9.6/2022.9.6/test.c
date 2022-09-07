#define _CRT_SECURE_NO_WARNINGS 1 
//#include<stdio.h>
//int main()
//{
//    int a, b, c;
//    while (scanf("%d %d %d", &a, &b, &c) != EOF)
//    {
//        int small = a < b ? a : b;
//        int smallest = small < c ? small : c;
//        int big = a > b ? a : b;
//        int biggest = big > c ? big : c;
//        int mid = (a + b + c) - smallest - biggest;
//        if (smallest + mid > biggest)
//        {
//            if (a == b && b == c)
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (a == b || a == c || b == c)
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//        {
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    char arr[10000];
//    gets(arr);
//    int count = strlen(arr);
//    int x = 0;
//    int y = 0;
//    for (int i = 0; i < count; i++)
//    {
//        if (arr[i] == 'A')
//        {
//            x++;
//        }
//        else if (arr[i] == 'B')
//        {
//            y++;
//        }
//    }
//    if (x > y)
//    {
//        printf("A");
//    }
//    else if (x < y)
//    {
//        printf("B");
//    }
//    else
//    {
//        printf("E");
//    }
//
//    return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    int a, b, c, d, e, f, g;
//    while (scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g) != EOF)
//    {
//        int max = a > b ? a : b;
//        max = max > c ? max : c;
//        max = max > d ? max : d;
//        max = max > e ? max : e;
//        max = max > f ? max : f;
//        max = max > g ? max : g;
//        int min = a < b ? a : b;
//        min = min < c ? min : c;
//        min = min < d ? min : d;
//        min = min < e ? min : e;
//        min = min < f ? min : f;
//        min = min < g ? min : g;
//        double average = (a + b + c + d + e + f + g - max - min) / 5.0;
//        printf("%.2lf\n", average);
//    }


#include<stdio.h>

int main()
{
    int math;
    while (scanf("%d", &math) != EOF)
    {
        if (math == 200)
        {
            printf("OK\n");
        }
        if (math == 202)
        {
            printf("Accepted\n");
        }
        if (math == 400)
        {
            printf("Bad Request\n");
        }
        if (math == 403)
        {
            printf("Forbidden\n");
        }
        if (math == 404)
        {
            printf("Not Found\n");
        }
        if (math == 500)
        {
            printf("Internal Server Error\n");
        }
        if (math == 502)
        {
            printf("Bad Gateway\n");
        }
    }
    return 0;
}