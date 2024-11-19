/*
    WEEK 07 - TASK 01: BASIC OPERATIONS WITH STRUCT

    [1]. Create struct to contain a vector in tridimensional space coordinates (X, Y, Z)
    [2]. Input 2 vectors v1, v2 with their respectively components for each dimension
    [3]. Calculate the next linear combination operation: 
         v = 2*v1 + 3*v2
    [4]. Calculate the scalar product between 2 vectors
    [5]. Calculate the vector product between 2 vectors
    [6]. Calculate the module for each vector
    [7]. Calculate the unit vectors
    [8]. Calculate the euclidean and manhattan distances between 2 vectors

    Definition of variables:
        - v1, v2: instances of 3D vector structs
        - vres: struct vector result of linear combination
        - scal_prod: numeric result of scalar product
        - vect_prod: struct vector result of vector product
        - unit_vec1, unit_vec2: struct unit vectors for v1 and v2 respectively
        - e_dist: numeric result of euclidean distance
        - m_dist: numeric result of manhattan distance
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Vector{
    double x;
    double y;
    double z;
};

// functions defined by user
struct Vector create_vector();
void print_vector(struct Vector v);
struct Vector calculate_linear_comb(struct Vector v1, struct Vector v2);
double scalar_product(struct Vector v1, struct Vector v2);
struct Vector vector_product(struct Vector v1, struct Vector v2);
double calculate_module(struct Vector v);
struct Vector get_unit_vector(struct Vector v);
double euclidean_dist(struct Vector v1, struct Vector v2);
double manhattan_dist(struct Vector v1, struct Vector v2);

// main function
int main(){
    struct Vector v1, v2, vres, vect_prod, unit_vec1, unit_vec2;
    double scal_prod, e_dist, m_dist;

    // input the vectors
    cout<<"\nInput vector v1: "<<endl;
    v1 = create_vector();
    cout<<"\nInput vector v2: "<<endl;
    v2 = create_vector();

    // print vector components
    cout<<"\nList of vectors: "<<endl;
    cout<<"\nv1 = ";
    print_vector(v1);
    cout<<"\nv2 = ";
    print_vector(v2);

    // calculate linear combination
    cout<<"\nCalculate v = 2*v1 + 3*v2"<<endl;
    vres = calculate_linear_comb(v1, v2);
    cout<<"\nv = ";
    print_vector(vres);

    // calculate scalar product
    scal_prod = scalar_product(v1, v2);
    cout<<"\nScalar product = "<<scal_prod<<endl;

    // calculate vector product
    vect_prod = vector_product(v1, v2);
    cout<<"\nVector product v = ";
    print_vector(vect_prod);

    // calculate module of vectors 
    cout<<"\nModule v1 = "<<calculate_module(v1);
    cout<<"\nModule v2 = "<<calculate_module(v2);

    // calculate the unit vectors
    unit_vec1 = get_unit_vector(v1);
    cout<<"\nUnit vector vu1 = ";
    print_vector(unit_vec1);

    unit_vec2 = get_unit_vector(v2);
    cout<<"\nUnit vector vu2 = ";
    print_vector(unit_vec2);

    // calculate euclidean distance
    e_dist = euclidean_dist(v1, v2);
    cout<<"\nEuclidean distance = "<<e_dist;

    // calculate manhattan distance
    m_dist = manhattan_dist(v1, v2);
    cout<<"\nManhattan distance = "<<m_dist<<endl;

    return 0;
}

// function to create struct Vector
struct Vector create_vector(){
    struct Vector v;

    cout<<"\nX: ";
    cin>> v.x;
    cout<<"Y: ";
    cin>>v.y;
    cout<<"Z: ";
    cin>> v.z;

    return v;
}

// procedure to print struct Vector
void print_vector(struct Vector v){
    cout<<v.x<<"i "<<" + "<<v.y<<"j + "<<v.z<<"k";
}

// function to calculate linear combination
struct Vector calculate_linear_comb(struct Vector v1, struct Vector v2){
    struct Vector result;

    result.x = 2*(v1.x) + 3*(v2.x);
    result.y = 2*(v1.y) + 3*(v2.y);
    result.z = 2*(v1.z) + 3*(v2.z);

    return result;
}

// function to calculate scalar product
double scalar_product(struct Vector v1, struct Vector v2){
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

// function to calculate vectorial product
struct Vector vector_product(struct Vector v1, struct Vector v2){
    struct Vector result;

    result.x = (v1.y * v2.z) - (v2.y * v1.z);
    result.y = -((v1.x * v2.z) - (v2.x * v1.z));
    result.z = (v1.x * v2.y) - (v2.x * v1.y);

    return result;
}

// function to calculate module of vector
double calculate_module(struct Vector v){
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

// function to obtain the unitary vector
struct Vector get_unit_vector(struct Vector v){
    struct Vector u;
    double mod;

    mod = calculate_module(v);
    u.x = v.x/mod;
    u.y = v.y/mod;
    u.z = v.z/mod;

    return u;
}

// function to calculate euclidean distance
double euclidean_dist(struct Vector v1, struct Vector v2){
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
}

// function to calculate manhattan distance
double manhattan_dist(struct Vector v1, struct Vector v2){
    return fabs(v1.x - v2.x) + fabs(v1.y - v2.y) + fabs(v1.z - v2.z);
}
