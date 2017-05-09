#include <iostream>
#include <math.h>

using namespace std;

void swap_ref (float & x , float & y){

    double tem;
    tem=x;
    x=y;
    y=tem;

}

void swap_pun (int * x , int * y){
    double tem;
    tem = *x;
    *x=*y;
    *y=tem;

}

void swap_pp (int ** x , int ** y){
    int * tem=*x;
    *x=*y;
    *y=tem;

}

void fun_rec(int * x , int tam){

    if (tam == 1)
        return;
    int * may = x;
    for (int i = 1 ; i < tam ; i++){
        if (x[i] > *may )
            may = &(x[i]);

    }
    swap_pun(x,may);
    x++;

    fun_rec(x,tam-1);

}

float conv (char * p , int tam){

    float ret=0;
    bool coma=false;
    int tem = -1;
    char var[10]={'0','1','2','3','4','5','6','7','8','9'};
    for (int i = 0 ; i < tam ; i++){
        if (p[i] == ',')
            coma = true;
        if (coma == true){
            for(int j = 0; j<10;j++){
                if (var[j]==p[i]){
                    ret = ret + j*pow(10,tem);
                    tem = tem -1;
                }
            }
        }
        else{
            for(int j = 0; j<10;j++){
                if (var[j]==p[i])
                    ret = ret*10 + j;

            }
        }

    }
    return ret;
}

int main()
{
    /*for(int x = 0; x<4; x++){
        for(int y = 0; y<4; y++){
            cout<<y;
        }

    }*/
    char *val = "12,45";
    int tam = 5;
    cout<<conv(val,tam)<<endl;
    int val1[10]={0,1,2,3,4,5,6,7,8,9};

    fun_rec(val1,10);

    for(int i = 0 ; i<10 ; i++){
        cout<<val1[i]<<" , ";
    }


    return 0;
}
