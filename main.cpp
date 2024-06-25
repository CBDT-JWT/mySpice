#include <stdio.h>
#include "matrix.cpp"
bool with_graph = false;
double time_step = 1e-13;
char MODE='D';
void print_help(){
    std::cout<<"\%\%\%Welcome to MySpice!\%\%\%"<<std::endl;
    
}
int main(int argc, char*argv[]){
    printf("Hello, from mySpice!\n");
    /*parse cmd input*/
    FILE* inputFile = nullptr;
    int iArg = 0;
    while(iArg<argc){
        if(argv[iArg][0]=='-'){
            switch (argv[iArg][1]){
                case 'h':
                    print_help();
                    return 0;
                    break;
                case 'f':
                    iArg++;
                    inputFile = fopen(argv[iArg],"r");
                    break;
                case 'g':
                    with_graph = true;
                    break;              
            }
        }
    }
    if(inputFile=nullptr) {
        std::cout<<"no input file!"<<std::endl;
    }
    /*parse file*/
    while(1){
        if(feof(inputFile)) break;
        char heading = fgetc(inputFile);
        switch(heading){
            case '#':
                fgets(nullptr,114514,inputFile);//skip a comment
                break;
            /*hyper-configs*/
            case '.':
                MODE=fgetc(inputFile);
                fscanf(inputFile, "%e" ,&err_lim);
                switch(MODE){
                    case 'd'://dc analysis
                        fscanf(inputFile, "%e" ,&err_lim);
                        break;
                    case 'a'://ac analysis
                        fscanf(inputFile, "%e %e", &err_lim,&time_step);
                        break;
                    case 'D'://DC scan
                        fscanf(inputFile, "%e" ,&err_lim);
                        break;
                    case 'A'://AC scan
                        //todo
                }
                break;
            /*add_conponents*/
            //todo
        } 
    }
    return 0;
}
