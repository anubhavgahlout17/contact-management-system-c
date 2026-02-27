# Contact Management System (C)

## 📌 Project Overview
This is a console-based Contact Management System developed using the C programming language.  
The program allows users to manage contacts by performing basic CRUD operations.  
All data is stored permanently using binary file handling (`fread`, `fwrite`) in a `.dat` file.

This project was built as a mini project to strengthen understanding of:
- Structures in C
- File handling (binary mode)
- String manipulation
- Menu-driven programs
- Basic data management logic

---

## 🚀 Features
- Add new contact  
- View all saved contacts  
- Search contact (case-insensitive search)  
- Update contact mobile number  
- Delete contact  
- Persistent data storage using binary files  
- Input handling using `fgets`  
- Temporary file method for update & delete operations  

---

## 🛠 Technologies Used
- C Programming Language  
- Structures  
- File Handling (`rb`, `wb`, `ab` modes)  
- String Functions (`strcmp`, `strcpy`, `strlen`)  
- Character handling (`tolower`)  
- Menu-driven console interface  

---

## 📂 File Structure
contact-management-system-c/
│
├── contact_manager.c
└── README.md

Note: `.exe` and `Contacts.dat` files are not included in the repository.

---

## ⚙ How to Compile and Run

Step 1: Compile
gcc contact_manager.c -o contact

Step 2: Run
./contact  
(Windows users can run `contact.exe`)

---

## 🎯 Learning Outcomes
- Implemented CRUD operations using C  
- Practiced binary file handling  
- Learned temporary file technique for update/delete  
- Improved understanding of string processing  
- Built a complete menu-driven console application  

---

## 📌 Future Improvements
- Add validation for mobile numbers  
- Add sorting feature  
- Store additional fields (email, address)  
- Convert project into a GUI-based application  
- Improve error handling and input validation  

---

## 👨‍💻 Author
Developed as a mini project during 2nd semester (BCA).  
Focused on building strong fundamentals in C and file handling.
