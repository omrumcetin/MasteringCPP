#include <iostream>
#include <cmath>
#include "AStaff.h";
#include "AWeapon.h"
#include <cassert>
#include <vector>
using namespace std;


void Show(vector<int> Arr)
{
    for(auto i : Arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void Swap(int* elem1, int* elem2)
{
    int temp = *elem2;
    *elem2 = *elem1;
    *elem1 = temp;
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

    Show( a);

    for(size_t i = 0 ; i < a.size() ; i++)
    {
        cout << "Iteration " << i << endl;
        for(size_t j = 0; j < a.size() - i - 1 ; j++)
        {
            if(a[j] > a[j+1])
                Swap(&a[j], &a[j+1]);
            Show(a);
        }
    }

    trysome(&a[0]);
    cout << &a[0] << endl;

}
