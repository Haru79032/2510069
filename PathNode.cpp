#include "PathNode.h"

void printPath(PathNode* start){
    PathNode* ite=start;
    while (ite!=nullptr){
        cout << ite->name << ' ';
        ite=ite->next;
    }
}

double heuristicalBFS(double adjMatrix[100][100], int startPoint, int endPoint){
    if (startPoint==endPoint) return 0.0;
    vector<bool> visited(100,false);
    vector<pair<int, int>> queue;
    queue.push_back({startPoint,0});
    visited[startPoint]=true;
    int queueIdx=0;
    while (queueIdx < queue.size()){
        int current=queue[queueIdx].first;
        int dist = queue[queueIdx].second;
        ++queueIdx;
        if (current==endPoint) {return (double)dist;}
        for (int neighbors=0; neighbors<100; ++neighbors){            //check each neighbor
            if (adjMatrix[current][neighbors] > 0 && !visited[neighbors]){     //if linked and not visited
                queue.push_back({neighbors,dist+1});
                visited[neighbors]=true;
            }
        }
    }
    return 0.0; // no path found
}
double Mah_Euc_Chev_heu(double adjMatrix[100][100], int coords[100][2], int startPoint, int endPoint, int mode){
    if (mode==1){
        return abs(coords[startPoint][0]-coords[endPoint][0]) + abs(coords[startPoint][1]-coords[endPoint][1]);
    }else if (mode==2){
        return sqrt(pow(coords[startPoint][0]-coords[endPoint][0],2)+pow(coords[startPoint][1]-coords[endPoint][1],2));
    }else if (mode==3){
        return max(abs(coords[startPoint][0]-coords[endPoint][0]),abs(coords[startPoint][1]-coords[endPoint][1]));
    }else return -1;
}