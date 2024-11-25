/*
    WEEK 07 - TASK 02: ARRAY OF STRUCT

    [1]. Create a list of students using struct. The user need define number of students by keyboard.
    [2]. Each student need have code, name, condition [0-scholarship; 1-contract], scores
         in calculus, physics and programming (scores between 0-100). 
    [3]. Print the list of students in ascendent alphabetic order
    [4]. Calculate the mean of scores for each student
    [5]. Sort and print the 3 best students of class in descendent order by highest mean of scores

    Definition of variables:
        - num_students: index which controls number of inserted students
        - n: total number of students
        - lst_student: array of students
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;

struct Student{
    int code;
    char name[50];
    bool status;
    double math;
    double physics;
    double programming;
    double mean_score;
};

// static variable index
static int num_students=0;

// functions defined by user
void define_num_students(int *n);
void insert_vect_students(int n, struct Student *lst_student);
void insert_student(struct Student *s);
void print_vec_student(int n, struct Student *lst_student);
void print_student(struct Student s);
void sort_by_name(int n, struct Student *lst_student);
void vec_mean_score(int n, struct Student *lst_student);
void calculate_mean_score(struct Student *s);
void sort_by_scores(int n, struct Student *lst_student);
void print_vec_scores(int n, struct Student *lst_student);

// main function
int main(){
    int n;
    struct Student *lst_student;
    
    // definition of variables
    define_num_students(&n);
    lst_student = new Student[n];

    // input students
    cout<<"\n***Insert students***"<<endl;
    insert_vect_students(n, lst_student);

    // print students    
    cout<<"\n***List of students***"<<endl;
    print_vec_student(n, lst_student);

    // sort in alphabetical order
    cout<<"\n***Alphabetical order of students***"<<endl;
    sort_by_name(n, lst_student);
    print_vec_student(n, lst_student);

    // calculate mean scores
    cout<<"\n***List of students with mean scores***"<<endl;
    vec_mean_score(n, lst_student);
    sort_by_scores(n, lst_student);
    print_vec_scores(n, lst_student);

    return 0;
}

// procedure to define total number of students
void define_num_students(int *n){
    do{
        cout<<"\nNumber of students: ";
        cin>> *n;
    }while(n<0);
}

// procedure to insert students in vector of struct
void insert_vect_students(int n, struct Student *lst_student){
    for(int i=0; i<n; i++){
        cout<<"Student "<<i<<endl;
        insert_student(&lst_student[i]);
    }
}

// procedure to insert 1 student
void insert_student(struct Student *s){
    s->code = num_students;
    cout<< "Name: ";
    cin>> s->name;
    cout<<"Status [0-scholarship; 1-contract]: ";
    cin>> s->status;
    cout<<"Score in math: ";
    cin>> s->math;
    cout<<"Score in physics: ";
    cin>> s->physics;
    cout<<"Score in programming: ";
    cin>> s->programming;
    num_students++;    
}

// procedure to print vector of students
void print_vec_student(int n, struct Student *lst_student){
    cout<<left;
    cout<<setw(10)<<"code"<<setw(10)<<"name"<<setw(15)<<"status"<<
        setw(10)<<"math"<<setw(10)<<"physics"<<setw(10)<<"programming"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;

    for(int i=0; i<n; i++){
        print_student(lst_student[i]);
    }
}

// procedure to print 1 student
void print_student(struct Student s){
    cout<<left;
    cout<<setw(10)<<s.code<<
          setw(10)<<s.name<<
          setw(15)<<(s.status == 0? "scholarship": "contract")<<
          setw(10)<<s.math<<
          setw(10)<<s.physics<<
          setw(10)<<s.programming<<endl;        
}

// procedure bubble-sort to order names alphabetically
void sort_by_name(int n, struct Student *lst_student){
    struct Student aux;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(lst_student[i].name, lst_student[j].name)>0){
                aux = lst_student[i];
                lst_student[i] = lst_student[j];
                lst_student[j] = aux;
            }
        }
    }
}

// procedure to calculate mean score in vector of students
void vec_mean_score(int n, struct Student *lst_student){
    for(int i=0; i<n; i++){
        calculate_mean_score(&lst_student[i]);
    }
}

// procedure to calculate mean score for 1 student
void calculate_mean_score(struct Student *s){
    s->mean_score = (s->math + s->physics + s->programming)/3.0;
}

// procedure bubble-sort to order students by highest scores
void sort_by_scores(int n, struct Student *lst_student){
    struct Student aux;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(lst_student[i].mean_score < lst_student[j].mean_score){
                aux = lst_student[i];
                lst_student[i] = lst_student[j];
                lst_student[j] = aux;
            }
        }
    }
}

// procedure to print 3 best students
void print_vec_scores(int n, struct Student *lst_student){
    cout<<left;
    cout<<setw(10)<<"code"<<setw(10)<<"name"<<setw(10)<<"mean_score"<<endl;
    cout<<"-----------------------------------"<<endl;    

    for(int i=0; i<3; i++){
        cout<<setw(10)<<lst_student[i].code<<
              setw(10)<<lst_student[i].name<<
              setw(10)<<lst_student[i].mean_score<<endl;        
    }
}
