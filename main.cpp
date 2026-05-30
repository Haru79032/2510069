#include "Algo.h"
using namespace Algo;

// void printDetailedPath(PathNode* head) {
//     cout << "\nSolution Path:\n";
//     int count = 0;
//     while (head != nullptr) {
//         cout << "Step " << count++ << ": Node " << head->name
//              << " | f=" << head->f
//              << " | g=" << head->g
//              << " | h=" << head->h << "\n";
//         head = head->next;
//     }
// }

// void printAdjMatrix(double matrix[100][100], int n) {
//     cout << "\nAdjacency Matrix (" << n << "x" << n << "):\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (matrix[i][j] > 0) cout << "1 ";
//             else cout << "0 ";
//         }
//         cout << "\n";
//     }
// }

// void printCoords(int coords[100][2], int n) {
//     cout << "\nCoordinates:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Point " << i << ": (" << coords[i][0] << ", " << coords[i][1] << ")\n";
//     }
// }

// // ============================================================================
// //                         TASK 1: SOCIAL NETWORK TESTS
// // ============================================================================

// void test1_linear_path() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 1.1: Linear Path (0-1-2-3-4)                       ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test1[100][100] = {0};
//     test1[0][1] = 1; test1[1][0] = 1;
//     test1[1][2] = 1; test1[2][1] = 1;
//     test1[2][3] = 1; test1[3][2] = 1;
//     test1[3][4] = 1; test1[4][3] = 1;
    
//     printAdjMatrix(test1, 5);
//     cout << "\nStart: 0, Goal: 4\n";
//     cout << "Expected Path: 0 → 1 → 2 → 3 → 4\n";
    
//     PathNode* result = findSocialPath(test1, 0, 4);
//     printDetailedPath(result);
// }

// void test1_multiple_paths() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 1.2: Multiple Paths (Diamond Shape)                ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test2[100][100] = {0};
//     //     1
//     //   /   \
//     //  0     3
//     //   \   /
//     //     2
//     test2[0][1] = 1; test2[1][0] = 1;
//     test2[0][2] = 1; test2[2][0] = 1;
//     test2[1][3] = 1; test2[3][1] = 1;
//     test2[2][3] = 1; test2[3][2] = 1;
    
//     printAdjMatrix(test2, 4);
//     cout << "\nStart: 0, Goal: 3\n";
//     cout << "Expected: Path length = 2 (either 0→1→3 or 0→2→3)\n";
    
//     PathNode* result = findSocialPath(test2, 0, 3);
//     printDetailedPath(result);
// }

// void test1_direct_connection() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 1.3: Direct Connection (1-hop)                     ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test3[100][100] = {0};
//     test3[0][1] = 1; test3[1][0] = 1;
//     test3[1][2] = 1; test3[2][1] = 1;
    
//     printAdjMatrix(test3, 3);
//     cout << "\nStart: 0, Goal: 1\n";
//     cout << "Expected: Path length = 1 (0→1)\n";
    
//     PathNode* result = findSocialPath(test3, 0, 1);
//     printDetailedPath(result);
// }

// void test1_same_node() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 1.4: Start = Goal (Edge Case)                      ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test4[100][100] = {0};
//     test4[0][1] = 1; test4[1][0] = 1;
    
//     cout << "\nStart: 0, Goal: 0\n";
//     cout << "Expected: Path with just node 0\n";
    
//     PathNode* result = findSocialPath(test4, 0, 0);
//     printDetailedPath(result);
// }

// void test1_complex_graph() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 1.5: Complex Graph                                  ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test5[100][100] = {0};
//     //     1---2
//     //    /     \
//     //   0       4---5
//     //    \     /
//     //     3---4
//     test5[0][1] = 1; test5[1][0] = 1;
//     test5[0][3] = 1; test5[3][0] = 1;
//     test5[1][2] = 1; test5[2][1] = 1;
//     test5[2][4] = 1; test5[4][2] = 1;
//     test5[3][4] = 1; test5[4][3] = 1;
//     test5[4][5] = 1; test5[5][4] = 1;
    
