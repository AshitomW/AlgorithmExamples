#include <iostream>
#include <vector>

class NQueensBacktracking {
    int n;
    int solutionCount;
    std::vector<int> board; // board[row] = col

public:
    NQueensBacktracking(int size) : n(size), solutionCount(0), board(size, -1) {}

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; ++i) {
            // Check same column
            if (board[i] == col) return false;
            
            // Check diagonals: if row diff == col diff, they are on a diagonal
            if (abs(i - row) == abs(board[i] - col)) return false;
        }
        return true;
    }

    void solve(int row) {
        if (row == n) {
            solutionCount++;
            printBoard();
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(row, col)) {
                // 1. Choose
                board[row] = col;

                // 2. Explore
                solve(row + 1);

                // 3. Backtrack (Un-choose)
                board[row] = -1; 
            }
        }
    }

    void printBoard() {
        std::cout << "Solution #" << solutionCount << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << (board[i] == j ? " Q " : " . ");
            }
            std::cout << "\n";
        }
        std::cout << "-----------------\n";
    }

    int getCount() { return solutionCount; }
};

int main() {
    int n = 4;     NQueensBacktracking solver(n);
    solver.solve(0);
    std::cout << "Total solutions found: " << solver.getCount() << std::endl;
    return 0;
}
