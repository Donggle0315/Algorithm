#include <iostream>

using namespace std;

int main() {
    // ax + by = c
    // dx + ey = f
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    
    int x,y;
    bool flag = false;
    for (x = -999; x < 1000; x++) {
        for (y = -999; y < 1000; y++) {
            if(a * x + b * y == c && d * x + e * y == f) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    
    cout << x << " " << y << "\n";

    return 0;
}