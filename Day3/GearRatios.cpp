#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


const int neighbors[][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                            {1,  -1}, {1, 0}, {1, 1},
                            {0,  -1}, {0, 1}};


bool isDigit(char c){
    return (c >= '0' && c <= '9');
     
}

int part1(const vector<string> engines){
    int sum = 0;  // Initialize the sum to accumulate the result.

    // Outer loop iterating over each row of the grid.
    for (int i = 0; i < engines.size(); ++i){
        int numStart = -1;  // Variable to track the starting position of a digit sequence.
        bool found = false;  // Flag to indicate if a neighboring non-digit character is found.

        // Inner loop iterating over each column of the current row.
        for (int j = 0; j < engines[i].length(); ++j){
            // Check if the current character is a digit.
            if (isDigit(engines[i][j])){
                // If numStart is -1, it means this is the start of a new digit sequence.
                if (numStart == -1){
                    numStart = j;
                }

                // If found is false, check for neighboring non-digit characters.
                if (!found){
                    // Iterate over predefined neighbors.
                    for (auto  n : neighbors){
                        // Calculate new coordinates based on the current position and neighbor offsets.
                        int x = i + n[0];
                        int y = j + n[1];

                        // Check if the new coordinates are within valid bounds for the grid.
                        if (x < 0 || x >= engines.size() || y < 0  || y >= engines[i].size()){
                            continue;
                        }

                        // Check if the character at the neighboring position is not a dot and not a digit.
                        if (engines[x][y] != '.' && !isDigit(engines[x][y])){
                            found = true;  // Set found to true if a neighboring non-digit character is found.
                            break;  // Break out of the loop, as one neighboring non-digit character is sufficient.
                        }
                    }
                }
            } else if (numStart != -1) {
                // If the current character is not a digit and numStart is not -1, it means the end of a digit sequence.
                if (found) {
                    // If a neighboring non-digit character was found, add the digit sequence to the sum.
                    sum += stoi(engines[i].substr(numStart, j - numStart));
                }
                found = false;  // Reset found flag.
                numStart = -1;  // Reset numStart, indicating no active digit sequence.
            }
        }

        // Check for an incomplete digit sequence at the end of the row.
        if (numStart !=  -1) {
            if (found){
                sum += stoi(engines[i].substr(numStart));
            }
        }
    }

    return sum;  // Return the final sum.
}

int main(){
    ifstream ifs("data.txt");
    string line;
    vector<string> engines;
    while (getline(ifs, line)){
        engines.push_back(line);
    }
    int p1  = part1(engines);
    cout << p1;
    return 0;
}