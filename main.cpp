#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <stdexcept>

class Bank {

    private:
        std::string password;
        std::string nextWord;
        std::string firstName;
        std::string lastName;
        int netWorth;
        int rowNumber = 0;
        bool tf = false;
        bool nouser = false;
        bool pwdFind = false;
        bool nopwd = false;
        std::string filename;
        std::string fileText;
        std::string username;
        std::string income;
        std::string expense;
        std::string category; 

    public:
        
        bool login() {
            tf = false;
            nouser = false;
            nopwd = false;
            pwdFind = false;
            std::cout << "Enter your username: ";
            std::cin >> username;

            try {
                std::ifstream username_File("username.txt");

                while (tf == false) {
                    std::getline(username_File, nextWord);

                    rowNumber += 1;

                    if(nextWord == username) {
                        tf = true;
                    }

                    if(username_File.eof()) {
                        nouser = true;
                        std::cout << "Sorry we were not able to find your username in our database.\n";
                        return pwdFind;
                    }
                }

                username_File.close();
                
            } catch(std::exception e) {
                std::cout << "Sorry we could not find that username in our database.\n";
                return pwdFind;
            }

            if (tf == true) {
                std::cout << "Enter your password: ";
                std::cin >> password;

                try {
                    std::ifstream password_File("password.txt");

                    for(int i = 0; i < rowNumber; i++) {
                        std::getline(password_File, nextWord);

                        if(nextWord == password) {
                            pwdFind = true;
                            return pwdFind;
                        }

                        if(password_File.eof()) {
                            nopwd = true;
                            std::cout << "Sorry your username or password is incorrect.\n";
                            return pwdFind;
                        }
                    }

                    password_File.close();

                } catch (std::exception e) {
                    std::cout << "We're sorry we were not able to log you in.\n";
                    return pwdFind;
                }
            }
            return pwdFind;
        }

        void signup() {
            std::cout << "Enter your first name: ";
            std::cin >> firstName;
            std::cout << "\n";

            std::cout << "Enter your last name: ";
            std::cin >> lastName;
            std::cout << "\n";

            std::cout << "Create a username: ";
            std::cin >> username;
            std::cout << "\n";

            std::string fileName = username + ".txt";

            std::ofstream user_File(fileName);

            user_File << "---------Account----------\n";
            user_File << firstName << " " << lastName << "\n" << "\n";

            std::cout << "Enter your current new worth: ";
            std::cin >> netWorth;

            user_File << "\nNet Worth: $" << netWorth << " \n";

            user_File.close();

            std::ofstream username_File;

            try {
                username_File.open("username.txt", std::ios::app);

               if(username_File.is_open()) {
                    username_File << username << "\n";
                    username_File.close();
               } 
            } catch(std::exception e) {
                std::cout << "Sorry, we had trouble processing your request, try again.";
                username_File.close();
            }

            std::cout << "Create a password: ";
            std::cin >> password;
            std::cout << "\n";

            std::ofstream password_File;
            
            try {
                password_File.open("password.txt", std::ios::app);

               if(password_File.is_open()) {
                    password_File << password << "\n";
                    password_File.close();
               } 
            } catch(std::exception e) {
                std::cout << "Sorry, we had trouble processing your request, try again.";
                password_File.close();
            }
        }

        void viewAccount() {
            
            filename = username + ".txt";

            try {
            std::ifstream user_File(filename);

            while(user_File) {
                getline(user_File, fileText);

                std::cout << fileText << std::endl << std::endl;
            }

            user_File.close();
            } catch(std::exception e) {
                std::cout << "Sorry we could not print your account.\n";
            }
        }

        void incomeMethod() {
            filename = username + ".txt";

            try {
                std::ofstream user_File;;

                user_File.open(filename, std::ios::app);

                std::cout << "Enter your amount of income: ";
                std::cin >> income;
                std::cout << std::endl;

                std::cout << "Enter the category of your income: ";
                std::cin >> category;
                std::cout << std::endl;

                user_File << "Inc - +$" << income << "      Category ----> " << category << std::endl;

                user_File.close();

            } catch (std::exception e) {
                std::cout << "Sorry we had a issue adding your transaction, please try again.";
            }

        };

        void expenseMethod() {
            filename = username + ".txt";

            try {
                std::ofstream user_File;;

                user_File.open(filename, std::ios::app);

                std::cout << "Enter the amount of your expense: ";
                std::cin >> expense;
                std::cout << std::endl;

                std::cout << "Enter the category of your expense: ";
                std::cin >> category;
                std::cout << std::endl;

                user_File << "Exp - -$" << expense << "      Category ----> " << category << std::endl;

                user_File.close();

            } catch (std::exception e) {
                std::cout << "Sorry we had a issue adding your transaction, please try again.";
            }
            
        };
        /*
        void newMonth() {
            std::ifstream user_File(filename);
            std::ofstream temp_File("temp.txt");

            std::string line;

            for(int i = 0; i < 5; i++) {
                getline(user_File, line);

                temp_File << line;
            }
            //Fix this eventually
            remove("nicmast.txt");
            rename("temp.txt", "nicmast.txt");

        };
        */
       /*
        void updateNetWorth() {
            std::string line, someString;

            std::fstream user_File;

            user_File.open(filename, std::ios::in | std::ios::app);

            while(std::getline(user_File, line)) {
                if(line.find(someString) != std::string::npos) {
                    if(someString == "Worth") {

                    }
                }
            }
        };
        */
};

int main() {
    Bank b;

    int loginChoice;
    bool loginSuccesful;
    int welcome = 1;
    int accountChoice;

    while(welcome == 1) {
        std::cout << "\nWelcome to Your Personal Finance Tool!" << "\n";
        std::cout << "          Press 1 to login            \n";
        std::cout << "          Press 2 to signup           \n";
        std::cin >> loginChoice;

        switch(loginChoice) {
            case 1:
                loginSuccesful = b.login();
                break;
            case 2:
                b.signup();
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }

        if(loginSuccesful == true) {
            welcome = 2;

        } else {
            welcome = 1;
        }
    }

    while (welcome == 2) {
        std::cout << "\n              Welcome!             \n";
        std::cout << "    Enter the number of your choice  \n";
        std::cout << "1. View Account                      \n";
        std::cout << "2. Add income                        \n";
        std::cout << "3. Add expense                       \n";
        std::cout << "4. Logout                            \n";

        std::cin >> accountChoice;

        switch(accountChoice) {
            case 1:
                b.viewAccount();
                break;
            case 2:
                b.incomeMethod();
                break;
            case 3:
                b.expenseMethod();
                break;
            case 4:
                welcome = 1;
                break;
            default:
                std::cout << "Invalid Choice.\n";
                break;
        }
    }

    return 0;
}