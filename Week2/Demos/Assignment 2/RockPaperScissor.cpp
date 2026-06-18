#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>

int main() {
  // start game (declare variables)
  int player_score = 0;
  int bot_score = 0;
  std::string player_move = "";
  int bot_move = 0;
  std::string bot_pick = "";
  int points_to_win = 0;

  std::cout << "Welcomes to Rock Paper Sissors vs Clankers!!!\nLets start off "
               "with how many points it will take to win: ";
  // validating points to win
  while (true) {
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
    break;
  }
  // game keeps going until someone has enough points to win
  while (player_score < points_to_win && bot_score < points_to_win) {
    // starts with generating bot move to make it easier for player to use cheat
    // ability
    // cheat lets the player know a move the bot won't make. More details later
    bot_move = rand() % 3;
    if (bot_move == 0) {
      bot_pick = "Rock";
    } else if (bot_move == 1) {
      bot_pick = "Paper";
    } else {
      bot_pick = "Scissor";
    }
    // choosing a move the bot won't make for in case the player chooses to
    // cheat
    int bot_wont_move = rand() % 2;
    if (bot_wont_move == 0) {
      bot_wont_move = (bot_move - 1) % 3;
    } else if (bot_wont_move == 1) {
      bot_wont_move = (bot_move + 1) % 3;
    }
    std::string bot_wont_pick = "";
    if (bot_wont_move == 0) {
      bot_wont_pick = "Rock";
    } else if (bot_wont_move == 1) {
      bot_wont_pick = "Paper";
    } else {
      bot_wont_pick = "Scissor";
    }

    // ask for user input
    std::cout << "Choose rock, paper or scissor, or cheat. What does cheat do? "
                 "You might ask. Choose it and find out at your own "
                 "peril.\n";
    // cheat_times starts at zero to allow player to cheat once per round
    size_t cheat_times = 0;
    // validate player move
    while (true) {
      std::cin >> player_move;
      std::string lowercase_player_move = player_move;
      std::transform(lowercase_player_move.begin(), lowercase_player_move.end(),
                     lowercase_player_move.begin(),
                     [](unsigned char c) { return std::tolower(c); });
      if (lowercase_player_move == "rock" || lowercase_player_move == "paper" ||
          lowercase_player_move == "sissor") {
        break;
      } 
      // cheating allows the player to see one of the moves the bot won't be
      // making this turn this allows the player to chose a move based on the
      // two remaining moves the bot could do
      // however it comes with a cost. The player loses 2 points      
      else if (player_move == "cheat") {
        cheat_times++;
        if (cheat_times == 1) {
          std::cout << "Bot will not choose " << bot_wont_pick
                    << ". Choose your move carefuly. And absolutely do not "
                       "cheat again this round. You won't like what happens.\n";
          player_score -= 2;
        } else {
          std::cout
              << "I told you not to cheat again. Couldn't listen?\nNow you'll "
                 "be punished. Condemned to be a loser forever.\nYou lose\n";
          player_score = -678362;
          break;
        }
      }
      else {
        std::cout << "Thats not a legal move. Choose a different one: ";
      }
    }
    std::cout << "You chose " << player_move << " | Bot chose " << bot_pick
              << "\n";

    // scores a single round
    if (player_move == "Rock" && bot_pick == "Scissor") {
      player_score++;
    } else if (player_move == "Paper" && bot_pick == "Rock") {
      player_score++;
    } else if (player_move == "Scissor" && bot_pick == "Paper") {
      player_score++;
    } else {
      bot_score++;
    }
    std::cout << "Your Score: " << player_score << " | Bot Score: " << bot_score
              << "\n";
  }
  // Declare winner or tie
  if (player_score == -678362) {
  } else if (player_score > bot_score) {
    std::cout << "You win!" << std::endl;
  } else if (bot_score > player_score) {
    std::cout << "Bot wins!" << std::endl;
  }
  return 0;
}