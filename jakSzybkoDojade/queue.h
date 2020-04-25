//
//  queue.h
//  jakSzybkoDojade
//
//  Created by Sophie Popow on 26/04/2020.
//  Copyright © 2020 Sophie Popow. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/// MARK: - Queue Implementation

typedef struct queueElement {
    struct queueElement *next;
    int val;
} queueElement;

typedef struct queue {
    int start, end, size;
    queueElement *elements;
} queue;

queue *new_queue(int size)
{
    queue *q = (queue *) malloc(sizeof(queue));
    q->start=0;
    q->end=0;
    q->size=size;
    q->elements=(queueElement *) malloc(size*sizeof(queueElement));
    return q;
}

void delete_queue(queue *q)
{
    free (q->elements);
    free (q);
}

queueElement* get(queue *q) {
    if (q->start+1 < q->size)
    {
        return &(q->elements[++q->start]);
    }
    else
    {
        q->start=0;
        return &(q->elements[q->start]);
    }
}

bool is_empty(queue *q) {
    if (q->start==q->end) return true;
    return false;
}

void push(int val, queue *q){
    if (q->end+1 < q->size)
    {
        q->end++;
        q->elements[q->end].val = val;

    }
    else
    {
        q->end=0;
        q->elements[q->end].val = val;

    }
}

#endif /* queue_h */
