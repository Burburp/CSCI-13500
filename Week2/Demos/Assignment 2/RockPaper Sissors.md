# Program Design Document

## Program Name

Rock Paper Sissors

## Purpose

Its a game that plays rock paper sissors against a bot.

---

## Inputs



* Points to Win
* Game Move

---

## Outputs

List what the program will display or produce.

Example:

* Score
* Winner

---

## Added Variables Variables


| cheat_times | size_t | Stores number of times cheated in a round |
| lowercase_player_move | string | stores player move in lower case |
| points_to_win | int | Stores number of points needed to win the game|
| bot_wont_pick | int | name of a random move bot won't pick that round
| bot_wont_move | string | name of a random move bot won't pick that round

---

## Key Design Choice CHanges



* Changed the for loop to a while loop as I felt that most people weren't satisfied with a rock paper sissors game
until one of them got a certain amount of points.
* Created a cheating ability mostly as a gimmick to give the player an advantage and more choice
* Added while loops for input validationso the user can keep correcting as many times as needed
* Created a score tracking system and let the player know about bot moves as a way to increase engagement

Smaller Changes:
Removed the scoring for tie as +=0 is redundant
Removed the tie winning declaration as the while loop and scoring makes a tie impossible with the code revisions

---

## Program Steps (Algorithm)

1. Set up game environment
2. Get Player input and validate move choice
3. Score points
4. Declare a winner