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
			printf("������ϵ��ʧ��\n");
			return;
		}
	}
	printf("���������֣�");
	scanf("%s", ps->data[ps->sz].name);
	printf("���������䣺");
	scanf("%d", &ps->data[ps->sz].age);
	printf("������ѧ�ţ�");
	scanf("%d", &ps->data[ps->sz].ID);
	printf("�������Ա�");
	scanf("%s", ps->data[ps->sz].sex);
	ps->sz++;
	printf("���ӳɹ�\n");
}

void Printcontact(contact* ps)
{
	printf("%-16s %-16s %-16s %-16s\n", "ID", "����", "����", "�Ա�");
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
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("�����뱻ɾ����������\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("��ɾ���˲����ڣ�\n");
	}
	else
	{
		for (int i = pos; i < ps->sz; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		ps->sz--;
		printf("ɾ���ɹ�\n");
	}
	
}

void Checkcontact(contact* ps)
{
	char name[32];
	printf("�����뱻������������\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("�������˲����ڣ�\n");
	}
	else
	{
		printf("%-16s %-16s %-16s %-16s\n", "ID", "����", "����", "�Ա�");
		printf("%-16d %-16s %-16d %-16s\n", ps->data[pos].ID, ps->data[pos].name, ps->data[pos].age, ps->data[pos].sex);
	}
	
}

void Amendcontact(contact* ps)
{
	char name[32];
	printf("�����뱻�޸���������\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("���޸��˲����ڣ�\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &ps->data[pos].age);
		printf("������ѧ�ţ�");
		scanf("%d", &ps->data[pos].ID);
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("�޸ĳɹ�\n");
	}
}