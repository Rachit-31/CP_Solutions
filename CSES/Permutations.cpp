#include <bits/stdc++.h>

using namespace std;

// Function to construct a beautiful permutation
void permutation(int N)
{
    // Check if N is 2 or 3, as a beautiful permutation is
    // not possible for these cases
    if (N == 2 || N == 3) {
        cout << "NO SOLUTION\n";
        return;
    }

    // Output all even numbers first
    for (int i = 2; i <= N; i = i + 2) {
    
        // Print even numbers with a step of 2
        cout << i << " ";
    }

    // Output all odd numbers next
    for (int i = 1; i <= N; i = i + 2) {
    
        // Print odd numbers with a step of 2
        cout << i << " ";
    }
}

// Driver Code
int main()
{
    int N;
    cin>>N;
    // Call the permutation function with input N
    permutation(N);

    return 0;
}
