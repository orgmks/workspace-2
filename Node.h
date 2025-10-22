#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int value;
    int x;
    int y;
    Node* next;
    Node* prev;

public:
    Node();
    Node(int v, int x, int y);

    int getValue();
    int getX();
    int getY();
    Node* getNext();
    Node* getPrev();
   
    void setValue(int value);
    void setNext(Node* n);
    void setPrev(Node* p);


    ~Node();
};

#endif 