/* Name: Crystal Piroozy Posey
Date: 1/5/2023
About this project: Simple login authentication program in C++.
Utilizing user input, fstream objects, and dynamic memory allocation.
All work below was performed by Crystal Piroozy Posey */

#include "LogInDetails.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    LogInDetails login;
    string username, password;
    bool correct;

    login.DisplayMsg();
    login.CreateLogin();
    login.SetLogin();

    printf("Please reenter your username and password\n");
    printf("Username: ");
    cin.ignore();
    getline(cin,  username);
    printf("Password: ");
    getline(cin,  password);

    correct = login.RetrieveLogin(username, password);

    while(!correct)
    {
        printf("Invalid username and/or password. Please try again.\n");
        printf("Username: ");
        getline(cin,  username);
        printf("Password: ");
        getline(cin,  password);
        correct = login.RetrieveLogin(username, password);
    }
    printf("Thank you!\n");

    return 0;
}
