#include <iostream>

void investigate(int& suspect, const int& clue)
{
    suspect += clue;

    std::cout << "Inside investigate(): "
         << suspect << " " << clue << std::endl;
}

int main()
{
    int score = 10;
    int bonus = 5;

    investigate(nullptr, bonus);

    std::cout << score << " " << bonus << std::endl;
}