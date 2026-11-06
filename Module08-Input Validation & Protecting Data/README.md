## Overview

For Module 8, I added input validation to my C++ application to prevent invalid user inputs and improve reliability.

### What Does It Do?

I created a getPositiveNumber() function that checks whether the user enters a valid positive integer.

The program:

Rejects negative numbers, zero, and non-numeric inputs.

Rejects incorrectly formatted inputs like 12abc.

Displays an error message when the input is invalid.

Allows the user to try again until a valid number is entered.

### How Does It Work?

I used getline(), stringstream, and a while loop to validate user input before accepting it.

Connection to My Application

This validation can be applied to my Midterm Lab Inventory Management System when entering inputs that are positive integers, such as device IDs, quantities, menu selections, etc.

It helps prevent incorrect data from entering the inventory system and makes the application more user-friendly.