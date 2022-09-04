#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[2000] = { 0 };
    int sum = 0;
    double average = 0;
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > 0)
        {
            count1++;
            sum += arr[i];
        }
    }
    if (count1)
        average = sum * 1.0 / count1;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            count2++;
    }
    printf("%d %.1lf", count2, average);
    return 0;
}

int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) 
{
    // write code here
    int min = rotateArray[0];
    for (int i = 0; i < rotateArrayLen; i++)
    {
        min = min < rotateArray[i] ? min : rotateArray[i];
    }
    return min;
}