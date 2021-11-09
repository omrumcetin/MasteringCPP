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


void Show(vector<int> Arr)
{
    for(auto i : Arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void trysome(int* som)
{
    cout << "In try some :"<< som << endl;  
    som++;
    cout << "In try some :" << som << endl;
}

void main()
{
    vector<int> a{ 65 , 24 , 15 , 8 , 94 , 111, 256 , 56, 15, 99};

    Show(a);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort(a.begin(), a.end());
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    clock_t end = clock();
    cout << "Elapsed(ms) : " << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.0 << endl;
    for(size_t i = 0 ; i < a.size() ; i++)
    {
        cout << "Iteration " << i << endl;
        for(size_t j = 0; j < a.size() - i - 1 ; j++)
        {
            if(a[j] > a[j+1])
                std::swap(a.at(j), a.at(j+1));
            Show(a);
        }
    }

    trysome(&a[0]);
    cout << &a[0] << endl;

}
