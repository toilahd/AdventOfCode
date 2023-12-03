#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool isDigit(char c){
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int sum1(string line){
    int first, last;
    first = 0;
    for (int i = 0; i < line.length(); i++){
        if (isDigit(line[i])){
            first = line[i] - '0';
            break;
        }
    }
    last = 0;
    for (int i = line.length() - 1; i >= 0; i--){
        if (isDigit(line[i])){
            last = line[i] - '0';
            break;
        }
    }
    return first*10 + last;
}

int sum2(string line, map<string, int> &mp){
    size_t first_pos = line.length();
    int first_val = -1;
    size_t last_pos = 0;
    int last_val = -1;
    for (auto [str, val]: mp){
        size_t pos = line.find(str);
        if (pos != string::npos && pos < first_pos){
            first_pos = pos;
            first_val = val;
        }
        pos = line.rfind(str);
        if (pos != string::npos && pos > last_pos){
            last_pos = pos;
            last_val = val;
        }
    }
    return 10*first_val + last_val;

}
int main(){
    map<string, int> validNumbers;
    for (int i = 1; i < 10; i++){
        validNumbers[to_string(i)] = i;
    }
    validNumbers["one"] = 1;
    validNumbers["two"] = 2;
    validNumbers["three"] = 3;
    validNumbers["four"] = 4;
    validNumbers["five"] = 5;
    validNumbers["six"] = 6;
    validNumbers["seven"] = 7;
    validNumbers["eight"] = 8;
    validNumbers["nine"] = 9;
    string line;
    vector<string> lines;
    ifstream ifs("data.txt");
    while (getline(ifs, line)){
        lines.push_back(line);
    }
    int p1 = 0;
    int p2 = 0;
    for (auto line : lines){
        p1 += sum1(line);
        p2 += sum2(line, validNumbers);
    }
    cout << "Part1: " << p1 << endl;
    cout << "Part2: " << p2;
    return 0;
 }