#include "Faculty.h"
#include <bits/stdc++.h>
using namespace std;
Faculty :: Faculty(int x,int y)
{
    data=x;
    data2=y;
}

void Faculty :: displayInfo()
{
    cout<<data+data2<<endl;
}