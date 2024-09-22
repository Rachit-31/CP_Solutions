#include <bits/stdc++.h>
using namespace std;

// function to generate all permutations of string S
set<string> solve(string S)
{
    int N = S.length();
    sort(S.begin(), S.end());

    // set to store all the unique permutations
    set<string> uniqueStrings;

    do {
        uniqueStrings.insert(S);
    } while (next_permutation(S.begin(), S.end()));
    return uniqueStrings;
}

int main()
{
    // Sample Input
    string S ;
    cin>>S;
    set<string> uniqueStrings = solve(S);

    cout << uniqueStrings.size() << "\n";
    for (string str : uniqueStrings) {
        cout << str << "\n";
    }
}
