#include "matrix.h"
MATRIX::MATRIX(int r, int c,double**p=nullptr ):rows(r),cols(c){
    std::cout<<"matrix with"<<r<<','<<c<<std::endl;
    if (p==nullptr) {//have to new a matrix
        this->ptr=new double*[r];
        for(int i=0;i<r;i++){
            ptr[i]=new double[c];
        }
    }
    else this->ptr=p;
}
MATRIX::MATRIX(MATRIX&A11,MATRIX&A12,MATRIX&A21,MATRIX&A22){
    if(A11.rows!=A12.rows||A11.cols!=A21.cols||A22.rows!=A21.rows||A22.cols!=A12.cols){
        exit(MATRIX_SIZE_ERROR);
    }

    rows=A11.rows+A21.rows;
    cols=A11.cols+A12.cols;
    ptr=new double*[rows];
    for(int i=0;i<rows;i++){
        ptr[i]=new double[cols];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i<A11.rows){
                if(j<A11.cols)ptr[i][j]=A11[i][j];
                else ptr[i][j]=A12[i][j-A11.cols];
            }
            else{
                if(j<A21.cols)ptr[i][j]=A21[i-A11.rows][j];
                else ptr[i][j]=A22[i-A11.rows][j-A21.cols];
            }
        }
    }
}MATRIX::MATRIX(const MATRIX&A11,const MATRIX&A12){
    if(A11.rows!=A12.rows){
        exit(MATRIX_SIZE_ERROR);
    }

    rows=A11.rows;
    cols=A11.cols+A12.cols;
    ptr=new double*[rows];
    for(int i=0;i<rows;i++){
        ptr[i]=new double[cols];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
                if(j<A11.cols)ptr[i][j]=A11[i][j];
                else ptr[i][j]=A12[i][j-A11.cols];
        }
    }
}
MATRIX::~MATRIX(){
    for(int i=0;i<rows;i++){
            delete[] ptr[i];   
        }
    delete[] ptr;
}
MATRIX& MATRIX::operator* (MATRIX& RIGHTMATRIX){
    if(cols!=RIGHTMATRIX.cols){
        exit(MATRIX_SIZE_ERROR);
    }
    double** result;
    result = new double*[rows];
    for(int i=0;i<rows;i++){
        result[i]=new double[RIGHTMATRIX.cols];
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<RIGHTMATRIX.cols; j++){
            result[i][j]=0;
            for(int k=0; k<cols; k++){
                result[i][j]+=((*this)[i][k])*RIGHTMATRIX[k][j];
            }
        }
    }
    MATRIX* ret= new MATRIX(rows,RIGHTMATRIX.cols,result);
    return *ret;
}

double* MATRIX::operator[](int a)const{
    if(a>=rows)exit(MATRIX_SIZE_ERROR);
    return ptr[a];
}
void MATRIX::print(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            std::cout<<ptr[i][j]<<" \n"[j+1==cols];
        }
    }
}
void MATRIX::swap_rows(int i,int j){
    if(i>=rows||j>=rows) exit(MATRIX_SIZE_ERROR);
    double*tmp= ptr[i];
    ptr[i]=ptr[j];
    ptr[j]=tmp;
    return;
}
double* MATRIX::solve(MATRIX& b)const {
    if(b.cols!=1) exit(MATRIX_SIZE_ERROR);
    if(cols!=rows) exit(MATRIX_SIZE_ERROR);
    if(cols!=rows) exit(MATRIX_SIZE_ERROR);
    double* ret=new double[cols];
    MATRIX Ab(*this,b);
    /*simple Gauss-Jordon algorithm*/
    int curr_row=0;
    bool leagal=true;
    while(curr_row<rows){
        for(int i=curr_row;i<rows;i++){
            leagal=false;
            if (ptr[i][curr_row]> err_lim ||ptr[i][curr_row]<- err_lim){
                Ab.swap_rows(i,curr_row);
                leagal=true;
                break;
            }
        }
        
        if(leagal==false){
            exit(MATRIX_DET_ERROR);
        }
        double multiplier = 1.0/Ab[curr_row][curr_row];
        Ab[curr_row][curr_row]=1.0;
        for(int j=curr_row+1;j<=cols;j++){//'<=' beacuse there's a b vector on the right
            Ab[curr_row][j]*=multiplier;
        }
        for(int i=curr_row+1;i<rows;i++){    
            for(int j=curr_row+1;j<=rows;j++){
                Ab[i][j]-=Ab[i][curr_row]*Ab[curr_row][j];
            }
            Ab[i][curr_row]=0;
        }
        curr_row++;
    }
    
    curr_row=Ab.rows-1;
    while(curr_row>0){
        for(int i=0;i<curr_row;i++){
            Ab[i][Ab.cols-1]-=Ab[curr_row][Ab.cols-1]*Ab[i][curr_row];
        }
        curr_row--;
    }
    for(int i=0;i<rows;i++){
        ret[i]=Ab[i][Ab.cols-1];
    }
    return ret;
}
MATRIX& MATRIX::operator+(MATRIX & B){
    if(cols!=B.cols||rows!=B.rows) exit(MATRIX_SIZE_ERROR);
    MATRIX ret(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            ret[i][j]=ptr[i][j]+B[i][j];
        }
    }
    return ret;
}
MATRIX& MATRIX::transpose(){
    MATRIX ret(cols,rows,nullptr);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            ret[j][i]=ptr[i][j];
        }
    }
    return ret;
}
int* MATRIX::get_size(){//return size in {rows,cols}
    int* ret=new int[2];
    ret[0]=rows;
    ret[1]=cols;
    return ret;
}
void test(){
    std::cout<<"666"<<std::endl;
}