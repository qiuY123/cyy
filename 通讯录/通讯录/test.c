#define _CRT_SECURE_NO_WARNINGS 1 
#include"contact.h"

void menu()
{
	printf("**************************\n");
	printf("******1.����  2.�h��******\n");
	printf("******3.��ԃ  4.�޸�******\n");
	printf("********* 5.��ӡ *********\n");
	printf("********* 0.�˳� *********\n");
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
		printf("�����룺\n");
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
				printf("ѡ�����������ѡ��\n");
				break;
		}

	} while (input);

	return 0;
}