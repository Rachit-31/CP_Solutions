#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int arraySize = 0;
    cin >> arraySize; 

    vector<int> inputArray(arraySize, 0);
    for (int i = 0; i < arraySize; ++i) {
        cin >> inputArray[i];
    }

    sort(inputArray.begin(), inputArray.end());

    
    if (inputArray.back() == inputArray.front()) {
        cout << "-1" << endl;
        return;
    }

    
    int partitionIndex = 0;
    while (inputArray[partitionIndex] == inputArray[0]) {
        ++partitionIndex;
    }

    cout << partitionIndex << " " << arraySize - partitionIndex << endl;

    
    for (int i = 0; i < partitionIndex; ++i) {
        cout << inputArray[i] << " ";
    }

    for (int i = partitionIndex; i < arraySize; ++i) {
        cout << inputArray[i] << " ";
    }
    cout << endl;
}

int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; ++i) {
        solve();
    }

    return 0;
}
