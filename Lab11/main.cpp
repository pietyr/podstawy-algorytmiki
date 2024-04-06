#include <iostream>

using namespace std;


// Singly Linked List Node
struct slNode{
    int value;
    slNode *next;
};

struct singlyLinkedList {
    slNode *head = nullptr;
    slNode *tail = nullptr;
    int size = 0;
};

// Doubly Linked List Node
struct dlNode{
	int value;
	dlNode *previous;
	dlNode *next;
};

struct doublyLinkedList {
	dlNode *head = nullptr;
	dlNode *tail = nullptr;
	int size = 0;
};

// Sinlgy Linked List functions

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

// Doubly Linked List functions

/**
 * Function adds new value to tail of the Doubly Linked List
 * @param list Doubly Linked List
 * @param value Integer Value to add
 */
void dlAddTail(doublyLinkedList &list, int value);

/**
 * Function adds new value to head of the Doubly Linked List
 * @param list Doubly Linked List
 * @param value Integer Value to add
 */
void dlAddHead(doublyLinkedList &list, int value);

/**
 * Function adds new value to selected index of the Doubly Linked List
 * @param list Doubly Linked List
 * @param value Integer Value to add
 * @param index Position where new value will be; head is 0 and tail is (size - 1)
 */
void dlInsert(doublyLinkedList &list, int value, int index);

/**
 * Function delete tail of the Doubly Linked List
 * @param list Doubly Linked List
 */
void dlDeleteTail(doublyLinkedList &list);

/**
 * Function delete head of the Doubly Linked List
 * @param list Doubly Linked List
 */
void dlDeleteHead(doublyLinkedList &list);

/**
 * Function delete element at index of the Doubly Linked List
 * @param list Doubly Linked List
 * @param index Index of the element to delete
 */
void dlDeleteAt(doublyLinkedList &list, int index);

/**
 * Function prints elements of the Doubly Linked List
 * @param list Doubly Linked List
 */
void dlPrint(doublyLinkedList &list);

/**
 * Function prints elements of the Doubly Linked List in reversed order
 * @param list Doubly Linked List
 */
void dlPrintReverse(doublyLinkedList &list);


int main() {
	doublyLinkedList *dlList = new doublyLinkedList;
	dlPrint(*dlList);
	dlAddHead(*dlList, 0);
	dlPrint(*dlList);
	dlAddTail(*dlList, 1);
	dlPrint(*dlList);
	dlAddHead(*dlList, 2);
	dlPrint(*dlList);
	dlAddHead(*dlList, 3);
	dlPrint(*dlList);
	dlAddTail(*dlList, 4);
	dlPrint(*dlList);

	dlInsert(*dlList, 5, 1);
	dlPrint(*dlList);
	dlInsert(*dlList, 6, 10);
	dlPrint(*dlList);
	dlInsert(*dlList, 7, 0);
	dlPrint(*dlList);

	dlDeleteHead(*dlList);
	dlPrint(*dlList);
	dlDeleteTail(*dlList);
	dlPrint(*dlList);
	dlDeleteAt(*dlList, 2);
	dlPrint(*dlList);
	dlPrintReverse(*dlList);

	delete dlList;
    return 0;
}

void slAddTail(singlyLinkedList &list, int value) {
	slNode *node = new slNode;
	node->value = value;
	node->next = nullptr;
	if(list.tail != nullptr) {
		list.tail->next = node;
	}else {
		list.head = node;
	}
	list.tail = node;
	list.size++;
}

void slAddHead(singlyLinkedList &list, int value) {
	slNode *node = new slNode;
	node->value = value;
	node->next = list.head;
	list.head = node;
	if(list.tail == nullptr) {
		list.tail = node;
	}
	list.size++;
}

