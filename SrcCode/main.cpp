#include <bits/stdc++.h>
using namespace std;
class facultyNode
{
public:
    string name;
    string designation;
    string emailID;
    string ext;
    int room;
    string mobileNumber; 
    facultyNode *next;

    facultyNode(string name, string designation, string emailID, string ext, int room, string mobileNumber)
    {
        this->name = name;
        this->designation=designation;
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
    void insertFacMem(string name, string designation, string emailID, string ext, int room, string mobileNumber)
    {
        facultyNode *newNode = new facultyNode(name, designation, emailID, ext, room, mobileNumber);
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

int main()
{
    faculty fl;
    fl.insertFacMem("Al Amin", "Professor", "alam1n@hotmail.com", "111", 69, "0164104743");
    fl.travers();
    cout<<"Hello";
    cout<<"test";
    return 0;
}