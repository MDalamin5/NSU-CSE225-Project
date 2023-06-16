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
        this->fc_intital = fc_intital;
        this->designation = designation;
        this->emailID = emailID;
        this->ext = ext;
        this->room = room;
        this->mobileNumber = mobileNumber;
        this->next = NULL;
    }
};

// Polash
//  CourseInfo class
class CourseInfo
{
public:
    string courseCode;
    string courseTitle;
    double credits;
    string courseType;
    CourseInfo *next;

    CourseInfo(string courseCode, string courseTitle, double credits, string courseType)
    {
        this->courseCode = courseCode;
        this->courseTitle = courseTitle;
        this->credits = credits;
        this->courseType = courseType;
        this->next = NULL;
    }
};
// Polash end

// shamim start
// Course Assignment class
class CourseAssignmentInfo
{
public:
    string course;
    string section;
    string instructor;
    string start_time;
    string end_time;
    string day;
    string room;
    CourseAssignmentInfo *next;

    CourseAssignmentInfo(string course, string section, string instructor, string start_time, string end_time, string day, string room)
    {
        this->course = course;
        this->section = section;
        this->instructor = instructor;
        this->start_time = start_time;
        this->end_time = end_time;
        this->day = day;
        this->room = room;
        this->next = NULL;
    }
};
// shamim end

// CourseManagementSystem class
class CourseManagementSystem
{
private:
    FacultyInfo *facultyList;
    CourseInfo *courseList;
    CourseAssignmentInfo *courseAssignmentList;
    CourseAssignmentInfo *stuCourseSelection;

public:
    CourseManagementSystem()
    {
        facultyList = NULL;
        courseList = NULL;
        courseAssignmentList = NULL;
        stuCourseSelection = NULL;
    }

    void homePage()
    {
        cout << "===== Course Management System =====" << endl;
        cout << "1. Faculty Information" << endl;
        cout << "2. Course Information" << endl;
        cout << "3. Course Assignment Information" << endl;
        cout << "4. Generating Report" << endl;
        cout << "5. Advising Window" << endl;
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
    // Report generate Menu
    void reportGeneratingMenu()
    {
        cout << "=====  Generating Report Information =====" << endl;
        cout << "1. Faculty-wise Routien" << endl;
        cout << "2. Course-wise Routine" << endl;
        cout << "3. Room-wise Routine" << endl;
        cout << "0. Back To Home Page" << endl;
        cout << "========================================" << endl;
    }
    // Advising Menu
    void advisingMenu()
    {
        cout << "=====  Welcome to Advising Page =====" << endl;
        cout << "1. Take Course" << endl;
        cout << "2. Show My List of the Course" << endl;
        cout << "3. Delete A Course From List" << endl;
        cout << "4. Reset My Course List" << endl;
        cout << "5. Save Course" << endl;
        cout << "6. Offer Course List" << endl;
        cout << "0. Back To Home Page" << endl;
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
                courseInfoPage();
                break;
            case 3:
                courseAssignmentInfoPage();
                break;
            case 4:
                reportGeneratingPage();
                break;
            case 5:
                advisingPage();
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
                cout << "Data Saved in File" << endl;
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
        string name, fc_initial, designation, emailID, ext, room, mobileNumber;

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

        FacultyInfo *newFaculty = new FacultyInfo(name, fc_initial, designation, emailID, ext, room, mobileNumber);

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
/*
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
                     << "Initeial: " << temp->fc_intital << " "
                     << "Designation: " << temp->designation << "  "
                     << "Email id: " << temp->emailID
                     << "  "
                     << "Ext: " << temp->ext << "  "
                     << "Room No: " << temp->room << "  "
                     << "Mobile Number: " << temp->mobileNumber << endl
                     << endl;

                cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                temp = temp->next;
            }
        }
    }
    */
   void displayFacultyInfo()
{
    if (facultyList == NULL)
    {
        cout << "No faculty information found!" << endl;
    }
    else
    {
        FacultyInfo *temp = facultyList;
        int serialNumber = 1;
        cout << "==================================================================================================================================================================" << endl;
        cout << "| " << left << setw(4) << "No.";
        cout << "| " << left << setw(38) << "Name";
        cout << "| " << left << setw(10) << "Initial";
        cout << "| " << left << setw(25) << "Designation";
        cout << "| " << left << setw(30) << "Email ID";
        cout << "| " << left << setw(6) << "Ext";
        cout << "| " << left << setw(12) << "Room No";
        cout << "| " << left << "Mobile Number" << " |" << endl;
        cout << "==================================================================================================================================================================" << endl;

        while (temp != NULL)
        {
            cout << "| " << left << setw(4) << serialNumber;
            cout << "| " << left << setw(38) << temp->name;
            cout << "| " << left << setw(10) << temp->fc_intital;
            cout << "| " << left << setw(25) << temp->designation;
            cout << "| " << left << setw(30) << temp->emailID;
            cout << "| " << left << setw(6) << temp->ext;
            cout << "| " << left << setw(12) << temp->room;
            cout << "| " << left << temp->mobileNumber << " |" << endl;

            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            temp = temp->next;
            serialNumber++;
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
        fflush(stdin);
        getline(cin, name);

        FacultyInfo *current = facultyList;
        FacultyInfo *previous = nullptr;

        while (current != nullptr && current->name != name)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Person not found." << endl;
            return;
        }

        if (previous == nullptr)
        {
            facultyList = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        cout << "Data Delete Succfully" << endl;

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
        // cout << cur_indx << endl;
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
            cout << "Name is Found Please give Updated Information" << endl
                 << endl;
            string name, fc_initial, designation, emailID, ext, room, mobileNumber;

            fflush(stdin);
            cout << "Enter Updatede Faculty Full Name: ";
            getline(cin, name);
            fflush(stdin);
            cout << "Enter Faculty Intitial: ";
            getline(cin, fc_initial);
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
            a->fc_intital = fc_initial;
            a->designation = designation;
            a->emailID = emailID;
            a->ext = ext;
            a->room = room;
            a->mobileNumber = mobileNumber;

            cout << endl
                 << "Faculty information updated successfully!" << endl;
            return;
        }
        else
        {
            cout << "Sorry! Name Not Found in Faculty List" << endl;
        }
    }

    // sss
    void loadFromFile(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "File not found." << endl;
            return;
        }

        string name, fc_intital, designation, emailID, ext, room, mobileNumber;

        while (getline(file, name))
        {
            file >> fc_intital >> designation >> emailID >> ext >> room >> mobileNumber;
            file.ignore();
            addPersonFromFile(name, fc_intital, designation, emailID, ext, room, mobileNumber);
        }

        file.close();
    }

    void saveToFile(const string &filename)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Error opening file for writing." << endl;
            return;
        }

        FacultyInfo *current = facultyList;
        while (current != nullptr)
        {
            file << current->name << endl;
            file << current->designation << " " << current->fc_intital << " "
                 << current->emailID << " " << current->ext << " " << current->room << " " << current->mobileNumber << endl;

            current = current->next;
        }

        file.close();
    }

