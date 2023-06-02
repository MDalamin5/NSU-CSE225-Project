#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
public:
    string fullName;
    int age;
    double salary;
    Person* next;

    Person(string fullName, int age, double salary) : fullName(fullName), age(age), salary(salary), next(nullptr) {}

    void displayPerson() {
        cout << "Full Name: " << fullName << ", Age: " << age << ", Salary: " << salary << endl;
    }
};

class PersonList {
public:
    Person* head;

    PersonList() : head(nullptr) {}

    ~PersonList() {
        deleteList();
    }

    void addPerson() {
        string fullName;
        int age;
        double salary;

        cout << "Enter full name: ";
        cin.ignore();
        getline(cin, fullName);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter salary: ";
        cin >> salary;

        Person* newPerson = new Person(fullName, age, salary);

        if (head == nullptr) {
            head = newPerson;
        } else {
            Person* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newPerson;
        }
    }

    void displayAll() {
        Person* current = head;
        while (current != nullptr) {
            current->displayPerson();
            current = current->next;
        }
    }

    Person* searchPerson() {
        string fullName;

        cout << "Enter full name to search: ";
        cin.ignore();
        getline(cin, fullName);

        Person* current = head;
        while (current != nullptr) {
            if (current->fullName == fullName) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void deletePerson() {
        string fullName;

        cout << "Enter full name to delete: ";
        cin.ignore();
        getline(cin, fullName);

        Person* current = head;
        Person* previous = nullptr;

        while (current != nullptr && current->fullName != fullName) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Person not found." << endl;
            return;
        }

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
    }

    void deleteList() {
        Person* current = head;
        while (current != nullptr) {
            Person* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "File not found." << endl;
            return;
        }

        string fullName;
        int age;
        double salary;

        while (getline(file, fullName)) {
            file >> age >> salary;
            file.ignore();

            addPersonFromFile(fullName, age, salary);
        }

        file.close();
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        Person* current = head;
        while (current != nullptr) {
            file << current->fullName << endl;
            file << current->age << " " << current->salary << endl;
            current = current->next;
        }

        file.close();
    }

    void displayMenu() {
        int choice;
        string filename = "persons.txt";

        loadFromFile(filename);

        do {
            cout << "\n-- Menu --" << endl;
            cout << "1. Add Person" << endl;
            cout << "2. Display All Persons" << endl;
            cout << "3. Search Person" << endl;
            cout << "4. Delete Person" << endl;
            cout << "5. Save to File" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addPerson();
                    break;
                case 2:
                    displayAll();
                    break;
                case 3: {
                    Person* foundPerson = searchPerson();
                    if (foundPerson != nullptr) {
                        cout << "Person found: ";
                        foundPerson->displayPerson();
                    } else {
                        cout << "Person not found." << endl;
                    }
                    break;
                }
                case 4:
                    deletePerson();
                    break;
                case 5:
                    saveToFile(filename);
                    cout << "Data saved to file." << endl;
                    break;
                case 6:
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 6);
    }

private:
    void addPersonFromFile(string fullName, int age, double salary) {
        Person* newPerson = new Person(fullName, age, salary);

        if (head == nullptr) {
            head = newPerson;
        } else {
            Person* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newPerson;
        }
    }
};

int main() {
    PersonList personList;

    personList.displayMenu();

    return 0;
}
