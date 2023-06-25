#include<bits/stdc++.h>
#include "Course.h"

using namespace std;

Course :: Course(string ss, int aggg)
{
    name=ss;
    age=aggg;
}

void Course :: coutseInfo()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
}
