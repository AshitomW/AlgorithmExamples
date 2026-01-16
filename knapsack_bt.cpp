#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_profit = 0;

// The recursive
void findMaxLoot(int index, int current_weight, int current_profit, int W, const vector<int>& weights, const vector<int>& values) {
    // Base case: We've looked at all items
    if (index == weights.size()) {
        max_profit = max(max_profit, current_profit);
        return;
    }

    // Choice 1: I want it
    // Only if it doesn't break the bag (and our spirits)
    if (current_weight + weights[index] <= W) {
        findMaxLoot(index + 1, current_weight + weights[index], current_profit + values[index], W, weights, values);
    }

    // Choice 2: The "I'll pass this shit" path
    // We skip the item even if it fits, just to see what happens
    findMaxLoot(index + 1, current_weight, current_profit, W, weights, values);
}

int main() {
    // Weight capacity of our backpack
    int W = 10;
    
    // Items: {value, weight}
    // Item 0: $40, 2kg | Item 1: $30, 5kg | Item 2: $50, 10kg
    vector<int> values = {40, 30, 50};
    vector<int> weights = {2, 5, 10};

    findMaxLoot(0, 0, 0, W, weights, values);

    cout << "Maximum profit found by brute force: $" << max_profit << endl;

    return 0;
}
