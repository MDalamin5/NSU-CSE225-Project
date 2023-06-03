#include <bits/stdc++.h>
using namespace std;
// Faculty Class
class FacultyInfo
{
public:
    string name;
    string designation;
    string emailID;
    string ext;
    string room;
    string mobileNumber;
    FacultyInfo *next;

    FacultyInfo(string name, string designation, string emailID, string ext, string room, string mobileNumber)
    {
        this->name = name;
        this->designation = designation;
        this->emailID = emailID;
        this->ext = ext;
        this->room = room;
        this->mobileNumber = mobileNumber;
        this->next = NULL;
    }
};


//Polash
// CourseInfo class
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
        this-> courseType= courseType;
        this->next = NULL;

    }
};
// Polash end

//shamim start
//Course Assignment class
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
//shamim end

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
                 courseInfoPage();
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
        string name, designation, emailID, ext, room, mobileNumber;

        fflush(stdin);
        cout << "Enter Faculty Full Name: ";
        getline(cin, name);
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

        FacultyInfo *newFaculty = new FacultyInfo(name, designation, emailID, ext, room, mobileNumber);

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

        string name, designation, emailID, ext, room, mobileNumber;

        while (getline(file, name)) {
            file >> designation >> emailID >> ext >> room >> mobileNumber;
            file.ignore();
            addPersonFromFile(name, designation, emailID, ext, room, mobileNumber);
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
            file << current->designation << " " 
            << current->emailID <<" "<< current->ext<<" "<<current->room<<" "<<current->mobileNumber<< endl;

            current = current->next;
        }

        file.close();
    }

    //new add faculty form file
    void addPersonFromFile(string name, string designation, string emailID, string ext, string room, string mobileNumber) {
        FacultyInfo *newFaculty = new FacultyInfo(name, designation, emailID, ext, room, mobileNumber);

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

    //Polash start

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
        loadFromFile(filename);
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

 void addCourseInfo()
    {
         string courseCode,courseTitle,courseType;
         double credits;

        fflush(stdin);
        cout << "Enter Course Code: ";
        getline(cin, courseCode);
        fflush(stdin);
        cout << "Enter Course Title: ";
        getline(cin, courseTitle);
        fflush(stdin);
        cout << "Enter Course Credits: ";
        cin>>credits;
        fflush(stdin);
        cout << "Enter Course Type: ";
        getline(cin, courseType);
        fflush(stdin);
    
        CourseInfo *newCourse = new CourseInfo(courseCode,courseTitle,credits,courseType);

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

                cout << "------------------------------" << endl;
                temp = temp->next;
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

        CourseInfo* current = courseList;
        CourseInfo* previous = nullptr;

        while (current != nullptr && current->courseCode != courseCode) {
            previous=current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Course Code not found." << endl;
            return;
        }

        if (previous == nullptr) {
            courseList = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        cout<<"Data Delete Succfully"<<endl;
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

//search by course code
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

    //update course info
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
            cout<<"Course Code is Found Please give Updated Information"<<endl<<endl;
            string courseCode,courseTitle,courseType;
            double credits;

            fflush(stdin);
            cout << "Enter Updatede Course Code: ";
            getline(cin, courseCode);
            fflush(stdin);
            cout << "Enter Updatede Course Title: ";
            getline(cin, courseTitle);
            fflush(stdin);
            cout << "Enter Updatede Course Credits: ";
            cin>>credits;
            fflush(stdin);
            cout << "Enter Updatede Course Type: ";
            getline(cin, courseType);
            fflush(stdin);

            a->courseCode = courseCode;
            a->courseTitle = courseTitle;
            a->credits = credits;
            a->courseType = courseType;

            cout <<endl<< "Course information updated successfully!" << endl;
            return;
        }
        else
        {
            cout << "Sorry! Course Not Found in Course List" << endl;
        }
    }

//course file
    void loadFromCourseFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "File not found." << endl;
            return;
        }

        string courseCode,courseTitle,courseType;
        double credits;

        while (getline(file, courseCode)) {
            file >> courseTitle >> credits >> courseType ;
            file.ignore();
            addCourseFromFile(courseCode,courseTitle,credits,courseType);
        }

        file.close();
    }

void saveToCourseFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        CourseInfo *current = courseList;
        while (current != nullptr) {
            file << current->courseCode <<endl;
            file << current->courseTitle << " " 
            << current->credits <<" "<< current->courseType<< endl;

            current = current->next;
        }

        file.close();
    }

    //new add Course form file

    void addCourseFromFile(string courseCode,string courseTitle,double credits,string courseType) {
        CourseInfo *newCourse = new CourseInfo(courseCode,courseTitle,credits,courseType);

        if (courseList == nullptr) {
            courseList=newCourse;
        } else {
            CourseInfo *current = courseList;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newCourse;
        }
    }
//Polash end


//Shamim start
//Delete Course Assignment Info Menu
    void deleteCourseAssignmentMenu()
    {
        cout<<"===== Course Assignment Delete Information ====="<<endl;
        cout<<"1. Delete By Searching Course Name"<<endl;
        cout<<"2. Delete By Searching Instructor Initial"<<endl;
        cout<<"3. Back to Course Assignment Page"<<endl;
        cout<<" ================================================="<<endl;
    }
    //Search Course Assignment Menu
    void searchCourseAsignmentMenu()
    {
        cout<<" ===== Course Assignment Search Information ====="<<endl;
        cout<<"1. Search By Course Name"<<endl;
        cout<<"2. Search By Instructor Initial"<<endl;
        cout<<"0. Back to Course Assignment Page"<<endl;
        cout<<"==================================================="<<endl;
    }
 void courseAssignmentInfoPage()
    {
        int choice;
        do
        {
            courseAssignmentInfoMenu();
            cout<<"Enter Your Choice: ";
            cin>>choice;

            switch(choice)
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
                searchCourseAsignmentInfo();
                break;
            case 6:
                saveToFile("CourseAssignment.txt");
                cout<<"Data Save in File"<<endl;
            case 0:
                cout<<"Returning to Home Page..."<<endl;
                break;
            default:
                cout<<"Invalid Choice! Please try again. "<<endl;
            }
        }while(choice != 0);
    }

    //Add Course Assignment Information
    void addCourseAssignmentInfo()
    {
        string course, section, instructor, start_time, end_time, day, room;

        fflush(stdin);
        cout<<"Enter Course Name: ";
        getline(cin, course);

        fflush(stdin);
        cout<<"Enter Section: ";
        getline(cin, section);

        fflush(stdin);
        cout<<"Enter Instructor initial: ";
        getline(cin, instructor);

        fflush(stdin);
        cout<<"Enter Class Start time: ";
        getline(cin, start_time);

        fflush(stdin);
        cout<<"Enter Class End time: ";
        getline(cin, end_time);

        fflush(stdin);
        cout<<"Enter Class Day: ";
        getline(cin, day);

        fflush(stdin);
        cout<<"Enter Room Number: ";
        getline(cin, room);
        fflush(stdin);

        CourseAssignmentInfo * newCourseAssignment = new CourseAssignmentInfo(course, section, instructor, start_time, end_time, day, room);

        //Add the new Course Assignment info to the linked list
        if(assignmentList == NULL)
        {
            assignmentList = newCourseAssignment;
        }
        else
        {
            CourseAssignmentInfo *temp = assignmentList;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newCourseAssignment;
        }
        cout<<" Course Information Added Successfully! "<<endl;
    }

    //Display Course Assignment
    void displayCourseAssignmentInfo()
    {
        if(assignmentList == NULL)
        {
            cout<<"No Course Assignment Information Found!"<<endl;
        }
        else{
            CourseAssignmentInfo *temp = assignmentList;
            cout<<"====== Course Assignment Information ======"<<endl;
            while(temp != NULL)
            {
                cout<<"Course Name: "<<temp->course<<" "
                    <<"Section: "<<temp->section<<" "
                    <<"Instructor: "<<temp->instructor<<" "
                    <<"Start time: "<<temp->start_time<<" "
                    <<"End time: "<<temp->end_time<<" "
                    <<"Day: "<<temp->day<<" "
                    <<"Room: "<<temp->room<<endl;
                cout<<endl;
                cout<<"--------------------------------------"<<endl;
                temp = temp->next;
            }
        }
    }

    //Delete Course Assignment Information
    void deleteCourseAssignmentInfo()
    {
        int choice;
        do
        {
            deleteCourseAssignmentMenu();
            cout<<"Enter Your Choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1:
                eraseSrcByCourseName();
                break;
            case 2:
                eraseSrcByIntructor();
                break;
            case 0:
                cout<<"Returning to Home Page..."<<endl;
                break;
            default:
                cout<<"Invalid Choice! Please try again."<<endl;
            }
        }
        while(choice != 0);
    }
    void eraseFromHeadCourseAssignment()
    {
        CourseAssignmentInfo *temp = assignmentList;
        assignmentList = temp->next;
        //size--;
        cout<<"Delete "<<assignmentList->course<<"Course Assignment Info From Out List"<<endl;
        delete temp;
        //return;
    }

    void eraseSrcByCourseName()
    {
        string course;
        cout<<"Please Enter the Course Name to Delete: ";
        cin>>course;

       CourseAssignmentInfo* current = assignmentList;
       CourseAssignmentInfo* previous = nullptr;

       while(current != nullptr && current->course != course)
       {
           previous = current;
           current = current->next;
       }

       if(current == nullptr)
       {
           cout<<"Course name not found! "<<endl;
           return;
       }
       if(previous == nullptr)
       {
           assignmentList = current->next;
       }
       else
       {
           previous->next = current->next;
       }
       delete current;
       cout<<"Data Delete Successfully"<<endl;
    }

    void  eraseSrcByIntructor()
    {
        string instructorInitial;
        cout<<"Please Enter the Instructor Initial: ";
        fflush(stdin);
        getline(cin, instructorInitial);

        if(assignmentList == NULL)
        {
            cout<<"No Data in Your File"<<endl;
            return;
        }

        int cur_index = 0;
        CourseAssignmentInfo *ca = assignmentList;
        bool flag;
        while(ca != NULL)
        {
            flag = true;
            for(int i =0; i<instructorInitial.length(); i++)
            {
                if(instructorInitial[i] != ca->instructor[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
            ca = ca->next;
            cur_index++;
        }
        cout<<cur_index<<endl;
        if(flag)
        {
            cout<<endl;
            //cout<<"Name Found"<<endl;
        }
        else
        {
            cout<<"Sorry! Name Not found";
            return;
        }
        int count_index = 0;
        CourseAssignmentInfo *prev = assignmentList;
        while(count_index != cur_index-1)
        {
            prev = prev->next;
        }
        prev->next = ca->next;
        //size--;
        cout<<"Delete "<<ca->course<<"Course Assignment Info From Our List"<<endl;
        delete ca;
    }

    //Search Course Assignment
    void searchCourseAsignmentInfo()
    {
        int choice;
        do
        {
            searchCourseAsignmentMenu();
            cout<<"Enter Your Choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1:
                CourseAssignmentSrcByCourseName();
                break;
            case 2:
                CourseAssignmentSrcByInstructorInitail();
                break;
            case 0:
                cout<<"Returning to Home Page..."<<endl;
                break;
            default:
                cout<<"Invalid Choice! Please try again. "<<endl;
            }
        }
        while(choice != 0);
    }

    void CourseAssignmentSrcByCourseName()
    {
        string courseName;
        cout << "Please Enter the Course name: ";
        fflush(stdin);
        getline(cin, courseName);

        CourseAssignmentInfo *ca = assignmentList;
        bool flag;
        while (ca != NULL)
        {
            flag = true;
            for (int i = 0; i < courseName.length(); i++)
            {
                if (courseName[i] != ca->course[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
            ca = ca->next;
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

    void CourseAssignmentSrcByInstructorInitail()
    {
        string instructorInitial;
        cout << "Please Enter the Instructor initial: ";
        fflush(stdin);
        getline(cin, instructorInitial);

        CourseAssignmentInfo *ca = assignmentList;
        bool flag;
        while (ca != NULL)
        {
            flag = true;
            for (int i = 0; i < instructorInitial.length(); i++)
            {
                if (instructorInitial[i] != ca->instructor[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
            ca = ca->next;
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


    //Update Course Assignment
    void updateCourseAssignmentInfo()
    {
        string courseName;
        cout<<"Please Enter the course name which do you want to Update: ";
        fflush(stdin);
        getline(cin, courseName);

        CourseAssignmentInfo *ca = assignmentList;
        bool flag;
        while(ca != NULL)
        {
            flag = true;
            for (int i = 0; i<courseName.length(); i++)
            {
                if(courseName[i] != ca->course[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
            ca = ca->next;
        }
        if(flag)
        {
            cout<<"Course Name is Found. Please give Update information"<<endl<<endl;
            string course, section, instructor, start_time, end_time, day, room;

            fflush(stdin);
            cout<<"Enter Updated Course Name: ";
            getline(cin, course);

            fflush(stdin);
            cout<<"Enter Updated Section: ";
            getline(cin, section);

            fflush(stdin);
            cout<<"Enter Updated Instructor Initial: ";
            getline(cin, instructor);

            fflush(stdin);
            cout<<"Enter Updated Start time: ";
            getline(cin, start_time);

            fflush(stdin);
            cout<<"Enter Updated End time: ";
            getline(cin, end_time);

            fflush(stdin);
            cout<<"Enter Updated Day: ";
            getline(cin, day);

            fflush(stdin);
            cout<<"Enter Updated Room: ";
            getline(cin, room);
            fflush(stdin);

            ca->course = course;
            ca->section = section;
            ca->instructor = instructor;
            ca->start_time = start_time;
            ca->end_time = end_time;
            ca->day = day;
            ca->room = room;

            cout<<endl<<" Course Assignment Information updated successfully!"<<endl;
            return;
        }
        else{
            cout<<"Sorry! Course name Not Found in Course Assignment List"<<endl;
        }
    }


    //File add
    void CourseAssignmentLoadFromFile(const string& filename)
    {
        ifstream file(filename);
        if(!file)
        {
            cout<<"File not Found! "<<endl;
            return;
        }
        string course, section, instructor, start_time, end_time, day, room;

        while (getline(file, course)) {
            file >>course>>section>>instructor>>start_time>>end_time>>day>>room;
            file.ignore();
            addCourseAssignmentFromFile(course, section, instructor, start_time, end_time, day, room);
        }

        file.close();
    }

    void saveToCourseAssignmentFile(const string& filename) {
        string filname = "CourseAssignment.txt";
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        CourseAssignmentInfo *current = assignmentList;
        while (current != nullptr) {
            file << current->course <<endl;
            file << current->section << " "
            << current->instructor <<" "<< current->start_time<<" "<<current->end_time<<" "<<current->day<<" "<<current->room<< endl;

            current = current->next;
        }

        file.close();
    }

    //new add faculty form file
    void addCourseAssignmentFromFile(string course, string section, string instructor, string start_time, string end_time, string day, string room) {
        CourseAssignmentInfo *newCourseAssignment = new CourseAssignmentInfo(course, section, instructor, start_time, end_time, day, room);

        if (assignmentList == nullptr) {
            assignmentList = newCourseAssignment;
        } else {
            CourseAssignmentInfo *current = assignmentList;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newCourseAssignment;
        }
    }

};

//Shamim end


int main()
{
    CourseManagementSystem cms;
    cms.run();
}
