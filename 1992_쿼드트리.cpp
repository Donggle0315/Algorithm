#include <iostream>

using namespace std;

int arr[64][64] = {0};
string result = "";

void divide(int, int, int);
bool isIdentical(int, int, int);

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < n; j++) {
            arr[i][j] = input.at(j)-'0';
        }
    }

    divide(n, 0, 0);
    cout << result << "\n";

    return 0;
}

void divide(int n, int startRow, int startCol) {
    int new_n = n / 2;

    if (n == 1 || isIdentical(n, startRow, startCol)) {
        result += (arr[startRow][startCol] == 1 ? "1" : "0");
        return;
    }

    result += "(";
    divide(new_n, startRow, startCol);
    divide(new_n, startRow, startCol + new_n);
    divide(new_n, startRow + new_n, startCol);
    divide(new_n, startRow + new_n, startCol + new_n);
    result += ")";

    
}

bool isIdentical(int length, int startRow, int startCol) {
    int target = arr[startRow][startCol];
    for(int i = startRow; i < startRow + length; i++) {
        for(int j = startCol; j < startCol + length; j++) {
            if (target != arr[i][j]) return false;
        }
    }
    return true;
}