#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mainMenu();
void userLogin();
void adminLogin();
void userMenu(string username);
void lowAdminMenu();
void midAdminMenu();
void highAdminMenu();
void addMoney();
void registerUser();
void changePassword();
void sendMoney(string sender);
void payBills(string username);
void forgotPassword();
void viewTransactions(string username);
void saveTransaction(string from, string to, double amount, string type);
bool checkIBAN(string iban);

const int MAX_USERS = 20;
string username[MAX_USERS];
string password[MAX_USERS];
double balance[MAX_USERS];
int userCount = 0;
int receiptNumber = 1000;

int main() {
    ifstream file("users.txt");
    if (file.is_open()) {
        userCount = 0;
        while (file >> username[userCount] >> password[userCount] >> balance[userCount]) {
            userCount++;
        }
        file.close();
    }
    
    mainMenu();
    return 0;
}

void mainMenu() {
    cout << "#===================================#\n";
    cout << "#      WELCOME TO ATM SYSTEM       #\n";
    cout << "#===================================#\n";
    cout << "#        Made by: Omar             #\n";
    cout << "#===================================#\n";
    cout << "# 1. User Login                    #\n";
    cout << "# 2. Admin Login                   #\n";
    cout << "# 3. Forgot Password               #\n";
    cout << "# 4. Exit                          #\n";
    cout << "#===================================#\n";
    cout << "Enter choice: ";
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        userLogin();
    } else if(choice == 2) {
        adminLogin();
    } else if(choice == 3) {
        forgotPassword();
    } else if(choice == 4) {
        ofstream out("users.txt");
        for (int i = 0; i < userCount; i++) {
            out << username[i] << " " << password[i] << " " << balance[i] << endl;
        }
        out.close();
        return;
    } else {
        cout << "Wrong choice!\n";
        mainMenu();
    }
}

void userLogin() {
    cout << "#===================================#\n";
    cout << "#          USER LOGIN              #\n";
    cout << "#===================================#\n";
    
    string inputUsername, inputPassword;
    cout << "Username: ";
    cin >> inputUsername;
    cout << "Password: ";
    cin >> inputPassword;
    
    for (int i = 0; i < userCount; i++) {
        if (username[i] == inputUsername && password[i] == inputPassword) {
            userMenu(inputUsername);
            return;
        }
    }
    
    cout << "Login failed!\n";
    mainMenu();
}

void adminLogin() {
    cout << "#===================================#\n";
    cout << "#          ADMIN LOGIN             #\n";
    cout << "#===================================#\n";
    
    string adminUser, adminPass;
    cout << "Admin username: ";
    cin >> adminUser;
    cout << "Admin password: ";
    cin >> adminPass;
    
    // Check for low-level admin
    if (adminUser == "lowadmin" && adminPass == "low123") {
        lowAdminMenu();
    } 
    // Check for mid-level admin
    else if (adminUser == "midadmin" && adminPass == "mid123") {
        midAdminMenu();
    } 
    // Check for high-level admin
    else if (adminUser == "highadmin" && adminPass == "high123") {
        highAdminMenu();
    } 
    else {
        cout << "Wrong admin login!\n";
        mainMenu();
    }
}

void userMenu(string currentUser) {
    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (username[i] == currentUser) {
            userIndex = i;
            break;
        }
    }
    
    while (true) {
        cout << "#===================================#\n";
        cout << "#         USER DASHBOARD           #\n";
        cout << "#===================================#\n";
        cout << "# Welcome, " << currentUser << "!\n";
        cout << "# Balance: $" << balance[userIndex] << "\n";
        cout << "#===================================#\n";
        cout << "# 1. Send Money                    #\n";
        cout << "# 2. Pay Bills                     #\n";
        cout << "# 3. View Transactions             #\n";
        cout << "# 4. Logout                        #\n";
        cout << "#===================================#\n";
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;
        
        if(choice == 1) {
            sendMoney(currentUser);
        } else if(choice == 2) {
            payBills(currentUser);
        } else if(choice == 3) {
            viewTransactions(currentUser);
        } else if(choice == 4) {
            mainMenu();
            return;
        } else {
            cout << "Wrong choice!\n";
        }
    }
}

