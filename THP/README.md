# Project Title: THP Game

## Description
THP is a card game implemented in C++. The project consists of several classes that manage the game flow, including a deck of cards, players, and the overall game management.

## Project Structure
```
THP
├── src
│   ├── main.cpp          # Entry point of the application
│   ├── deck.cpp          # Implementation of the Deck class
│   ├── card.cpp          # Implementation of the Card class
│   ├── player.cpp        # Implementation of the Player class
│   ├── GameManager.cpp    # Implementation of the GameManager class
├── include
│   ├── deck.h            # Header for the Deck class
│   ├── card.h            # Header for the Card class
│   ├── player.h          # Header for the Player class
│   ├── GameManager.h      # Header for the GameManager class
├── Makefile               # Makefile for building the project
└── README.md              # Documentation for the project
```

## How to Build
To compile the project, navigate to the project directory and run the following command:

```
make
```

This will generate an executable named `game`.

## How to Clean
To remove the compiled object files and the executable, run:

```
make clean
```

## Usage
After building the project, you can run the game using:

```
./game
```

## Authors
- Your Name

## License
This project is licensed under the MIT License - see the LICENSE file for details.