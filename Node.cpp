#include "Node.h"
#include <iostream>
#include <string>


Node::Node(){} // same as this
Node::~Node(){} //method of destructor, i just typed here

Node::Node(int v,int xPos, int yPos){
    this -> value =v;
    this -> x = xPos;
    this -> y = yPos;
    this -> next = nullptr;
    this -> prev = nullptr;
}

int Node::getValue(){
    return value
;}
int Node::getX(){
    return x
;}
int Node::getY(){
    return y
;}
Node* Node::getNext(){
    return next
;}
Node* Node::getPrev(){
    return prev
;}

void Node::setValue(int v){
    this -> value = v;
}

void Node::setNext(Node* next){
    this -> next = next;
}

void Node::setPrev(Node* previous){
    this -> prev = previous;
}