#pragma once

#include <vector>
#include <iostream>
#include <random>

using namespace std;

namespace sort {

template<typename Type>
void bubble(vector<Type> &array)
{
    for (int i = 0; i < array.size() - 1; i++)
        for (int j = 0; j < array.size() - i - 1; j++)
            if (array.at(j) > array.at(j+1))
                swap(array[j], array[j+1]);
}

template<typename Type>
void bubble(vector<Type> &array, int begin, int end)
{
    for (int i = begin; i <= end; i++)
        for (int j = begin; j <= end - 1; j++)
            if (array.at(j) > array.at(j+1))
                swap(array[j], array[j+1]);
}

template <typename Type>
void insertion(vector<Type> &array)
{
    for (int i = 1; i < array.size(); i++) {
        Type key = array.at(i);
        int j = i - 1;
        while (j >= 0 && array.at(j) > key) {
            array[j + 1] = array.at(j);
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

template <typename Type>
void insertion(vector<Type> &array, int begin, int end)
{
    for (int i = begin + 1; i <= end; i++)
    {
        Type key = array.at(i);
        int j = i - 1;
        while (j >= begin && array.at(j) > key)
        {
            array[j + 1] = array.at(j);
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

template <typename Type>
void selection(vector<Type> &array)
{
    for (int i = 0; i < array.size() - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < array.size(); j++)
            if (array.at(j) < array.at(min_idx))
                min_idx = j;

        swap(array[min_idx], array[i]);
    }
}

template <typename Type>
void selection(vector<Type> &array, int begin, int end)
{
    for (int i = begin; i < end; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j <= end; j++)
            if (array.at(j) < array.at(min_idx))
                min_idx = j;

        swap(array[min_idx], array[i]);
    }
}
template <typename Type>
void printArray(const vector<Type> &array)
{
    for (auto a : array)
        cout << a << " ";
    cout << endl;
}

template<typename Type>
Type minItem(vector<Type> &array, int begin, int end)
{
    Type result = array.at(begin);
    for( int i = begin; i <= end; i++)
        if (array.at(i) < result)
            result = array.at(i);
    return result;
}

template<typename Type>
Type maxItem(vector<Type> &array, int begin, int end)
{
    Type result = array.at(begin);
    for( int i = begin; i <= end; i++)
        if (array.at(i) > result)
            result = array.at(i);
    return result;
}
vector<int> randomValues(int size) {
    random_device rnd_device;
    mt19937 mersenne_engine {rnd_device()};
    uniform_int_distribution<int> dist {1, 52};

    auto gen = [&dist, &mersenne_engine](){
        return dist(mersenne_engine);
    };

    vector<int> vec(size);
    generate(begin(vec), end(vec), gen);
    return vec;
}

}
