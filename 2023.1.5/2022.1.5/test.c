#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<string.h>
int main() 
{
    char str[1000] = { '\0' };
    while (gets(str)) 
    {
        int len = strlen(str);
        int english = 0, blank = 0, num = 0, other = 0;
        for (int i = len - 1; i >= 0; i--) 
        {
            if ((('a' <= str[i]) && (str[i] <= 'z')) || (('A' <= str[i]) && (str[i] <= 'Z'))) 
                english++;
            else if (str[i] == ' ') 
                blank++; 
            else if (('0' <= str[i]) && (str[i] <= '9')) 
                num++; 
            else 
                other++; 
        }
        printf("%d\n%d\n%d\n%d\n", english, blank, num, other);
    }
}