// Low-level admin menu: Can only add money
void lowAdminMenu() {
    while (true) {
        cout << "#===================================#\n";
        cout << "#       LOW ADMIN DASHBOARD        #\n";
        cout << "#===================================#\n";
        cout << "# 1. Add Money to User             #\n";
        cout << "# 2. Logout                        #\n";
        cout << "#===================================#\n";
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;
        
        if(choice == 1) {
            addMoney();
        } else if(choice == 2) {
            mainMenu();
            return;
        } else {
            cout << "Wrong choice!\n";
        }
    }
}

// Mid-level admin menu: Can add money and register users
void midAdminMenu() {
    while (true) {
        cout << "#===================================#\n";
        cout << "#       MID ADMIN DASHBOARD        #\n";
        cout << "#===================================#\n";
        cout << "# 1. Add Money to User             #\n";
        cout << "# 2. Register New User             #\n";
        cout << "# 3. View All Users                #\n";
        cout << "# 4. Logout                        #\n";
        cout << "#===================================#\n";
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;
        
        if(choice == 1) {
            addMoney();
        } else if(choice == 2) {
            registerUser();
        } else if(choice == 3) {
            cout << "\nAll Users:\n";
            for (int i = 0; i < userCount; i++) {
                cout << username[i] << " - $" << balance[i] << "\n";
            }
        } else if(choice == 4) {
            mainMenu();
            return;
        } else {
            cout << "Wrong choice!\n";
        }
    }
}

// High-level admin menu: Can change passwords
void highAdminMenu() {
    while (true) {
        cout << "#===================================#\n";
        cout << "#      HIGH ADMIN DASHBOARD        #\n";
        cout << "#===================================#\n";
        cout << "# 1. Change User Password          #\n";
        cout << "# 2. View All Users                #\n";
        cout << "# 3. Logout                        #\n";
        cout << "#===================================#\n";
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;
        
        if(choice == 1) {
            changePassword();
        } else if(choice == 2) {
            cout << "\nAll Users:\n";
            for (int i = 0; i < userCount; i++) {
                cout << username[i] << " - $" << balance[i] << "\n";
            }
        } else if(choice == 3) {
            mainMenu();
            return;
        } else {
            cout << "Wrong choice!\n";
        }
    }
}

void addMoney() {
    cout << "#===================================#\n";
    cout << "#        ADD MONEY TO USER         #\n";
    cout << "#===================================#\n";
    
    string targetUser;
    double amount;
    cout << "Enter username: ";
    cin >> targetUser;
    cout << "Enter amount: $";
    cin >> amount;
    
    for (int i = 0; i < userCount; i++) {
        if (username[i] == targetUser) {
            balance[i] += amount;
            cout << "Added $" << amount << " to " << targetUser << "\n";
            saveTransaction("Admin", targetUser, amount, "Added Money");
            return;
        }
    }
    
    cout << "User not found!\n";
}

void registerUser() {
    cout << "#===================================#\n";
    cout << "#        REGISTER NEW USER         #\n";
    cout << "#===================================#\n";
    
    if (userCount >= MAX_USERS) {
        cout << "Maximum users reached!\n";
        return;
    }
    
    string newUser, newPass;
    double initialBalance;
    
    cout << "Enter new username: ";
    cin >> newUser;
    
    // Check if user already exists
    for (int i = 0; i < userCount; i++) {
        if (username[i] == newUser) {
            cout << "Username already exists!\n";
            return;
        }
    }
    
    cout << "Enter new password: ";
    cin >> newPass;
    cout << "Enter initial balance: $";
    cin >> initialBalance;
    
    // Add new user
    username[userCount] = newUser;
    password[userCount] = newPass;
    balance[userCount] = initialBalance;
    userCount++;
    
    cout << "User registered successfully!\n";
}

