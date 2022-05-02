#ifndef COMB_H
#define COMB_H

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

namespace comb {
int factorial(int arg);

int A(int n, int k);
int _A(int n, int k);

int C(int n, int k);
int _C(int n, int k);

template <typename Type>
void printArray(std::vector<Type> arr) {
    for (auto a : arr)
        std::cout << a << " ";
    std::cout << std::endl;
}

template <typename Type>
void genPermHelper(std::vector<Type> &array) {
    int size = array.size();
    bool firstCondition = false;
    bool secondCondition = true;

    int i = 0;
    for(i = size - 2; i >= 0; i--) {
        firstCondition = false;
        secondCondition = true;

        if(array[i] < array [i+1]) {
            firstCondition = true;

            for(int j = i + 1; j <= size - 2 ; j++) {
                secondCondition = (array[j] > array[j+1]);
                if(!secondCondition) {
                    break;
                }
            }
        }

        if(firstCondition && secondCondition) {
            break;
        }
    }

    if(firstCondition && secondCondition) {
        std::sort(array.begin() + i + 1, array.end());
        for(int j = i + 1; j < size; j++) {
            if(array[j] > array[i]) {
                std::swap(array[j],array[i]);
                break;
            }
        }
    }
}

template <typename Type>
void genPermutation(std::vector<Type> &array) {
    std::cout  << "counter = " << 1 << " ";
    comb::printArray(array);
    for (int i = 2; i <= comb::factorial(array.size()); ++i) {
        comb::genPermHelper(array);
        std::cout  << "counter = " << i << " ";
        comb::printArray(array);
    }
}

static void genCombHelper(std::vector<int> &array, int k) {
    int n = array.size();
    for(int i = k - 1; i >= 0; i--) {
        if(array[i] != (n - k + i + 1)) {
            array[i]++;

            for(int j = i+1; j < k; j++)
            {
                array[j] = array[j-1]+1;
            }
            return;
        }
    }
}

template<typename Type>
static void genComb(std::vector<Type> &values, std::vector<int> &index , int k)
{
    static std::vector<Type> copy = values;
    genCombHelper(index, k);
    for(int i = 0 ; i < k; i++) {
        values[i] = copy[index[i] - 1];
    }
}
template <typename Type>
void printCombination(std::vector<Type> arr, int n)
{
    std::vector<int> ivec(arr.size());
    std::iota(ivec.begin(), ivec.end(), 1);

    int number_of_iterations = comb::C(arr.size(), n);

    for(int i = 1 ; i <= number_of_iterations; i++)
    {
        std::cout << i << ") ";
        for(int i = 0 ; i < n; i++)
        {
            std::cout << arr[i]<< " ";
        }
        std::cout << std::endl;
        comb::genComb(arr, ivec, n);
    }
}
}
#endif // COMB_H
