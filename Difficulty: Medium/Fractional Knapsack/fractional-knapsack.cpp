//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort by value-to-weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items;

        for (int i = 0; i < n; i++) {
            items.push_back(Item(val[i], wt[i]));
        }

        // Sort items by value/weight ratio
        sort(items.begin(), items.end(), cmp);

        double profit = 0.0;
        int i = 0;

        while (capacity > 0 && i < n) {
            if (capacity >= items[i].weight) {
                profit += items[i].value;
                capacity -= items[i].weight;
            } else {
                double temp = (double)items[i].value / items[i].weight;
                profit += temp * capacity;
                capacity = 0;
            }
            i++;
        }

        return profit;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends