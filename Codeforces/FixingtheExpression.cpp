#include <iostream>
#include <vector>
#include <string>
using namespace std;

string fixExpression(string s) {
    char first = s[0], second = s[2], op = s[1];

   
    if ((op == '<' && first < second) ||
        (op == '=' && first == second) ||
        (op == '>' && first > second)) {
        return s; 
    }

    if (first < second) {
        s[1] = '<';
    } else if (first == second) {
        s[1] = '=';
    } else if (first > second) {
        s[1] = '>';
    }

    return s;
}

int main() {
    int t;
    cin >> t; 
    vector<string> results;

    while (t--) {
        string s;
        cin >> s;
        results.push_back(fixExpression(s));
    }

    for (const string& res : results) {
        cout << res << endl;
    }

    return 0;
}
