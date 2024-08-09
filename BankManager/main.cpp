#include <cctype>
#include <iostream>
#include <fstream>
#include <cstdlib>

class account {
    private:
        char name[100], address[100], email[100], type;
        int phone, accnum;
        double balance;
        public:
        void NewAcc();
        void Deposit();
        void Withdraw();
        void DispAcc();

};

void account::NewAcc() {
    std::cout << "Enter your name: ";
    //std::cin.ignore();
    std::cin.getline(name, 100);
    std::cout << "Enter your adress: ";
    //std::cin.ignore();
    std::cin.getline(address, 100);
    std::cout << "Enter email: ";
    //std::cin.ignore();
    std::cin.getline(email, 100);
    std::cout << "Enter phone number: ";
    std::cin >> phone;
    std::cout << "What type of accout o you want ? Saving (S) or Current (C): ";
    std::cin >> type;
    type = toupper(type);
    std::cout << "Enter account number: ";
    std::cin >> accnum;
    std::cout << "Conratulations you have successfully created a bank account!" << std::endl;
}

void account::Deposit() {
    double x;
    std::cout << "How much would you like to depossite?: ";
    std::cin >> x;
    balance += x;
    std::cout << "New total balance: " << balance << std::endl;
}

void account::Withdraw() {
    double y;
    std::cout << "Enter amount to withdraw: ";
    std::cin >> y;
    balance -= y;
    std::cout << "New total balance: " << balance << std::endl;
}

void account::DispAcc() {
    std::cout << "Account holder info";
    std::cout << "Full name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone number: " << phone << std::endl;
    std::cout << "Account type: " << type << std::endl;
    std::cout << "account number: " << accnum << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}

void ExitProgram() {
    exit(0);
}

int main() {
    account acc;
    int opt;

    do {
        std::cout << "-------------------------------------------------------------------------------\n";
        std::cout << "Welcome to the bank\n";
        std::cout << "-------------------------------------------------------------------------------\n";
        std::cout << "\n1Create a new accout" << "\n2 Make a depissit"
            << "\n3 Make a withdraw" << "\n4 Show account info"
            << "\n0 Exit" << std::endl;
        std::cin >> opt;

        switch (opt) {
            case 0:
                ExitProgram();
            break;
            case 1:
                acc.NewAcc();
            break;
            case 2:
                acc.Deposit();
            break;
            case 3:
                acc.Withdraw();
            break;
            case 4:
                acc.DispAcc();
            break;
            default:
                std::cout << "Something went wrong!!" << std::endl;
                }

    } while(opt != 0);


    return 0;
}
