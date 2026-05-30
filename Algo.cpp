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
    void buildWeightMatrix(int grid[100][100],int m,int n, double weightMatrix[100][100]){
        for (int i=0;i<100;++i){
            for (int j=0;j<100;++j){
                weightMatrix[i][j]=0;
            }
        }
        for (int row=0;row<m;++row){
            for (int col=0;col<n;++col){
                if (!grid[row][col]) {continue;}
                for (int i=0; i<8;++i){
                    if (row+directions.dr[i][1] < 0 || row+directions.dr[i][1] >= m || col + directions.dr[i][0] < 0 || col + directions.dr[i][0] >= n )
                        continue;
                    if (grid[row+directions.dr[i][1]][col+directions.dr[i][0]]){
                        switch (i)
                        {
                        case 0:
                            if (!weightMatrix[row*n+col][(row-1)*n+col-1]){
                                weightMatrix[row*n+col][(row-1)*n+col-1]=1.5;
                                weightMatrix[(row-1)*n+col-1][row*n+col]=1.5;
                            }
                            break;
                        case 1:
                            if (!weightMatrix[row*n+col][(row-1)*n+col+1]){
                                weightMatrix[row*n+col][(row-1)*n+col+1]=1.5;
                                weightMatrix[(row-1)*n+col+1][row*n+col]=1.5;
                            }

                            break;
                        case 2:
                            if (!weightMatrix[row*n+col][(row+1)*n+col-1]){
                                weightMatrix[row*n+col][(row+1)*n+col-1]=1.5;
                                weightMatrix[(row+1)*n+col-1][row*n+col]=1.5;
                            }
                            break;
                        case 3:
                            if (!weightMatrix[row*n+col][(row+1)*n+col+1]){
                                weightMatrix[row*n+col][(row+1)*n+col+1]=1.5;
                                weightMatrix[(row+1)*n+col+1][row*n+col]=1.5;
                            }
                            break;
                        case 4:
                            if (!weightMatrix[row*n+col][(row-1)*n+col]){
                                weightMatrix[row*n+col][(row-1)*n+col]=1;
                                weightMatrix[(row-1)*n+col][row*n+col]=1;
                            }
                            break;
                        case 5:
                            if (!weightMatrix[row*n+col][row*n+col-1]){
                                weightMatrix[row*n+col][row*n+col-1]=1;
                                weightMatrix[row*n+col-1][row*n+col]=1;
                            }
                            break;
                        case 6:
                            if (!weightMatrix[row*n+col][row*n+col+1]){
                                weightMatrix[row*n+col][row*n+col+1]=1;
                                weightMatrix[row*n+col+1][row*n+col]=1;
                            }
                            break;
                        case 7:
                            if (!weightMatrix[row*n+col][(row+1)*n+col]){
                                weightMatrix[row*n+col][(row+1)*n+col]=1;
                                weightMatrix[(row+1)*n+col][row*n+col]=1;
                            }
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }


        
    PathNode* findSocialPath(double adjMatrix[100][100], int startPerson, int goalPerson){
        vector<bool> visited(100,false);
        vector<PathNode*> queue;
        vector<PathNode*> nodesCreated;

        PathNode* startPoint = new PathNode();
        startPoint->next=nullptr;
        startPoint->prev=nullptr;
        startPoint->name=to_string(startPerson);
        startPoint->id=startPerson;
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
            if (current->id==goalPerson){
                return constructPath(current);
            }
            // If goal is not reached, marked this vertex as visited
            queue.erase(remove(queue.begin(), queue.end(), current), queue.end());
            visited[current->id]=true;

            for (int neighbor=0; neighbor<100; ++neighbor){
                if (adjMatrix[current->id][neighbor] > 0){
                    if (visited[neighbor]) continue;

                    double nextg=current->g+1;

                    PathNode* neighborNode = findMatchinQueue(queue, neighbor);

                    if (neighborNode==nullptr){
                        neighborNode=new PathNode;
                        neighborNode->name=to_string(neighbor);
                        neighborNode->id=neighbor;
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
        start->id=startPoint;
        start->g=0.0;
        start->h=Mah_Euc_Chev_heu(coords, startPoint, goalPoint, mode);
        start->f=start->g+start->h;

        PathNode* current;
        queue.push_back(start);
        nodesCreated.push_back(start);
        while (!queue.empty()){
            current = F_minInQueue(queue);
            if (current->id == goalPoint){
                return constructPath(current);
            }

            queue.erase(remove(queue.begin(), queue.end(), current), queue.end());
            visited[current->id]=true;

            for (int neighbors=0; neighbors<100; ++neighbors){
                if (weightMatrix[current->id][neighbors]){
                    if (visited[neighbors]) {continue;}

                    double nextG=current->g + weightMatrix[current->id][neighbors];

                    PathNode* neighborNode = findMatchinQueue(queue, neighbors);
                    if (neighborNode==nullptr){
                        neighborNode=new PathNode;
                        neighborNode->name=to_string(neighbors);
                        neighborNode->id=neighbors;
                        neighborNode->h=Mah_Euc_Chev_heu(coords, neighbors, goalPoint, mode);
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
    PathNode* findEvacuationPath(int floorPlan[100][100], int m, int n, int startX,
    int startY, int exitX, int exitY, double weightMatrix[100][100], int mode){
        int startPoint=startX*m+startY;
        int goalPoint=exitX*m+exitY;
        buildWeightMatrix(floorPlan, m, n, weightMatrix);
        vector<bool> visited(100,false);
        vector<PathNode*> queue;
        vector<PathNode*> nodesCreated;

        PathNode* start = new PathNode();
        start->next=nullptr;
        start->prev=nullptr;
        start->name="("+to_string(startX)+","+to_string(startY)+")";
        start->id=startPoint;
        start->g=0.0;
        start->h=Mah_Chev_heu(startX, startY, exitX, exitY, mode);
        start->f=start->g+start->h;

        PathNode* current;
        queue.push_back(start);
        nodesCreated.push_back(start);
        while (!queue.empty()){
            current = F_minInQueue(queue);
            cout << "Currently at node: " << current->id << "\n";
            if (current->id == goalPoint){
                return constructPath(current);
            }

            queue.erase(remove(queue.begin(), queue.end(), current), queue.end());
            visited[current->id]=true;

            for (int neighbors=0; neighbors<100; ++neighbors){
                if (weightMatrix[current->id][neighbors]){
                    if (visited[neighbors]) {continue;}

                    int neighborX=neighbors/n;
                    int neighborY=neighbors-neighborX*n;
                    double nextG=current->g + weightMatrix[current->id][neighbors];

                    PathNode* neighborNode = findMatchinQueue(queue, neighbors);
                    if (neighborNode==nullptr){
                        neighborNode=new PathNode;
                        neighborNode->name="("+to_string(neighborX)+","+to_string(neighborY)+")";
                        neighborNode->id=neighbors;
                        neighborNode->h=Mah_Chev_heu(neighborX,neighborY , exitX, exitY, mode);
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