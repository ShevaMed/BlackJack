# BlackJack
This is a C++ implementation of the classic card game Blackjack. The game features a graphical interface for rendering using Qt library. 

The cards are animated and appear to move onto the screen from any side. Additionally, the game allows for the customization of card skins and includes sound playback (music and sound effects).

## Development
The implementation follows modern C++ practices and utilizes various features such as virtual functions, smart pointers, and RAII. The codebase embraces the best practices of C++ and aims to provide an efficient and maintainable solution.

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

## Installation
To set up the project, follow these steps:
1. Clone the repository to your local machine.
2. Install the necessary technologies and libraries specified in the project's [Technologies Used](#technologies-used).
3. Build a project with Qt Creator using the `BlackJack.pro` file.
4. Compile the project with the Desktop Qt 6.4.0 MinGW 64-bit or higher version.
5. Now you can run the program using Qt Creator.

## Technologies Used
- Framework: Qt 6.4.0 in C++
- IDE: Qt Creator 8.0.2
- Compiler: Desktop Qt 6.4.0 MinGW 64-bit
