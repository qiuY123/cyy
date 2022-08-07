#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<string.h>

void reverse(char* p, int len)
{
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        char temp = *(p + left);
        *(p + left) = *(p + right);
        *(p + right) = temp;
        //*(p + len) = '\0';
        left++;
        right--;
    }
}
int main()
{
    char arr[100];
    char* p = arr;
    gets(arr);
    int len = strlen(arr);
    reverse(p, len);
    //printf("%s\n", arr);
    while (*p)
    {
        char* temp = p;
        int count = 0;
        while (*temp != ' '&& *temp != '\0')
        {
            count++;
            temp++;    
        }
        reverse(p, count);
        if (*temp == ' ')
            p = temp + 1;
        else
            p = temp;
    } 
    printf("%s", arr);
    return 0;
}