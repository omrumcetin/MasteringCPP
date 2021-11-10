#include <iostream>
#include <cmath>
#include "AStaff.h";
#include "AWeapon.h"
#include <cassert>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace std;

enum colors{ red = 5 , black = 2};

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Show(vector<int> Arr)
{
    for(auto i : Arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void Trysome(int* som)
{
    cout << "In try some :"<< som << endl;  
    som++;
    cout << "In try some :" << som << endl;
}

int Partition(vector<int> &Arr, int low, int high)
{
    // pivot (Element to be placed at right position)
    auto pivot = Arr[high];

    auto i = (low - 1);  // Index of smaller element and indicates the 
                   // right position of pivot found so far

    for (auto j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (Arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap( &Arr[i], &Arr[j]);
            Show(Arr);
        }
        Show(Arr);
    }
    swap(Arr[i + 1], Arr[high]);
    Show(Arr);
    return (i + 1);
}

void QuickSort(vector<int> &Arr, int Low, int High)
{
    if (Low < High)
    {
        auto partIndex = Partition( Arr, Low, High);

        QuickSort(Arr, Low, partIndex -1);
        QuickSort(Arr, partIndex + 1, High);
    }
}
void main()
{
    vector<int> a{ 65 , 24 , 15 , 8 , 94 , 111, 256 , 56, 15, 99};

    Show(a);
    QuickSort(a, 0, a.size()-1);
    Show(a);

    Trysome(&a[0]);
    cout << &a[0] << endl;

    cout << red << endl;
}
