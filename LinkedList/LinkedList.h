#pragma once

struct NODE {
    string data; 
    NODE* next; 
};

struct LINKEDLIST {
    NODE* head;

    void init() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    NODE* makeNode(string x) {
        NODE* newNode = new NODE(); 
        newNode->data = x;
        newNode->next = nullptr;
        return newNode;
    }

    void pushFront(string x) {
        NODE* newNode = makeNode(x);
        if (this->isEmpty()) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    bool insert(string x, int k) {
        if (k == 1) {
            pushFront(x);
            return 1;
        }

        if (k < 1 || k > this->size())
            return 0;
  
        NODE* newNode = makeNode(x);
        NODE* tmp = head;
        for (int i = 1; i < k - 1; i++)
            tmp = tmp->next;
        newNode->next = tmp->next;
        tmp->next = newNode;
        return 1;
    }

    void popFront() {
        if (this->isEmpty())
            return;
        else {
            NODE* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void popBack() {
        if (this->isEmpty())
            return;
        else {
            NODE* tmp = head;
            if (head->next == nullptr) {
                head = nullptr;
                delete tmp;
            }
            else {
                while (tmp->next->next != nullptr)
                    tmp = tmp->next;
                NODE* last = tmp->next; 
                tmp->next = nullptr;
                delete last;
            }
        }
    }

    bool deleteNode(int k) {
        if (k < 1 || k > this->size())
            return 0;

        if (k == 1) {
            popFront();
            return 1;
        }

        if (k == this->size()) {
            popBack();
            return 1;
        }
       
        NODE* tmp = head;
        for (int i = 1; i < k - 1; i++)
            tmp = tmp->next;
        NODE* kth = tmp->next;
        tmp->next = kth->next;
        delete (kth);
        return 1;
    }

    string dataOfNode(int k) {
        NODE* tmp = head;
        int cnt = 0;
        while (tmp != nullptr) {
            ++cnt;
            if (cnt == k)
                return tmp->data;
            tmp = tmp->next;
        }
    }

    int size() {
        NODE* tmp = head;
        int cnt = 0;
        while (tmp != nullptr) {
            cnt++;
            tmp = tmp->next; 
        }
        return cnt;
    }
};

