#include "SparseMatrix.h"
#include "Node.h"
#include <iostream>
using namespace std;

SparseMatrix::SparseMatrix(){
    this -> start = nullptr; 
}

SparseMatrix::~SparseMatrix(){
    Node* current = start;
    while(current != nullptr){
        Node* temp = current -> getNext();
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
    int maxPosX = 0;
    int maxPosY = 0;
    

    while (current != nullptr){
        if(current -> getX() > maxPosX){
            maxPosX = current -> getX();
        }
        if(current -> getY() > maxPosY){
            maxPosY = current -> getY();
        }
        current = current -> getNext();
    }
    
    for (int i = 0; i <= maxPosY; i++){
        for (int j = 0; j <= maxPosX; j++){
            cout << get(j,i) << "\t";
        }
        cout << endl;
    }
}

int SparseMatrix::density(){
    if(start == nullptr){
        cout << "The Matrix is empty right now" << endl;
        return 0;
    }
    int elements = 0;
    int maxPosX = 0;
    int maxPosY = 0;
    Node* current = start;
    while (current != nullptr){
        //the program found a digit no 0
        elements = elements + 1;
        if(current -> getX() > maxPosX){
            maxPosX = current -> getX();
        }
        if(current -> getY() > maxPosY){
            maxPosY = current -> getY();
        }
        current = current -> getNext();
    }

    int allPossibleCases = (maxPosX + 1) * (maxPosY + 1);
    float density = (1.0 * elements)/allPossibleCases; 
    //Here I got a bit of help and some info about how C++ works. I read that when you do a division, C++ automatically converts the result into
    //an integer. For example,
    //1/9 = 0.111111 → but C++ will just give you 0.
    //So I multiplied one of the numbers by 1.0 to avoid that and get the real percentage
    int porcentage = density * 100;

    return porcentage;
}
SparseMatrix* SparseMatrix::multiply(SparseMatrix* secondMatrix){
    




    return nullptr;
}
