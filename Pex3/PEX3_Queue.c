/** Queue.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator Queue
* Documentation: I called all the functions provide in the linked list library provided on canvas.
* I also followed along with the provided queue file on canvas while writing mine to ensure it was right.
* ===========================================================
*/
#include "PEX3_queue.h"

/** queueInit() - initializes the queue */
Queue* queueInit() {
    return createLinkedList();
}

/** queueEnqueue() - puts an element onto the top of the queue
 * @param queue is a pointer to the queue 
 * @param val is the value to push */
void queueEnqueue(Queue* queue, int val) {
    appendElementLinkedList(queue, val);
}


/** queueDequeue() - returns the first element of the queue
 * @param queue is a pointer to the queue
 * @return the first element of the queue or -1 if it fails */
int queueDequeue(Queue* queue) {
    int elem = getElementLinkedList(queue, 0);
    deleteElementLinkedList(queue, 0);
    return elem;
}

/** display() - prints the queue
 * @param queue is the queue  */
void displayQueue(Queue queue) {
    printLinkedList(&queue);
}

/** queueIsEmpty() - reutrns true if empty
 * @param queue is a pointer to the queue 
 * @return true if the queue is empty or false if not */
bool queueIsEmpty(Queue queue) {
    if (lengthOfLinkedList(&queue) == 0) {
        return true;
    }
    return false;
}

/** queuePeek() - returns the item on the top of the queue but keeps it
 * @param queue is a ptr to the queue
 * @return the first item */
int queuePeek(Queue queue) {
    return getElementLinkedList(&queue, 0);
}


/** queueSize() returns the queue size
 * @param queue is a pointer to the queue
 * @return the size of the queue */
int queueSize(Queue queue) {
    return lengthOfLinkedList(&queue);
}