    // new add faculty form file
    void addPersonFromFile(string name, string fc_intital, string designation, string emailID, string ext, string room, string mobileNumber)
    {
        FacultyInfo *newFaculty = new FacultyInfo(name, fc_intital, designation, emailID, ext, room, mobileNumber);

        if (facultyList == nullptr)
        {
            facultyList = newFaculty;
        }
        else
        {
            FacultyInfo *current = facultyList;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newFaculty;
        }
    }

    // Polash start

    // Delete course info menu
    void deleteCourseMenu()
    {
        cout << "=====  Delete Course Information =====" << endl;
        cout << "1. Delete By searching Course Code " << endl;
        cout << "2. Delete By searching Course Title" << endl;
        cout << "0. Back to Course Page" << endl;
        cout << "========================================" << endl;
    }
    // course Search Menu
    void searchCourseMenu()
    {
        cout << "===== Search Course Information =====" << endl;
        cout << "1. Search By Course Code " << endl;
        cout << "2. Search By Course Title " << endl;
        cout << "0. Back to Course Page" << endl;
        cout << "========================================" << endl;
    }
    void courseInfoPage()
    {
        int choice;
        string filename = "course.txt";
        loadFromCourseFile(filename);
        do
        {
            courseInfoMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addCourseInfo();
                break;
            case 2:
                displayCourseInfo();
                break;
            case 3:
                updateCourseInfo();
                break;
            case 4:
                deleteCourseInfo();
                break;
            case 5:
                searchCourseInfo();
                break;
            case 6:
                saveToCourseFile(filename);
                cout << "Data Saved in File" << endl;
                break;
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }

    void addCourseInfo()
    {
        string courseCode, courseTitle, courseType;
        double credits;

        fflush(stdin);
        cout << "Enter Course Code: ";
        getline(cin, courseCode);
        fflush(stdin);
        cout << "Enter Course Title: ";
        getline(cin, courseTitle);
        fflush(stdin);
        cout << "Enter Course Credits: ";
        cin >> credits;
        fflush(stdin);
        cout << "Enter Course Type: ";
        getline(cin, courseType);
        fflush(stdin);

        CourseInfo *newCourse = new CourseInfo(courseCode, courseTitle, credits, courseType);

        // Add the new coure info to the linked list
        if (courseList == NULL)
        {
            courseList = newCourse;
        }
        else
        {
            CourseInfo *temp = courseList;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newCourse;
        }

        cout << "Course information added successfully!" << endl;
    }

    // display course information
    /*
    void displayCourseInfo()
    {
        if (courseList == NULL)
        {
            cout << "No Course information found!" << endl;
        }
        else
        {
            CourseInfo *temp = courseList;
            cout << "===== Course Information =====" << endl;
            while (temp != NULL)
            {
                cout << "Course Code: " << temp->courseCode << "  "
                     << "Course Title: " << temp->courseTitle << "  "
                     << "Course Credits: " << temp->credits << "  "
                     << "Course Type: " << temp->courseType << "  "
                     << endl;

                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                temp = temp->next;
            }
        }
    }
    */

   void displayCourseInfo()
{
    if (courseList == NULL)
    {
        cout << "No Course information found!" << endl;
    }
    else
    {
        CourseInfo *temp = courseList;
        int serialNumber = 1;
        cout << "=============================================================================================" << endl;
        cout << "| " << left << setw(4) << "No.";
        cout << "| " << left << setw(12) << "Course Code";
        cout << "| " << left << setw(38) << "Course Title";
        cout << "| " << left << setw(15) << "Course Credits";
        cout << "| " << left << "Course Type" << " |" << endl;
        cout << "=============================================================================================" << endl;

        while (temp != NULL)
        {
            cout << "| " << left << setw(4) << serialNumber;
            cout << "| " << left << setw(12) << temp->courseCode;
            cout << "| " << left << setw(38) << temp->courseTitle;
            cout << "| " << left << setw(15) << temp->credits;
            cout << "| " << left << temp->courseType << " |" << endl;

            cout << "---------------------------------------------------------------------------------------------" << endl;
            temp = temp->next;
            serialNumber++;
        }
    }
}


    // Delete course info
    void deleteCourseInfo()
    {

        int choice;
        do
        {
            deleteCourseMenu();
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                eraseSrcByCourseCode();
                break;
            case 2:
                eraseSrcByCourseTitle();
                break;
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }
    void eraseCourseFromHead()
    {
        CourseInfo *temp = courseList;
        courseList = temp->next;
        // size--;
        cout << "Delete " << courseList->courseCode << " Course Info From  List" << endl;
        delete temp;

        // return;
    }

    void eraseSrcByCourseCode()
    {

        string courseCode;

        cout << "Enter the Course Code to delete: ";
        cin >> courseCode;

        CourseInfo *current = courseList;
        CourseInfo *previous = nullptr;

        while (current != nullptr && current->courseCode != courseCode)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Course Code not found." << endl;
            return;
        }

        if (previous == nullptr)
        {
            courseList = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        cout << "Data Delete Succfully" << endl;
    }
    void eraseSrcByCourseTitle()
    {
        string src_courseTitle;
        cout << "Please Enter the Course Title: ";
        fflush(stdin);
        getline(cin, src_courseTitle);

        if (courseList == NULL)
        {
            cout << "No data in your file" << endl;
            return;
        }

        int cur_indx = 0;
        CourseInfo *a = courseList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_courseTitle.length(); i++)
            {
                if (src_courseTitle[i] != a->courseTitle[i])
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
            // cout << "Course Title Found " << endl;
        }
        else
        {
            cout << "Sorry! Course Title Not Found";
            return;
        }

        if (cur_indx == 0)
        {
            eraseCourseFromHead();
            return;
        }
        int count_index = 0;
        CourseInfo *prev = courseList;
        while (count_index != cur_indx - 1)
        {
            prev = prev->next;
        }

        prev->next = a->next;
        // size--;
        cout << "Delete " << a->courseTitle << " Course Info From Our List" << endl;
        delete a;
    }
    // delete method end

    // Faculty Search Start
    void searchCourseInfo()
    {
        int choice;
        do
        {
            searchCourseMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cou_searchByCourseCode();
                break;
            case 2:
                cou_searchByCourseTitle();
                break;

            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }

        } while (choice != 0);
    }

