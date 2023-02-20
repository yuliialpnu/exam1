#include <iostream>
#include <stdlib.h> //підключаємо бібліотеки
#include <time.h>

using namespace std; //простір імен, який будемо використовувати

struct list
{
    int value; list* next, * prev;
};

list* fill_list(list*&);
list* delete_same_values(list*);
void output_list(list*, const char*);
void CheckDuplicates(list*);
void DestroyList(list*&);

int main()
{
    list* head = NULL;
    head = fill_list(head); //заповнюємо список
    CheckDuplicates(head);
    system("pause");
    return 0;
}



list* fill_list(list*& head)//заповнюємо список
{
    srand(time(0));

    list* ptr1, * ptr2 = NULL;
    head = new list;
    head->value = rand() % 25;//генеруємо елементи
    head->next = ptr2;
    head->prev = NULL;
    ptr2 = head;
    ptr2->next = NULL;
    ptr2->prev = head;

    while (head->value != 0 && ptr2->value != 0)
    {
        ptr1 = new list;
        ptr1->value = rand() % 25;
        ptr1->next = ptr2->next;
        ptr1->prev = ptr2;
        ptr2->next = ptr1;
        ptr2 = ptr1;
    }
    output_list(head, "list");//вивід списку
    return head;
}
void DestroyList(list*& node) //звільняємо пам'ять
{
    list* next;

    while (node)
    {
        next = node->next;
        delete node;
        node = next;
    }
}

void CheckDuplicates(list* l) //перевірка на повторення символів
{
    for (list* p = l; p; p = p->next)
        for (list* q = p->next; q; q = q->next)
        {
            if (p->value == q->value)
            {
                q->prev->next = q->next;
                q->next->prev = q->prev;

            }
        }
    output_list(l, "\nNew list");
}


list* delete_same_values(list* head)//видалення однакових символів
{
    int i = 0;
    while (head)
    {
        i++;
    }
    return nullptr;
}

void output_list(list* head, const char* msg)//виводимо список
{

    cout << msg << endl;
    while (head)
    {
        cout << head->value << " ";
        head = head->next;
    }
}