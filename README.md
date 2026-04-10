# 📚 Library Management System (C++)

A robust, console-based Library Management System developed in **C++**. This project provides a comprehensive set of tools for librarians to manage book inventories, track borrowings, and maintain library statistics efficiently through an interactive command-line interface.

<img width="1057" height="480" alt="librarycpp" src="https://github.com/user-attachments/assets/cc14a388-6a6e-46e5-968e-542a1caa1992" />

## ✨ Core Features

The system offers 12 specialized functions to ensure complete control over the library's workflow:

*   **📖 Book Management**: Add new books, edit existing details, and delete obsolete entries from the database.
*   **🔍 Advanced Search**: Quickly locate any book in the library using the built-in search functionality.
*   **🔄 Transaction Tracking**: Manage the "Borrow" and "Restore" (Return) cycles for members.
*   **📊 Inventory Counters**:
    *   **Total Books**: Real-time count of every copy in the library.
    *   **Borrowed Books**: Tracking the current volume of books out on loan.
    *   **Unique Titles**: Distinguishing between multiple copies and unique book titles.
    *   **Shelf Management**: A logical "Shelves Counter" to help organize physical space.

## 🛠️ Technical Implementation

*   **Language**: C++ (Standard 11/14/17).
*   **Paradigm**: Procedural Programming with structured data (Structs).
*   **Memory Management**: Efficient use of arrays to manage and display book records in real-time.
*   **Algorithm Efficiency**: Optimized search and counter logic for fast performance within the system.

## 🚀 Getting Started

### Prerequisites
*   A C++ Compiler (GCC, Clang, or MSVC).
*   Code Editor/IDE (VS Code, Code::Blocks, or Visual Studio).

### Installation & Running
1.  **Clone the Repository**:
    ```bash
    git clone https://github.com/habiba-mahfouz/Library-Management-System-Cpp.git
    ```
2.  **Compile the Code**:
    ```bash
    g++ main.cpp source.cpp -o library_system
    ```
3.  **Run the Application**:
    ```bash
    ./library_system
    ```

## 🎮 How to Use
Once launched, the system presents a numbered menu. Simply **enter the command number** (1-12) to execute the desired operation and follow the on-screen prompts. 

> **Note:** This version maintains all data in memory during the session.

---
*Developed with a focus on logic and data organization.*
