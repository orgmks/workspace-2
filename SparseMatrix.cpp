#include "SparseMatrix.h"
#include "Node.h"
#include <iostream>
using namespace std;

SparseMatrix::SparseMatrix(){
    this -> start = nullptr; 
}

SparseMatrix::~SparseMatrix(){
    clear();
}

void SparseMatrix::clear(){
    Node* current = start;
    while(current != nullptr){
        Node* temp = current ->getNext();
        delete current;
        current = temp;
    }
    start = nullptr;
}

void SparseMatrix::add(int v, int xPos, int yPos){
    if (v == 0){ //remove in the case the value is 0
        remove(xPos,yPos);
        return;
    }

    if (start == nullptr){ //add something if this is null
        start = new Node(v,xPos,yPos);
        return;
    }

    Node* current = start;
    while(current != nullptr){
        if(current->getX() == xPos && current->getY()== yPos){
            current-> setValue(v);
            return; //update value
        }
        if(current->getNext() == nullptr){
            break;
        }
        current = current ->getNext();
    }

    Node* newNode = new Node(v,xPos,yPos);
    current -> setNext(newNode);
    newNode -> setPrev(current);
}

int SparseMatrix::get(int xPos, int yPos){
    Node* current = start;
    while(current != nullptr){
        if(current->getX() == xPos && current->getY() == yPos){
            return current -> getValue();
        }
        current = current -> getNext();
    } //error control
    return 0; //in case of not founded, ill return 0 
}


void SparseMatrix::remove(int xPos,int yPos){
    Node* current = start;
    
    while(current != nullptr){
        if(current->getX() == xPos && current->getY() == yPos){
            Node* previous = current -> getPrev();
            Node* next = current -> getNext();

            if (previous != nullptr){
                previous -> setNext(next); //dynamic change between the previous and the next
            } else {
                start = next; 
            }
            if(next != nullptr){
                next -> setPrev(previous);
            }
            delete current;
            return;
        }
        current = current->getNext();
    }
}

void SparseMatrix::printStoredValues(){
    Node* current = start;
    if(current == nullptr){
        cout << "Empty Matrix" << endl;
        return;
    }

    cout << "Matrix Value" << endl;
    while(current != nullptr){
        cout << "("<<current -> getX() << ","
            << current -> getY() << ") = "
            << current -> getValue() << endl;
        current = current -> getNext();
    }
}

int SparseMatrix::density(){
    return 0;
}
SparseMatrix* SparseMatrix::multiply(SparseMatrix* secondMatrix){
    return nullptr;
}
