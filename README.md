# 1. Project Description
- This is a simple console-based library management system. It is designed to demonstrate the fundamental knowledge aboout OOP in C++. This system's functions include: Login, Show books, Show users's information, show librarian's information.

# 2. Simple class Diagram
<img width="771" height="321" alt="OOP drawio" src="https://github.com/user-attachments/assets/2861691b-f7b5-4fbc-b50b-5e21996ac0a3" />

# 3. Explaination of Inheritance, polymorphism, abstraction, and interface
- Abstraction: User abstract class. It defines a blueprint for all users without specifying any user until it is inherited.
- Inheritance: Students and Librarian class. These classes inherit from User class. It allows them to reuse the general information like id and name while adding their unique details like bookBorrows for Students and Shift for Librarian.
- Polymorphism: In the main function, we use User* pointers to point Students of Librarian objects. For example when we call displayRole(), based on the type of user that is pointed at the runtime, the program know exactly which function has to be execute, the role of librarian or students.
- Interface: The Login class acts as the interface. It defines the log in ability to access to the main system that any class can implement, keeping it separate from the main hierachy.

# 4. Explaination of composition and inheritance
- Inheritance: IS-A relationship. We use this when a class is a specialized version of another, for example Student IS-A User
- Composition: HAS-A relationship. We use this when a class contains another class as a member, for example Library HAS-A Book

# 5. How to compile and run the program
- If using terminal we have to compile and run it separately:
+ To compile it, use the command: g++ main.cpp -o LibraryManager
+ To run the program, use the command: ./LibraryManager.exe

- If using Visual Studio, just use the Build and Use function in the app, it will automatically compile and run the program for us

- For the login, I provide 2 options:
+ Login as Students:
ID: 201
Name: Ngo Gia Hy

+ Login as Librarian:
ID: 101
Name: Le Thanks Wuang Min

However, eventhough we login as a student or librarian, the function or the accessibility to the contain are the same due to the fact that this is just a simple program.
