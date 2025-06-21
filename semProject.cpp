#include <iostream>
#include <string>
#include <map>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

class User{};
class Admin{
    private:
        int userId;
        string userUsername;   
        string userPassword;
        map <int, pair<string, string>> userLoginDetailsMap;

       
    public:
        

    };

int idGenerator(){
    srand(time(0));
    int myId = rand() % 10000;
    return myId;
}
bool checkUserlogin(int role, string username, string password){
    string savedUsername, savedPassword;
    int savedId;
    ifstream fileIn;
    map <int, pair<string, string>> users;
    if (role ==1){
        fileIn.open("users.txt");
        while(fileIn >>savedId >>savedUsername >> savedPassword ){
            if (username == savedUsername && password == savedPassword){
                return true;
            }
        }
        fileIn.close();
    }else if( role == 2){
        fileIn.open("admin.txt");
        fileIn>>savedUsername >> savedPassword;
        fileIn.close();

        return username == savedUsername && password == savedPassword;
        
    }else {
        cerr <<"invalid input";
    }
}

int main(){
    cout<<"****** Welcome to CAR RENTAL SYSTEM ******" <<endl;
    cout<<"Select your role to proceed"<<endl;
    cout<<"        1. Normal User Login"<<endl;
    cout<<"        2. Adminstrator Login"<<endl;
    cout<<"        3. Exit"<<endl;
    cout<<"Enter role to proceed: "<<endl;
    cout<<"------------------------------------------"<<endl;
    int role;
    string username, password;
    cin>>role;

    switch(role){
        case 1:
            cout<<"****WELCOME TO USER LOGIN PAGE****"<<endl;
            cout<<"Enter your username: "<<endl;
            cin>>username;
            cout<<"Enter your password"<<endl;
            cin>>password;
            cout<<"------------------------------------------"<<endl;

            if(checkUserlogin(role, username, password)){
                cout<<"Successfully logged in"<<endl;
                cout<<" "<<endl;
                cout<<"Select one of the options below"<<endl;
                cout<<"        1.View personal details"<<endl;
                cout<<"        2.Request to rent a car"<<endl;
                cout<<"        3.Return a rented car"<<endl;
                cout<<"        4.Change balance"<<endl;
            }
            break;

        case 2:
            cout<<"****WELCOME TO ADMINSTRATOR LOGIN PAGE****"<<endl;
            cout<<"Enter admin username: "<<endl;
            cin>>username;
            cout<<"Enter admin password"<<endl;
            cin>>password;
            cout<<"------------------------------------------"<<endl;

            if(checkUserlogin(role, username, password)){
                cout<<"Successfully logged in"<<endl;
                cout<<" "<<endl;
                cout<<"Select one of the options below"<<endl;
                cout<<"        1.Register new users"<<endl;
                cout<<"        2.Approve user's Car rent request"<<endl;
                cout<<"        3.Update system on returned cars"<<endl;
                cout<<"        4.Change password"<<endl;
                cout<<"        5.View registered users"<<endl;
                cout<<"        6.View available cars"<<endl;
            }
            break;


        case 3:
            exit(0);
            break;
        default:
            cout<<"Invalid output"<<endl;
    }

    return 0;
}