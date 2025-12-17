#include <iostream>

using namespace std;

struct DLL
{
    int data;
    DLL *prev, *next;
    DLL(int val)
    {
        this->data = val;
        prev = next = nullptr;
    }
};

class Queue
{
    DLL *start, *end;
    int lenght;

public:
    Queue()
    {
        start = end = nullptr;
        lenght = 0;
    }

    void push(int val)
    {
        lenght++;
        if (start == nullptr)
        {
            start = new DLL(val);
            end = start;
            return;
        }
        end->next = new DLL(val);
        end->next->prev = end;
        end = end->next;
        return;
    }

    void pop()
    {
        if (lenght == 0)
        {
            throw runtime_error("Queue is empty");
        }

        lenght--;
        start = start->next;
        if (start != nullptr)
        {
            start->prev->next = nullptr;
            start->prev = nullptr;
        }
        else
            end = nullptr;
    }

    int front()
    {
        if (lenght == 0)
        {
            throw runtime_error("Queue is empty");
        }
        return start->data;
    }

    bool isEmpty()
    {
        return lenght == 0;
    }

    int size()
    {
        return lenght;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "start element: " << q.front() << endl; // 10
    cout << "Queue size: " << q.size() << endl;     // 3
    q.pop();
    q.pop();
    cout << "start element after pop: " << q.front() << endl; // 20
    q.pop();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // No
    q.pop();
    return 0;
}