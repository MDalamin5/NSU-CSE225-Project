#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//macro definitions
#define MAX_NAME_LEN 60 // Maximum length of your name can't be more than 60
#define MAX_ADDRESS_LEN 120 // Maximum length of your address can't be more than 120
#define MAX_ABOUT_LEN 250 // Maximum length of your profession can't be more than 250

int main () {
char y_name[MAX_NAME_LEN], y_address[MAX_ADDRESS_LEN], about_y[MAX_ABOUT_LEN];

cout << "Enter your name: ";
cin.getline (y_name, MAX_NAME_LEN);

cout << "Enter your City: ";
cin.getline (y_address, MAX_ADDRESS_LEN);

cout << "Enter your profession (press $ to complete): ";
cin.getline (about_y, MAX_ABOUT_LEN, '$'); //$ is a delimiter

cout << "\n\nEntered details are:\n\n";
cout << "Name: " << y_name << endl;
cout << "Address: " << y_address << endl;
cout << "Profession is: " << about_y << endl;
}
