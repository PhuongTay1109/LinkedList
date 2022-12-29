#include"graphics.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void drawWelcomeInterface();
void linkedlistSimulation();
void drawObjectsInLinkedlist();
void drawObjectsInLinkedlist(int breakPos);
void drawInsert(string data, int pos);
void drawDelete(string data, int pos);

// Each node has height is 50 and width is 50
RECT firstNodePos = { 300, 250, 350, 300 }; 
int sleepTime = 10;
LINKEDLIST* list = new LINKEDLIST();

int main() {
	list->init();
	initgraph();

	drawWelcomeInterface(); 
	_getch();
	system("cls");

	linkedlistSimulation(); 
	return 0;
}

void drawWelcomeInterface()
{
    drawText(400, 80, "LINKEDLIST SIMULATION", 255, 0, 0);

	int x1 = firstNodePos.left;
	int y1 = firstNodePos.top;
	int x2 = firstNodePos.right;
	int y2 = firstNodePos.bottom;
	for (int i = 0; i < 4; i++)
	{
		// Each node has height is 50 and width is 50
		// The arrow has width is 50
		// To display each object needs 100
		if (i != 0) {
			x1 += 100;
			x2 += 100;
		}
		setcolor(12);
        node(x1, y1, x2, y2, " ");
	}
    drawText(x1 + 100, y1 + 10, "NULL", 255, 0, 0);
    drawText(300, 400, "This program simulates the linked list having capacity of 4 objects.", 255, 255, 255);
    drawText(400, 430, "Press any key to start.", 255, 255, 255);
}

void drawObjectsInLinkedlist()
{
    int x1 = firstNodePos.left;
    int y1 = firstNodePos.top;
    int x2 = firstNodePos.right;
    int y2 = firstNodePos.bottom;

    if (list->isEmpty()) {
        drawText(x1, y1 + 10, "NULL", 255, 0, 0);
        return;
    }

    NODE* tmp = list->head;
    while(tmp != nullptr) {
        if (tmp != list->head) {
            x1 += 100;
            x2 += 100;
        }
        setcolor(12);
        node(x1, y1, x2, y2, tmp->data.c_str());
        tmp = tmp->next;
    }

    drawText(x1 + 100, y1 + 10, "NULL", 255, 0, 0);
}

void drawObjectsInLinkedlist(int breakPos) {
    int x1 = firstNodePos.left;
    int y1 = firstNodePos.top;
    int x2 = firstNodePos.right;
    int y2 = firstNodePos.bottom;

    if (list->isEmpty()) {
        drawText(x1, y1 + 10, "NULL", 255, 0, 0);
        return;
    }

    NODE* tmp = list->head;
    for(NODE *tmp = list->head; tmp != nullptr; tmp = tmp ->next) {
        if (tmp != list->head) {
            x1 += 100;
            x2 += 100;
        }
        if (x1 == breakPos)
            continue;
        setcolor(12);
        node(x1, y1, x2, y2, tmp->data.c_str());
    }

    drawText(x1 + 100, y1 + 10, "NULL", 255, 0, 0);
}

void drawDelete(string data, int pos) {
    system("cls");

    int deleteNodePosX1 = firstNodePos.left;
    if (pos != 1)
        deleteNodePosX1 = firstNodePos.left + 100 * (pos - 1);

    for (int i = 0; i <= 50; i++) {
        // go up
        node(deleteNodePosX1, 200 - i, deleteNodePosX1 + 50, 250 - i, data.c_str());
        drawObjectsInLinkedlist();
        Sleep(sleepTime);
        system("cls");
    }
    
    drawObjectsInLinkedlist();
}

void drawInsert(string data, int pos) {
    system("cls");

    int insertNodePosX1 = firstNodePos.left;
    if (pos != 1)
        insertNodePosX1 = firstNodePos.left + 100 * (pos - 1);

    for (int i = 0; i <= 50; i++) {
        // go down
        node(insertNodePosX1, 200 + i, insertNodePosX1 + 50, 250 + i, data.c_str());
        drawObjectsInLinkedlist(insertNodePosX1);
        Sleep(sleepTime);
        system("cls");
    }

    drawObjectsInLinkedlist();
}

void linkedlistSimulation() {
    cout << "Press '1' to Insert." << endl;
    cout << "Press '2' to Delete." << endl;
    cout << "Press any other key to esc." << endl;
    int opt, pos;
    string data;
    cin >> opt;
    if (opt == 1) {
        if (list->size() >= 4) {
            cout << "Linked list is full. You can only choose Delete." << endl;
            linkedlistSimulation();
        }
        else {
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> pos;
            if (list->insert(data, pos)) {
                drawInsert(data, pos);
                linkedlistSimulation();
            }
            else {
                cout << "Position to insert isn't valid" << endl;
                linkedlistSimulation();
            }
        }
    }
    else if (opt == 2) {
        if (!list->isEmpty()) {
            cout << "Enter position: ";
            cin >> pos;
            data = list->dataOfNode(pos); // data of delete node
            if (list->deleteNode(pos)) {
                drawDelete(data, pos);
                linkedlistSimulation();
            }
            else {
                cout << "Position to delete isn't valid" << endl;
                linkedlistSimulation();
            }
        }
        else {
            cout << "Linked list is empty. You must Insert data first." << endl;
            linkedlistSimulation();
        }
    }
    else
    {
        system("cls");
    }
}