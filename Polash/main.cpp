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
    string credits;
    string courseType;
    CourseInfo *next;

    CourseInfo(string courseCode, string courseTitle, string credits, string courseType)
    {
        this->courseCode = courseCode;
        this->courseTitle = courseTitle;
        this->credits = credits;
        this-> courseType= courseType;
        this->next = NULL;

    }
};
// Polash end


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
        cout << "0. Back to Home" << endl;
        cout << "========================================" << endl;
    }

    // Delete Faculty info menu
    void deleteFacultyMenu()
    {
        cout << "===== Faculty Delte Information =====" << endl;
        cout << "1. Delete By searchin name" << endl;
        cout << "2. Delete By searchin name" << endl;
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
// display faculty info
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
        cout << "Delete " << a->name << " Faculty Info From Our List" << endl;
        delete a;
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
        cout << "Delete " << a->name << " Faculty Info From Our List" << endl;
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

    // Faculty Search end

    //update faculty info start
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

    // Polash

/*
// CourseInfo class also in top of the code
class CourseInfo
{
public:
    string courseCode;
    string courseTitle;
    string credits;
    string courseType;
    CourseInfo *next;

    CourseInfo(string courseCode, string courseTitle, string credits, string courseType)
    {
        this->courseCode = courseCode;
        this->courseTitle = courseTitle;
        this->credits = credits;
        this-> courseType= courseType;
        this->next = NULL;

    }
};
// CourseInfo class end
*/

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
// course info page
void courseInfoPage()
    {
        int choice;

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
            case 0:
                cout << "Returning to Home Page..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }

    //add course info
void addCourseInfo()
    {
        string courseCode,courseTitle,credits,courseType;

        fflush(stdin);
        cout << "Enter Course Code: ";
        getline(cin, courseCode);
        fflush(stdin);
        cout << "Enter Course Title: ";
        getline(cin, courseTitle);
        fflush(stdin);
        cout << "Enter Course Credits: ";
        getline(cin, credits);
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
        cout << "Delete " << courseList->courseCode << " Course Info From Our List" << endl;
        delete temp;

        // return;
    }

 void eraseSrcByCourseCode()
    {
        string src_courseCode;
        cout << "Please Enter the Course Code: ";
        fflush(stdin);
        getline(cin, src_courseCode);

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
            cur_indx++;
        }
        cout << cur_indx << endl;
        if (flag)
        {
            cout << endl;
            // cout << "Course Code Found " << endl;
        }
        else
        {
            cout << "Sorry! Course Code Not Found";
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
            count_index++;
        }

        prev->next = a->next;
        cout << "Delete " << a->courseCode << " Course Info From Our List" << endl;
        delete a;
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

 // Course  Search Start

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
            cout << "Course Code Found " << endl;
        }
        else
        {
            cout << "Sorry! Course Code Not Found" << endl;
        }
    }


 // Search By course title
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
            cout << "Course Title Found " << endl;
        }
        else
        {
            cout << "Sorry! Course Title Not Found" << endl;
        }
    }

    // Course Search end

   //update course info start
    void updateCourseInfo()
    {
        string src_courseCode;
        cout << "Please Enter the course code which course info want to Update: ";
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
            string courseCode,courseTitle,credits,courseType;

            fflush(stdin);
            cout << "Enter Updatede Course Code: ";
            getline(cin, courseCode);
            fflush(stdin);
            cout << "Enter Updatede Course Title: ";
            getline(cin, courseTitle);
            fflush(stdin);
            cout << "Enter Updatede Course Credits: ";
            getline(cin, credits);
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

    //
    //Polash end
};
int main()
{
    CourseManagementSystem cms;
    cms.run();
}
