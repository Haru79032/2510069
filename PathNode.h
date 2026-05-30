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
    int id;
    double f; // f(n) = g(n) + h(n)
    double g; // g(n) cost from start to current
    double h; // h(n) heuristic cost from current to goal
    PathNode* next=nullptr; //next node in the solution path
    PathNode* prev=nullptr; //prev node in the solution path
};
struct dir{
    int dr[8][2]={{-1,-1},{1,-1},{-1,1},{1,1},{0,-1},{-1,0},{1,0},{0,1}};
    string name[8]={"Up-Left", "Up-Right", "Down-Left", "Down-Right", "Up", "Left", "Right", "Down"};
};
extern dir directions;

template <typename T>
void printVector(vector<T> vec);
void printPath(PathNode* start);


// double heuristic(double adjMatrix[100][100], int start, int goal, int mode=1);
double heuristicalBFS(double adjMatrix[100][100], int startPoint, int endPoint); //heuristic value on non-weighted, non-directive graph
double Mah_Euc_Chev_heu(int coords[100][2], int startPoint, int endPoint, int mode); //Three mode heuristic value, mode 1 for Mahattan, mode 2 for Euclidean, mode 3 for Chev
double Mah_Chev_heu(int startX, int startY, int endX, int endY, int mode); //Three mode heuristic value, mode 1 for Mahattan, mode 2 for Chev
#endif