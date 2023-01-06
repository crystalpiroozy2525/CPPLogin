//
// Created by poseycry on 1/5/2023.
//

#include "LogInDetails.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstring>
using namespace std;

void LogInDetails::DisplayMsg()
{
    printf("Welcome to the Water Main Database.\n");
    printf("-----------------------------------\n");
    printf("You will complete the following steps, in order to access and retrieve data:\n\n");
    printf("1. The program will prompt you to create a username and password.\n");
    printf("2. Once the username and password is created correctly, the program will prompt you to enter the log in details you created.\n");
    printf("3. You will be asked to enter a water asset identification number. ");
    printf("From there, the program will retrieve the length of the pipe and the program will end.\n");

    printf("\nAre you ready? (Y/N)\n");
    char* answer = new char;
    cin >> answer;
    cin.ignore();
    if(toupper(*answer) != 'Y')
        exit(0);
    delete answer;
}

void LogInDetails::CreateLogin()
{
    string user;
    char* pass = new char [8];
    char nonchar [] = "&=-'+#,<>.%ABCDEFGHIJKLMNOPQRSTUVWXYZ()&^@/?{}[]";
    bool correct = false;

    printf("Please create a username: ");
    getline(cin, user);
    for(int i = 0; i<strlen(nonchar); i++)
    {
        for(int j = 0;j<user.length(); j++)
        {
            if(user[j] == nonchar[i] || user.length() < 5 || user.length() > 15)
            {
                printf("\nInvalid. Your username must be greater than 5 characters, less than 15 characters, ");
                printf("and it must only contain lowercase letters (a-z), numbers (0-9), and/or underscores (_).\n");
                cin >> user;
            }
        }
    }

    printf("Please create a password: ");
    cin >> pass;
    while (!correct)
    {
        for (int i = 0; i < strlen(nonchar); i++)
        {
            for (int j = 0; j < strlen(pass); j++)
            {
                if (pass[j] == nonchar[i] && strlen(pass)>=8)
                    correct = true;
            }
        }
        if(!correct)
        {
            printf("Invalid. Must contain at least 8 characters, a special character, and/or uppercase/lowercase letter.\n");
            printf("Please create a valid password: ");
            cin >> pass;
        }
    }

    //setting login details to private members
    username = user;
    password = pass;
    delete [] pass;
}

void LogInDetails::SetLogin()
{
    ofstream login;
    login.open("LOG.csv");

    login << username << " , "
          << password << endl;

}


bool LogInDetails::RetrieveLogin(string user, string pass)
{
    ifstream login;
    char comma;
    login.open("LOG.csv");
    login >> username;
    login >> comma;
    login >> password;

    if(user == username && pass == password)
        return true;
    else
        return false;
}
