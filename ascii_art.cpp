#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
 
    vector<string> v;

    // get inputs
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        v.push_back(ROW);
    }

    // create offset map, increase speed of output
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    int offset;
    vector<int> o;

    for (std::string::size_type j = 0; j < T.size(); j++) {
        offset = alp.find(toupper(T[j]));
        if ( offset == std::string::npos) {
            offset = alp.length()-1;
        }
        o.push_back(offset);
    }

    
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (int i = 0; i < H; i++ ){
        for (int it  : o) { 
            cout << v[i].substr(it*L,L);
        }
        cout << endl;
    }
}