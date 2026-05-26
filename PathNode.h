#ifndef PATHNODE_H
#define PATHNODE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct PathNode{
    string name;
    double f; // f(n) = g(n) + h(n)
    double g; // g(n) cost from start to current
    double h; // h(n) heuristic cost from current to goal
    PathNode* next=nullptr; //next node in the solution path
    PathNode* prev=nullptr; //prev node in the solution path
};


template <typename T>
void printVector(vector<T> vec){
    for (const auto&a : vec){
        cout << a << " ";
    }
    cout << '\n';
}
void printPath(PathNode* start);


// double heuristic(double adjMatrix[100][100], int start, int goal, int mode=1);
double heuristicalBFS(double adjMatrix[100][100], int startPoint, int endPoint); //heuristic value on non-weighted, non-directive graph
double Mah_Euc_Chev_heu(double adjMatrix[100][100], int coords[100][2], int startPoint, int endPoint, int mode); //Three mode heuristic value, mode 1 for Mahattan, mode 2 for Euclidean, mode 3 for Chev

#endif