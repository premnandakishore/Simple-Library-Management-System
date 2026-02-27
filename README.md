# 📚 Simple Library Management System (C++)

## 📌 Project Overview

This is a console-based Library Management System developed in C++ that manages book records using a **Singly Linked List** data structure.

The system allows dynamic memory allocation for books and supports full CRUD operations (Create, Read, Update, Delete).

This project demonstrates practical implementation of core Data Structures concepts.

## 🚀 Features

- ➕ Add New Book
- 🔍 Search Book by ID
- 📖 Issue Book to Student
- 🔄 Return Book
- 📋 List All Books
- ❌ Delete Book
- 🧹 Automatic Memory Cleanup using Destructor

## 🧠 Data Structures & Concepts Used

- Singly Linked List
- Dynamic Memory Allocation (`new` / `delete`)
- Pointers
- Structs & Classes
- Constructors & Destructors
- Object-Oriented Programming
- Menu-driven System Design

## 🛠 Technologies Used

- C++
- Standard Library (`iostream`, `string`)
- Console-based UI

## ⚙️ How It Works

Each book is stored as a node in a singly linked list containing:

- Book ID
- Title
- Author
- Issue Status (Available / Issued)
- Pointer to next book

Books are dynamically added to the end of the list.  
Search operations traverse the list linearly.  
Memory is properly released when the program exits.
