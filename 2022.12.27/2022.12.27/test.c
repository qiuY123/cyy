#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

#define a 10
void foo();
int main()
{
	printf("%d..", a);
	foo();
	printf("%d", a);
	return 0;
} 
void foo() 
{
	#undef a
	#define a 50
}


//char* f(char* str, char ch)
//{
//	char* it1 = str;
//	char* it2 = str;
//	while (*it2 != '\0')
//	{
//		while (*it2 == ch)
//		{
//			it2++;
//		} *
//			it1++ = *it2++;
//	} 
//	return str;
//} 
//int main() {
//	char a[10];
//	strcpy(a, "abcdcccd");
//	printf("%s", f(a, 'c'));
//	return 0;
//}

/*int main()
{
	char a = 101;
	int sum = 200;
	a += 27; sum += a;
	printf("%d\n", sum);
	char* p;
	//p = getchar(); 
	//scanf("%s", p); 
	char s[] = "china"; 
	p = s; 
	//*p = "china";
	return 0;
}*/