//     printAdjMatrix(test5, 6);
//     cout << "\nStart: 0, Goal: 5\n";
//     cout << "Expected: Path length = 3 (multiple optimal paths exist)\n";
    
//     PathNode* result = findSocialPath(test5, 0, 5);
//     printDetailedPath(result);
// }

// // ============================================================================
// //                         TASK 2: DRONE DELIVERY TESTS
// // ============================================================================

// void test2_linear_path() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 2.1: Linear Path with Equal Weights                ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test1[100][100] = {0};
//     int coords1[100][2] = {0};
    
//     // Points on a line: 0(0,0) - 1(1,0) - 2(2,0) - 3(3,0) - 4(4,0)
//     for (int i = 0; i < 5; i++) {
//         coords1[i][0] = i;
//         coords1[i][1] = 0;
//     }
    
//     // All edges cost 1
//     test1[0][1] = 1; test1[1][0] = 1;
//     test1[1][2] = 1; test1[2][1] = 1;
//     test1[2][3] = 1; test1[3][2] = 1;
//     test1[3][4] = 1; test1[4][3] = 1;
    
//     printCoords(coords1, 5);
//     cout << "\nStart: 0, Goal: 4, Mode: 1 (Manhattan)\n";
//     cout << "Expected Cost: 4\n";
    
//     PathNode* result = findDronePath(test1, coords1, 0, 4, 1);
//     printDetailedPath(result);
// }

// void test2_multiple_paths() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 2.2: Multiple Paths (Different Weights)            ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test2[100][100] = {0};
//     int coords2[100][2] = {0};
    
//     // Diamond shape with weighted edges
//     coords2[0][0] = 0; coords2[0][1] = 0;
//     coords2[1][0] = 0; coords2[1][1] = 1;
//     coords2[2][0] = 0; coords2[2][1] = -1;
//     coords2[3][0] = 2; coords2[3][1] = 0;
    
//     // Path 1: 0→1→3 (weights: 1 + 2 = 3)
//     test2[0][1] = 1; test2[1][0] = 1;
//     test2[1][3] = 2; test2[3][1] = 2;
    
//     // Path 2: 0→2→3 (weights: 2 + 1 = 3)
//     test2[0][2] = 2; test2[2][0] = 2;
//     test2[2][3] = 1; test2[3][2] = 1;
    
//     printCoords(coords2, 4);
//     cout << "\nStart: 0, Goal: 3, Mode: 1 (Manhattan)\n";
//     cout << "Expected: Both paths have same cost = 3\n";
    
//     PathNode* result = findDronePath(test2, coords2, 0, 3, 1);
//     printDetailedPath(result);
// }

// void test2_three_heuristics() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 2.3: Compare Three Heuristics                      ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test3[100][100] = {0};
//     int coords3[100][2] = {0};
    
//     // 4 points in a square
//     coords3[0][0] = 0; coords3[0][1] = 0;
//     coords3[1][0] = 2; coords3[1][1] = 0;
//     coords3[2][0] = 0; coords3[2][1] = 2;
//     coords3[3][0] = 2; coords3[3][1] = 2;
    
//     // All edges cost 1
//     test3[0][1] = 1; test3[1][0] = 1;
//     test3[0][2] = 1; test3[2][0] = 1;
//     test3[1][3] = 1; test3[3][1] = 1;
//     test3[2][3] = 1; test3[3][2] = 1;
//     // Diagonal shortcut
//     test3[0][3] = 1.5; test3[3][0] = 1.5;
    
//     printCoords(coords3, 4);
//     cout << "\nStart: 0, Goal: 3\n";
//     cout << "Three heuristic modes to compare:\n";
    
//     cout << "\n--- MODE 1: Manhattan ---\n";
//     PathNode* result1 = findDronePath(test3, coords3, 0, 3, 1);
//     printDetailedPath(result1);
    
