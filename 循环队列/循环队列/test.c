#define _CRT_SECURE_NO_WARNINGS 1 


//typedef struct {
//    int* a;
//    int head;
//    int tail;
//    int k;
//} MyCircularQueue;
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    obj->a = (int*)malloc((k + 1) * sizeof(int));
//    obj->head = obj->tail = 0;
//    obj->k = k;
//    return obj;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    assert(obj);
//    return obj->tail == obj->head;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    assert(obj);
//    return ((obj->tail + 1) % (obj->k + 1)) == obj->head;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    assert(obj);
//
//    if (myCircularQueueIsFull(obj))
//    {
//        return false;
//    }
//    obj->a[obj->tail++] = value;
//    obj->tail %= (obj->k + 1);
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    assert(obj);
//    if (myCircularQueueIsEmpty(obj))
//        return false;
//    obj->head++;
//    obj->head %= (obj->k + 1);
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    assert(obj);
//    if (myCircularQueueIsEmpty(obj))
//    {
//        return -1;
//    }
//    return obj->a[obj->head];
//
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    assert(obj);
//    if (myCircularQueueIsEmpty(obj))
//    {
//        return -1;
//    }
//    return obj->a[(obj->tail + obj->k) % (obj->k + 1)];
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    free(obj->a);
//    free(obj);
//}