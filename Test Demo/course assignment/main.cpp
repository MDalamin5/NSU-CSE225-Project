#include<bits/stdc++.h>
using namespace std;
class courseNode
{
public:
    int sl_no;
    string courseCode;
    string courseTitle;
    float credits;
    string courseType;
    string PCC;
    courseNode *next;
    courseNode(int sl_no, string courseCode, string courseTitle, float credits, string courseType, string PCC)
    {
        this->sl_no = sl_no;
        this->courseCode = courseCode;
        this->courseTitle = courseTitle;
        this->credits = credits;
        this->courseType = courseType;
        this->PCC = PCC;
        this->next = NULL;
    }
    void insertCourse(int sl_no, string courseCode, string courseTitle, float credits, string courseType, string PPC)
    {
        
    }
};
class courseList
{
public:
    courseNode *head;
    int courseListSize;
    courseList()
    {
        head = NULL;
        courseListSize = 0;
    }
};