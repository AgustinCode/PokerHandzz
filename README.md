   # 🃏 PokerHandzz

   ![Poker Banner](https://via.placeholder.com/800x200?text=PokerHandzz)

   ## 📖 Description

   PokerHandzz is an console application poker game simulation featuring multiple players and different rounds: Preflop, Flop, Turn, River, and Showdown. The main objective of this program is to calculate the win rate of each hand in real-time during the game, based on various factors such as community cards and player hands.
   
   Currently, the program runs in a console-based environment, simulating poker gameplay and displaying community cards and player hands as the game progresses.

   ### 🚀 Future Enhancements

   - Graphical interface for a more user-friendly experience
   - Advanced real-time win rate calculations for each player's hand

   ## ✨ Features

   - 🎲 Simulates poker rounds: Preflop, Flop, Turn, River, and Showdown
   - 🃏 Randomized card distribution to players
   - 👁️ Displays community cards and player hands during each round
   - 🔄 State management system to transition between different game phases

   ## 🛠️ Installation

   Ensure you have a C++ development environment set up.

   1. Clone this repository:
      ```bash
      git clone https://github.com/your-username/PokerHandzz.git
      ```

   2. Navigate to the project directory:
      ```bash
      cd PokerHandzz
      ```

   3. Compile the program:
      ```bash
      g++ -o pokerhandzz main.cpp Game.cpp Player.cpp Hand.cpp Card.cpp -std=c++11
      ```

   4. Run the program:
      ```bash
      ./pokerhandzz
      ```

   ## 🎮 Usage

   Once the program is running, it will automatically add players, deal hands, and progress through the poker phases (Preflop, Flop, Turn, River). The player's hands and community cards will be displayed during each phase.

   Basic commands (when added):
   - `Arrow Keys`: Progress to the next game phase


   ## 🔮 Future Plans

   ### Win Rate Calculation

   We will implement real-time win rate calculations for each hand based on:
   - Visible player and community cards
   - Mathematical probabilities of hand improvement
   - Opponent hands and potential outcomes

   ### Graphical User Interface (GUI)

   A graphical interface will be added using a library like SFML or Qt to improve user experience and allow for a visual poker simulation.

   ## 🤝 Contributing

   Contributions are welcome! To contribute to this project:

   1. Fork the repository
   2. Create a new branch for your feature: `git checkout -b feature-name`
   3. Make your changes and commit: `git commit -m "Clear description of changes"`
   4. Push your changes to GitHub: `git push origin feature-name`
   5. Create a Pull Request and explain your proposed changes

   ## 📄 License

   This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

   ## 📞 Contact

   For any questions or suggestions, feel free to contact us via the GitHub repository or send an email to relaxingscript@gmail.com.

   ---

   <p align="center">
   Made with ❤️
   </p>