void changePassword() {
    cout << "#===================================#\n";
    cout << "#        CHANGE PASSWORD           #\n";
    cout << "#===================================#\n";
    
    string targetUser, newPass;
    cout << "Enter username: ";
    cin >> targetUser;
    
    for (int i = 0; i < userCount; i++) {
        if (username[i] == targetUser) {
            cout << "Enter new password: ";
            cin >> newPass;
            password[i] = newPass;
            cout << "Password changed successfully!\n";
            return;
        }
    }
    
    cout << "User not found!\n";
}

void sendMoney(string sender) {
    cout << "#===================================#\n";
    cout << "#           SEND MONEY             #\n";
    cout << "#===================================#\n";
    
    string iban;
    double amount;
    cout << "Enter IBAN (PK + 9 digits): ";
    cin >> iban;
    
    if (!checkIBAN(iban)) {
        cout << "Wrong IBAN format!\n";
        return;
    }
    
    cout << "Enter amount: $";
    cin >> amount;
    
    for (int i = 0; i < userCount; i++) {
        if (username[i] == sender) {
            if (balance[i] >= amount) {
                balance[i] -= amount;
                receiptNumber++;
                cout << "\n#===================================#\n";
                cout << "#            RECEIPT               #\n";
                cout << "#===================================#\n";
                cout << "# Receipt No: R" << receiptNumber << "\n";
                cout << "# From: " << sender << "\n";
                cout << "# To: IBAN " << iban << "\n";
                cout << "# Amount: $" << amount << "\n";
                cout << "#===================================#\n";
                saveTransaction(sender, "IBAN " + iban, amount, "Money Transfer");
            } else {
                cout << "Not enough balance!\n";
            }
            return;
        }
    }
}

void payBills(string user) {
    cout << "#===================================#\n";
    cout << "#            PAY BILLS             #\n";
    cout << "#===================================#\n";
    
    string billType, accountNumber;
    double amount;
    cout << "Bill type: ";
    cin >> billType;
    cout << "Account number: ";
    cin >> accountNumber;
    cout << "Amount: $";
    cin >> amount;
    
    for (int i = 0; i < userCount; i++) {
        if (username[i] == user) {
            if (balance[i] >= amount) {
                balance[i] -= amount;
                receiptNumber++;
                cout << "\n#===================================#\n";
                cout << "#         BILL PAYMENT             #\n";
                cout << "#===================================#\n";
                cout << "# Receipt No: R" << receiptNumber << "\n";
                cout << "# Customer: " << user << "\n";
                cout << "# Bill: " << billType << "\n";
                cout << "# Account: " << accountNumber << "\n";
                cout << "# Amount: $" << amount << "\n";
                cout << "#===================================#\n";
                saveTransaction(user, billType + " Bill", amount, "Bill Payment");
            } else {
                cout << "Not enough balance!\n";
            }
            return;
        }
    }
}

void forgotPassword() {
    cout << "#===================================#\n";
    cout << "#        FORGOT PASSWORD           #\n";
    cout << "#===================================#\n";
    
    string user;
    cout << "Enter username: ";
    cin >> user;
    
    for (int i = 0; i < userCount; i++) {
        if (username[i] == user) {
            cout << "Your password: " << password[i] << "\n";
            mainMenu();
            return;
        }
    }
    
    cout << "User not found!\n";
    mainMenu();
}

void viewTransactions(string user) {
    cout << "#===================================#\n";
    cout << "#       TRANSACTION HISTORY        #\n";
    cout << "#===================================#\n";
    
    ifstream file("transactions.txt");
    string line;
    bool found = false;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(user) != string::npos) {
                cout << line << "\n";
                found = true;
            }
        }
        file.close();
    }
    
    if (!found) {
        cout << "No transactions found.\n";
    }
    cout << "#===================================#\n";
}

void saveTransaction(string from, string to, double amount, string type) {
    ofstream file("transactions.txt", ios::app);
    if (file.is_open()) {
        file << from << " -> " << to << " | $" << amount << " | " << type << "\n";
        file.close();
    }
}

bool checkIBAN(string iban) {
    if (iban.length() != 11) return false;
    if (iban[0] != 'P' || iban[1] != 'K') return false;
    for (int i = 2; i < 11; i++) {
        if (iban[i] < '0' || iban[i] > '9') return false;
    }
    return true;
}