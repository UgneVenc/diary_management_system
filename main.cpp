#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = filesystem;
class user{
private:
    string username;
    int choice;
    string date;
public:
    user() : username("") { }
    user(string x) : username(x) { }
    void menu() {
        cout<<"--------------------------------------------------"<<endl;
        cout<<"               WELCOME TO YOUR DIARY!"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"1. ADD ENTRY"<<endl;
        cout<<"2. EDIT ENTRY"<<endl;
        cout<<"3. DELETE ENTRY"<<endl;
        cout<<endl<<"your answer: ";
        cin>>choice;
    }
    void add_entry() {
        cout<<"Enyer the date: ";
        cin>>date;

        string text;

        cout<<"---------------------------------------"<<endl;
        cout<<"  DEAR DIARY                 "<<date<<endl;
        cout<<"---------------------------------------"<<endl;

        cin.ignore();
        getline(cin, text);

        ofstream file(username+"/"+date+".txt");
        file<<text;
        file.close();

    }
    void delete_endtry() {

    }
    void edit_entry() {

    }
    int out_choice() {
        return choice;
    }
};
int main() {
    user Diary_System;
    int x;
    string user_name, pswrd;
    bool entry=false;

    cout<<"Do you have an account?"<<endl;
    cout<<"1. I do"<<endl;
    cout<<"2. I don't"<<endl;
    cout<<"Your answer: ";
    cin>>x;

    if (x==1) {
        string real_pswrd;

        cout<<"Enter your username: ";
        cin>>user_name;
        cout<<endl;
        cout<<"Enter your password: ";
        cin>>pswrd;

        ifstream file(user_name+"/pswrd.txt");
        file>>real_pswrd;
        file.close();

        while (real_pswrd != pswrd) {
            cout << "The password is wrong, please try again: ";
            cin >> pswrd;
        }
        entry = true;

    }
    else if (x==2) {
        int n;

        cout<<"Create your user name: ";
        cin>>user_name;
        cout<<endl;
        cout<<"Create your password: ";
        cin>>pswrd;

        fs::create_directory(user_name); //creates a folder
        ofstream file(user_name+"/pswrd.txt");
        file<<pswrd;
        file.close();
        entry=true;

        ifstream file1("user_count");
        file1>>n;
        file1.close();

        ofstream file2("user_count");
        file2<<n+1;

        file2.close();


    }
    else {
        cout<<"Your answer is invalid"<<endl;
    }

    if (entry==true) {
        user Diary_System(user_name);
        while (true) {
            Diary_System.menu();
            if ( Diary_System.out_choice()==1) {
                Diary_System.add_entry();
            }
            else if ( Diary_System.out_choice()==2) {
                Diary_System.edit_entry();
            }
            else if ( Diary_System.out_choice()==3) {
                Diary_System.delete_endtry();
            }
        }
    }
    else {
        cout<<"Error :(";
    }

    return 0;
}