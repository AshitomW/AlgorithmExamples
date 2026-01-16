#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end;
};

// Telling C++ how to compare these two based on who finishes their shift first
bool compareActivities(Activity a, Activity b) {
    return a.end < b.end;
}

void solveActivities(vector<Activity>& acts) {
    // Sort them so the early finishers go first
    sort(acts.begin(), acts.end(), compareActivities);

    cout << "The chosen ones: " << endl;

    // The first one is a freebie because it finishes so fast
    int last_finish_time = acts[0].end;
    cout << "(" << acts[0].start << ", " << acts[0].end << ")" << endl;

    // Checking the rest to see who isn't a scheduling nightmare
    for (int i = 1; i < acts.size(); i++) {
        // If they start after the last guy finished, they're invited
        if (acts[i].start >= last_finish_time) {
            cout << "(" << acts[i].start << ", " << acts[i].end << ")" << endl;
            last_finish_time = acts[i].end; // They're the new benchmark
        }
    }
}

int main() {
    // A bunch of people fighting for the same conference room
    vector<Activity> acts = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}};

    solveActivities(acts);

    return 0;
}
