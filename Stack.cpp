#include <iostream>
using namespace std;

struct LinkedList
{
    int data;
    LinkedList *prev, *next;

    LinkedList(int val)
    {
        this->data = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class Stacks
{
    LinkedList *head, *cur;
    int length;

public:
    Stacks()
    {
        head = new LinkedList(-1);
        cur = head;
        length = 0;
    }

    int size()
    {
        return length;
    }

    void push(int val)
    {
        LinkedList *newEle = new LinkedList(val);
        cur->next = newEle;
        newEle->prev = cur;
        cur = cur->next;
        length++;
    }

    int top()
    {
        if (length > 0)
            return cur->data;
        throw std::runtime_error("Stack is empty");
    }

    void pop()
    {
        if (length <= 0)
            throw std::runtime_error("Stack is empty");

        cur = cur->prev;
        cur->next->prev = nullptr;
        cur->next = nullptr;
        length--;
        return;
    }

    bool empty()
    {
        if (length > 0)
            return false;
        return true;
    }
};

int main()
{
    Stacks stk;

    cout << "Is stack empty? " << (stk.empty() ? "Yes" : "No") << endl;
    stk.push(10);
    stk.push(20);
    cout << "Top element: " << stk.top() << endl; // should print 20
    cout << "Stack size: " << stk.size() << endl; // should print 2
    stk.pop();
    cout << "Top element after pop: " << stk.top() << endl; // should print 10
    cout << "Stack size after pop: " << stk.size() << endl; // should print 1
    stk.pop();
    cout << "Is stack empty after popping all elements? " << (stk.empty() ? "Yes" : "No") << endl;

    return 0;
}