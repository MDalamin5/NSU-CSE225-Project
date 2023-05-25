#include <bits/stdc++.h>
using namespace std;
void TempMain();
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
    //Read data or Searching 
    void readFacultyInfo()
    {
        
    }



    void travers()
    {
        facultyNode *a = head;
        while (a != NULL)
        {
            cout << "Faculty Name: " << a->name << " Email id: " << a->emailID << " EXT: " << a->ext
             << " Room No: " << a->room << " Mobile: " << a->mobileNumber << endl;
            a = a->next;
        }
        cout << endl;
    }
};
class manageRecord
{
    public:
    void addNewRecord()
    {
        faculty f;
        int choise;
    cout<<"Welcome to Course Management System"<<endl<<endl;
    while(1)
    {
        cout<<"1. Add New Record"<<endl;
        cout<<"2. Searching Records"<<endl;
        cout<<"3. Update Data"<<endl;
        cout<<"4. Generating Report"<<endl;
        cout<<"5. Add Course"<<endl;
        cout<<"6. Display My Course"<<endl;
        cout<<"0. Exit from Here"<<endl;
        
        cout<<endl<<"Please Enter Choice"<<" ";
        cin>>choise;

        switch(choise)
        {
            case 0:
            TempMain();
            break;

            case 1:
            //f.insertFacMem();
            break;

            case 2:
            //c.insertCourse();
            break;

            case 3:
            //ca.insertCourseAssign();
            break;

            default:
            cout<<"Invalid input try again"<<endl;
            break;
        }
    }
    }
    void seacrchigRecord()
    {
        int input;
        cout<<"Search"<<endl;
        cout<<"Going to main"<<endl;
        cin>>input;
        TempMain();

    }
    void updateRecord()
    {
        cout<<"Update"<<endl;
    }
    void genrateReport()
    {
        cout<<"Report Generate"<<endl;
    }
    void addCourse()
    {
        cout<<"Add Course"<<endl;
    }
    void displayCourse()
    {
        cout<<"Display My data"<<endl;
    }
};
void TempMain()
{
    manageRecord mr;
    int choise;
    cout<<"Welcome to Course Management System"<<endl<<endl;
    while(1)
    {
        cout<<"1. Add New Record"<<endl;
        cout<<"2. Searching Records"<<endl;
        cout<<"3. Update Data"<<endl;
        cout<<"4. Generating Report"<<endl;
        cout<<"5. Add Course"<<endl;
        cout<<"6. Display My Course"<<endl;
        cout<<"0. Exit from Here"<<endl;
        
        cout<<endl<<"Please Enter Choice"<<" ";
        cin>>choise;

        switch(choise)
        {
            case 0:
            exit(0);

            case 1:
            mr.addCourse();
            break;

            case 2:
            mr.seacrchigRecord();
            break;

            case 3:
            mr.updateRecord();
            break;

            case 4:
            mr.genrateReport();
            break;

            case 5:
            mr.addCourse();
            break;
            case 6:
            mr.displayCourse();
            break;

            default:
            cout<<"Invalid input try again"<<endl;
            break;
        }
    }
}
int main()
{
    faculty fl;
    manageRecord mr;
    TempMain();
    return 0;
}