#include<iostream>
using namespace std;
typedef struct vertex {
    char n;
    vertex* next;
}STACK;
int main() {
    char a;
    STACK* head, * q;
    head = NULL;
    cout << "Enter string of numbers: ";
    do
    {
        a = getchar();
        q = new STACK;
        q->n = a;
        q->next = head;
        head = q;
    } while (a != '\n');
    while (head->next != NULL)
    {
        head = q->next;
        int element;
        element = atoi(&head->n);
        if (element == 1) {
            element = 0;
        }
        else if (element == 0) {
            element = 1;
        }
        cout << element << " ";
        q = head;
    };
    cout << endl;
    while (head)
    {
        q = head->next;
        delete head;
        head = q;
    }
    return 0;
}