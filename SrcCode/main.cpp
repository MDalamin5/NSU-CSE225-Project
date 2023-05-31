#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX_NAME_LEN 60
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
    void insertFacMem()
    {

        string name, designation, emailID, ext, mobileNumber;
        int room;
        fflush(stdin);
        cout<<"Enter Faculty Full Name: ";
        getline(cin,name); fflush(stdin);
        cout<<"Enter Faulty Designation: ";
        getline(cin,designation); fflush(stdin);
        cout<<"Enter Faculty Email ID: ";
        getline(cin,emailID); fflush(stdin);
        cout<<"Enter EXT Nunber: ";
        getline(cin,ext); fflush(stdin);
        cout<<"Enter Room Number: ";
        cin>>room; fflush(stdin);
        cout<<"Enter Mobile Number: ";
        getline(cin,mobileNumber); fflush(stdin);

        facultyNode *newNode = new facultyNode(name, designation, emailID, ext, room, mobileNumber);
        if (head == NULL)
        {
            head = newNode;
            size++;
            cout << endl
                 <<size<<" Faculty Sussfully add" << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
        cout << endl<<size<<" Faculty Sussfully add" << endl;
    }
    //Read data or Searching 
    void readFacultyInfo()
    {
        int searchOption;
       cout<<"\n"<<"Please Chose Your Option"<<endl;
       cout<<"1. Search By Name"<<endl;
       cout<<"2. Search By Contact ID"<<endl;
       cout<<"3. Search By Phone Number"<<endl;
       cout<<"0. Go to home page"<<endl;
       cout<<endl<<"Please Enter Your Choise: ";
       cin>>searchOption;
       switch(searchOption)
       {
        case 0:
        TempMain();
        break;

        case 1:
        searchByName();
        break;

        case 2:
        searchByPhoneNo();
        break;


        default:
        cout<<"You are entering invalid input\n\n Try again \n\n";
        readFacultyInfo();

       }
    }
 
 void searchByName()
    {
        string src_name;
        cout<<"Please Enter the name: ";
        fflush(stdin);
        getline(cin,src_name);

        facultyNode *a = head;
        bool flag;
        while(a!=NULL)
        {
            flag = true;
            for(int i=0;i<src_name.length();i++)
            {
                if(src_name[i]!=a->name[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
            a=a->next;
        }
        if(flag)
        {
            cout<<"Name Found "<<endl;
        }
        else
        {
            cout<<"Sorry! Name Not Found"<<endl;
        }
        
    }

// Search By Phone NUmber
void searchByPhoneNo()
    {
        string src_ph_no;
        cout<<"Please Enter the Phone Number: ";
        fflush(stdin);
        getline(cin,src_ph_no);

        facultyNode *a = head;
        bool flag;
        while(a!=NULL)
        {
            flag = true;
            for(int i=0;i<src_ph_no.length();i++)
            {
                if(src_ph_no[i]!=a->mobileNumber[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
            a=a->next;
        }
        if(flag)
        {
            cout<<"Name Found ok"<<endl;
        }
        else
        {
            cout<<"Sorry! Name Not Found"<<endl;
        }
    }
// delete Faculty Info

    void DeleteFacultyInfo()
    {
        int cos_opt;
        cout<<"which contact you want to delete"<<endl;
        //cout<<"Enter contact name"<<endl;
        cout<<"How way to daelte the contact"<<endl;
        cout<<"Chose your option: "<<endl;
        cout<<"1. Delete faculty Search by name: "<<endl;
        cout<<"2. Delete Faculty Search by PhoneNumber: "<<endl;
        cout<<"Please Enter your choise: "<<endl;
        cin>>cos_opt;
        switch (cos_opt)
        {
            case 1: 
            eraseSrcByName();
            break;

            case 2:
            eraseSrcByPhoneNumber();
            break;
        
            default:
            cout<<"You are enteing wrong input"<<endl;
            break;
        }

    }
    void eraseFromHead()
    {
        facultyNode *temp=head;
        head=temp->next;
        size--;
        delete temp;
        cout<<"Delete "<<head->name <<"Faculty Info From Our List"<<endl;
        //return;
    }
     void eraseSrcByName()
    {
         string src_name;
        cout << "Please Enter the name: ";
        fflush(stdin);
        getline(cin, src_name);

    if(size==0)
    {
        cout<<"No data in your file"<<endl;
        return;
    }

        int cur_indx=0;
        facultyNode *a = head;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_name.length(); i++)
            {
                if (src_name[i] != a->name[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
            a = a->next;
            cur_indx++;
        }
        cout<<cur_indx<<endl;
        if (flag)
        {
            cout<<endl;
            //cout << "Name Found " << endl;
        }
        else
        {
            cout << "Sorry! Name Not Found";
            return;
        }

        if(cur_indx==0)
        {
            eraseFromHead();
            return;
        }
        int count_index=0;
        facultyNode *prev=head;
        while(count_index!=cur_indx-1)
        {
            prev=prev->next;
            count_index++;
        }

            prev->next=a->next;
            size--;
            cout<<"Delete "<<a->name <<"Faculty Info From Our List"<<endl;
            delete a;
            
    } 

   //delete by phonenumber
    void eraseSrcByPhoneNumber()
    {
        string src_PhNO;
        cout << "Please Enter the Phone_Number: ";
        fflush(stdin);
        getline(cin, src_PhNO);

    if(size==0)
    {
        cout<<"No data in your file"<<endl;
        return;
    }

        int cur_indx=0;
        facultyNode *a = head;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_PhNO.length(); i++)
            {
                if (src_PhNO[i] != a->mobileNumber[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
            a = a->next;
            cur_indx++;
        }
        cout<<cur_indx<<endl;
        if (flag)
        {
            cout<<endl;
            //cout << "Name Found " << endl;
        }
        else
        {
            cout << "Sorry! Name Not Found";
            return;
        }

        if(cur_indx==0)
        {
            eraseFromHead();
            return;
        }
        int count_index=0;
        facultyNode *prev=head;
        while(count_index!=cur_indx-1)
        {
            prev=prev->next;
        }

            prev->next=a->next;
            size--;
            cout<<"Delete "<<a->name <<"Faculty Info From Our List"<<endl;
            delete a;
    }
    // delete method end

    // Faculty Modify Function




//display data
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
    faculty fac;
    void addNewRecord()
    {
        
        int choise;
    cout<<"Welcome to Course Management System"<<endl<<endl;
    while(1)
    {
        cout<<"1. Add Faculty"<<endl;
        cout<<"2. Add coutse"<<endl;
        cout<<"3. add course Assignment"<<endl;
        cout<<"0. Home Page"<<endl;
        
        cout<<endl<<"Please Enter Choice"<<" ";
        cin>>choise;

        switch(choise)
        {
            case 0:
            TempMain();
            break;

            case 1:
            fac.insertFacMem();
            break;

            case 2:
            //c.insertCourse();
            //fac.readFacultyInfo();
            fac.DeleteFacultyInfo();
            break;

            case 3:
            //ca.insertCourseAssign();
            fac.travers();
            break;

            default:
            cout<<"Invalid input try again"<<endl;
            break;
        }
    }
    }
    void seacrchigRecord()
    {

        int searchOption;
       cout<<"\n"<<"Please Chose Your Option"<<endl;
       cout<<"1. Search By Facuty Data"<<endl;
       cout<<"2. Search By Course Data"<<endl;
       cout<<"3. Search By Course Assignment"<<endl;
       cout<<"0. Go to home page"<<endl;
       cout<<endl<<"Please Enter Your Choise: ";
       cin>>searchOption;
       switch(searchOption)
       {
        case 0:
        TempMain();
        break;

        case 1:
        fac.readFacultyInfo();
        break;

        case 2:
        //searchByContactID();
        //fac.travers();
        break;

        case 3:
        //searchByPhoneNo();
        //fac.searchByName();
        break;

        default:
        cout<<"You are entering invalid input\n\n Try again \n\n";
        seacrchigRecord();

       }

    }
    void updateRecord()
    {
        int searchInput;
       cout<<"\n"<<"Please Chose Your Option"<<endl;
       cout<<"1. Delete from Facuty Data"<<endl;
       cout<<"2. delete Course Data"<<endl;
       cout<<"3. delete Course Assignment"<<endl;
       cout<<"0. Go to home page"<<endl;
       cout<<endl<<"Please Enter Your Choise: ";
       cin>>searchInput;
       switch(searchInput)
       {
        case 0:
        TempMain();
        break;

        case 1:
        fac.DeleteFacultyInfo();
        break;

        case 2:
        //c.DeleteCourseINfo();
        fac.travers();
        break;

        case 3:
        //fac.searchByName();
        break;

        default:
        cout<<"You are entering invalid input\n\n Try again \n\n";
        seacrchigRecord();
    }
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
       fac.travers();
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
            mr.addNewRecord();
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
    TempMain();
    return 0;
}