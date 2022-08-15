#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <iomanip>
#include <fstream>

class Bank {

    private:
        std::string name;
        int total;
        int amount, expamount;
        std::string category;

    public:

        void createAccount() {
            std::ofstream bank_acct("bank.txt", std::ios::app);
            bank_acct << "           Account             " << "\n";
            bank_acct << "-------------------------------" << "\n";
            
            std::cout << "Enter name: ";
            std::cin >> name;
            bank_acct << "Name: " << name << "\n";

            std::cout << "How much money do you currently have: $";
            std::cin >> total;
            bank_acct << "Account Balance: " << total << "\n";

            bank_acct.close();

        }

        void showdata() {
            std::fstream bank_acct;
            bank_acct.open("bank.txt", std::ios::in);
            
            if (bank_acct.is_open()) {
                std::string tp;
                
                while(getline(bank_acct, tp)) {
                    std::cout << tp << "\n";
                }
                
                bank_acct.close();
            }
        }

        //Add income amount to total
        //Insert income into income section of file
        void income() {
            std::string line;
            std::ifstream bank_acct("bank.txt");

            std::cout << "Enter amount of income: ";
            std::cin >> amount;
            std::cout << std::endl;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << std::endl;

        }

        void expense() {
            std::cout << "Enter expense amount: ";
            std::cin >> expamount;
            std::cout << std::endl;
            std::cout << " Enter category: ";
            std::cin >> category;
            std::cout << std::endl;
            
        }

        void balance() {
            total  = total + amount - expamount;
            std::cout << "Your current balance is: $" << total << std::endl;
        }


};

int main() {
    Bank b;

    int choice;

    while(1) {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~~~~~ \n";
        std::cout << "                Enter your choice:              \n";
        std::cout << "1. Make an account\n";
        std::cout << "2. View account details\n";
        std::cout << "3. Enter income\n";
        std::cout << "4. Enter an expense\n";
        std::cout << "5. Cancel\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                b.createAccount();
                b.balance();
                break;

            case 2:
                b.showdata();
                break;

            case 3:
                b.income();
                b.balance();
                break;

            case 4:
                b.expense();
                b.balance();
                break;

            case 5:
                exit(1);
                break;

            default:
                std::cout << "Invalid choice\n";
                break;
        }

    }

    return 0;
}