//     cout << "\n--- MODE 2: Euclidean ---\n";
//     PathNode* result2 = findDronePath(test3, coords3, 0, 3, 2);
//     printDetailedPath(result2);
    
//     cout << "\n--- MODE 3: Chebyshev ---\n";
//     PathNode* result3 = findDronePath(test3, coords3, 0, 3, 3);
//     printDetailedPath(result3);
// }

// void test2_3x3_grid() {
//     cout << "\n╔════════════════════════════════════════════════════════════╗\n";
//     cout << "║  TASK 2.4: 3x3 Grid Network                              ║\n";
//     cout << "╚════════════════════════════════════════════════════════════╝\n";
    
//     double test4[100][100] = {0};
//     int coords4[100][2] = {0};
    
//     // 3x3 grid
//     int idx = 0;
//     for (int y = 0; y < 3; y++) {
//         for (int x = 0; x < 3; x++) {
//             coords4[idx][0] = x;
//             coords4[idx][1] = y;
//             idx++;
//         }
//     }
    
//     // Connect horizontally and vertically (cost 1)
//     test4[0][1] = 1; test4[1][0] = 1;
//     test4[1][2] = 1; test4[2][1] = 1;
//     test4[3][4] = 1; test4[4][3] = 1;
//     test4[4][5] = 1; test4[5][4] = 1;
//     test4[6][7] = 1; test4[7][6] = 1;
//     test4[7][8] = 1; test4[8][7] = 1;
    
//     // Vertical connections (cost 1)
//     test4[0][3] = 1; test4[3][0] = 1;
//     test4[1][4] = 1; test4[4][1] = 1;
//     test4[2][5] = 1; test4[5][2] = 1;
//     test4[3][6] = 1; test4[6][3] = 1;
//     test4[4][7] = 1; test4[7][4] = 1;
//     test4[5][8] = 1; test4[8][5] = 1;
    
//     printCoords(coords4, 9);
//     cout << "\nStart: 0 (0,0), Goal: 8 (2,2), Mode: 2 (Euclidean)\n";
//     cout << "Expected: Shortest path length = 4 (2 right, 2 down)\n";
    
//     PathNode* result = findDronePath(test4, coords4, 0, 8, 2);
//     printDetailedPath(result);
// }
void printMatrix(double matrix[100][100],int m, int n){
    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
//     cout << "\n" << string(60, '=') << "\n";
//     cout << "          A* PATHFINDING ALGORITHM TEST SUITE\n";
//     cout << string(60, '=') << "\n";
    
//     // TASK 1 TESTS
//     cout << "\n" << string(60, '=') << "\n";
//     cout << "                    TASK 1: SOCIAL NETWORK\n";
//     cout << string(60, '=') << "\n";
    
//     test1_linear_path();
//     test1_multiple_paths();
//     test1_direct_connection();
//     test1_same_node();
//     test1_complex_graph();
    
//     // TASK 2 TESTS
//     cout << "\n" << string(60, '=') << "\n";
//     cout << "                  TASK 2: DRONE DELIVERY\n";
//     cout << string(60, '=') << "\n";
    
//     test2_linear_path();
//     test2_multiple_paths();
//     test2_three_heuristics();
//     test2_3x3_grid();
    
//     cout << "\n" << string(60, '=') << "\n";
//     cout << "                   ALL TESTS COMPLETED!\n";
//     cout << string(60, '=') << "\n\n";
    
//     return 0;
    int grid[100][100] = {
    {1,1,1,0,1},
    {1,1,0,1,1},
    {0,1,0,1,1}
};
    double weightedMatrix[100][100];
    buildWeightMatrix(grid, 3, 3, weightedMatrix);
    printMatrix(weightedMatrix,15,15);
    PathNode* path=nullptr;
    path=findEvacuationPath(grid,3,5,0,0,2,4,weightedMatrix,1);
    printPath(path);
}