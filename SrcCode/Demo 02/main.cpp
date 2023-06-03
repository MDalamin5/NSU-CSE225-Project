#include <bits/stdc++.h>
using namespace std;
// Faculty Class
class FacultyInfo
{
public:
    string name;
    string fc_intital;
    string designation;
    string emailID;
    string ext;
    string room;
    string mobileNumber;
    FacultyInfo *next;

    FacultyInfo(string name, string fc_intital, string designation, string emailID, string ext, string room, string mobileNumber)
    {
        this->name = name;
        this->fc_intital=fc_intital;
        this->designation = designation;
        this->emailID = emailID;
        this->ext = ext;
        this->room = room;
        this->mobileNumber = mobileNumber;
        this->next = NULL;
    }
};

// CourseInfo class
class CourseInfo
{
public:
    CourseInfo *next;

    CourseInfo()
    {
    }
};

// CourseAssignmentInfo class
class CourseAssignmentInfo
{
public:
    CourseAssignmentInfo *next;

    CourseAssignmentInfo()
    {
    }
};

// CourseManagementSystem class
class CourseManagementSystem
{
private:
    FacultyInfo *facultyList;
    CourseInfo *courseList;
    CourseAssignmentInfo *assignmentList;

public:
    CourseManagementSystem()
    {
        facultyList = NULL;
        courseList = NULL;
        assignmentList = NULL;
    }

    void homePage()
    {
        cout << "===== Course Management System =====" << endl;
        cout << "1. Faculty Information" << endl;
        cout << "2. Course Information" << endl;
        cout << "3. Course Assignment Information" << endl;
        cout << "4. Generating Report" << endl;
        cout << "5. Advising Now" << endl;
        cout << "6. Display My Course" << endl;
        cout << "0. Exit" << endl;
        cout << "====================================" << endl;
    }

    // Faculty Info Menu
    void facultyInfoMenu()
    {
        cout << "===== Faculty Information =====" << endl;
        cout << "1. Add Faculty Information" << endl;
        cout << "2. Display Faculty Information" << endl;
        cout << "3. Update Faculty Information" << endl;
        cout << "4. Delete Faculty Information" << endl;
        cout << "5. Search Faculty" << endl;
        cout << "6. Save To File" << endl;
        cout << "0. Back to Home" << endl;
        cout << "===============================" << endl;
    }

    // Course Info Menu
    void courseInfoMenu()
    {
        cout << "===== Course Information =====" << endl;
        cout << "1. Add Course Information" << endl;
        cout << "2. Display Course Information" << endl;
        cout << "3. Update Course Information" << endl;
        cout << "4. Delete Course Information" << endl;
        cout << "5. Search Course" << endl;
        cout << "6. Save To File" << endl;
        cout << "0. Back to Home" << endl;
        cout << "==============================" << endl;
    }

    // Course Assignment Info
    void courseAssignmentInfoMenu()
    {
        cout << "===== Course Assignment Information =====" << endl;
        cout << "1. Add Course Assignment Information" << endl;
        cout << "2. Display Course Assignment Information" << endl;
        cout << "3. Update Course Assignment Information" << endl;
        cout << "4. Delete Course Assignment Information" << endl;
        cout << "5. Search Course Assignment" << endl;
        cout << "6. Save To File" << endl;
        cout << "0. Back to Home" << endl;
        cout << "========================================" << endl;
    }

    // Delete Faculty info menu
    void deleteFacultyMenu()
    {
        cout << "===== Faculty Delte Information =====" << endl;
        cout << "1. Delete By searchin name" << endl;
        cout << "2. Delete By searchin Phonenumber" << endl;
        cout << "0. Back Faculty Page" << endl;
        cout << "========================================" << endl;
    }
    // Faculty Search Menu
    void searchFacultyMenu()
    {
        cout << "===== Faculty Delte Information =====" << endl;
        cout << "1. Search By Name" << endl;
        cout << "2. Search By Phonenumber" << endl;
        cout << "0. Back Faculty Page" << endl;
        cout << "========================================" << endl;
    }

    void run()
    {
        int choice;
        do
        {
            homePage();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                facultyInfoPage();
                break;
            case 2:
                // courseInfoPage();
                break;
            case 3:
                // courseAssignmentInfoPage();
                break;
            case 0:
                cout << "Exiting the Course Management System..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }

        } while (choice != 0);
    }