void slInsert(singlyLinkedList &list, int value, int index) {
	if(index == 0) {
		slAddHead(list, value);
	}else if(index >= list.size) {
		slAddTail(list, value);
	}else {
		slNode *node = new slNode;
		node->value = value;

		slNode *temp = list.head;
		for(int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		node->next = temp->next;
		temp->next = node;
		list.size++;
	}
}

void slDeleteTail(singlyLinkedList &list) {
	if(list.size > 0) {
		slNode *oldTail = list.tail;
		if(list.size == 1) {
			list.tail = nullptr;
			list.head = nullptr;
			list.size = 0;
		}else {
			slNode *temp = list.head;
			for(int i = 0; i < list.size - 1; i++) {
				temp = temp->next;
			}
			list.tail=temp;
			list.tail->next = nullptr;
		}
		delete oldTail;
		list.size--;
	}
}

void slDeleteHead(singlyLinkedList &list) {
	if(list.size > 0) {
		slNode *temp = list.head;
		list.head = list.head->next;
		if(list.size == 1) {
			list.tail = nullptr;
		}
		delete temp;
		list.size--;
	}
}

void slDeleteAt(singlyLinkedList &list, int index) {
	if(index == 0) {
		slDeleteHead(list);
	}else if(index > 0 && list.size > 0 && index < list.size) {
		slNode *previous = list.head;
		for(int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}
		slNode *temp = previous->next;
		previous->next = temp->next;
		delete temp;
		list.size--;
	}
}

void slPrint(singlyLinkedList &list) {
	cout << "[";
	if(list.head != nullptr) {
		slNode *temp = list.head;
		for(int i = 0; i < list.size; i++) {
			cout << temp->value;
			if(i != list.size - 1) {
				cout << ", ";
			}
			temp = temp->next;
		}
	}

	cout << "]" << endl;
}

void dlAddTail(doublyLinkedList &list, int value) {
	dlNode *node = new dlNode;
	node->value = value;
	node->next = nullptr;
	node->previous = nullptr;
	if(list.tail != nullptr) {
		list.tail->next = node;
		node->previous = list.tail;
	}else {
		list.head = node;
	}
	list.tail = node;
	list.size++;
}

void dlAddHead(doublyLinkedList &list, int value) {
	dlNode *node = new dlNode;
	node->value = value;
	node->next = nullptr;
	node->previous = nullptr;

	if(list.head != nullptr) {
		list.head->previous = node;
		node->next = list.head;
	}else {
		list.tail = node;
	}
	list.head = node;
	list.size++;
}

void dlInsert(doublyLinkedList &list, int value, int index) {
	if(index == 0) {
		dlAddHead(list, value);
	}else if(index >= list.size) {
		dlAddTail(list, value);
	}else {
		dlNode *node = new dlNode;
		node->value = value;

		dlNode *temp = list.head;
		for(int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		node->previous = temp;
		node->next = temp->next;
		temp->next->previous = node;
		temp->next = node;
		list.size++;
	}
}

void dlDeleteTail(doublyLinkedList &list) {
	if(list.size > 0) {
		dlNode *oldTail = list.tail;
		if(list.size == 1) {
			list.tail = nullptr;
			list.head = nullptr;
			list.size = 0;
		}else {
			list.tail = list.tail->previous;
			list.tail->next = nullptr;
		}
		delete oldTail;
		list.size--;
	}
}

void dlDeleteHead(doublyLinkedList &list) {
	if(list.size > 0) {
		dlNode *oldHead = list.head;
		if(list.size == 1) {
			list.tail = nullptr;
			list.head = nullptr;
		}else {
			list.head = list.head->next;
			list.head->previous = nullptr;
		}
		delete oldHead;
		list.size--;
	}
}

void dlDeleteAt(doublyLinkedList &list, int index) {
	if(index == 0) {
		dlDeleteHead(list);
	}else if(index > 0 && list.size > 0 && index < list.size) {
		dlNode *previous = list.head;
		for(int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}
		dlNode *temp = previous->next;
		previous->next = temp->next;
		previous->next->previous = previous;
		delete temp;
		list.size--;
	}
}

void dlPrint(doublyLinkedList &list) {
	cout << "[";
	if(list.head != nullptr) {
		dlNode *temp = list.head;
		for(int i = 0; i < list.size; i++) {
			cout << temp->value;
			if(i != list.size - 1) {
				cout << ", ";
			}
			temp = temp->next;
		}
	}

	cout << "]" << endl;
}

void dlPrintReverse(doublyLinkedList &list) {
	cout << "[";
	if(list.tail != nullptr) {
		dlNode *temp = list.tail;
		for(int i = list.size - 1; i >= 0; i--) {
			cout << temp->value;
			if(i != 0) {
				cout << ", ";
			}
			temp = temp->previous;
		}
	}

	cout << "]" << endl;
}