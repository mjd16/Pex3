/** queue.h
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* ===========================================================
*/

#ifndef PEX3_queue_h
#define PEX3_queue_h
#include <stdbool.h>
#include <stdio.h>
#include "listAsLinkedList.h"

typedef LinkedList Queue;

/** queueInit() - initializes the queue */
Queue* queueInit(void);

/** queueEnqueue() - puts an element onto the top of the queue
 * queue is a pointer to the queue
 * element is the value to push */
void queueEnqueue(Queue* queue, int element);

///** queueDequeue() - returns the first element of the queue
// * @param queue is a pointer to the queue
// * @return the first element of the queue or -1 if it fails */
int queueDequeue(Queue* queue);

/** display() - prints the queue
 * @param queue is the queue  */
void displayQueue(Queue queue);

/** queueIsEmpty() - reutrns true if empty
 * @param queue is a pointer to the queue
 * @return true if the queue is empty or false if not */
bool queueIsEmpty(Queue queue);

/** queuePeek() - returns the item on the top of the queue but keeps it
 * @param queue is a ptr to the queue
 * @return the first item */
int queuePeek(Queue queue);

/** queueSize() returns the queue size
 * @param queue is a pointer to the queue
 * @return the size of the queue */
int queueSize(Queue queue);
#endif
