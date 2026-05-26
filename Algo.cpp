#include "Algo.h"
#include "PathNode.h"
namespace Algo{
    PathNode* F_minInQueue(vector<PathNode*> vec){
        double min=1e9;
        PathNode* res=nullptr;
        for (PathNode* p : vec){
            if (p->f < min){
                res=p;
                min=p->f;
            }
        }
        return res;
    }    
    PathNode* findMatchinQueue(vector<PathNode*> vec, int match){
        PathNode* res=nullptr;
        for (PathNode* p : vec){
            if (p->name == to_string(match)){
                res=p;
            }
        }
        return res;
    }
    PathNode* constructPath(PathNode* end){
        vector<PathNode*> pathReversing;
        PathNode* current=end;
        while (current!=nullptr){
            pathReversing.push_back(current);
            current=current->prev;
        }
        PathNode* head=nullptr;
        for (int i=0; i<(int)pathReversing.size(); ++i){
            PathNode* newNode = new PathNode;
            newNode->name=pathReversing[i]->name;
            newNode->f=pathReversing[i]->f;
            newNode->g=pathReversing[i]->g;
            newNode->h=pathReversing[i]->h;
            newNode->next=head;
            newNode->prev=nullptr;
            head=newNode;
        }
        return head;
    }
    
        
    PathNode* findSocialPath(double adjMatrix[100][100], int startPerson, int goalPerson){
        vector<bool> visited(100,false);
        vector<PathNode*> queue;
        vector<PathNode*> nodesCreated;

        PathNode* startPoint = new PathNode();
        startPoint->next=nullptr;
        startPoint->prev=nullptr;
        startPoint->name=to_string(startPerson);
        startPoint->g=0.0;
        startPoint->h=heuristicalBFS(adjMatrix ,startPerson, goalPerson);
        startPoint->f=startPoint->g+startPoint->h;

        PathNode* current;
        queue.push_back(startPoint);
        nodesCreated.push_back(startPoint);
        while (!queue.empty()){
            //Get the vertex with smallest f(n) (we are greedy)
            current=F_minInQueue(queue);
            //Check if we reached the goal
            if (current->name == to_string(goalPerson)){
                return constructPath(current);
            }
            // If goal is not reached, marked this vertex as visited
            queue.erase(remove(queue.begin(), queue.end(), current), queue.end());
            visited[stoi(current->name)]=true;

            for (int neighbor=0; neighbor<100; ++neighbor){
                if (adjMatrix[stoi(current->name)][neighbor] > 0){
                    if (visited[neighbor]) continue;

                    double nextg=current->g+1;

                    PathNode* neighborNode = findMatchinQueue(queue, neighbor);

                    if (neighborNode==nullptr){
                        neighborNode=new PathNode;
                        neighborNode->name=to_string(neighbor);
                        neighborNode->h=heuristicalBFS(adjMatrix,neighbor, goalPerson);
                        neighborNode->g=nextg;
                        neighborNode->f=neighborNode->g+neighborNode->h;
                        neighborNode->next=nullptr;
                        neighborNode->prev=current;

                        queue.push_back(neighborNode);
                        nodesCreated.push_back(neighborNode);
                    }else if (nextg < neighborNode->g){
                        neighborNode->g=nextg;
                        neighborNode->f=neighborNode->h+neighborNode->g;
                        neighborNode->prev=current;
                    }
                }
            }
        }
        cout << "No path found\n";
        return nullptr;
    }
    PathNode* findDronePath(double weightMatrix[100][100], int coords[100][2],
    int startPoint, int goalPoint, int mode){
        vector<bool> visited(100,false);
        vector<PathNode*> queue;
        vector<PathNode*> nodesCreated;

        PathNode* start = new PathNode();
        start->next=nullptr;
        start->prev=nullptr;
        start->name=to_string(startPoint);
        start->g=0.0;
        start->h=Mah_Euc_Chev_heu(weightMatrix, coords, startPoint, goalPoint, mode);
        start->f=start->g+start->h;

        PathNode* current;
        queue.push_back(start);
        nodesCreated.push_back(start);
        while (!queue.empty()){
            current = F_minInQueue(queue);
            if (current->name == to_string(goalPoint)){
                return constructPath(current);
            }

            queue.erase(remove(queue.begin(), queue.end(), current), queue.end());
            visited[stoi(current->name)]=true;

            for (int neighbors=0; neighbors<100; ++neighbors){
                if (weightMatrix[stoi(current->name)][neighbors]){
                    if (visited[neighbors]) {continue;}

                    double nextG=current->g + weightMatrix[stoi(current->name)][neighbors];

                    PathNode* neighborNode = findMatchinQueue(queue, neighbors);
                    if (neighborNode==nullptr){
                        neighborNode=new PathNode;
                        neighborNode->name=to_string(neighbors);
                        neighborNode->h=Mah_Euc_Chev_heu(weightMatrix, coords, neighbors, goalPoint, mode);
                        neighborNode->g=nextG;
                        neighborNode->f=neighborNode->g+neighborNode->h;
                        neighborNode->next=nullptr;
                        neighborNode->prev=current;

                        queue.push_back(neighborNode);
                        nodesCreated.push_back(neighborNode);
                    }else if (nextG < neighborNode->g){
                        neighborNode->g=nextG;
                        neighborNode->f=neighborNode->h+neighborNode->g;
                        neighborNode->prev=current;
                    }
                }
            }
        }
        cout << "No path found";
        return nullptr;
    }
}