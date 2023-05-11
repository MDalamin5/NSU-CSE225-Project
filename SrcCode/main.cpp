#include <bits/stdc++.h>
using namespace std;
class facultyNode
{
public:
    string name;
    string emailID;
    string ext;
    int room;
    string mobileNumber; 
    facultyNode *next;

    facultyNode(string name, string emailID, string ext, int room, string mobileNumber)
    {
        this->name = name;
        this->emailID = emailID;
        this->ext = ext;
        this->room = room;
        this->mobileNumber = mobileNumber;
        this->next = NULL;
    }
};
class faculty
{
public:
    facultyNode *head;
    int size;
    faculty()
    {
        head = NULL;
        size = 0;
    }
    void insertFacMem(string name, string emailID, string ext, int room, string mobileNumber)
    {
        facultyNode *newNode = new facultyNode(name, emailID, ext, room, mobileNumber);
        if (head == NULL)
        {
            head = newNode;
            size++;
            cout << endl
                 << "Sussfully add data" << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
        cout << endl
             << "Sussfully add data" << endl;
    }
    void travers()
    {
        facultyNode *a = head;
        while (a != NULL)
        {
            cout << "Faculty Name: " << a->name << " Email id: " << a->emailID << " EXT: " << a->ext << " Room No: " << a->room << " Mobile: " << a->mobileNumber << endl;
            a = a->next;
        }
        cout << endl;
    }
};
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
int main()
{
    faculty fl;
    fl.insertFacMem("Al Amin", "alam1n@hotmail.com", "225", 69, "01641049756");
    fl.travers();
    cout<<"Hello";
    cout<<"test";
    return 0;
}