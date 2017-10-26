// Input:
// 2
// 10 4 3 23
// 8 4 6 2
//
// Output:
//
// 3 23
// 10 4
// 6 2
// 8 4
//////////////////////////////////////////////////////////////////////
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <regex>
#include <map>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a;
    string line, buffer;
    string delimeter = " ";
    regex e(" ");
    int n;
    map<int, int> mymap;
    map<int, int>::iterator map_iter;
    
    int key, value;
    int count;
    
    cin >> n;
    
    for(int i=0; i<=n; i++) {
    
        getline(cin, line);
        if(!line.empty()) {
            count = 0;
            sregex_token_iterator it(line.begin(), line.end(), e, -1);
            sregex_token_iterator it_end;
    
            for (; it != it_end; ++it) {
                if(count %2 ==0) {
                    key = stoi(it->str());
                }
                else {
                    value = stoi(it->str());
                    mymap[key] = value;
                }
                //cout << key << " ";
                //cout << it->str() << " ";
                count++;
            }
            //cout << endl;
            for(map_iter = mymap.begin(); map_iter != mymap.end(); map_iter++) {
                cout << map_iter->first << " " << map_iter->second << endl;
            }
            mymap.clear();
        }
    }
    return 0;
}
