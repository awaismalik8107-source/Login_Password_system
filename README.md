# Login_Password_system
This project implements a terminal-based Login and Authentication System in C, designed for small console applications that require secure user validation. It reads user credentials (username, password, and authority level) from a text file and verifies them using string parsing and comparison methods.

🔐 C Login & Authentication System

A simple yet functional username/password login system in C, complete with loading animations, color-based UI, and authority-level support.
This program reads user credentials from a text file (User-List.txt) and authenticates users before allowing access to the main program.

📁 Project Structure
.
├── login.h           # Login system header file
├── login.c           # Implementation of login functions
├── COLORS.c          # ANSI color codes for UI
├── User-List.txt     # User database (text file)
└── main.c            # Your main program (calls Login())

🚀 Features

✔ Username & password authentication

✔ Case-insensitive username checking

✔ Authority level loading (e.g., admin / staff)

✔ Loading animation + welcome screen

✔ Colorful terminal interface

✔ Global variables store logged-in username & authority

✔ Loops until valid credentials are entered

📌 User Database Format (User-List.txt)

Each user entry must be on one line, like this:

username:- John Password:- 1234 Authority level:- admin
username:- Ali Password:- pass123 Authority level:- staff
username:- Guest Password:- guest Authority level:- viewer


The program automatically extracts:

username

password

authority

Using strstr() and sscanf().

🧠 How the Login System Works
1. Loading Screen

load() displays:

A welcome banner (loading_screen())

A timed progress animation (loading())

2. Username & Password Input

Login_username() asks the user to input:

Username:
Password:

3. Authentication

For each line in User-List.txt:

Extracts username

Compares with input (case-insensitive)

If matched → checks password

If both match → loads authority

If incorrect:

“User Not Found” or “Wrong Password”

Waits 3 seconds

Repeats

4. Successful Login

The program stores:

login_usernames  → actual username
login_authority  → authority level


Then clears the screen and returns control to the main program.

🔧 Functions Overview
Function	Description
Login()	Main login wrapper. Shows loading screen and calls Login_username().
Login_username(char*)	Handles credential checking against User-List.txt.
load()	Combined screen + animation loader.
loading_screen()	Displays welcome banner.
loading()	Produces timed loading progress bar.

Global variables (from login.h):

extern char login_usernames[20];
extern char login_authority[20];

📌 Example Usage in main.c
#include "login.h"
#include <stdio.h>

int main() {
    Login();

    printf("Logged in as: %s\n", login_usernames);
    printf("Authority: %s\n", login_authority);

    // Continue program...
}

⚠ Requirements

GCC or any C compiler

Linux/Mac terminal (system("clear"))

Windows users must replace with cls

Ensure User-List.txt exists in the same directory

📜 License

This project is free to use, modify, and adapt for educational and learning purposes.
