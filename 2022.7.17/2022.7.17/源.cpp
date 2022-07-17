#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
//int main()
//{   
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d %d", a / b, a % b);
//    return 0;
//	return 0;
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int i = 0;
//    do
//    {
//        i++;
//    } while (n / 10);
//
//    return 0;
//}
//int main()
//{
//    int n;
//    int m = 1;
//    scanf("%d", &n);
//    int ret = n;
//    int temp = n;
//    do
//    {
//
//        n = n / m;
//        ret = n;
//        m = 10;
//        ret = ret % 10;
//        printf("%d", ret);
//
//    } while (temp = temp / 10);
//    return 0;
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int a, b, c, d;
//    a = n % 10;
//    b = n / 10 % 10;
//    c = n / 100 % 10;
//    d = n / 1000 % 10;
//    printf("%d%d%d%d", a, b, c, d);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int a, b, c, d, e;
//    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
//    double average = (a + b + c + d + e) * 1.0 / 5;
//    printf("%.1f", average);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF)
//    {
//
//        if (a == b)
//        {
//            printf("%d=%d\n", a, b);
//        }
//        else if (a > b)
//        {
//            printf("%d>%d\n", a, b);
//        }
//        else
//        {
//            printf("%d<%d\n", a, b);
//        }
//    }
//    return 0;
//}
int main()
{
    int seconds = 0;
    scanf("%d", &seconds);
    int h = seconds / 3600;
    int m = seconds % 3600 / 60;
    int s = seconds % 3600 % 60;
    printf("%d %d %d", h, m, s);


    return 0;
}