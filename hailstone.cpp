/*
Describe:
    hailstone(n):
        case 1: n <= 1  {n}
        case 2: n % 2 == 0 {n} union hailstone(n / 2)
        case 3: n % 2 == 1 {n} union hailstone(3 * n + 1)
*/

#include <iostream>

using namespace std;

int hailStoneLen(int);

int main(){
    int n;

    cout << "Please enter an integer: ";
    cin >> n;
    while (n){
        cout << "haliStone(" << n << ")'s length =" << hailStoneLen(n) << endl;
        cout << "Next number, pls: ";
        cin >> n;
    }

    return 0;
}

int hailStoneLen(int n){
//    int length = 0;
//
//    while (n > 1){
//        if(n % 2)
//            n = 3 * n + 1;
//        else
//            n = n / 2;
//        length++;
//    }
//
//    return ++length;

    int length = 1;

    while (1 < n) {
            (n % 2) ? n = 3 * n + 1 : n /= 2;
            length++;
    }

    return length;
}
