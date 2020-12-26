#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int get_direction(int X, vector<int> LZ){
    if ( X > LZ.at(1) - 200 ) {
        return -1;
    }
    else if ( X < LZ.at(0) + 200 ) {
        return 1;
    }
    return 0;
}

 
int main()
{
    int prevY = -1;
    int prevX;
    int landingY;
    vector<int> lZone;

    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();
    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();

    //find landing zone
        if ( landY == prevY ) {
            lZone.push_back(prevX);
            lZone.push_back(landX);
            landingY = landY;
            break;
        }
        prevY = landY;
        prevX = landX;
    }
    
    if ( lZone.size() != 2 ) {
        cout << "No landing zone found!" << endl;
    }
    else {
        cerr << "LZ is " << lZone.at(0) << " - " << lZone.at(1) << endl;
    }

    // game loop
    while (1) {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> rotate >> power >> X >> Y >> hSpeed >> vSpeed >> fuel ; cin.ignore();

        if ( false ){
        cerr<< X<<endl;
        cerr<<Y<<endl;
        cerr<<hSpeed<<endl; // the horizontal speed (in m/s), can be negative.
        cerr<<vSpeed<<endl; // the vertical speed (in m/s), can be negative.
        cerr<<fuel<<endl; // the quantity of remaining fuel in liters.
        cerr<<rotate<<endl; // the rotation angle in degrees (-90 to 90).
        cerr<<power<<endl;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        int angle = 0;
        int pwr = 4;
        
        int dir2LZ = get_direction(X, lZone);
        
        if ( dir2LZ != 0 ) {
            // If not over the landing zone
            cerr << " Not over LZ : " << dir2LZ << endl;

            if ( abs(vSpeed) < 30 ) {
                cerr << "VS good, modify for VH" << endl;
                pwr = 3;
                if ( abs(hSpeed) < 10 ) {
                    // If going too slow
                    cerr << "Speed up H" << endl;
                    angle = -1 * dir2LZ * 90;
                }
                else if ( hSpeed / abs(hSpeed) != dir2LZ ){
                    // If pointed in the wrong direction
                    // add more refinement
                    cerr << "Slow Down H, reverse thruster" << endl;
                    angle = (hSpeed/abs(hSpeed)) * 20;
                }
                else if ( abs(hSpeed) > 60 ){
                    cerr << "Slow Down H, reverse thruster" << endl;
                    angle = (hSpeed/abs(hSpeed)) * 60;
                }
                else if ( abs(hSpeed) > 15 ){
                    cerr << "Slow Down H, reverse thruster" << endl;
                    angle = (hSpeed/abs(hSpeed)) * 30;
                }
            }
            else{
                if ( hSpeed / abs(hSpeed) != dir2LZ ){
                    // If pointed in the wrong direction
                    // add more refinement
                    cerr << "Slow Down H, reverse thruster" << endl;
                    angle = (hSpeed/abs(hSpeed)) * 20;
                }
                else if ( abs(hSpeed) > 60 ){
                    cerr << "Slow Down H, reverse thruster" << endl;
                    angle = (hSpeed/abs(hSpeed)) * 60;
                }
                else if ( abs(hSpeed) > 20 ){
                    cerr << "Slow Down H, reverse thruster" << endl;
                    angle = (hSpeed/abs(hSpeed)) * 30;
                }
            else{
                angle = -1 * dir2LZ * 30;
                }
            }
        }
        else {
            cerr << "Over Landing Zone" << endl;
            if ( Y > landingY + 200 ){
                cerr << "Still time to move H" << endl;
                if ( abs(hSpeed) > 50 ){
                    cerr << "Slow Down H, hard" << endl;
                    angle = (hSpeed/abs(hSpeed)) * 45;
                }
                else if ( abs(hSpeed) > 10 ) {
                    angle = (hSpeed/abs(hSpeed)) * 30;
                }
            }
            else if ( hSpeed < 16 && vSpeed < 36 ) {
                pwr = 2;
            }
        }
        
        
        // rotate power. rotate is the desired rotation angle. power is the desired thrust power.
        cout << angle << " " << pwr << endl;
    }
}