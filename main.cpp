#include "Algo.h"
using namespace Algo;


int main(){
    cout << "\n╔════ TEST 5: Start = Goal ════╗\n";
    double test5[100][100] = {0};
    test5[0][1] = 1; test5[1][0] = 1;
    

    cout << "Start: 0, Goal: 0\n";
    cout << "Expected: Path with just node 0\n";
    
    PathNode* result5 = findSocialPath(test5, 0, 0);
    printPath(result5);
    
    return 0;
}