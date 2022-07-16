#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
//#define MAX(x,y) (x)>(y)?(x):(y)
//
//int main()
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	int max = MAX(x, y);
//	printf("%d", max);
//	return 0;
//}
//int main()
//{
//    int a = 40;
//    int c = 212;
//    int value = (-8 + 22) * a - 10 + c / 2;
//    printf("%d", value);
//    return 0;
//}
//int main()
//{
//    int IQ = 0;
//    scanf("%d", &IQ);
//    if (IQ > 140 || IQ == 140)
//    {
//        printf("Genius");
//    }
//
//    return 0;
//}
//struct stu
//{
//    char name[100];
//    int age;
//    char sex[100];
//};
//int main()
//{
//    struct stu s = { "Jack",18,"man" };
//    printf("Name    Age    Gender\n");
//    printf("---------------------\n");
//    printf("%s    %d     %s\n", s.name, s.age, s.sex);
//    return 0;
//}
int main()
{
    int M;
    scanf("%d", &M);
    if (M % 5 == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
	return 0;
}