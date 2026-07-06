#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>

/**
 * Introduces name of the game and asks for the number of points the user wants
 * to win
 */
void Rps_Intro();
/**
 * Tells the user what moves are available
 */
void Rule_Explanation();
/**
 * Validates and takes input from player on how many points
 * it should take to win
 * @returns The Number of Points Needed to Win A Game
 */
int Ask_Win_Points();
/**
 * Takes a number from 0-2 and turns it into rock paper sissor move
 * @param bot_pick A number representing one of the game moves
 * @return A string of the chosen rock paper scissor move
 */
std::string Num_To_Move(int bot_pick);
/**
 * Takes a rock paper scissor move and turn it into a number from 0-2
 * @param bot_move A string containing a rock paper scissor move
 * @return A number representing the rock paper scissor move
 */
int Move_To_Num(std::string bot_move);
/**
 * Generates a random rock paper scissor move
 * @return A rock paper scissor move
 */
std::string Bot_Move();
/**
 * Picks a rock paper scissor move the bot won't take
 * @param bot_move The move the bot will make
 * @return A move the bot won't make
 */
std::string Bot_Wont_Move(std::string bot_move);
/**
 * Makes a string lower case
 * @param player_move The move the player chose to make
 * @return The lower case of the player's move
 */
std::string To_Lowercase(std::string player_move);
/**
 * Validates moves and responds to cheating
 * @param bot_move The move the bot will make
 * @param player_score The player's score
 * @param punishment_number The score given to a player who cheats too much
 * @return The player's move
 */
std::string Get_Player_Move(std::string bot_move, int& player_score,
                            int punishment_number);
/**
 * The Logic that decides who gets a point during a round
 * @param bot_move The move the bot made
 * @param player_move The move the player chose to make
 * @param bot_score The current score of the bot
 * @param player_score The current Score of the player
 */
void Score_Round(std::string bot_move, std::string player_move, int& bot_score,
                 int& player_score);
/**
 * Prints the player and bot move
 * @param bot_move The move the bot made
 * @param player_move The move the player chose to make
 */
void Print_Moves(std::string bot_move, std::string player_move);
/**
 * Prints the player's score and bot's score
 * @param bot_score The current score of the bot
 * @param player_score The current Score of the player
 */
void Print_Score(int bot_score, int player_score);
/**
 * Declares who the winner is
 * @param bot_score The bot's score
 * @param player_score The player's score
 * @param punishment_number The score for a player who cheated too much
 */
void Declare_Winner(int bot_score, int player_score, int punishment_number);

int main() {
  int player_score = 0;
  int bot_score = 0;
  std::string player_move = "";
  std::string bot_move = "";
  int points_to_win = 0;
  // A random negative number to check for cheating
  int punishment_number = -678362;

  Rps_Intro();
  points_to_win = Ask_Win_Points();
  // game keeps going until someone has enough points to win or a player cheats
  // too much
  while ((player_score < points_to_win && bot_score < points_to_win) &&
         player_score != punishment_number) {
    bot_move = Bot_Move();

    Rule_Explanation();
    player_move = Get_Player_Move(bot_move, player_score, punishment_number);
    Print_Moves(bot_move, player_move);

    // scores a single round
    Score_Round(bot_move, player_move, bot_score, player_score);
    Print_Score(bot_score, player_score);
  }

  Declare_Winner(bot_score, player_score, punishment_number);
  return 0;
}

void Rps_Intro() {
  std::cout << "Welcomes to Rock Paper Sissors vs Clankers!!!\nLets start off "
               "with how many points it will take to win: ";
}

void Rule_Explanation() {
  std::cout << "Choose rock, paper or scissor, or cheat. What does cheat do? "
               "You might ask. Choose it and find out at your own "
               "peril.\n";
}

