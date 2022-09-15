#define _CRT_SECURE_NO_WARNINGS 1 
#include"contact.h"

void menu()
{
	printf("**************************\n");
	printf("******1.增加  2.刪除******\n");
	printf("******3.查詢  4.修改******\n");
	printf("********* 5.打印 *********\n");
	printf("********* 0.退出 *********\n");
	printf("**************************\n");
}

int main()
{
	contact con;
	Initcontact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请输入：\n");
		scanf("%d", &input);
		switch (input)
		{
			case 0:
				contactDestory(&con);
				break;
			case 1:
				Addcontact(&con);
				break;
			case 2:
				Deletecontact(&con);
				break;
			case 3:
				Checkcontact(&con);
				break;
			case 4:
				Amendcontact(&con);
				break;
			case 5:
				Printcontact(&con);
				break;
			default:
				printf("选择错误，请重新选择：\n");
				break;
		}

	} while (input);

	return 0;
}