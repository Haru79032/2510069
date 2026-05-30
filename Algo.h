#ifndef ALGO_H
#define ALGO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include "PathNode.h"
using namespace std;
namespace Algo{
    /*struct GraphNode{
        int n_name;
        double h_cost;
        double g_cost;
        double f_cost;
        vector<GraphNode*> neighbors; // vector of neighbor pointers
};*/
    //GraphNode* constructGraph(double adjMatrix[100][100]);
    PathNode* F_minInQueue(vector<PathNode*> vec);
    PathNode* findMatchinQueue(vector<PathNode*> vec, int match);
    PathNode* constructPath(PathNode* end);
    void buildWeightMatrix(int grid[100][100],int m,int n, double weightMatrix[100][100]);

    
    PathNode* findSocialPath(double adjMatrix[100][100], int startPerson, int goalPerson);
    PathNode* findDronePath(double weightMatrix[100][100], int coords[100][2],
    int start, int goal, int mode);
    PathNode* findWarehousePath(int warehouse[100][100], int m, int n, int startX,
    int startY, int goalX, int goalY, int mode);
    PathNode* findEvacuationPath(int floorPlan[100][100], int m, int n, int startX,
    int startY, int exitX, int exitY, double weightMatrix[100][100], int mode);
}
#endif