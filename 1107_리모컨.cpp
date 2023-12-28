#include <iostream>
#include <vector>

#define INF 1000007
using namespace std;

int getMinCount();
int getNearestLowerChannel();
int getNearestUpperChannel();
bool canAccessDirect(int);
int getDigit(int);

int n,m;
bool broken_button[10];

int main() {
    cin >> n >> m;
    //broken_button = new bool[10];
    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        broken_button[tmp] = true;
    }

    cout << getMinCount() << "\n";
    
    return 0;
}

int getMinCount() {
    int min = n >= 100 ? n - 100 : 100 - n;
    int upperChannel = getNearestUpperChannel();
    int lowerChannel = getNearestLowerChannel();

    if (min > upperChannel - n + getDigit(upperChannel)) min = upperChannel - n + getDigit(upperChannel);
    if (min > n - lowerChannel + getDigit(lowerChannel)) min = n - lowerChannel + getDigit(lowerChannel);

    return min;
}

int getNearestUpperChannel() {
    int channel;
    for(channel = n; channel <= 1000000; channel++) {
        if (canAccessDirect(channel)) break;
    }
    if(channel > 1000000) return INF;
    return channel;
}

int getNearestLowerChannel() {
    int channel;
    for(channel = n - 1; channel >= 0; channel--) {
        if(canAccessDirect(channel)) break;
    }
    if(channel < 0) return -INF;
    return channel;
}

bool canAccessDirect(int channel) {
    if(channel == 0) return !broken_button[0];
    while (channel != 0) {
        if (broken_button[channel % 10]) return false;
        channel /= 10;
    }
    return true;
}

int getDigit(int channel) {
    int cnt = 0;
    if (channel == 0 ) return 1;
    for(cnt = 0; channel != 0; channel/=10, cnt++) {
        ;
    }
    return cnt;
}