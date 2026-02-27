# C++ atm management system
console based simple C++ atm management system 


# 🏧 ATM Management System (C++)

## 📌 Project Description

This project is a console-based ATM Management System developed using C++. The application simulates real-world banking operations through a menu-driven interface. It allows users and administrators to perform different financial and management operations while storing data using file handling.

The system demonstrates core programming concepts including authentication systems, role-based access control, file storage, and transaction management.

---

## 🛠️ Technologies Used

* C++ – Core programming language used to build the application
* Standard Library (iostream) – For console input and output
* fstream – For file handling and data persistence
* string library – For managing usernames, passwords, and transactions
* Text Files (.txt) – Used as a simple database system

---

## ⚙️ How the System Works

### 🚀 1. Program Startup

* The system reads user data from `users.txt`.
* Usernames, passwords, and balances are loaded into memory arrays.
* The Main Menu is displayed.

---

### 🧭 2. Main Menu

The user chooses one of the following:

* User Login

* Admin Login

* Forgot Password

* Exit

* When exiting, updated data is saved back into `users.txt`.

---

### 🔐 3. User Authentication

* Users enter a username and password.
* The system checks stored data.
* If credentials match, the User Dashboard opens.

---

### 👤 4. User Dashboard Functions

#### 💸 Send Money

* User enters an IBAN (PK + 9 digits).
* IBAN format is validated.
* Balance is checked before transfer.
* Transaction receipt is generated.
* Transaction is saved in `transactions.txt`.

#### 🧾 Pay Bills

* User enters bill type and account number.
* Amount is deducted from balance.
* Payment receipt is generated.
* Transaction is recorded.

#### 📜 View Transactions

* System reads `transactions.txt`.
* Displays only transactions related to the logged-in user.

#### 🚪 Logout

* Returns to main menu.

---

### 🛡️ 5. Admin System (Role-Based Access)

The system includes three administrator levels:

#### 🟢 Low-Level Admin

* Can add money to user accounts.

#### 🟡 Mid-Level Admin

* Add money
* Register new users
* View all registered users

#### 🔴 High-Level Admin

* Change user passwords

* View all users

* Each admin level has different permissions, simulating real banking hierarchy.

---

### 💾 6. File Handling (Data Storage)

#### 📄 users.txt

* Stores:

  * Username
  * Password
  * Account balance

* Example:

```
ali ali123 4000
sana sana123 3000
```

#### 🧮 transactions.txt

* Stores transaction history
* Example:

```
Ali -> IBAN PK123456789 | $500 | Money Transfer
```

* This allows data to remain saved even after closing the program.

---

### 🔑 7. Password Recovery

* User enters username.
* System displays stored password (for learning purposes).

---

### 💽 8. Data Saving

* Before exiting:

  * All updated balances and user data are written back to `users.txt`.

---

## 🧩 Program Structure

The project is divided into multiple functions:

* `mainMenu()` — Controls navigation
* `userLogin()` — Handles user authentication
* `adminLogin()` — Handles admin authentication
* `userMenu()` — User operations dashboard
* `addMoney()` — Admin balance updates
* `registerUser()` — Create new users
* `sendMoney()` — Transfer system
* `payBills()` — Bill payment system
* `viewTransactions()` — Transaction history
* `saveTransaction()` — Writes transaction data
* `checkIBAN()` — Validates IBAN format

---

## 🎯 Learning Concepts Demonstrated

* Menu-driven program design
* File handling in C++
* Role-based access systems
* Authentication logic
* Data persistence
* Modular programming using functions

---

## 👨‍💻 Author

* Omar


