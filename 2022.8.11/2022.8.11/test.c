#define _CRT_SECURE_NO_WARNINGS 1 
//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
//                {
//                    printf("* ");
//                }
//                else
//                {
//                    printf("  ");
//                }
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[51];
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }
    int x = 0;
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            int count = n;
            while (count > i)
            {
                arr[count] = arr[count - 1];
                count--;
            }
            arr[i] = x;
            break;
        }
        else
        {
            arr[n] = x;
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}