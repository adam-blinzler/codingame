#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0, Xmax, Xmin;
    int Y0, Ymax, Ymin;
    cin >> X0 >> Y0; cin.ignore();

    Xmin = Ymin = 0;
    Xmax = W-1;
    Ymax = H-1;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        if (bombDir.find("D") != std::string::npos) {
            Ymin = Y0 + 1;
        }
        else if (bombDir.find("U") != std::string::npos) {
            Ymax = Y0 - 1;
        }
        if (bombDir.find("R") != std::string::npos) {
            Xmin = X0 + 1;
        }
        else if (bombDir.find("L") != std::string::npos) {
            Xmax = X0 - 1;
        }
        
        X0 = Xmin + ceil((Xmax  - Xmin)/2);
        Y0 = Ymin + ceil((Ymax  - Ymin)/2);

        // the location of the next window Batman should jump to.
        cout << X0 << " " << Y0 << endl;
    }
}