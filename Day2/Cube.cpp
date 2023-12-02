#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("Data.txt");
    string line;
    int ID = 1, power = 0;
    string temp;
    int r = -1, b = -1, g = -1, temp_color;
    while (getline(ifs, line)){
        r = -1, b = -1, g = -1;  
        stringstream ss(line);
        cout << line << endl;
        getline(ss, temp, ':');
        string temp_line;
        while (getline(ss, temp_line, ';')){     
            cout << temp_line << endl;
            stringstream sss(temp_line);
            while (getline(sss, temp, ',')){
                stringstream ssss(temp);
                ssss >> temp_color;
                ssss >> temp;
                if (temp[0] == 'b') {
                    if (b < temp_color)
                        b = temp_color;
                }
                else if (temp[0] == 'r'){
                    if (r < temp_color)
                        r = temp_color;
                }
                else if (temp[0] == 'g')
                    if (g < temp_color)
                        g = temp_color;
            }
        }
        power += (r*g*b);
    }
    cout << power;
    return 0;
}