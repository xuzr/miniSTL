#include"whichOneToRun.h"
#ifdef ALLOCATOR_SIMPLE

#include"allocator_simple.h"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int, xuzr::allocator<int>> nums{0, 1, 2, 3, 4};
    nums.push_back(123);
    for (auto& num : nums)
    {
        num++;
        cout << num << endl;
    }
    return 0;
}

#endif