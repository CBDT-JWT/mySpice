#include "matrix.h"
MATRIX::MATRIX(double**p, int r, int c):rows(r),cols(c){
    if (p==nullptr) {//have to new a matrix
        this->ptr=new double*[r];
        for(int i=0;i<r;i++){
            ptr[i]=new double[c];
        }
    }
    else this->ptr=p;
}
MATRIX::~MATRIX(){
    for(int i=0;i<rows;i++){
            delete[] ptr[i];   
        }
    delete[] ptr;
}
 MATRIX& MATRIX::operator* (MATRIX& RIGHTMATRIX){
    if(cols!=RIGHTMATRIX.cols){
        exit(1);
    }
    double** result;
    result = new double*[rows];
    for(int i=0;i<rows;i++){
        result[i]=new double[RIGHTMATRIX.cols];
    }
    //TODO: mat mult function

}
void test(){
    std::cout<<"666"<<std::endl;
}