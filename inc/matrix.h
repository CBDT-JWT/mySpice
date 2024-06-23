#define _matrix
#include<iostream>
//MATRIX class for leanear algebra arithmatics
class MATRIX{
    protected:
    int cols, rows;
    double** ptr;

    public:
    MATRIX(double**,int ,int c);
    ~MATRIX();
    MATRIX& operator *(MATRIX&);
    MATRIX& operator +(MATRIX&);
    const double* operator[](int);//return addr of indxth row
    void inverse();
    MATRIX& solve(MATRIX&);
    const double determinent();
    MATRIX& transpose();
};
void test();