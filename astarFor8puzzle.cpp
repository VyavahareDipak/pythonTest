#include<bits/stdc++.h>
using namespace std;

// Define the 3x3 puzzle state
typedef vector<vector<int>> PuzzleState;

// class to represent a node in the search tree
class Node {
    public:
    PuzzleState state;
    int cost;
    int heuristic;
    Node* parent;

    Node(PuzzleState state, int cost, Node* parent) : state(state), cost(cost), parent(parent) {
        heuristic = calculateHeuristic(state);
    }

    // Function to calculate the Manhattan distance heuristic
    int calculateHeuristic( PuzzleState state) {
        int heuristic = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (state[i][j] != 0) {
                    int goalRow = (state[i][j] - 1) / 3;
                    int goalCol = (state[i][j] - 1) % 3;
                    heuristic += abs(i - goalRow) + abs(j - goalCol);
                }
            }
        }
        return heuristic;
    }

    // Function to check if two nodes have the same state
    bool operator==(const Node& other)  {
        return state == other.state;
    }
};

// Custom comparator for the priority queue

    auto CompareNode=[](Node* a, Node* b){
        return a->cost + a->heuristic > b->cost + b->heuristic;
    };


// Function to print the puzzle state
void printPuzzle(PuzzleState state) {
    for (auto row : state) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if the puzzle is solvable
bool isSolvable(const PuzzleState& state) {
    // Count inversions
    int inversions = 0;
    vector<int> flattened;
    for (auto row : state) {
        for (int cell : row) {
            if (cell != 0) flattened.push_back(cell);
        }
    }
    for (int i = 0; i < flattened.size(); ++i) {
        for (int j = i + 1; j < flattened.size(); ++j) {
            if (flattened[i] > flattened[j]) inversions++;
        }
    }
    // Check if the number of inversions is even
    return inversions % 2 == 0;
}

// Function to generate successor states
vector<PuzzleState> generateSuccessors(PuzzleState state) {
    vector<PuzzleState> successors;
    int zeroRow, zeroCol;
    // Find the location of the empty tile (0)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state[i][j] == 0) {
                zeroRow = i;
                zeroCol = j;
                break;
            }
        }
    }
    // Generate successors by swapping the empty tile with its neighbors
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto dir : directions) {
        int newRow = zeroRow + dir.first;
        int newCol = zeroCol + dir.second;
        if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
            PuzzleState successor = state;
            swap(successor[zeroRow][zeroCol], successor[newRow][newCol]);
            successors.push_back(successor);
        }
    }
    return successors;
}

// A* search algorithm
vector<PuzzleState> aStarSearch(PuzzleState initialState) {
    if (!isSolvable(initialState)) {
        cout << "The puzzle is not solvable." << endl;
        return {};
    }

    priority_queue<Node*, vector<Node*>, decltype(CompareNode)> openList(CompareNode);
    map<PuzzleState, int> costs;
    Node* initialNode = new Node(initialState, 0, NULL);
    openList.push(initialNode);

    while (!openList.empty()) {
        Node* currentNode = openList.top();
        openList.pop();

        if (currentNode->heuristic == 0) {
            // Found the goal state
            vector<PuzzleState> solution;
            while (currentNode != nullptr) {
                solution.push_back(currentNode->state);
                currentNode = currentNode->parent;
            }
            reverse(solution.begin(), solution.end());
            return solution;
        }

        vector<PuzzleState> successors = generateSuccessors(currentNode->state);
        for (const auto successor : successors) {
            int newCost = currentNode->cost + 1;
            if (costs.find(successor) == costs.end() || newCost < costs[successor]) {
                Node* newNode = new Node(successor, newCost, currentNode);
                costs[successor] = newCost;
                openList.push(newNode);
            }
        }
    }

    // If the open list is empty and the goal state is not found
    cout << "Goal state not found." << endl;
    return {};
}

int main() {
    // Example initial state
    PuzzleState initialState = {
        {1, 0, 3},
        {4, 2, 5},
        {6, 7, 8}
    };

    cout << "Initial State:" << endl;
    printPuzzle(initialState);

    vector<PuzzleState> solution = aStarSearch(initialState);
    if (!solution.empty()) {
        cout << "Solution:" << endl;
        for (const auto& state : solution) {
            printPuzzle(state);
        }
    }

    return 0;
}