int Ask_Win_Points() {
  // Validates User Input of Number of Points to win rps
  while (true) {
    int points_to_win = 0;
    std::cin >> points_to_win;
    // if input isn't an interger
    if (std::cin.fail()) {
      std::cout
          << "Error: Invalid Input. Please check your input and enter again: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      continue;
    }
    if (points_to_win < 0) {
      std::cout << "Error Non Positve Number: Winning Points have to be "
                   "positive.\nTry entering the points one more time: ";
      continue;
    }
    return points_to_win;
  }
}

std::string Num_To_Move(int bot_pick) {
  std::string bot_move;
  if (bot_pick == 0) {
    bot_move = "rock";
  } else if (bot_pick == 1) {
    bot_move = "paper";
  } else {
    bot_move = "scissor";
  }
  return bot_move;
}

int Move_To_Num(std::string bot_move) {
  int bot_pick;
  if (bot_move == "rock") {
    bot_pick = 0;
  } else if (bot_move == "paper") {
    bot_pick = 1;
  } else {
    bot_pick = 2;
  }
  return bot_pick;
}

std::string Bot_Move() {
  int bot_pick;
  std::string bot_move;
  bot_pick = rand() % 3;
  bot_move = Num_To_Move(bot_pick);
  return bot_move;
}

std::string Bot_Wont_Move(std::string bot_move) {
  int bot_pick = Move_To_Num(bot_move);
  // Finds a move the bot won't use
  int bot_wont_pick = (bot_pick + (rand() % 2) + 1) % 3;
  std::string bot_wont_move = Num_To_Move(bot_wont_pick);
  return bot_wont_move;
}

std::string To_Lowercase(std::string player_move) {
  std::string lowercase_player_move = player_move;
  std::transform(lowercase_player_move.begin(), lowercase_player_move.end(),
                 lowercase_player_move.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return lowercase_player_move;
}

std::string Get_Player_Move(std::string bot_move, int& player_score,
                            int punishment_number) {
  // Used to see if player needs to be punished for cheating
  size_t cheat_times = 0;
  std::string player_move = "";

  // validate player move and check for "cheating"
  while (true) {
    std::cin >> player_move;
    player_move = To_Lowercase(player_move);

    if (player_move == "rock" || player_move == "paper" ||
        player_move == "scissor") {
      return player_move;
    }

    // cheat to see bot upcoming move
    if (player_move == "cheat") {
      cheat_times++;
      if (cheat_times == 1) {
        std::string bot_wont_move = Bot_Wont_Move(bot_move);
        std::cout << "Bot will not choose " << bot_wont_move
                  << ". Choose your move carefuly. And absolutely do not "
                     "cheat again this round. You won't like what happens.\n";
        // cost of cheating
        player_score -= 2;
      }
      // Player instantly looses for cheating too much
      else {
        std::cout
            << "I told you not to cheat again. Couldn't listen?\nNow you'll "
               "be punished. Condemned to be a loser forever.\n";
        // Value to check if player cheated too much
        player_score = punishment_number;
        break;
      }
    } else {
      std::cout << "Thats not a legal move. Choose a different one: ";
    }
  }
  return player_move;
}

void Score_Round(std::string bot_move, std::string player_move, int& bot_score,
                 int& player_score) {
  if (player_move == bot_move) {
  } else if (player_move == "rock" && bot_move == "scissor") {
    player_score++;
  } else if (player_move == "paper" && bot_move == "rock") {
    player_score++;
  } else if (player_move == "scissor" && bot_move == "paper") {
    player_score++;
  } else {
    bot_score++;
  }
}

void Print_Moves(std::string bot_move, std::string player_move) {
  std::cout << "You chose " << player_move << " | Bot chose " << bot_move
            << "\n";
}
void Print_Score(int bot_score, int player_score) {
  std::cout << "Your Score: " << player_score << " | Bot Score: " << bot_score
            << "\n";
}

void Declare_Winner(int bot_score, int player_score, int punishment_number) {
  // Checks if player is punished for cheating too much
  if (player_score == punishment_number) {
    std::cout << "You lose\n";
  } else if (player_score > bot_score) {
    std::cout << "You win!" << std::endl;
  } else if (bot_score > player_score) {
    std::cout << "Bot wins!" << std::endl;
  }
}