    void facultyInfoPage()
    {
        int choice;
        string filename = "faculty.txt";
        loadFromFile(filename);
        do
        {
            facultyInfoMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addFacultyInfo();
                break;
            case 2:
                displayFacultyInfo();
                break;
            case 3:
                 updateFacultyInfo();
                break;
            case 4:
                deleteFacultyInfo();
                break;
            case 5:
                searchFacultyInfo();
                break;
            case 6:
               saveToFile(filename);
               cout<< "Data Saved in File" << endl;
               break;    
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }
    void addFacultyInfo()
    {
        string name,fc_initial, designation, emailID, ext, room, mobileNumber;

        fflush(stdin);
        cout << "Enter Faculty Full Name: ";
        getline(cin, name);
        fflush(stdin);
        cout << "Enter Faculty Initial: ";
        getline(cin, fc_initial);
        fflush(stdin);
        cout << "Enter Faulty Designation: ";
        getline(cin, designation);
        fflush(stdin);
        cout << "Enter Faculty Email ID: ";
        getline(cin, emailID);
        fflush(stdin);
        cout << "Enter EXT Nunber: ";
        getline(cin, ext);
        fflush(stdin);
        cout << "Enter Room Number: ";
        getline(cin, room);
        fflush(stdin);
        cout << "Enter Mobile Number: ";
        getline(cin, mobileNumber);
        fflush(stdin);

        FacultyInfo *newFaculty = new FacultyInfo(name,fc_initial, designation, emailID, ext, room, mobileNumber);

        // Add the new faculty info to the linked list
        if (facultyList == NULL)
        {
            facultyList = newFaculty;
        }
        else
        {
            FacultyInfo *temp = facultyList;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newFaculty;
        }

        cout << "Faculty information added successfully!" << endl;
    }

    void displayFacultyInfo()
    {
        if (facultyList == NULL)
        {
            cout << "No faculty information found!" << endl;
        }
        else
        {
            FacultyInfo *temp = facultyList;
            cout << "===== Faculty Information =====" << endl;
            while (temp != NULL)
            {
                cout << "Name: " << temp->name << "  "
                     << "Designation: " << temp->designation << "  "
                     << "Email id: " << temp->emailID
                     << "  "
                     << "Ext: " << temp->ext << "  "
                     << "Room No: " << temp->room << "  "
                     << "Mobile Number: " << temp->mobileNumber << endl
                     << endl;

                cout << "------------------------------" << endl;
                temp = temp->next;
            }
        }
    }

    // Delete Faculty info
    void deleteFacultyInfo()
    {

        int choice;
        do
        {
            deleteFacultyMenu();
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                eraseSrcByName();
                break;
            case 2:
                eraseSrcByPhoneNumber();
                break;
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }
    void eraseFromHead()
    {
        FacultyInfo *temp = facultyList;
        facultyList = temp->next;
        // size--;
        cout << "Delete " << facultyList->name << "Faculty Info From Our List" << endl;
        delete temp;

        // return;
    }
    void eraseSrcByName()
    {

        string name;

        cout << "Enter name to delete: ";
        cin >> name;

        FacultyInfo* current = facultyList;
        FacultyInfo* previous = nullptr;

        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Person not found." << endl;
            return;
        }

        if (previous == nullptr) {
            facultyList = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        cout<<"Data Delete Succfully"<<endl;









        /*
        string src_name;
        cout << "Please Enter the name: ";
        fflush(stdin);
        getline(cin, src_name);
   
        if (facultyList == NULL)
        {
            cout << "No data in your file" << endl;
            return;
        }

        int cur_indx = 0;
        FacultyInfo *a = facultyList;
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
        cout << cur_indx << endl;
        if (flag)
        {
            cout << endl;
            // cout << "Name Found " << endl;
        }
        else
        {
            cout << "Sorry! Name Not Found";
            return;
        }

        if (cur_indx == 0)
        {
            eraseFromHead();
            return;
        }
        int count_index = 0;
        FacultyInfo *prev = facultyList;
        while (count_index != cur_indx - 1)
        {
            prev = prev->next;
            count_index++;
        }

        prev->next = a->next;
        cout << "Delete " << a->name << "Faculty Info From Our List" << endl;
        delete a;
        */
    }

    void eraseSrcByPhoneNumber()
    {
        string src_PhNO;
        cout << "Please Enter the Phone_Number: ";
        fflush(stdin);
        getline(cin, src_PhNO);

        if (facultyList == NULL)
        {
            cout << "No data in your file" << endl;
            return;
        }

        int cur_indx = 0;
        FacultyInfo *a = facultyList;
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
        cout << cur_indx << endl;
        if (flag)
        {
            cout << endl;
            // cout << "Name Found " << endl;
        }
        else
        {
            cout << "Sorry! Name Not Found";
            return;
        }

        if (cur_indx == 0)
        {
            eraseFromHead();
            return;
        }
        int count_index = 0;
        FacultyInfo *prev = facultyList;
        while (count_index != cur_indx - 1)
        {
            prev = prev->next;
        }

        prev->next = a->next;
        // size--;
        cout << "Delete " << a->name << "Faculty Info From Our List" << endl;
        delete a;
    }
    // delete method end

    // Faculty Search Start
    void searchFacultyInfo()
    {
        int choice;
        do
        {
            searchFacultyMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                fac_searchByName();
                break;
            case 2:
                fac_searchByPhoneNo();
                break;

            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }

        } while (choice != 0);
    }

    void fac_searchByName()
    {
        string src_name;
        cout << "Please Enter the name: ";
        fflush(stdin);
        getline(cin, src_name);

        FacultyInfo *a = facultyList;
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
        }
        if (flag)
        {
            cout << "Name Found " << endl;
        }
        else
        {
            cout << "Sorry! Name Not Found" << endl;
        }
    }

