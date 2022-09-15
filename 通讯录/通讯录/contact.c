#define _CRT_SECURE_NO_WARNINGS 1 

#include"contact.h"

void Initcontact(contact* ps)
{
	ps->data = (SL*)malloc(100 * sizeof(SL));
	if (ps->data == NULL)
	{
		perror("Initcontact");
		return;
	}
	ps->sz = 0;
	ps->capacity = 100;
}

void Addcontact(contact* ps)
{
	if (ps->sz == ps->capacity)
	{
		SL* p = (SL*)realloc(ps->data, (ps->capacity * 2) * sizeof(SL));
		if (p != NULL)
		{
			ps->data = p;
			ps->capacity *= 2;
		}
		else
		{
			perror("Addcontact");
			printf("增加联系人失败\n");
			return;
		}
	}
	printf("请输入名字：");
	scanf("%s", ps->data[ps->sz].name);
	printf("请输入年龄：");
	scanf("%d", &ps->data[ps->sz].age);
	printf("请输入学号：");
	scanf("%d", &ps->data[ps->sz].ID);
	printf("请输入性别：");
	scanf("%s", ps->data[ps->sz].sex);
	ps->sz++;
	printf("增加成功\n");
}

void Printcontact(contact* ps)
{
	printf("%-16s %-16s %-16s %-16s\n", "ID", "名字", "年龄", "性别");
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%-16d %-16s %-16d %-16s\n", ps->data[i].ID, ps->data[i].name, ps->data[i].age, ps->data[i].sex);
	}
}

void contactDestory(contact* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}

int FindByName(contact* ps, char name[])
{
	for (int i = 0; i < ps->sz; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Deletecontact(contact* ps)
{
	char name[32];
	if (ps->sz == 0)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入被删除人姓名：\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("被删除人不存在！\n");
	}
	else
	{
		for (int i = pos; i < ps->sz; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		ps->sz--;
		printf("删除成功\n");
	}
	
}

void Checkcontact(contact* ps)
{
	char name[32];
	printf("请输入被查找人姓名：\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("被查找人不存在！\n");
	}
	else
	{
		printf("%-16s %-16s %-16s %-16s\n", "ID", "名字", "年龄", "性别");
		printf("%-16d %-16s %-16d %-16s\n", ps->data[pos].ID, ps->data[pos].name, ps->data[pos].age, ps->data[pos].sex);
	}
	
}

void Amendcontact(contact* ps)
{
	char name[32];
	printf("请输入被修改人姓名：\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("被修改人不存在！\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：");
		scanf("%d", &ps->data[pos].age);
		printf("请输入学号：");
		scanf("%d", &ps->data[pos].ID);
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("修改成功\n");
	}
}