#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

int main(){
    Node* first=new Node;
    Node* second=new Node;
    first->data=1;
    second->data=2;
    first->next=second;
    return 0;
}