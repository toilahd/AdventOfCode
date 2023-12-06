#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("data.txt");
    string line;
    string temp;
    int part1 = 0;
    vector<tuple<vector<int>, vector<int>>> decks;
    while(getline(ifs, line)){
        int points = 0;
        vector<int> winningNumbers;
        vector<int> cards;
        stringstream ss(line);
        getline(ss, temp, ':');
        int a;
        for (int i = 0; i < 10; i++){
            ss >> a;
            winningNumbers.push_back(a);
        }
        getline(ss, temp, '|');
        while (ss >> a){
            cards.push_back(a);
        }
        decks.emplace_back(cards, winningNumbers);
        vector<int> copies(cards.size(), 1);
        for (auto i : winningNumbers){
            for (auto j : cards){
                if (i == j) {
                    
                    if (points == 0 ){
                        points++;
                    } else {
                        points*=2;
                    }
                }
            }
        }
        part1 += points;
        points = 0;
    }
    int part2 = 0;
    vector<int> copies(decks.size(), 1);
    for (int i = 0; i < decks.size(); i++){
        auto card = decks[i];
        int hits = 0;
        auto winning = get<1>(card);
        for (auto number: get<0>(card)){
            if (find(winning.begin(), winning.end(), number) != winning.end()){
                hits++;
            }
        }
        for (int j = 1; j <= hits; j++){
            copies[i + j] += copies[i];
        }
        part2 += copies[i];
    }
    cout << part1 << endl << part2;
    return 0;
}