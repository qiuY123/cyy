#define _CRT_SECURE_NO_WARNINGS 1 
//#include<stdio.h>
//
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	int ret = 0;
//	int sum = 0;
//	sum = x;
//	ret = x;
//	while (ret > 1)
//	{
//		int temp = 0;
//		temp = ret;
//		sum += ret / 2;
//		temp = ret % 2;
//		ret = ret / 2;
//		ret += temp;
//	}
//	printf("%d", sum);
//	
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    for (int i = 10000; i < 100000; i++)
//    {
//        int count = 0;
//        int temp = i;
//        while (temp)
//        {
//            count++;
//            temp /= 10;
//        }
//        int x = 1 * pow(10, count - 1);
//        int sum = 0;
//        while (x)
//        {
//            if (x > 9)
//            {
//                sum = sum + (i / x) * (i % x);
//            }
//            x /= 10;
//        }
//        if (i == sum)
//        {
//            printf("%d\n", i);
//        }
//    }
//    return 0;
//}