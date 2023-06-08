
#include <iostream>
#include <ctime>

// Game introduction message
void PrintIntroduction(int Difficulty)
{
    std::cout << " \n\nYour are a secret agent breaking into a level " << Difficulty <<  std:: endl;
    std::cout << "Dungeon room... Break this code if you want to take the challenge...." << std::endl;
    std::cout << "Press enter have each number you have entered." << std::endl;
}


bool PlayGame(int Difficulty)
{   
    PrintIntroduction(Difficulty);

    // Declaring 3 numbers
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int Codesum = CodeA + CodeB + CodeC;
    const int Codeproduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code " << std::endl;
    std::cout << "The code adds up to: " << Codesum << std::endl;
    std::cout << "The code multiplies to give: " << Codeproduct << std::endl;

    // Store Player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    // If the players guess is correct
    if (GuessSum == Codesum && GuessProduct == Codeproduct)
    {
        std::cout << "You cracked the code ! Enter the server room !!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "You didn't guess the right code, you got this try again! ";
        return false;
    }

}


int main()
{
    srand(time(NULL));// To be able to generate random seeding for GuessA, GuessB, and GuessC
    const int MaxDifficult = 5;
    int LevelOfDifficulty = 1;
    while (LevelOfDifficulty <= MaxDifficult) {
        bool LevelOfComplete = PlayGame(LevelOfDifficulty);
        std::cin.clear();// Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (LevelOfComplete) {
            ++LevelOfDifficulty;
        }
      
    }

    std::cout << " \nGreat Job getting all the data you are a hero !! \n";
    return 0;
}

