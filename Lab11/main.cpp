#include <iostream>

using namespace std;


// Singly Linked List Node
struct slNode{
    int value;
    slNode *next;
};

struct singlyLinkedList {
    slNode *head;
    slNode *tail;
    int size;
};

/**
 * Function adds new value to tail of the Singly Linked List
 * @param list Singly Linked List
 * @param value Integer Value to add
 */
void slAddTail(singlyLinkedList &list, int value);

/**
 * Function adds new value to head of the Singly Linked List
 * @param list Singly Linked List
 * @param value Integer Value to add
 */
void slAddHead(singlyLinkedList &list, int value);

/**
 * Function adds new value to selected index of the Singly Linked List
 * @param list Singly Linked List
 * @param value Integer Value to add
 * @param index Position where new value will be; head is 0 and tail is (size - 1)
 */
void slInsert(singlyLinkedList &list, int value, int index);


/**
 * Function delete tail of the Singly Linked List
 * @param list Singly Linked List
 */
void slDeleteTail(singlyLinkedList &list);

/**
 * Function delete head of the Singly Linked List
 * @param list Singly Linked List
 */
void slDeleteHead(singlyLinkedList &list);

/**
 * Function delete element at index of the Singly Linked List
 * @param list Singly Linked List
 * @param index Index of the element to delete
 */
void slDeleteAt(singlyLinkedList &list, int index);

/**
 * Function prints elements of the Singly Linked List
 * @param list Singly Linked List
 */
void slPrint(singlyLinkedList &list);

int main() {

    return 0;
}
