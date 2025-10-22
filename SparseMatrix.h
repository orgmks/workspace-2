#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

class SparseMatrix
{
private:
    Node* start;

public:
    SparseMatrix(); //empty method

    void add(int value, int xPos, int yPos);
    int get(int xPos, int yPos);
    void remove(int xPos, int yPos);
    void printStoredValues();
    int density();
    SparseMatrix* multiply(SparseMatrix* second);

    ~SparseMatrix(); //destructor
};
#endif