/*
SuperAntiNetRunner Version #0.4.0
To Do List:
Method for displaying architecture (Use BFS)
Edit Menu
Add price calculator
Create .txt or .json lists for default control nodes and black ice, pull from PHB
Add method to load above content (large arrays of pointers in main)
Actual graphics? Consider openGL, unity, unreal engine
*/

#include <iostream>
#include <string>
#include <random>
#include "dice.h"

using namespace std;

int main ()
{
    // INIT
    string versionNumber = "0.4.0";
    std::random_device rd;
    std::mt19937 rng = std::mt19937(rd());
    string difficultyChoice, generationChoice, editChoice;

    // Begin "ui"; may replace later with graphics ui
    cout << "Welcome to SuperAntiNetrunner version " << versionNumber << ".\n";

    // Choose difficulty
    difficultyMenu:
    cout
    << "\nPlease select your NET Architecture's difficulty rating.\n"
    << "1. Basic\n"
    << "2. Standard\n"
    << "3. Uncommon\n"
    << "4. Advanced\n"
    << "5. Never mind, get me out of here!\n"
    << flush;
    while (true)
    {
        cout << "Difficulty Choice: ";
        getline(cin, difficultyChoice);
        if (difficultyChoice == "5") 
        {
            cout << "'Ight, see you at the Afterlife!" << endl;
            return 0;
        }
        else if (difficultyChoice == "1" || difficultyChoice == "2" || difficultyChoice == "3" || difficultyChoice == "4")
        {
            break;
        }
        cout << "Invalid Choice, Choomba!" << endl;
    }

    // Choose generation
    generationMenu:
    cout
    << "\nWould you like to build your architecture from the ground up, or edit a randomly generated one?\n"
    << "1. Ground Up\n"
    << "2. Randomly Generated\n"
    << "3. Return to previous menu.\n"
    << "4. Never mind, get me out of here!\n"
    << flush;
    while (true)
    {
        cout << "Generation Choice: ";
        getline(cin, generationChoice);
        if (generationChoice == "4")
        {
            cout << "'Ight, see you at the Afterlife!" << endl;
            return 0;
        }
        else if (generationChoice == "3")
        {
            goto difficultyMenu;
        }
        else if (generationChoice == "2" || generationChoice == "1")
        {
            break;
        }
        cout << "Invalid Choice, Choomba!" << endl;
    }

    // Ground Up
    if (generationChoice == "1")
    {
        groundUpGeneration:;
        //TODO
    }

    // Random Generation
    else if (generationChoice == "2")
    {
        randomGeneration:;
        //TODO
    }

    // Choose to Edit
    editChoiceMenu:
    cout
    << "\nWould you like to make any edits?\n"
    << "1. Yes.\n"
    << "2. No.\n"
    << "3. Return to previous menu.\n"
    << "4. Never mind, get me out of here!\n"
    << flush;
    while (true)
    {
        cout << "Edit Choice: ";
        getline(cin, editChoice);
        if (editChoice == "4")
        {
            cout << "'Ight, see you at the Afterlife!" << endl;
            return 0;
        }
        else if (editChoice == "3")
        {
            goto generationMenu;
        }
        else if (editChoice == "2")
        {
            goto displayFinal;
        }
        else if (editChoice == "1")
        {
            goto editMenu;
        }
        cout << "Invalid Choice, Choomba!" << endl;
    }

    // Edit the Created Architecture
    editMenu:;
    // TODO

    // Display the Final Architecture, then quit and/or output
    displayFinal:;
    // TODO

    return 0;
}