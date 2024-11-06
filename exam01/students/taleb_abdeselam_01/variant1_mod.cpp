#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

double function1(double x){
    double function_x;    

    if(x<=-1){
        function_x=-x+2;
    }else if(x>-1 && x<=3){
        function_x=pow(x,2)-1;
    }else {
        function_x=-2*x+2;
    }

    return  function_x;
}
    
float function2(int x){
    float exponatial;
    exponatial=1/(1+exp(-x));
    return exponatial;
}

double part_function_result(double &x){
    int result_function_x;
    float exponatial_function;

    result_function_x=function1(x);
    exponatial_function=function2(result_function_x);

    return exponatial_function;
} 
/// second task ;


double *input_vector_A(int &n){
    double *vectorA=new double[n];
     for (int i=0;i<n;i++){
        vectorA[i]=1+rand()%3;
    }
   
    return vectorA;
}
void print_vector(double *vec ,int n){
    for (int i=0;i<n;i++){
        cout<< vec[i];
    }
}
double *input_vector_b(int &n){
    double *vecotrB=new double [n];
    for (int i=0;i<n;i++){
        vecotrB[i]=100000+rand()%350000;
    }
    return vecotrB;
}

double    *input_vectorC(double *vector_A,double*vector_b,int n){
    double *vectorC=new double [n];
    double *employe;
    int salarie;
    int salarie_total;
    for (int i=0;i<n;i++){
     if(vector_A[i]==1){
      vectorC[i]=vector_b[i]+vector_b[i]*10/100;
     }
     else if(vector_A[i]==2){
        vectorC[i]=vector_b[i]-vector_b[i]*5/100;

     }
     else{
          vectorC[i]=vector_b[i]-vector_b[i]*2/100;

     }
     for (int i=0;i<n;i++)
{
    cout<<vectorC[i]<<endl ;
}
    }
  
    return vectorC;

}


int main(){
    
    double x;

    do{
        cout<<"enter value of x";
        cin>>x;
    }while(x<-10 || x>10);
    
    double result1;
    float  result2;
    double part_fun;
    result1=function1(x);
    result2=function2(x);
    part_fun=part_function_result(x);
    cout<<part_fun;
    cout<<endl;

// second part 
  int a=3;
  int n=5;
  

  double  *vec_a =nullptr ,*vec_b=nullptr;
  vec_a=input_vector_A(a);
  print_vector(vec_a,3);

  vec_b= input_vector_b(n);
  print_vector(vec_b,5);

 
 input_vectorC(vec_a,vec_b,n);

  



  delete[] vec_a;
  delete[] vec_b;
  


    return 0;
}


