#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

typedef struct SeqList
{
	int ID;
	char name[32];
	int age;
	char sex[8];
}SL;
typedef struct contact
{
	SL* data;
	int sz;
	int capacity;
}contact;

void Initcontact(contact* ps);

void Addcontact(contact* ps);

void Printcontact(contact* ps);

void contactDestory(contact* ps);

void Deletecontact(contact* ps);

void Checkcontact(contact* ps);

void Amendcontact(contact* ps);

