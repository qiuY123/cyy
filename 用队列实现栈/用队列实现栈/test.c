#define _CRT_SECURE_NO_WARNINGS 1 

//typedef int Datetype;
//
//typedef struct queueNode
//{
//	Datetype date;
//	struct queueNode* next;
//}qNode;
//
//typedef struct queue
//{
//	qNode* head;
//	qNode* tail;
//	int count;
//}queue;
//
//void queueInit(queue* p)
//{
//	assert(p);
//	p->head = p->tail = NULL;
//	p->count = 0;
//}
//void queueDestory(queue* p)
//{
//	assert(p);
//	qNode* cur = p->head;
//	while (cur)
//	{
//		qNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	p->head = p->tail = NULL;
//	p->count = 0;
//}
//void queuePush(queue* p, Datetype x)
//{
//	assert(p);
//	qNode* newnode = (qNode*)malloc(sizeof(qNode));
//	newnode->date = x;
//	newnode->next = NULL;
//	if (p->tail == NULL)
//	{
//		p->head = p->tail = newnode;
//	}
//	else
//	{
//		p->tail->next = newnode;
//		p->tail = newnode;
//	}
//	p->count++;
//}
//void queuePop(queue* p)
//{
//	assert(p);
//	assert(p->head);
//	//如果还剩最后一个数据，删除后tail为野指针
//	if (p->head->next == NULL)//一个节点
//	{
//		free(p->head);
//		p->head = p->tail = NULL;
//	}
//	else//多个节点
//	{
//		qNode* temp = p->head->next;
//		free(p->head);
//		p->head = temp;
//	}
//	p->count--;
//}
//Datetype queueFront(queue* p)
//{
//	assert(p);
//	assert(p->head);
//	return p->head->date;
//}
//Datetype queueBack(queue* p)
//{
//	assert(p);
//	assert(p->head);
//	return p->tail->date;
//
//}
//int queueEmpty(queue* p)
//{
//	assert(p);
//	if (p->head)
//	{
//		return 1;
//	}
//	return 0;
//}
//int queueSize(queue* p)
//{
//	assert(p);
//	return p->count;
//}
//
//typedef struct {
//	queue e1;
//	queue e2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	queueInit(&obj->e1);
//	queueInit(&obj->e2);
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	if (queueEmpty(&obj->e1))
//	{
//		queuePush(&obj->e1, x);
//	}
//	else
//	{
//		queuePush(&obj->e2, x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	queue* empty = &obj->e1;
//	queue* inempty = &obj->e2;
//	if (queueEmpty(&obj->e1))
//	{
//		empty = &obj->e2;
//		inempty = &obj->e1;
//	}
//	while (queueSize(inempty) > 1)
//	{
//		queuePush(empty, queueFront(inempty));
//		queuePop(inempty);
//	}
//	int top = queueFront(inempty);
//	queuePop(inempty);
//	return top;
//}
//
//int myStackTop(MyStack* obj) {
//	if (queueEmpty(&obj->e1))
//	{
//		return queueBack(&obj->e1);
//	}
//	else
//	{
//		return queueBack(&obj->e2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj) {
//	return !queueEmpty(&obj->e1) && !queueEmpty(&obj->e2);
//}
//
//void myStackFree(MyStack* obj) {
//	queueDestory(&obj->e1);
//	queueDestory(&obj->e2);
//	free(obj);
//}