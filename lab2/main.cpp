#include <iostream>

#include "sort.h"

#include <string>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

int main()
{

    vector<int> a = sort::randomValues(50000);
    cout << "bubble" << endl;
//    sort::printArray(a);
    auto start = high_resolution_clock::now();
//    sort::selection(a);
    auto stop = high_resolution_clock::now();
//    sort::printArray(a);

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;

    a = sort::randomValues(10000000);
    start = high_resolution_clock::now();
    std::sort(a.begin(), a.end());
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken by function: "
             << duration.count() << " milliseconds" << endl;

    vector<double> aa{0, 0.1, 0.2};
    sort::bubble(aa);

    cout << endl << "insertion" << endl;

    vector<int> b = sort::randomValues(10);
    sort::printArray(b);
    sort::insertion(b);
    sort::printArray(b);

    cout << endl << "selection" << endl;

    vector<int> c = sort::randomValues(10);
    sort::printArray(c);
    sort::selection(c);
    sort::printArray(c);

    cout << endl;
    cout << "---------------------------";
    cout << endl;

    vector<int> d = sort::randomValues(10);
    sort::printArray(d);
    sort::bubble(d, 0, 4);

    sort::printArray(d);
    sort::bubble(d, 5, 9);

    sort::printArray(d);

    cout << endl;
    cout << "---------------------------";
    cout << endl;

    vector<int> e = sort::randomValues(10);
    sort::printArray(e);
    sort::insertion(e, 0, 4);

    sort::printArray(e);
    sort::insertion(e, 5, 9);

    sort::printArray(e);

    cout << endl;
    cout << "---------------------------";
    cout << endl;

    vector<int> f = sort::randomValues(10);
    sort::printArray(f);
    sort::selection(f, 0, 4);

    sort::printArray(f);
    sort::selection(f, 5, 9);

    sort::printArray(f);

    cout << endl;
    cout << "---------------------------";
    cout << endl;

    cout << "Input size -----------> " << endl;
    int size = 0;
    cin >> size;

    cout << "Input elements -------> " << endl;
    vector<int> arr;
    for (int i = 0; i < size; ++i)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int start_index, end_index;
    cout << "Input start index ----> " << endl;
    cin >> start_index;

    cout << "Input end index   ----> " << endl;
    cin >> end_index;

    cout << "Choose method " << endl
         << "1 - bubble " << endl
         << "2 - insertion " << endl
         << "3 - selection " << endl;

    int key;
    cin >> key;

    if (key == 1)
        sort::bubble(arr, start_index, end_index);
    else if (key == 2)
        sort::insertion(arr, start_index, end_index);
    else if (key == 3)
        sort::selection(arr, start_index, end_index);
    else
        cout << "Invalid method key" << endl;

    sort::printArray(arr);
    cout << "Min Item = " << sort::minItem(arr, start_index, end_index) << endl;
    cout << "Max Item = " << sort::maxItem(arr, start_index, end_index) << endl;
}
