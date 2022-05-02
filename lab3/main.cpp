#include <iostream>

#include "comb.h"

using namespace std;

int main()
{
    int n, k;
    cout << "Input n, k" << endl;
    cin >> n >> k;

    cout << "factorial= " << comb::factorial(n) << endl;

    cout << "A=" << comb::A(n, k) << endl;
    cout << "_A=" <<comb::_A(n, k) << endl;

    cout << "C=" << comb::C(n, k) << endl;
    cout << "_C=" <<comb::_C(n, k) << endl;

    cout << "Input size " << endl;
    int size = 0;
    cin >> size;

    cout << "Input elements " << endl;
    vector<int> arr;
    for (int i = 0; i < size; ++i)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "Choose method " << endl
         << "1 - Permutatio " << endl
         << "2 - Combination " << endl;

    int key;
    cin >> key;

    if (key == 1)
        comb::genPermutation(arr);
    else if (key == 2) {
        int n;
        cout << "Input n " << endl;
        cin >> n;
        comb::printCombination(arr, n);
    }
    else
        cout << "Invalid method key" << endl;
}
