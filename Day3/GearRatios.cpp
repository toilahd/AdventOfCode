#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;


const int neighbors[][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                            {1,  -1}, {1, 0}, {1, 1},
                            {0,  -1}, {0, 1}};


bool isDigit(char c){
    return (c >= '0' && c <= '9');
     
}

int part1(const vector<string> engines){
    int sum = 0;  
    for (int i = 0; i < engines.size(); ++i){
        int numStart = -1; 
        bool found = false; 
        for (int j = 0; j < engines[i].length(); ++j){
            if (isDigit(engines[i][j])){
                if (numStart == -1){
                    numStart = j;
                }

                if (!found){
                    for (auto  n : neighbors){
                        int x = i + n[0];
                        int y = j + n[1];
                        if (x < 0 || x >= engines.size() || y < 0  || y >= engines[i].size()){
                            continue;
                        }
                        if (engines[x][y] != '.' && !isDigit(engines[x][y])){
                            found = true;  
                            break; 
                        }
                    }
                }
            } else if (numStart != -1) {
                if (found) {
                    sum += stoi(engines[i].substr(numStart, j - numStart));
                }
                found = false;  
                numStart = -1; 
            }
        }
        if (numStart !=  -1) {
            if (found){
                sum += stoi(engines[i].substr(numStart));
            }
        }
    }

    return sum;  
}

int part2(const vector<string> engines){
    int sum = 0;

    // Loop through each row of the engines
    for (size_t i = 0; i < engines.size(); i++){
        // Loop through each character in the current row
        for (size_t j = 0; j < engines[i].length(); j++){
            // Check if the current character is not '*'
            if (engines[i][j] != '*'){
                continue;  // Skip to the next character if not '*'
            }

            // Initialize vectors to store numbers and their positions
            vector<int> numbers;
            vector<tuple<size_t, size_t>> numbersPos;

            // Loop through neighboring positions
            for (auto neigh : neighbors){
                int x = neigh[0] + i;
                int y = neigh[1] + j;

                // Check if the neighboring position is within bounds
                if (x < 0 || x >= engines.size() || y < 0 || y >= engines[i].length()){
                    continue;
                }

                // Check if the character at the neighboring position is a digit
                if (isDigit(engines[x][y])){
                    // Move to the beginning of the digit sequence
                    while (y >= 0 && isDigit(engines[x][y])){
                        y--;
                    }
                    if (y < 0 || !isDigit(engines[x][y])){
                        y++;
                    }

                    // Store the position and parse the number
                    tuple<size_t, size_t> pos(x, y);
                    if (find(numbersPos.begin(), numbersPos.end(), pos) == numbersPos.end()) {
                        numbersPos.push_back(pos);
                        size_t start = y;
                        
                        // Move to the end of the digit sequence
                        while (y < engines[x].size() && isDigit(engines[x][y])){
                            y++;
                        } 
                        
                        // Adjust position to the last digit
                        if (x == engines[y].size() || !isDigit(engines[x][y])){
                            y--;
                        }

                        // Convert the substring to an integer and add to the numbers vector
                        numbers.push_back(stoi(engines[x].substr(start, y - start + 1)));
                    }
                }
            }

            // If there are exactly two numbers, add their product to the sum
            if (numbers.size() == 2){
                sum += numbers[0] * numbers[1];
            }
        }
    }

    return sum;
}


int main(){
    ifstream ifs("data.txt");
    string line;
    vector<string> engines;
    while (getline(ifs, line)){
        engines.push_back(line);
    }
    int p1  = part1(engines);
    cout << p1 << endl;
    int p2 = part2(engines);
    cout << p2;
    return 0;
}