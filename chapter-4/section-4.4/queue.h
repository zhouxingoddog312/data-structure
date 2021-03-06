#ifndef _Queue_H
#define _Queue_H
#include <stdbool.h>
#include "avltree.h"
typedef AvlTree ElementType_Q;

/*typedef int ElementType_Q;	for test*/

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef struct QueueRecord *Position_Q;


bool IsEmpty(Queue Q);
Queue CreateQueue(Queue Q);
Queue DisposeQueue(Queue Q);
Queue EnQueue(ElementType_Q X,Queue Q);
Queue DeQueue(Queue Q);
ElementType_Q Front(Queue Q);
#endif
