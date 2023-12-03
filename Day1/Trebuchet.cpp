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
int main(){
    map<string, int> mp;
    mp["one"]=1; mp["two"]=2; mp["three"]=3; mp["four"]=4; 
    mp["five"]=5;mp["six"]=6; mp["seven"]=7; mp["eight"]=8; mp["nine"]=9;
    vector<string> str = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    ifstream ifs("data.txt");
    string line;
    int sum = 0, first, last, inF = 0, inL = 0;
    while (getline(ifs, line)){ 
        inF = 0, inL = 0;
        first = 0;
        for (int i = 0; i < line.length(); i++){
            if (isDigit(line[i])){
                first = line[i] - '0';
                inF = i;
                break;
            }
        }
        last = 0;
        for (int i = line.length() - 1; i >= 0; i--){
            if (isDigit(line[i])){
                last = line[i] - '0';
                inL = i;
                break;
            }
        }
        // for (auto i : str){
        //     if (line.find(i) != string::npos && line.find(i) < inF){
        //         first = mp[i];
        //     }
        // }
        // reverse(line.begin(), line.end());
        // for (auto i : str){
        //     reverse(i.begin(), i.end());
        //     if (line.find(i) != string::npos && line.find(i) < line.length() - 1 - inL){
        //         last = mp[i];
        //     }
        // }
        sum += first*10 + last;
    }
    cout << sum;
    return 0;
}