    // search by course code
    void cou_searchByCourseCode()
    {
        string src_courseCode;
        cout << "Please Enter the Course Code: ";
        fflush(stdin);
        getline(cin, src_courseCode);

        CourseInfo *a = courseList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_courseCode.length(); i++)
            {
                if (src_courseCode[i] != a->courseCode[i])
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
            cout << "Course Found " << endl;
        }
        else
        {
            cout << "Sorry! Course Not Found" << endl;
        }
    }

    // Search By course Title
    void cou_searchByCourseTitle()
    {
        string src_courseTitle;
        cout << "Please Enter the Course Title: ";
        fflush(stdin);
        getline(cin, src_courseTitle);

        CourseInfo *a = courseList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_courseTitle.length(); i++)
            {
                if (src_courseTitle[i] != a->courseTitle[i])
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
            cout << "Course  Found " << endl;
        }
        else
        {
            cout << "Sorry! Course  Not Found" << endl;
        }
    }

    // Course  Search end

    // update course info
    void updateCourseInfo()
    {
        string src_courseCode;
        cout << "Please Enter the Course Code which Course info want to Update: ";
        fflush(stdin);
        getline(cin, src_courseCode);

        CourseInfo *a = courseList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_courseCode.length(); i++)
            {
                if (src_courseCode[i] != a->courseCode[i])
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
            cout << "Course Code is Found Please give Updated Information" << endl
                 << endl;
            string courseCode, courseTitle, courseType;
            double credits;

            fflush(stdin);
            cout << "Enter Updatede Course Code: ";
            getline(cin, courseCode);
            fflush(stdin);
            cout << "Enter Updatede Course Title: ";
            getline(cin, courseTitle);
            fflush(stdin);
            cout << "Enter Updatede Course Credits: ";
            cin >> credits;
            fflush(stdin);
            cout << "Enter Updatede Course Type: ";
            getline(cin, courseType);
            fflush(stdin);

            a->courseCode = courseCode;
            a->courseTitle = courseTitle;
            a->credits = credits;
            a->courseType = courseType;

            cout << endl
                 << "Course information updated successfully!" << endl;
            return;
        }
        else
        {
            cout << "Sorry! Course Not Found in Course List" << endl;
        }
    }

    // course file
    void loadFromCourseFile(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "File not found." << endl;
            return;
        }

        string courseCode, courseTitle, courseType;
        double credits;

        while (getline(file, courseCode))
        {
            file >> courseTitle >> credits >> courseType;
            file.ignore();
            addCourseFromFile(courseCode, courseTitle, credits, courseType);
        }

        file.close();
    }

    void saveToCourseFile(const string &filename)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Error opening file for writing." << endl;
            return;
        }

        CourseInfo *current = courseList;
        while (current != nullptr)
        {
            file << current->courseCode << endl;
            file << current->courseTitle << " "
                 << current->credits << " " << current->courseType << endl;

            current = current->next;
        }

        file.close();
    }

    // new add Course form file

    void addCourseFromFile(string courseCode, string courseTitle, double credits, string courseType)
    {
        CourseInfo *newCourse = new CourseInfo(courseCode, courseTitle, credits, courseType);

        if (courseList == nullptr)
        {
            courseList = newCourse;
        }
        else
        {
            CourseInfo *current = courseList;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newCourse;
        }
    }
    // Polash end

    // Shamim Start

    // Delete Faculty info menu
    void deleteCourseAssignmentMenu()
    {
        cout << "===== Delete course Assignment Information =====" << endl;
        cout << "1. Delete By searching Course Name" << endl;
        cout << "2. Delete By searching Course Instructor " << endl;
        cout << "0. Back Course Assignment Page" << endl;
        cout << "========================================" << endl;
    }
    // Course Assignment Search Menu
    void searchCourseAssignmentMenu()
    {
        cout << "===== Delete Course Assignment Information =====" << endl;
        cout << "1. Search By Course Name" << endl;
        cout << "2. Search By Course Instructor " << endl;
        cout << "0. Back Course Assignment Page" << endl;
        cout << "========================================" << endl;
    }

    void courseAssignmentInfoPage()
    {
        int choice;
        string filename = "CourseAssignment.txt";
        loadFromCourseAssignmentFile(filename);
        do
        {
            courseAssignmentInfoMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addCourseAssignmentInfo();
                break;
            case 2:
                displayCourseAssignmentInfo();
                break;
            case 3:
                updateCourseAssignmentInfo();
                break;
            case 4:
                deleteCourseAssignmentInfo();
                break;
            case 5:
                searchCourseAssignmentInfo();
                break;
            case 6:
                saveToCourseAssignmentFile(filename);
                cout << "Data Saved in File" << endl;
                break;
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }
    void addCourseAssignmentInfo()
    {
        string course, section, instructor, start_time, end_time, day, room;

        fflush(stdin);
        cout << "Enter Course Name: ";
        getline(cin, course);

        fflush(stdin);
        cout << "Enter Section: ";
        getline(cin, section);

        fflush(stdin);
        cout << "Enter Instructor initial: ";
        getline(cin, instructor);

        fflush(stdin);
        cout << "Enter Class Start time: ";
        getline(cin, start_time);

        fflush(stdin);
        cout << "Enter Class End time: ";
        getline(cin, end_time);

        fflush(stdin);
        cout << "Enter Class Day: ";
        getline(cin, day);

        fflush(stdin);
        cout << "Enter Room Number: ";
        getline(cin, room);
        fflush(stdin);

        CourseAssignmentInfo *newCourseAssignment = new CourseAssignmentInfo(course, section, instructor, start_time, end_time, day, room);

        // Add the new Course assignment info to the linked list
        if (courseAssignmentList == NULL)
        {
            courseAssignmentList = newCourseAssignment;
        }
        else
        {
            CourseAssignmentInfo *temp = courseAssignmentList;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newCourseAssignment;
        }

        cout << "Course Assignment information added successfully!" << endl;
    }

/*
    void displayCourseAssignmentInfo()
    {
        if (courseAssignmentList == NULL)
        {
            cout << "No Course Assignment information found!" << endl;
            cout << "No Course Offering Right now!" << endl;
            return;
        }
        else
        {
            CourseAssignmentInfo *temp = courseAssignmentList;
            cout << "===== Course Assignment Information =====" << endl;
            while (temp != NULL)
            {
                cout << "Course Name: " << temp->course << " | "
                     << "Section: " << temp->section << " "
                     << "Instructor: " << temp->instructor << " | "
                     << "Start time: " << temp->start_time << " | "
                     << "End time: " << temp->end_time << " | "
                     << "Day: " << temp->day << " | "
                     << "Room: " << temp->room << " | " << endl;
                cout << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                temp = temp->next;
            }
        }
    }
*/

void displayCourseAssignmentInfo()
{
    if (courseAssignmentList == NULL)
    {
        cout << "No Course Assignment information found!" << endl;
        cout << "No Course Offering Right now!" << endl;
        return;
    }
    else
    {
        CourseAssignmentInfo *temp = courseAssignmentList;
        int serialNumber = 1;
        cout << "====================================================================================" << endl;
        cout << "| " << left << setw(4) << "No.";
        cout << "| " << left << setw(12) << "Course Name";
        cout << "| " << left << setw(8) << "Section";
        cout << "| " << left << setw(10) << "Instructor";
        cout << "| " << left << setw(10) << "Start Time";
        cout << "| " << left << setw(10) << "End Time";
        cout << "| " << left << setw(5) << "Day";
        cout << "| " << left << "Room" << " |" << endl;
        cout << "====================================================================================" << endl;

        while (temp != NULL)
        {
            cout << "| " << left << setw(4) << serialNumber;
            cout << "| " << left << setw(12) << temp->course;
            cout << "| " << left << setw(8) << temp->section;
            cout << "| " << left << setw(10) << temp->instructor;
            cout << "| " << left << setw(10) << temp->start_time;
            cout << "| " << left << setw(10) << temp->end_time;
            cout << "| " << left << setw(5) << temp->day;
            cout << "| " << left << temp->room << " |" << endl;

            cout << "--------------------------------------------------------------------------------------" << endl;
            temp = temp->next;
            serialNumber++;
        }
    }
}

        
    // Delete Course Assignment info
    void deleteCourseAssignmentInfo()
    {

        int choice;
        do
        {
            deleteCourseAssignmentMenu();
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                eraseSrcByCourseName();
                break;
            case 2:
                eraseSrcByCourseInstructor();
                break;
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }
    void eraseFromCourseAssignmentHead()
    {
        CourseAssignmentInfo *temp = courseAssignmentList;
        courseAssignmentList = temp->next;
        // size--;
        cout << "Delete " << courseAssignmentList->course << " CourseAssignment Info From Our List" << endl;
        delete temp;

        // return;
    }
    void eraseSrcByCourseName()
    {

        string course;

        cout << "Enter course name to delete: ";
        cin >> course;

        CourseAssignmentInfo *current = courseAssignmentList;
        CourseAssignmentInfo *previous = nullptr;

        while (current != nullptr && current->course != course)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Course not found." << endl;
            return;
        }

        if (previous == nullptr)
        {
            courseAssignmentList = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        cout << "Data Delete Succfully" << endl;
    }

    void eraseSrcByCourseInstructor()
    {
        string src_courseInstructor;
        cout << "Please Enter the course Instructor: ";
        fflush(stdin);
        getline(cin, src_courseInstructor);

        if (courseAssignmentList == NULL)
        {
            cout << "No data in your file" << endl;
            return;
        }

        int cur_indx = 0;
        CourseAssignmentInfo *a = courseAssignmentList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_courseInstructor.length(); i++)
            {
                if (src_courseInstructor[i] != a->instructor[i])
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
            // cout << "Name of Instructor Found " << endl;
        }
        else
        {
            cout << "Sorry! Name of Instructor Not Found";
            return;
        }

        if (cur_indx == 0)
        {
            eraseFromCourseAssignmentHead();
            return;
        }
        int count_index = 0;
        CourseAssignmentInfo *prev = courseAssignmentList;
        while (count_index != cur_indx - 1)
        {
            prev = prev->next;
        }

        prev->next = a->next;
        // size--;
        cout << "Delete " << a->instructor << " Course Assignment Info From Our List" << endl;
        delete a;
    }
    // delete method end

    // Course Assignment Search Start
    void searchCourseAssignmentInfo()
    {
        int choice;
        do
        {
            searchCourseAssignmentMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                ass_searchByCourseName();
                break;
            case 2:
                ass_searchByCourseInstructor();
                break;

            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }

        } while (choice != 0);
    }

    void ass_searchByCourseName()
    {
        string src_courseName;
        cout << "Please Enter the Course name: ";
        fflush(stdin);
        getline(cin, src_courseName);

        CourseAssignmentInfo *a = courseAssignmentList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_courseName.length(); i++)
            {
                if (src_courseName[i] != a->course[i])
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
            cout << "Course name Found " << endl;
        }
        else
        {
            cout << "Sorry! course Name Not Found" << endl;
        }
    }

    // Search By instructor name
    void ass_searchByCourseInstructor()
    {
        string src_courseInstructor;
        cout << "Please Enter the course Instructor: ";
        fflush(stdin);
        getline(cin, src_courseInstructor);

        CourseAssignmentInfo *a = courseAssignmentList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_courseInstructor.length(); i++)
            {
                if (src_courseInstructor[i] != a->instructor[i])
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
            cout << "Instructor Name Found ok" << endl;
        }
        else
        {
            cout << "Sorry! Instructor Name Not Found" << endl;
        }
    }

    // Course Assignment Search end

    void updateCourseAssignmentInfo()
    {
        string src_courseName;
        cout << "Please Enter the course which  info want to Update: ";
        fflush(stdin);
        getline(cin, src_courseName);

        CourseAssignmentInfo *a = courseAssignmentList;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_courseName.length(); i++)
            {
                if (src_courseName[i] != a->course[i])
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
            cout << "Course Name is Found. Please give Update information" << endl
                 << endl;
            string course, section, instructor, start_time, end_time, day, room;

            fflush(stdin);
            cout << "Enter Updated Course Name: ";
            getline(cin, course);

            fflush(stdin);
            cout << "Enter Updated Section: ";
            getline(cin, section);

            fflush(stdin);
            cout << "Enter Updated Instructor Initial: ";
            getline(cin, instructor);

            fflush(stdin);
            cout << "Enter Updated Start time: ";
            getline(cin, start_time);

            fflush(stdin);
            cout << "Enter Updated End time: ";
            getline(cin, end_time);

            fflush(stdin);
            cout << "Enter Updated Day: ";
            getline(cin, day);

            fflush(stdin);
            cout << "Enter Updated Room: ";
            getline(cin, room);
            fflush(stdin);

            a->course = course;
            a->section = section;
            a->instructor = instructor;
            a->start_time = start_time;
            a->end_time = end_time;
            a->day = day;
            a->room = room;

            cout << endl
                 << " Course Assignment Information updated successfully!" << endl;
            return;
        }
        else
        {
            cout << "Sorry! Course name Not Found in Course Assignment List" << endl;
        }
    }

    // sss
    void loadFromCourseAssignmentFile(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "File not found." << endl;
            return;
        }

        string course, section, instructor, start_time, end_time, day, room;

        while (getline(file, course))
        {
            file >> section >> instructor >> start_time >> end_time >> day >> room;
            file.ignore();
            addFromCourseAssignmentFile(course, section, instructor, start_time, end_time, day, room);
        }

        file.close();
    }

    void saveToCourseAssignmentFile(const string &filename)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Error opening file for writing." << endl;
            return;
        }

        CourseAssignmentInfo *current = courseAssignmentList;
        while (current != nullptr)
        {
            file << current->course << endl;
            file << current->section << " "
                 << current->instructor << " " << current->start_time << " " << current->end_time << " " << current->day << " " << current->room << endl;

            current = current->next;
        }

        file.close();
    }

    // new add faculty form file
    void addFromCourseAssignmentFile(string course, string section, string instructor, string start_time, string end_time, string day, string room)
    {
        CourseAssignmentInfo *newCourseAssignment = new CourseAssignmentInfo(course, section, instructor, start_time, end_time, day, room);

        if (courseAssignmentList == nullptr)
        {
            courseAssignmentList = newCourseAssignment;
        }
        else
        {
            CourseAssignmentInfo *current = courseAssignmentList;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newCourseAssignment;
        }
    }

    // report part

    void reportGeneratingPage()
    {
        int choice;
        do
        {
            reportGeneratingMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                generateInstructorReport();
                break;
            case 2:

                generateCourseWiseReport();
                break;
            case 3:
                generateRoomWiseReport();
                break;
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }

    // Faculty wise Routine
    



void generateInstructorReport()
{
    string instructorInitials;
    cout << "Enter Faculty Initial: ";
    cin >> instructorInitials;
    cout << endl;

    fflush(stdin);
    int courseCount = 0;

    string facultyName = getFacultyName(instructorInitials);
    

    cout << "Faculty Name: " << facultyName << endl << endl;

    CourseAssignmentInfo *current = courseAssignmentList;
    while (current != nullptr)
    {
        if (current->instructor == instructorInitials)
        {
            if (courseCount == 0)
            {
                cout << "================================================================" << endl;
                cout << "| " << left << setw(4) << "No.";
                cout << "| " << left << setw(11) << "Course Code";
                cout << "| " << left << setw(5) << "Day";
                cout << "| " << left << setw(10) << "Start Time";
                cout << "| " << left << setw(10) << "End Time";
                cout << "| " << left << "Class Room" << " |" << endl;
                cout << "================================================================" << endl;
            }

            cout << "| " << left << setw(4) << courseCount + 1;
            cout << "| " << left << setw(11) << (current->course + "." + current->section);
            cout << "| " << left << setw(5) << current->day;
            cout << "| " << left << setw(10) << current->start_time;
            cout << "| " << left << setw(10) << current->end_time;
            cout << "| " << left << current->room << " |" << endl;

            cout << "-----------------------------------------------------------------" << endl;
            courseCount++;
        }
        current = current->next;
    }

    if (courseCount == 0)
    {
        cout << "This semester " << instructorInitials << " is not taking any courses." << endl << endl;
    }
    else
    {
        cout << "Total courses taken by instructor " << instructorInitials << ": " << courseCount << endl << endl;
    }
}



 string getFacultyName(string fac_intitial)
 {
    FacultyInfo *cur = facultyList;
    while(cur!=NULL)
    {
        if(cur->fc_intital==fac_intitial)
        {
            return cur->name;
        }
        cur=cur->next;
    }
    return "To Be Announced";
 }

 

     void generateCourseWiseReport()
{
    string courseCode;
    cout << "Enter Course Code Only: ";
    cin >> courseCode;
    cout << endl;

    fflush(stdin);
    string courseTitle = getCourseTitle(courseCode);
    

    cout << "Course Title: " << courseTitle << endl << endl;

    int courseCount = 0;
    CourseAssignmentInfo *current = courseAssignmentList;

    while (current != nullptr)
    {
        if (current->course == courseCode)
        {
            if (courseCount == 0)
            {
                cout << "========================================================================================" << endl;
                cout << "| " << left << setw(4) << "No.";
                cout << "| " << left << setw(15) << "Course Section";
                cout << "| " << left << setw(15) << "Faculty Initial";
                cout << "| " << left << setw(5) << "Day";
                cout << "| " << left << setw(10) << "Start Time";
                cout << "| " << left << setw(10) << "End Time";
                cout << "| " << left << "Class Room" << " |" << endl;
                cout << "==========================================================================================" << endl;
            }

            cout << "| " << left << setw(4) << courseCount + 1;
            cout << "| " << left << setw(15) << current->section;
            cout << "| " << left << setw(15) << current->instructor;
            cout << "| " << left << setw(5) << current->day;
            cout << "| " << left << setw(10) << current->start_time;
            cout << "| " << left << setw(10) << current->end_time;
            cout << "| " << left << current->room << " |" << endl;

            cout << "------------------------------------------------------------------------------------------" << endl;
            courseCount++;
        }
        current = current->next;
    }

    if (courseCount == 0)
    {
        cout << "This semester does not offer the course with code: " << courseCode << endl << endl;
    }
    else
    {
        cout << "Total Number of Sections for this semester course (" << courseCode << "): " << courseCount << endl << endl;
    }
}



void generateRoomWiseReport()
{
    string roomNumber;
    cout << "Enter Room Number: ";
    cin >> roomNumber;
    cout << endl;

    int courseCount = 0;
    CourseAssignmentInfo *current = courseAssignmentList;

    while (current != nullptr)
    {
        if (current->room == roomNumber)
        {
            if (courseCount == 0)
            {
                cout << "==========================================================================================" << endl;
                cout << "| " << left << setw(4) << "No.";
                cout << "| " << left << setw(15) << "Course Code";
                cout << "| " << left << setw(15) << "Section";
                cout << "| " << left << setw(15) << "Faculty Initial";
                cout << "| " << left << setw(5) << "Day";
                cout << "| " << left << setw(10) << "Start Time";
                cout << "| " << left << setw(10) << "End Time" << " |" << endl;
                cout << "==========================================================================================" << endl;
            }

            cout << "| " << left << setw(4) << courseCount + 1;
            cout << "| " << left << setw(15) << current->course;
            cout << "| " << left << setw(15) << current->section;
            cout << "| " << left << setw(15) << current->instructor;
            cout << "| " << left << setw(5) << current->day;
            cout << "| " << left << setw(10) << current->start_time;
            cout << "| " << left << setw(10) << current->end_time << " |" << endl;

            cout << "------------------------------------------------------------------------------------------" << endl;
            courseCount++;
        }
        current = current->next;
    }

    if (courseCount == 0)
    {
        cout << "No courses are scheduled in room number: " << roomNumber << endl << endl;
    }
    else
    {
        cout << "Total Number of Classes held in room number " << roomNumber << ": " << courseCount << endl << endl;
    }
}



 

    // Report Generate end
    // advising page
    void advisingPage()
    {
        int choice;
        string filename = "studentCourse.txt";
        loadFromFileStudenCourse(filename);

        do
        {
            advisingMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                takeCourse();
                break;
            case 2:
                showMyCourseList();
                break;
            case 3:
               deleteCourseFromAdvisingList();
                break;
            case 4:
                resetMyCourseList();
                break;
            case 5:
                saveStudentCourse(filename);
                cout << "Data Saved in File" << endl;
                break;
                case 6:
                 displayCourseAssignmentInfo();
                 break;
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }
    void takeCourse()
    {
        string courseCode,s_section;
        cout << "Enter Course Code Only: ";
        cin >> courseCode;
        cout<< "Enter Course Sections: ";
        cin>>s_section;
        bool courseAdd = false;
        CourseAssignmentInfo *current = courseAssignmentList;
        while (current != nullptr)
        {
            if (current->course == courseCode && current->section==s_section)
            {
                if (stuCourseSelection == NULL)
                {
                    addStudentCourse(current->course, current->section, current->instructor, current->start_time, current->end_time, current->day, current->room);
                    courseAdd = true;
                    break;
                }
                else if(checkCourseDuplicateConflict(current))
                {
                    cout<<"This Course alrady your List."<<endl;
                    cout<<"You can add this Section But remove that Course First... "<<endl;
                    return;
                }
                else if (checkCourseDayConflict(current))
                {
                    cout << "You can not add this course" << endl;
                    cout << "Try to add anothr section" << endl;
                    return;
                }
                else if (!checkCreditLimit(current))
                {
                    cout << "Credit limit is exceeded." << endl;
                    return;
                }
                else
                {
                    addStudentCourse(current->course, current->section, current->instructor, current->start_time, current->end_time, current->day, current->room);
                    courseAdd = true;
                    break;
                }
            }
            current = current->next;
        }
        if (courseAdd)
        {
            cout << "Course added Successfully!" << endl;
        }
        else
            cout << "This course: " << courseCode << " IS not offer this semister" << endl
                 << endl;
    }
    //duplicate course Conflict
    bool checkCourseDuplicateConflict(CourseAssignmentInfo *newCourse)
    {
        CourseAssignmentInfo *current = stuCourseSelection;
        while (current != nullptr)
        {
            if (current->course == newCourse->course)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // CONFLIC CHECK
    bool checkCourseDayConflict(CourseAssignmentInfo *newCourse)
    {
        CourseAssignmentInfo *current = stuCourseSelection;
        while (current != nullptr)
        {
            if (current->day == newCourse->day)
            {
                if (current->start_time == newCourse->start_time)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            current = current->next;
        }
        return false;
    }

    bool checkCreditLimit(CourseAssignmentInfo *newCourse)
    {
        double totalCredits = 0;
        CourseAssignmentInfo *current = stuCourseSelection;
        // CourseInfo *curseData=courseList;
        while (current != nullptr)
        {
            if (current->instructor == newCourse->instructor)
            {
                totalCredits += giveCourseCradit(newCourse->course);
            }
            current = current->next;
        }
        totalCredits += giveCourseCradit(newCourse->course);
        return totalCredits <= 11;
    }

    double giveCourseCradit(string courseName)
    {
        CourseInfo *cur = courseList;
        while (cur != NULL)
        {
            if (cur->courseCode == courseName)
            {
                return cur->credits;
            }
            cur = cur->next;
        }
        return 0;
    }
    string getCourseTitle(string C_code)
    {
        CourseInfo *cur = courseList;
        while (cur != NULL)
        {
            if (cur->courseCode == C_code)
            {
                return cur->courseTitle;
            }
            cur = cur->next;
        }
        return "Course Title Update Soon";
    }

    void addStudentCourse(string course, string section, string instructor, string start_time, string end_time, string day, string room)
    {
        CourseAssignmentInfo *newCourseAssignment = new CourseAssignmentInfo(course, section, instructor, start_time, end_time, day, room);

        if (stuCourseSelection == NULL)
        {
            stuCourseSelection = newCourseAssignment;
        }
        else
        {
            CourseAssignmentInfo *temp = stuCourseSelection;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newCourseAssignment;
        }
    }
    

void showMyCourseList()
{
    if (stuCourseSelection == NULL)
    {
        cout << "No Course found! Please add courses first." << endl;
    }
    else
    {
        CourseAssignmentInfo *temp = stuCourseSelection;
        cout << "===== Advising Course Information =====" << endl << endl;
        cout << "=======================================================================================================================" << endl;
        cout << "| " << left << setw(5) << "No.";
        cout << "| " << left << setw(15) << "Course Code";
        cout << "| " << left << setw(30) << "Course Title";
        cout << "| " << left << setw(15) << "Instructor";
        cout << "| " << left << setw(10) << "Start Time";
        cout << "| " << left << setw(10) << "End Time";
        cout << "| " << left << setw(5) << "Day";
        cout << "| " << left << setw(10) << "Room" << " |" << endl;
        cout << "=======================================================================================================================" << endl;

        int courseCount = 0;

        while (temp != NULL)
        {
            cout << "| " << left << setw(5) << courseCount + 1;
            cout << "| " << left << setw(15) << temp->course;
            cout << "| " << left << setw(30) << getCourseTitle(temp->course);
            cout << "| " << left << setw(15) << temp->instructor;
            cout << "| " << left << setw(10) << temp->start_time;
            cout << "| " << left << setw(10) << temp->end_time;
            cout << "| " << left << setw(5) << temp->day;
            cout << "| " << left << setw(10) << temp->room << " |" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

            courseCount++;
            temp = temp->next;
        }

        cout << endl;
        cout << "Total Courses Enrolled: " << courseCount << endl;
    }
}



    void resetMyCourseList()
    {
        CourseAssignmentInfo *current = stuCourseSelection;
        CourseAssignmentInfo *temp;
        while (current != NULL)
        {
            temp = current;
            current = current->next;
            delete temp;
        }
        stuCourseSelection=NULL;
        cout << "All Course Delete Sussfully" << endl;
    }

    void loadFromFileStudenCourse(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "File not found." << endl;
            return;
        }

        string course, section, instructor, start_time, end_time, day, room;

        while (getline(file, course))
        {
            file >> section >> instructor >> start_time >> end_time >> day >> room;
            file.ignore();
            addStdentCourseFromFile(course, section, instructor, start_time, end_time, day, room);
        }

        file.close();
    }

    void saveStudentCourse(const string &filename)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Error opening file for writing." << endl;
            return;
        }

        CourseAssignmentInfo *current = stuCourseSelection;
        while (current != nullptr)
        {
            file << current->course << endl;
            file << current->section << " "
                 << current->instructor << " " << current->start_time << " " << current->end_time << " " << current->day << " " << current->room << endl;

            current = current->next;
        }

        file.close();
    }

    void addStdentCourseFromFile(string course, string section, string instructor, string start_time, string end_time, string day, string room)
    {
        CourseAssignmentInfo *newCourseAssignment = new CourseAssignmentInfo(course, section, instructor, start_time, end_time, day, room);

        if (stuCourseSelection == nullptr)
        {
            stuCourseSelection = newCourseAssignment;
        }
        else
        {
            CourseAssignmentInfo *current = stuCourseSelection;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newCourseAssignment;
        }
    }

    void deleteCourseFromAdvisingList()
    {

        string course;

        cout << "Enter course name to delete: ";
        cin >> course;

        CourseAssignmentInfo *current = stuCourseSelection;
        CourseAssignmentInfo *previous = nullptr;

        while (current != nullptr && current->course != course)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Course not found." << endl;
            return;
        }

        if (previous == nullptr)
        {
            stuCourseSelection = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        cout << "Data Delete Succfully" << endl;
    }
};

int main()
{
    CourseManagementSystem cms;
    cms.run();
}