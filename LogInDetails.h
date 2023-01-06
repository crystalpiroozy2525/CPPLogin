//
// Created by poseycry on 1/5/2023.
//

#ifndef LOGIN_LOGINDETAILS_H
#define LOGIN_LOGINDETAILS_H
#include <iostream>
#include <string>
using namespace std;

class LogInDetails{

public:
    void DisplayMsg();
    void CreateLogin();
    void SetLogin();
    bool RetrieveLogin(string, string);

private:
    string username;
    string password;

};



#endif //LOGIN_LOGINDETAILS_H
