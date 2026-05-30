# Student Management System 📖 

A clean, terminal-based application built in C to mark the successful completion of my 1st semester in CSIT. This project serves as a practical application of core procedural programming concepts before transitioning to higher-level languages.

## 🛠️ Key Features
* **Full CRUD Operations:** Add, view, update, and delete student data.
* **Search Engine:** Find students instantly by Roll Number or Name.
* **Course Filter:** List all students enrolled in a specific Course ID.
* **Record Deletion:** Shifting algorithm to cleanly remove records without leaving empty spaces.

## 🧠 Concepts Applied
* **Structures (`struct`):** For grouping different data types into a unified student record.
* **Nested Loops:** For searching deep inside individual course arrays.
* **String Processing:** Used `strcmp` for text-based matching.
* **Flag Variables:** Tracking states (`found = 1`) to handle search failures cleanly.
* **Input/Output Handling:** Used `%[^\n]` to read full strings with spaces.

## 💻 How To Run
To compile and run this project locally, execute the following commands in your terminal:

```bash
gcc main.c -o program
./program
```
