#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int n)
    {
        data = n;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *last;

public:
    Stack()
    {
        last = nullptr;
    }

    void push(int n)
    {
        Node *latest = new Node(n);
        latest->next = last;
        last = latest;
        cout<<"Pushed - "<<n<<endl;
    }

    void pop()
    {
        if (last == nullptr)
        {
            cout << "Underflow Occured!" << endl;
        }

        Node *temp = last;
        last = temp->next;
        cout<<"popped - "<<temp->data<<endl;
        delete temp;
    }

    int peek()
    {
        if (last == nullptr)
        {
            cout << "Empty!" << endl;
        }
        cout << "Top Element :" << endl;
        return last->data;
        cout << endl;
    }

    void print()
    {
        if (last == nullptr)
        {
            cout << "Empty!" << endl;
            return;
        }

        Node *temp = last;
        cout << "Stack:" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Stack a;
    a.push(1);
    a.push(2);
    a.push(3);

    a.print();

    a.pop();
    a.pop();

    a.print();
    return 0;
}