# BlackJack
This is a C++ implementation of the classic card game Blackjack. The game features a graphical interface for rendering using Qt library. 

The cards are animated and appear to move onto the screen from any side. Additionally, the game allows for the customization of card skins and includes sound playback (music and sound effects).

## Demonstration
![screenshot](https://github.com/ShevaMed/BlackJack/blob/main/screenshots/demonstration.gif)

## Screenshots
![screenshot](https://github.com/ShevaMed/BlackJack/blob/main/screenshots/screen1.png)
![screenshot](https://github.com/ShevaMed/BlackJack/blob/main/screenshots/screen2.png)
![screenshot](https://github.com/ShevaMed/BlackJack/blob/main/screenshots/screen3.png)

## Gameplay
The goal of Blackjack is to beat the dealer's hand without going over 21. Here are the basic rules:
- Face cards (king, queen, and jack) are worth 10 points each.
- Aces can be worth either 1 or 11 points, depending on which value makes a better hand.
- The value of numbered cards is equal to their number.
- Each player starts with two cards, and one of the dealer's cards is hidden until the end.
- To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn.
- If a player's hand goes over 21, they bust and automatically lose the round, regardless of the dealer's hand.
The game provides buttons for the player to either 'Hit' (ask for another card) or 'Stand' (end their turn). The dealer's and player's cards are rendered on the screen.

## Development
The implementation follows modern C++ practices and utilizes various features such as virtual functions, smart pointers, and RAII. The codebase embraces the best practices of C++ and aims to provide an efficient and maintainable solution.

## Installation
To set up the project, follow these steps:
1. Clone the repository to your local machine.
2. Install the necessary technologies and libraries specified in the project's [Dependencies](#dependencies).
3. Build a project with Qt Creator using the `BlackJack.pro` file.
4. Compile the project with the Desktop MinGW (>= 11.2.0) 64-bit for C++.
5. Now you can run the program using Qt Creator.

## Dependencies
- Qt (>= 6.4.0) in C++
- Desktop MinGW (>= 11.2.0) 64-bit for C++
- Qt Creator (>= 8.0.2) or other IDE

To download Qt, Compiler and IDE, you need to follow the link: https://www.qt.io/download-open-source and download the Qt Online Installer or Qt Source Packages.

## Technologies Used
- Framework: Qt 6.4.0 in C++
- Compiler: Desktop MinGW 11.2.0 64-bit for C++
- IDE: Qt Creator 8.0.2
