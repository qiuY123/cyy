#define _CRT_SECURE_NO_WARNINGS 1 

//#include<stdio.h>
//
//int main()
//{
//    int n, m;
//    int val;
//    scanf("%d %d", &n, &m);
//    int arr[2000] = { 0 };
//    int arr1[1000] = { 0 };
//    int arr2[1000] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d ", &val);
//        arr1[i] = val;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d ", &val);
//        arr2[i] = val;
//    }
//    int i = 0;
//    int j = 0;
//    for (int k = 0; k < n + m; k++)
//    {
//        arr[k] = arr1[i] < arr2[j] ? arr1[i] : arr2[j];
//        if (arr[k] == arr1[i])
//        {
//            if (i < n)
//                i++;
//        }
//        else if (arr[k] == arr2[j])
//        {
//            if (j < m)
//                j++;
//        }
//        if (i == n)
//        {
//            int x = j;
//            while (x < m)
//            {
//                arr[n + x] = arr2[x];
//                x++;
//            }
//        }
//        else if (j == m)
//        {
//            int y = i;
//            while (y < n)
//            {
//                arr[m + y] = arr1[y];
//                y++;
//            }
//        }
//    }
//    for (int i = 0; i < m + n; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//
//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int k = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (j == k || j == n - k - 1)
//                    printf("*");
//                else
//                    printf(" ");
//            }
//            printf("\n");
//            k++;
//        }
//    }
//    return 0;
//}

#include<stdio.h>
#include<string.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int k = 1;
        for (int i = 0; i <= n; i++)
        {
            int count = k;
            for (int j = 0; j <= 2 * n - 2 * k + 1; j++)
            {
                printf(" ");
            }
            while (count--)
            {
                printf("*");
            }
            printf("\n");
            k++;
        }
        k = k - 2;
        for (int i = 0; i < n; i++)
        {
            int count = k;
            for (int j = 0; j <= 2 * n - 2 * k + 1; j++)
            {
                printf(" ");
            }
            while (count--)
            {
                printf("*");
            }
            printf("\n");
            k--;
        }
    }
    return 0;
}