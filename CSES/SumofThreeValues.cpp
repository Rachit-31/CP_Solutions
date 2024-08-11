// #include <bits/stdc++.h>
// using namespace std;

// bool findSum(vector<int> nums, long long x)
// {
//     sort(nums.begin(), nums.end());

//     int n = nums.size();
//     for (int i = 0; i < n - 2; i++)
//     {
//         long long target = x - nums[i];  
//         int left = i + 1;
//         int right = n - 1;

//         while (left < right)
//         {
//             long long currentSum = nums[left] + nums[right];  

//             if (currentSum == target)
//             {
//                 cout << i+1 << " " << left+1 << " " << right+1 << endl;
//                 return true;  
//             }
//             else if (currentSum < target)
//             {
//                 left++;
//             }
//             else
//             {
//                 right--;
//             }
//         }
//     }

//     return false;
// }

// int main()
// {
//     int n;
//     long long x;
//     cin >> n >> x;

//     vector<int> nums(n);
//     for (int i = 0; i < n; i++) 
//     {
//         cin >> nums[i];
//     }

//     if (!findSum(nums, x))
//     {
//         cout << "IMPOSSIBLE" << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define ll long long int

using namespace std;


void solve(vector<ll>& arr, ll X, ll N)
{
    
    vector<vector<ll> > vec(N, vector<ll>(2));
    for (int i = 0; i < N; i++) {
        vec[i][0] = arr[i];
        vec[i][1] = i + 1;
    }

    
    sort(vec.begin(), vec.end());

    // Iterate for all possible values of first element
    for (ll ptr1 = 0; ptr1 < N - 2; ptr1++) {
        // Maintain two pointers for the second and third
        // element
        ll ptr2 = ptr1 + 1;
        ll ptr3 = N - 1;

        while (ptr2 < ptr3) {
            ll currentSum = vec[ptr1][0] + vec[ptr2][0]
                            + vec[ptr3][0];

            // If current sum is equal to X, then we have
            // found a triplet whose sum = X
            if (currentSum == X) {
                cout << vec[ptr1][1] << " " << vec[ptr2][1]
                     << " " << vec[ptr3][1] << "\n";
                return;
            }
            // Decrease the currentSum by moving ptr3 to
            // ptr3 - 1
            else if (currentSum > X) {
                ptr3--;
            }
            // Increase the currentSum by moving ptr2 to
            // ptr2 + 1
            else if (currentSum < X) {
                ptr2++;
            }
        }
    }

    // If no triplet has sum = X, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE";
}

int main()
{
    // Sample Input
    ll N = 4, X = 8;
    vector<ll> arr = { 2, 7, 5, 1 };

    solve(arr, X, N);
    // your code goes here
    return 0;
}
