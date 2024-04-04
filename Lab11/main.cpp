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
	singlyLinkedList *slList = new singlyLinkedList;
	slPrint(*slList);
	slAddHead(*slList, 0);
	slPrint(*slList);
	slAddTail(*slList, 1);
	slPrint(*slList);
	slAddHead(*slList, 2);
	slPrint(*slList);
	slAddHead(*slList, 3);
	slPrint(*slList);
	slAddTail(*slList, 4);
	slPrint(*slList);

	slInsert(*slList, 5, 1);
	slPrint(*slList);
	slInsert(*slList, 6, 10);
	slPrint(*slList);
	slInsert(*slList, 7, 0);
	slPrint(*slList);

	slDeleteHead(*slList);
	slPrint(*slList);
	slDeleteTail(*slList);
	slPrint(*slList);
	slDeleteAt(*slList, 2);
	slPrint(*slList);

	delete slList;
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