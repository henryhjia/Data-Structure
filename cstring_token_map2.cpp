// Input:
// 2
// 1 1 1 1 2 2 2
// 3 3 3 5 5 5 5 5 5
//
// Output:
// 4 1
// 3 2
// 3 3
// 6 5
//
///////////////////////////////////////////////////////////////
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
    
            for(; it!= it_end; ++it) {                
                key = stoi(it->str());                
                mymap[key]++;                     
            }

            for(map_iter = mymap.begin(); map_iter != mymap.end(); map_iter++) {
                cout << map_iter->second << " " << map_iter->first << endl;
            }            
            
            mymap.clear();
            line.clear();
        }
    }
    return 0;
}
