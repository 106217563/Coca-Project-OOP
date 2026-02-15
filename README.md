1. Project Description
This is a simple console-based Library Management System designed to demonstrate core Object-Oriented Programming (OOP) concepts in C++. The system allows users to login as either a Student or a Librarian. Once authenticated, users can view all available books in the library or check their own profile information.

2. Simple Class Diagram
Plaintext
[Interface] Login 
      ▲
      │ (implements)
      │
[Abstract] User ◄────────────────┐ (Composition: Library HAS-A Book)
      ▲                          │
      ├─── Student (IS-A User)   │
      └─── Librarian (IS-A User) │
                                 │
    Library ─────────────────────┘
3. Explanation of Core OOP Concepts
Abstraction: Demonstrated through the User abstract class. It defines the "blueprint" for all users without specifying their exact roles until inherited.

Interface: The Login class acts as an interface. It defines a "capability" (the ability to log in) that any class can implement, keeping it separate from the main user hierarchy.

Inheritance: The Student and Librarian classes inherit from User. This allows them to reuse common attributes like id and name while adding their own specific details (like booksBorrowed or shift).

Polymorphism: In the main function, we use User* pointers to point to Student and Librarian objects. When we call displayRole(), C++ automatically decides which version of the function to run based on the actual object type at runtime.

4. Composition vs Inheritance
Inheritance (IS-A relationship): We use this when one class is a specialized version of another. For example, a Student IS-A User.

Composition (HAS-A relationship): We use this when one class is made up of other objects. For example, a Library HAS-A list of Books.

Decision: We chose Composition for the Library class because a library is a container for books, not a type of book itself.

5. How to Compile and Run
Requirement: A C++ compiler (like G++ or Visual Studio).

Compile:

Bash
g++ main.cpp -o library_system
Run:

Bash
./library_system
Login Info:

Student: ID 201, Name Ngo Gia Hy

Librarian: ID 101, Name Le Thanks Wuang Min
