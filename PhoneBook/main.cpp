#include <string.h>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int contact_id;
    string name;
    string phone_no;
    node *next;
};
class phoneBook
{
public:
    node *head;
    node *tail;
    int size;
    phoneBook()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // create a new node function
    node *createNewNode(int contact_id, string name, string phone_no)
    {
        node *newNode = new node;
        newNode->contact_id = contact_id;
        newNode->name = name;
        newNode->phone_no = phone_no;
        newNode->next = NULL;
        return newNode;
    }
    // add contact method start
    void addNewContact()
    {
        int contact_id;
        string name;
        string phone_no;
        cout << "Enter contact ID: ";
        cin >> contact_id;
        fflush(stdin);
        cout << "Enter the name of the persotn: ";
        getline(cin, name);
        fflush(stdin);
        cout << "Enter phone Number: ";
        getline(cin, phone_no);
        fflush(stdin);
        node *a = createNewNode(contact_id, name, phone_no);
        if (head == NULL)
        {
            head = a;
            tail = a->next;
            size++;
        }
        else
        {
            a->next = head;
            head = a;
            tail = a->next;
            size++;
        }
        cout << "Contact Added Succefully" << endl
             << endl;
    }
    // add contact method start end

    // Contact search Method start
    void searchContact()
    {
        /*
        3 option will be avilable
        1. search by name;
        2. search bu contact id
        3. search by phone number
        */

        int searchOption;
        cout << "\n"
             << "Please Chose Your Option" << endl;
        cout << "1. Search By Name" << endl;
        cout << "2. Search By Contact ID" << endl;
        cout << "3. Search By Phone Number" << endl;
        cout << "0. Go to home page" << endl;
        cout << endl
             << "Please Enter Your Choise: ";
        cin >> searchOption;
        switch (searchOption)
        {
        case 0:
            // main();
            break;

        case 1:
            searchByName();
            break;

        case 2:
            searchByContactID();
            break;

        case 3:
            searchByPhoneNo();
            break;

        default:
            cout << "You are entering invalid input\n\n Try again \n\n";
            searchContact();
        }
    }
    void searchByName()
    {
        string src_name;
        cout << "Please Enter the name: ";
        fflush(stdin);
        getline(cin, src_name);

        node *a = head;
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
            cout << "Sorry! Name Not Found";
        }
    }
    void searchByContactID()
    {
        int con_id;
        cout << "Enter Contact id: ";
        cin >> con_id;
        bool flag = false;
        node *a = head;
        while (a != NULL)
        {
            if (a->contact_id == con_id)
            {
                flag = true;
                break;
            }
            a = a->next;
        }
        if (flag)
        {
            cout << "Your contac found and name is: " << a->name << endl;
        }
        else
        {
            cout << "Contact is not found" << endl;
        }
    }
    void searchByPhoneNo()
    {
        string src_ph_no;
        cout << "Please Enter the Phone Number: ";
        fflush(stdin);
        getline(cin, src_ph_no);

        node *a = head;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_ph_no.length(); i++)
            {
                if (src_ph_no[i] != a->phone_no[i])
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
    // contact search method end

    // all contact travers method start
    void displayAllContact()
    {
        if(size==0)
        {
            cout<<"No data in your list"<<endl;
            return;
        }
        // cout<<"Contact id     User Name       Phone Number"<<endl;
        node *a = head;
        while (a != NULL)
        {
            cout << a->contact_id << "    " << a->name << "     " << a->phone_no << endl;
            a = a->next;
        }
        cout << endl;
    }
    // all contact travers method end

    // delet method start
    void eraseContact()
    {
        int cos_opt;
        cout << "which contact you want to delete" << endl;
        // cout<<"Enter contact name"<<endl;
        cout << "How way to daelte the contact" << endl;
        cout << "Chose your option: " << endl;
        cout << "1. Delete Contact Search by name: " << endl;
        cout << "2. Delete Contack Search by PhoneNumber: " << endl;
        cout << "Please Enter your choise: " << endl;
        cin >> cos_opt;
        switch (cos_opt)
        {
        case 1:
            eraseSrcByName();
            break;

        case 2:
            eraseSrcByPhoneNumber();
            break;

        default:
            cout << "You are enteing wrong input" << endl;
            break;
        }

        // delete contact by name, id, phone number
    }

    void eraseFromHead()
    {
        node *temp=head;
        head=temp->next;
        size--;
        delete temp;
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
        node *a = head;
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
        node *prev=head;
        while(count_index!=cur_indx-1)
        {
            prev=prev->next;
        }

            prev->next=a->next;
            size--;
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
        node *a = head;
        bool flag;
        while (a != NULL)
        {
            flag = true;
            for (int i = 0; i < src_PhNO.length(); i++)
            {
                if (src_PhNO[i] != a->phone_no[i])
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
        node *prev=head;
        while(count_index!=cur_indx-1)
        {
            prev=prev->next;
        }

            prev->next=a->next;
            size--;
            delete a;
    }
    // delete method end

    // Contact Modeify Method start
    void modifyContact()
    {
        cout<<endl<<endl<<"Note: You have to Know The contact name which you want to modify"<<endl<<endl;

        string mod_name;
        eraseSrcByName();
        cout<<endl<<"Enter new contact information: "<<endl;
        addNewContact();
        cout<<"Modify sussfully"<<endl;
    }
    // contack modeify Method end

    // return PhoneBook size
    int getSizeOfPhoneBook()
    {
        return size;
    }
};

int main()
{
    phoneBook pb;

    /*
    pb.addNewContact(12344, "Al Amin","01641049759");
    pb.addNewContact(12343, "Kay sar","01641049758");
    pb.addNewContact(12342, "AbuShin","01641049757");
    pb.addNewContact(12341, "Rubel h","01641049756");
    pb.displayAllContact();
    */
    cout << "                 Contact List" << endl
         << endl;
    int choise;
    while (1)
    {
        cout << "\n\n";
        cout << "1. Add New Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Modify Contact List" << endl;
        cout << "4. Delete contact List" << endl;
        cout << "5. All Contact List" << endl;
        cout << "0. Exit" << endl
             << endl;

        cout << "Please Enter Your Choise: ";
        cin >> choise;

        switch (choise)
        {
        case 0:
            exit(0);

        case 1:
            pb.addNewContact();
            break;

        case 2:
            pb.searchContact();
            break;

        case 3:
            pb.modifyContact();
            break;

        case 4:
            pb.eraseContact();
            break;

        case 5:
            pb.displayAllContact();
            break;
        }
    }
}