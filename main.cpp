#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node * next;
}*first=nullptr, *second = nullptr, *third = nullptr;

// Create a linked-list from an array..

void create(int A[], int n) {
    Node *temp, *last;
    first = (Node *) malloc(sizeof(Node));
    first -> data = A[0];
    first -> next = nullptr;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp -> data = A[i];
        temp -> next = NULL;
        last -> next = temp;
        last = temp;    
    }
}

void create2(int A[], int n) {
    Node *temp, *last;
    second = (Node *) malloc(sizeof(Node));
    second -> data = A[0];
    second -> next = nullptr;
    last = second;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp -> data = A[i];
        temp -> next = NULL;
        last -> next = temp;
        last = temp;    
    }
}


void display(Node *p) {
    while (p)
    {
        printf("%d\n", p -> data);
        p = p -> next;
    }
}

void displayRecursiveCalling(Node *p) {
    if (p)
    {
        printf("%d\n", p->data);
        displayRecursiveCalling(p->next);
    }
}

void displayRecursiveReturning(Node *p) {
    if (p != nullptr)
    {
        displayRecursiveReturning(p->next);
        printf("%d\n", p->data);
    }
}

int lenLinkedList(Node *p) {
    static int count = 0;
    while (p != nullptr)
    {
        count ++;
        p = p->next;
    }
    return count;
}

int countRecursive(Node *p) {
    static int recursiveCount;
    if (p)
    {
        recursiveCount +=1;
        return countRecursive(p->next);
    }
    return recursiveCount;
}

int countRecursive2Returning(Node *p) {
    if (p == 0)
    {
        return 0;
    }
    return countRecursive2Returning(p->next) + 1;
}

int countRecursive2Calling(Node *p) {
    if (p == 0)
    {
        return 0;
    }
    return countRecursive2Calling(p->next) + 1;
}

int recursiveSum(Node *p) {
    static int recursiveSummation = 0;
    if (p != nullptr)
    {
        return recursiveSum(p->next) + p->data;
    }
    return 0;
}

int sum(Node *p) {
    int summation = 0;
    while (p)
    {
        summation += p->data;
        p = p->next;
    }
    return summation;
}

int max(Node *p) {
    int maxValue = INT_MIN;
    while (p != nullptr)
    {
        if (p->data > maxValue)
        {
            maxValue = p->data;
        }
        p = p->next;

    }
    return maxValue;
}

int rMax(Node *p) {
    static int rMaxValue = INT_MIN;
    if (p == nullptr)
    {  
        return INT_MIN;
    }
    else 
    {
        rMaxValue = rMax(p->next);
        if (rMaxValue > p->data)
        {
            return rMaxValue;
        }
        return p->data;
    }
}

int rMaxSimple(Node *p) {
    int x = 0;
    if (!p) {
        return INT_MIN;
    }
    x = max(p->next);
    return x > p->data ? x : p->data;
}

Node * Lsearch(Node *p, int value) {
    while (p != nullptr)
    {
        if (p->data == value)
        {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

Node * rSearch(Node *p, int value) {
    if (p == NULL)
    {
        return nullptr;
    }
    if (p->data == value)
    {
        return p;
    }
    return rSearch(p->next, value);
}

// Move to head for an effective function. For this, we need two pointer following each other
Node * search(Node *p, int key) {
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            // what if you cut and paste "q = p" this line? It's infinite loop and I didn't get it.
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }         
        q = p;
        p = p->next;
    }
    return NULL;
}
// Use this in main for search function..
    // create(A, 6);
    // temp = search(first, 10);
    // if (temp)
    // {
    //     cout << "The found key is " << temp->data << endl;
    // }
    // else {
    //     cout << "The key was not found" << endl << endl;
    // }
    // display(first);

void insert(Node *p, int index, int insertingValue) {
    Node *temp;

    if (index < 0 || index > lenLinkedList(p))
    {
        return; // stop the function
    }
    
    temp = new Node;
    temp->data = insertingValue;

    if (index == 0)
    {
        temp->next = first;
        first = temp;
    }
    else {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;

    }

}

void insertLast(int x) {
    Node *temp = new Node;
    Node *last;

    temp->data = x;
    temp->next = nullptr;

    if (first == nullptr)
    {
        first = last = temp;
    }
    else {
        last->next = temp;
        last = temp;
    }
}

// Even if the linked-list is empty, function will work!
void insertToSortedList(Node *p, int value) {
    Node *temp;
    Node *q = nullptr;

    temp = new Node;
    temp->data = value;
    temp->next = nullptr;

    if (first == nullptr)
    {
        first = temp;
    }
    else{
        while (p && p->data < value)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            temp->next = first;
            first = temp;
        }
        else {
            temp->next = q->next;
            q->next = temp;
        }
    }   
}

int deleteElement(Node *p, int index) { // First index is 1 by default

    Node *q = nullptr;
    int x = -1; // To store the deleted value

    if (index < 1 || index > lenLinkedList(p)) // To control invalid index
    {
        return -1;
    }

    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;

        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int isSorted(Node *p) {
    int value = INT_MIN;

    while (p != nullptr)
    {
        if (p->data < value)
        {
            return 0;
        }
        value = p->data;
        p = p->next; 
    }
    return 1;
}

void removeDublicate(Node *p) {
    Node *q = p->next;
    while (q != nullptr)
    {
        if (p->data != q->data)
        {
             p = q;
             q = q->next;
        }
        else
        {
            p->next = q->next;
            delete(q);
            q = p->next;
        }   
    }
}

void reverseWithRecursion(Node *q, Node *p) {
    if (p)
    {
        reverseWithRecursion(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void concatanate(Node *p, Node *q) {
    third = p;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(Node *p, Node *q) {
    Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = nullptr;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = nullptr;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }
    if (p != nullptr)
    {
        last->next = p;
    }
    if (q != nullptr)
    {
        last->next = q;
    }
}

int main() {
    Node *temp;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    int B[] = {5, 15, 25, 35, 45};
    create2(B, 5);

    merge(first, second);
    display(third);
    return 0;
}
