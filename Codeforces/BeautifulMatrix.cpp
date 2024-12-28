/*------------------------------------
You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one. Let's index the matrix rows by numbers from 1 to 5 from top to bottom, let's index the matrix columns by numbers from 1 to 5 from left to right. In one move, you are allowed to apply one of the two following transformations to the matrix:

    Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for some integer i (1 ≤ i < 5).
    Swap two neighboring matrix columns, that is, columns with indexes j and j + 1 for some integer j (1 ≤ j < 5). 

You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell that is on the intersection of the third row and the third column). Count the minimum number of moves needed to make the matrix beautiful.
Input

The input consists of five lines, each line contains five integers: the j-th integer in the i-th line of the input represents the element of the matrix that is located on the intersection of the i-th row and the j-th column. It is guaranteed that the matrix consists of 24 zeroes and a single number one.
Output

Print a single integer — the minimum number of moves needed to make the matrix beautiful.
-----------------------------------------*/


#include <bits/stdc++.h>
using namespace std;

// Function to find the coordinate of the element '1'
pair<int, int> findCoordinate(vector<vector<int>>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1); 
}

// Function to check if the move is possible
bool isPossible(int newx, int newy, vector<vector<bool>>& vis, int n) {
    return (newx >= 0 && newx < n && newy >= 0 && newy < n && !vis[newx][newy]);
}

// Recursive function to solve the problem
void solve(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& arr, int cnt, int& ans, int targetx, int targety, int n) {
    // Base condition
    if (x == targetx && y == targety) {
        ans = min(ans, cnt);
        return;
    }

    vis[x][y] = true;  // Mark the cell as visited

    // Moving col-wise and row-wise
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (isPossible(newx, newy, vis, n)) {
            solve(newx, newy, vis, arr, cnt + 1, ans, targetx, targety, n);
        }
    }

    vis[x][y] = false;  // Unmark the cell for backtracking
}

// Function to find the minimum path
int minPath(vector<vector<int>>& arr, int n) {
    pair<int, int> coord = findCoordinate(arr);
    int x = coord.first;
    int y = coord.second;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    int ans = INT_MAX;
    int cnt = 0;
    int targetx = 2, targety = 2;
    solve(x, y, visited, arr, cnt, ans, targetx, targety, n);

    return ans;
}

int main() {
    vector<vector<int>> nums(5, vector<int>(5));  // Initialize the vector with size 5x5

    // Input handling
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> nums[i][j];
        }
    }

    int n = 5;
    int ans = minPath(nums, n);

    cout << ans << endl;

    return 0;
}