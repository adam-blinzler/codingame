#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 void write_string(string &answer, char b_type, int t_cnt){
    answer.append("0");
    if ( b_type == '0' ){
        answer.append("0");
    }
    answer.append(" ");
    for ( int i = 0 ; i < t_cnt ; i++ ){
        answer.append("0");
    }
}
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);


    string answer;
    string bit_string;
    int t_cnt = 0;
    char b_type= ' ';
    bool first = true;
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (char& c : MESSAGE) {
        bit_string = bitset<8>(c).to_string().substr(1, 8);
        cerr << bit_string << endl;
    
        for (char& c : bit_string){
            if ( !first ){
                if ( c != b_type ){
                    write_string(answer, b_type, t_cnt);
                    answer.append(" ");
                    t_cnt = 0;   
                }
            }
            else{
                first = false;
            }
            t_cnt++;
            b_type = c;
        }
    }
    write_string(answer, b_type, t_cnt);
    
    cout << answer << endl;
}