    // Search By Phone NUmber
    void fac_searchByPhoneNo()
    {
        string src_ph_no;
        cout << "Please Enter the Phone Number: ";
        fflush(stdin);
        getline(cin, src_ph_no);

        FacultyInfo *a = facultyList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_ph_no.length(); i++)
            {
                if (src_ph_no[i] != a->mobileNumber[i])
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
        }
        if (flag)
        {
            cout << "Name Found ok" << endl;
        }
        else
        {
            cout << "Sorry! Name Not Found" << endl;
        }
    }

    // Faculty Seacrch end
    void updateFacultyInfo()
    {
        string src_name;
        cout << "Please Enter the name which faculy info want to Update: ";
        fflush(stdin);
        getline(cin, src_name);

        FacultyInfo *a = facultyList;
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
        }
        if (flag)
        {
            cout<<"Name is Found Please give Updated Information"<<endl<<endl;
            string name, designation, emailID, ext, room, mobileNumber;

            fflush(stdin);
            cout << "Enter Updatede Faculty Full Name: ";
            getline(cin, name);
            fflush(stdin);
            cout << "Enter Updatede Faulty Designation: ";
            getline(cin, designation);
            fflush(stdin);
            cout << "Enter Updatede Faculty Email ID: ";
            getline(cin, emailID);
            fflush(stdin);
            cout << "Enter Updatede EXT Nunber: ";
            getline(cin, ext);
            fflush(stdin);
            cout << "Enter Updatede Room Number: ";
            getline(cin, room);
            fflush(stdin);
            cout << "Enter Updatede Mobile Number: ";
            getline(cin, mobileNumber);
            fflush(stdin);

            a->name = name;
            a->designation = designation;
            a->emailID = emailID;
            a->ext = ext;
            a->room = room;
            a->mobileNumber = mobileNumber;

            cout <<endl<< "Faculty information updated successfully!" << endl;
            return;
        }
        else
        {
            cout << "Sorry! Name Not Found in Faculty List" << endl;
        }
    }

    //sss
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "File not found." << endl;
            return;
        }

        string name,fc_intital, designation, emailID, ext, room, mobileNumber;

        while (getline(file, name)) {
            file >>fc_intital >> designation >> emailID >> ext >> room >> mobileNumber;
            file.ignore();
            addPersonFromFile(name,fc_intital, designation, emailID, ext, room, mobileNumber);
        }

        file.close();
    }

void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        FacultyInfo *current = facultyList;
        while (current != nullptr) {
            file << current->name <<endl;
            file << current->designation << " " <<current->fc_intital<<" "
            << current->emailID <<" "<< current->ext<<" "<<current->room<<" "<<current->mobileNumber<< endl;

            current = current->next;
        }

        file.close();
    }

    //new add faculty form file
    void addPersonFromFile(string name, string fc_intital, string designation, string emailID, string ext, string room, string mobileNumber) {
        FacultyInfo *newFaculty = new FacultyInfo(name,fc_intital, designation, emailID, ext, room, mobileNumber);

        if (facultyList == nullptr) {
            facultyList=newFaculty;
        } else {
            FacultyInfo *current = facultyList;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newFaculty;
        }
    }

};
int main()
{
    CourseManagementSystem cms;
    cms.run();
}