#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class Node {
   public:
    int val;
    Node* prev;
    Node* next;

    Node(int num) {
        val = num;
        prev = NULL;
        next = NULL;
    }
};

class MyLinkedList {
   public:
    Node* head;
    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node* curr = head;
        for (int i = 1; curr != NULL and i <= index; i++) {
            curr = curr->next;
        }

        if (curr == NULL) {
            return -1;
        } else {
            return curr->val;
        }
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->prev = curr;
    }

    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);

        Node* curr = head;
        int count = 0;

        for (int i = 1; curr != NULL and i <= index; i++) {
            count++;
            curr = curr->next;
        }

        if (index == 0) {
            addAtHead(val);
        } else if (curr == NULL and count == index) {
            addAtTail(val);
        } else if (curr != NULL) {
            Node* tempNode = curr->prev;
            tempNode->next = newNode;
            newNode->prev = tempNode;
            newNode->next = curr;
            curr->prev = newNode;
        }
    }

    void deleteAtIndex(int index) {
        Node* curr = head;

        for (int i = 1; curr != NULL and i <= index; i++) {
            curr = curr->next;
        }

        if (curr == NULL) {
            return;
        }

        if (curr->prev == NULL) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }

        } else if (curr->next == NULL) {
            curr->prev->next = NULL;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
