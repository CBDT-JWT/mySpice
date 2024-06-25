#define _matrix
#define MATRIX_SIZE_ERROR 1
#define MATRIX_DET_ERROR 2
double err_lim = 1e-5;
#include<iostream>

//MATRIX class for leanear algebra arithmatics
class MATRIX{
    protected:
    int cols, rows;
    double** ptr;

    public:
    MATRIX(int ,int, double**);
    MATRIX(MATRIX&,MATRIX&,MATRIX&,MATRIX&);//2*2 blocked matrix consturct
    MATRIX(const MATRIX&,const MATRIX&);//1*2 blocked matrix construct
    MATRIX();
    ~MATRIX();

    //basic arith
    MATRIX& operator *(MATRIX&);
    MATRIX& operator +(MATRIX&);
    
    double* solve(MATRIX&)const;
    MATRIX& transpose();
    //support functions
    void print();
    void swap_rows(int,int);
    int* get_size();
    double* operator[](int)const ;//return addr of indxth row
};
void test();