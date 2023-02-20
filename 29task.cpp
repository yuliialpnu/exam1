// Задано натуральне число. Створити стек з його цифр.
#include<iostream> 
using namespace std;

typedef unsigned long long ull;
const int s_len = 21;
struct stack
{
    ull info;
    stack* el;
};
void push(stack*&, int);
void print_stack(stack*, const char*);
void delete_stack(stack*&);
void creat_stack(stack*&);
double input_number(const char*);


int main()
{
    stack* top = NULL;
    stack* a_top = top;
    creat_stack(a_top);
    //print_stack(top, "Created stack: ");  
    delete_stack(top);
    cout << "End of program!" << endl;
    return 0;
}

double input_number(const char* msg)
{
    cout << "Enter " << msg << ": ";
    char s[s_len + 1];
    cin.getline(s, s_len);
    return atof(s);
}

void push(stack*& no, int a) {

    stack* prev = no; //prev і no вказують на вершину стеку 
    no = new stack;
    no->info = a; //запис інформаційної частини нового елементу 
    no->el = prev; //під'єднання нового елементу до стеку 
    //no вказує на нову вершину стеку і повертається у main() 
}

void print_stack(stack* no, const char* msg) //друк стеку 
{
    cout << msg << endl;
    if (!no)
    {
        cout << "Is empty";
        return;
    }
    while (no)
    {
        cout << no->info << ' ';
        no = no->el;
    }
    cout << endl;
}

void delete_stack(stack*& no)
{
    stack* next;
    while (no)
    {
        next = no->el; //переміщення вказівника на вершину стеку 
        delete no;
        no = next;
    }
}

void creat_stack(stack*& top)
{
    ull n = (ull)input_number("your number");
    int i;
    do
    {
        i = n % 10;
        if (i == 1) i = 0;
        else if (i == 0) i = 1;
        push(top, i);
    } while (n /= 10);
    print_stack(top, "Created stack: ");
}
