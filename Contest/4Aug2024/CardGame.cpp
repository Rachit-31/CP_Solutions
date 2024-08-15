#include <iostream>
using namespace std;

int countWins(int a1, int a2, int b1, int b2) {
    
    pair<int, int> suneet_cards[] = {{a1, a2}, {a1, a2}, {a2, a1}, {a2, a1}};
    pair<int, int> slavic_cards[] = {{b1, b2}, {b2, b1}, {b1, b2}, {b2, b1}};
    
    int win_count = 0;
    
    for (int i = 0; i < 4; i++) {
        int suneet_wins = 0, slavic_wins = 0;
        
        // Round 1
        if (suneet_cards[i].first > slavic_cards[i].first) {
            suneet_wins++;
        } else if (suneet_cards[i].first < slavic_cards[i].first) {
            slavic_wins++;
        }
        
        // Round 2
        if (suneet_cards[i].second > slavic_cards[i].second) {
            suneet_wins++;
        } else if (suneet_cards[i].second < slavic_cards[i].second) {
            slavic_wins++;
        }
        
        // Check if Suneet wins more rounds
        if (suneet_wins > slavic_wins) {
            win_count++;
        }
    }
    
    return win_count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        cout << countWins(a1, a2, b1, b2) << endl;
    }
    
    return 0;
}