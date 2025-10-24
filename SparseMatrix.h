#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"


class SparseMatrix
{
private:
    Node* start;

public:
    SparseMatrix(); 

    void add(int value, int xPos, int yPos);
    int get(int xPos, int yPos);
    void remove(int xPos, int yPos);
    void printStoredValues();
    int density();
    SparseMatrix* multiply(SparseMatrix* second);

    ~SparseMatrix(); //destructor following requirement 1 
};

#endif