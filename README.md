# Stone-Paper-Scissors Game (C++) 🎮

## Overview
A console-based Rock-Paper-Scissors game built with C++. This project demonstrates the practical application of **Clean Code** principles, modularity, and structural software design.

## Features
* **Modular Design:** The game logic is divided into single-responsibility functions (Input, Processing, Output) for high maintainability.
* **State Management:** Utilizes `struct` and pass-by-reference (`&`) for efficient memory management and tracking game results across multiple rounds.
* **Clean Code & Readability:** Extensively uses `enum` to eliminate "magic numbers", making the code self-documenting.
* **Interactive Console UI:** Features dynamic console color changes and sound alerts based on round results.

## Technologies Used
* C++ (Standard Library: `<iostream>`, `<cmath>`, `<cstdlib>`, `<ctime>`)

## How to Play
1. Compile and run the `.cpp` file using any C++ IDE (like Code::Blocks or Visual Studio Code).
2. Enter the number of rounds you want to play.
3. Choose your move:
   * `[1]` for Stone
   * `[2]` for Paper
   * `[3]` for Scissor
4. The game will announce the winner of each round and display a final scoreboard at the end. You can choose to play again without restarting the program.

## Engineering Concepts Applied
* Top-Down Design Approach.
* DRY (Don't Repeat Yourself) principle.
* Separation of Concerns (UI vs Logic).
* Foundation for Object-Oriented Programming (OOP).

---
*Developed by Moaaz Hejazi.*
