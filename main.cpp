/*
SuperAntiNetRunner Version #0.3.0
To Do List:
RETHINK DATA STRUCTURE FOR ARCHITECTURE
Method for displaying architecture
Edit Menu
Add price calculator
Create classes/structures for control nodes, black ice
Create .txt or .json lists for default control nodes and black ice, pull from PHB
Add method to load above content
Add pathfinder numbers
Actual graphics? Consider openGL, unity, unreal engine
*/

#include <iostream>
#include <string>
#include "dice.h"

using namespace std;

int main ()
{
    // INIT
    string versionNumber = "0.3.0";
    string difficultyChoice, generationChoice, editChoice;

    // Begin "ui"; may replace later with graphics ui
    cout << "Welcome to SuperAntiNetrunner version " << versionNumber << "." << endl;

    // Choose difficulty
    difficultyMenu:
    cout << endl << "Please select your NET Architecture's difficulty rating." << endl;
    cout << "1. Basic" << endl;
    cout << "2. Standard" << endl;
    cout << "3. Uncommon" << endl;
    cout << "4. Advanced" << endl;
    cout << "5. Never mind, get me out of here!" << endl << endl;
    while (true)
    {
        cout << "Difficulty Choice: ";
        getline(cin, difficultyChoice);
        if (difficultyChoice == "5") 
        {
            cout << "'Ight, see you at the Afterlife!" << endl;
            exit(EXIT_SUCCESS);
        }
        else if (difficultyChoice == "1" || difficultyChoice == "2" || difficultyChoice == "3" || difficultyChoice == "4")
        {
            break;
        }
        cout << "Invalid Choice, Choomba!" << endl;
    }

    // Choose generation
    generationMenu:
    cout << endl << "Would you like to build your architecture from the ground up, or edit a randomly generated one?" << endl;
    cout << "1. Ground Up" << endl;
    cout << "2. Randomly Generated" << endl;
    cout << "3. Return to previous menu." << endl;
    cout << "4. Never mind, get me out of here!" << endl;
    while (true)
    {
        cout << "Generation Choice: ";
        getline(cin, generationChoice);
        if (generationChoice == "4")
        {
            cout << "'Ight, see you at the Afterlife!" << endl;
            exit(EXIT_SUCCESS);
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
    cout << endl << "Would you like to make any edits?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    cout << "3. Return to previous menu." << endl;
    cout << "4. Never mind, get me out of here!" << endl;
    while (true)
    {
        cout << "Edit Choice: ";
        getline(cin, editChoice);
        if (editChoice == "4")
        {
            cout << "'Ight, see you at the Afterlife!" << endl;
            exit(EXIT_SUCCESS);
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