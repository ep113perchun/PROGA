#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <class T>
struct node {
    T key;
    struct node<T>* next;
};

template <class T>
class List {
public:
    node<T>* head = NULL;
    node<T>* tail = NULL;
    node<T>* cur = NULL;
    //List() { cout << "Create List\n"; }
    void AddHead(T banan) {
        node<T>* p = new node<T>;
        p->key = banan;
        p->next = head;
        head = p;
        if (tail == NULL) {
            tail = head;
        }
    }
    void AddTail(T banan) {
        node<T>* p = new node<T>;
        p->key = banan;
        if (tail != NULL) {
            tail->next = p;
        }
        p->next = NULL;
        tail = p;
        if (head == NULL) head = tail;
    }
    void DeleteHead() {
        try {
            if (head != NULL) {
                node<T>* NHead = head->next;
                head->next = nullptr;
                delete head;
                head = NHead;
                if (head == NULL) {
                    tail = NULL;
                }
            }
            else {
                throw (1);
            }
        }
        catch (...) {
            cout << "Stack is empty\n";
        }
    }
    void DeleteTail() {
        try {
            if (tail != NULL) {
                node<T>* NTail = head;

                if (NTail == tail) {
                    head = NULL;
                    NTail = NULL;
                }
                if (NTail != NULL) {
                    while (NTail->next != tail) {
                        NTail = NTail->next;
                    }
                }
                delete tail;
                tail = NTail;
                if (tail != NULL) {
                    tail->next = NULL;
                }
            }
            else {
                throw(1);
            }
        }
        catch (int a) {
            cout << "Stack is empty\n";
        }
    }
};

template <class T>
class Stack : public List<T> {
public:
    //List<T>::head;
    Stack() { cout << "Create Stack\n"; }
    void AddStack(T banan) {
        List<T>::AddHead(banan);
    }
    void DeleteStack() {
        List<T>::DeleteHead();
    }
    void AddStack2(Stack<T>& a, Stack<T>& b) {
        node<T>* tail = b.head;
        node<T>* tailNext = b.head->next;
        while (tailNext != NULL) {
            tail = tailNext;
            tailNext = tailNext->next;
        }
        tail->next = a.head;
        a.head = b.head;
    }
};

template <class T>
class Queue : public Stack<T> {
public:
    void AddQueue(T banan) {
        List<T>::AddHead(banan);
    }
    void DeleteQueue() {
        List<T>::DeleteTail();
    }
};


int main()
{
    List<int> list;
    Stack<int> stack;
    Queue<int> queue;
    int c = 0;
    int a = 100;
    int b = 0;
    do {
        cout << "1 - list, 2 - Stack, 3 - Queue, 0 - Exit\n";
        cin >> c;
        if (c == 1) {
            do {
                printf("1 - AddHead, 2 - AddTail, 3 - DeleteHead, 4 - DeleteTail, 5 - Print, 0 - Exit\n");
                cin >> a;
                switch (a)
                {
                case 1:
                {
                    cout << "AddHead: ";
                    cin >> b;
                    list.AddHead(b);
                    break;
                }
                case 2:
                {
                    cout << "AddTail: ";
                    cin >> b;
                    list.AddTail(b);
                    break;
                }
                case 3:
                {
                    if (list.head != NULL) {
                        printf("Delete: %d\n", list.head->key);
                    }
                    list.DeleteHead();
                    break;
                }
                case 4:
                {
                    if (list.tail != NULL) {
                        printf("Delete: %d\n", list.tail->key);
                    }
                    list.DeleteTail();
                    break;
                }
                case 5:
                {
                    list.cur = list.head;
                    printf("Composition: ");
                    while (list.cur != NULL) {
                        printf("%d ", list.cur->key);
                        list.cur = list.cur->next;
                    }
                    list.cur = list.head;
                    printf("\n");
                    break;
                }
                default:
                    break;
                }
            } while (a != 0);
        }
        if (c == 2) {
            do {
                printf("1 - AddStack, 2 - DeleteStack, 3 - Print, 0 - Exit\n");
                cin >> a;
                switch (a)
                {
                case 1:
                {
                    cout << "AddStack: ";
                    cin >> b;
                    stack.AddStack(b);
                    break;
                }
                case 2:
                {
                    if (stack.head != NULL) {
                        printf("Delete: %d\n", stack.head->key);
                    }
                    stack.DeleteStack();
                    break;
                }
                case 3:
                {
                    stack.cur = stack.head;
                    printf("Composition: ");
                    while (stack.cur != NULL) {
                        printf("%d ", stack.cur->key);
                        stack.cur = stack.cur->next;
                    }
                    stack.cur = stack.head;
                    printf("\n");
                    break;
                }
                default:
                    break;
                }
            } while (a != 0);
        }
        if (c == 3) {
            do {
                printf("1 - AddQueue, 2 - DeleteQueue, 3 - Print, 0 - Exit\n");
                cin >> a;
                switch (a)
                {
                case 1:
                {
                    cout << "AddQueue: ";
                    cin >> b;
                    queue.AddQueue(b);
                    break;
                }
                case 2:
                {
                    if (queue.tail != NULL) {
                        printf("Delete: %d\n", queue.tail->key);
                    }
                    queue.DeleteQueue();
                    break;
                }
                case 3:
                {
                    queue.cur = queue.head;
                    printf("Composition: ");
                    while (queue.cur != NULL) {
                        printf("%d ", queue.cur->key);
                        queue.cur = queue.cur->next;
                    }
                    queue.cur = queue.head;
                    printf("\n");
                    break;
                }
                default:
                    break;
                }
            } while (a != 0);
        }
    } while (c != 0);

    printf("_________________________\n");

    Stack<int> stack1;
    Stack<int> stack2;

    stack1.AddStack(4);
    stack1.AddStack(5);
    stack1.AddStack(6);
    
    stack2.AddStack(1);
    stack2.AddStack(2);
    stack2.AddStack(3);

    stack1.AddStack2(stack1, stack2);
    for (int i = 0; i < 6; i++) {
        printf("%d \n", stack1.head->key);
        stack1.DeleteStack();
    }

    return 0;
}