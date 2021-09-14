/*SuperAntiNetRunner Version# 0.2.0
To Do List:
Build menus
Add all default BlackIce
Add ability for custom BlackIce
Add default blockers
Add default Deamons
Add default control nodes
Add a price calculator
Add pathfinder numbers
Add deferentiating classes of dificulty for all items in the Arc
QOL:
Add updatedable notes to control nodes
OpenGL Graphics!
*/



#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

//Classes
class Price //This keeps track of the price through the program
{
    private:
        int totalPrice;

    public:
        Price(){
            totalPrice = 0;
        }

        Price(int setPrice){
            totalPrice = setPrice;
        }

        int getPrice(){
            return totalPrice;
        }

};


//Functions
int d(int num, int sides){ //Random Generator
      int total = 0;
      for(int i = 0; i < num; i++){
          total += rand() % sides + 1;
    }
      return total;
}

void printArchi(vector<string> nodeContent, vector<int> nodeConnection){ //Print the Architecture

    for(int i=0; i < nodeContent.size(); i++){
        cout.width(15); cout << right << nodeContent[i] << endl;
    }

      for(int j=0; j < nodeConnection.size(); j++){
        cout << nodeConnection[j] << endl;
    }
}

bool isIn(vector<string> vec, string elem){
              for(int i = 0; i < vec.size(); i++){
                  if(elem == vec[i]){
                      return true;
                }
            }
              return false;
        }

int main()
{
      //Set Random seed
      srand(time(NULL));

    //Variables
      bool open;
      int budget, floors, branches;
      int totalContents = 0;
      int totalLobby = 0;
      string diff, choice, editChoice, contentLines, contentLobby;
      string version = "0.1.0";
      vector<string> lobby;
      vector<string> content;
      vector<string> alreadyRolled;

/*
random or custom?
    menu to generate floors either random or custom (full random and sets price/ difficulty limit)
    navigate to lobby and then each floor past. left to right in case of split
    menu open that the user selects either to fill node with random or custom
     takes the price of the total number of floors and the cost of the blackice/blockers and ads them together
    ability to print the architecture and possibly select individual nodes to make edits/ make notes
*/

      cout << "Welcome to SuperAntiNetRunner Version " << version << endl;

      open = true;
      while (open){
        cout << "Please select your SuperAntiNetRunner NET Architecture's difficulty rating." << endl << endl; //Takes the users selection of difficulty for the program to build on
        cout << "1. Basic" << endl;
        cout << "2. Standard" << endl;
        cout << "3. Uncommon" << endl;
        cout << "4. Advanced" << endl;
          cout << "5. Get me out of here! (Delta)" << endl;
          cout << "Difficulty Choice: ";

          getline(cin, diff);
          if(diff != "1" && diff != "2" && diff != "3" && diff != "4" && diff != "5"){
            cout << "ERROR: INVALID CHOICE CHOOMBA" << endl << endl;
            continue;
        }
          open = false;
    }
    if (diff == "5"){ //Quit command
          cout << "Ight! See you at The Afterlife" << endl;
        exit(EXIT_SUCCESS);
    }

      open = true;
      while(open){
          cout << "Would you like to build your architecture from the ground up, or edit a randomly generated one?" << endl; //Takes the users selection of architecture builder
          cout << "1. Ground up" << endl;
          cout << "2. Radomly generated" << endl;
          cout << "3. Nevermind I'll pass. (Delta)" << endl;
          cout << "Generation Choice: ";

          getline(cin, choice);
          if(choice != "1" && choice != "2" && choice != "3"){
            cout << "ERROR: INVALID CHOICE CHOOMBA" << endl << endl;
            continue;
        }
        open = false;
    }

      if(choice == "1"){ //Ground up stuff
        cout << "How much are you willing to spend? (In Eddies)"<< endl;
        cin >> budget;
        cout << "That's preem! " << budget << "Eddies gives us room to work!" << endl;
          cout << "How many floors do you want?" << endl;
        cin >> floors;
          cout << "Good choice Choomba! " << floors << " floors is nice!" << endl;
          cout << "Now how many branches are we working with?" << endl;
          cin >> branches;
          cout << "Alright! " << branches << "branches it is!" << endl;
          cout << "Building your stuff now!" << endl;

          vector<string> nodeContent(floors, "Filler");
          vector<int> nodeConnection{-1,0};

          printArchi(nodeContent, nodeConnection);

    }
      else if(choice == "2"){ //Random generation
        //generate # of floors and branches
          floors = d(3, 6);
          branches = 1;
          while(d(1, 10) > 6){
              branches++;
        }
          if(floors == 3){
              branches = 1;
        }
          else if(branches > floors - 3){
              branches = floors - 3;
        }
        cout << floors << " floors" << endl;
        cout << branches << " branches" << endl;

          //generate content of floors

        if(diff == "1"){
            ifstream difficulty("difficulty1.txt");
            totalContents = 0;
            while(getline(difficulty, contentLines)){
                totalContents++;
                content.push_back(contentLines);
            }
        }
        else if(diff == "2"){
            ifstream difficulty("difficulty2.txt");
            totalContents = 0;
            while(getline(difficulty, contentLines)){
                totalContents++;
                content.push_back(contentLines);
            }
        }
        else if(diff == "3"){
            ifstream difficulty("difficulty3.txt");
            totalContents = 0;
            while(getline(difficulty, contentLines)){
                totalContents++;
                content.push_back(contentLines);
            }
        }
        else if(diff == "4"){
            ifstream difficulty("difficulty4.txt");
            totalContents = 0;
            while(getline(difficulty, contentLines)){
                totalContents++;
                content.push_back(contentLines);
            }
        }

        vector<string> nodeContent(floors);

        ifstream lobbyFile("lobby.txt");
        totalLobby = 0;
        while(getline(lobbyFile, contentLobby)){
            totalLobby++;
            lobby.push_back(contentLobby);
        }

        for (int i = 0; i < 3; i++){
            nodeContent[i] = lobby[d(1,6)-1];
              while(isIn(alreadyRolled, nodeContent[i])){
                  nodeContent[i] = lobby[d(1,6)-1];
            }
              alreadyRolled.push_back(nodeContent[i]);
        }
        alreadyRolled.clear();

        for(int i= 3; i < floors; i++){
            nodeContent[i] = content[d(3,6)-3];
              while(isIn(alreadyRolled, nodeContent[i])){
                  nodeContent[i] = content[d(3,6)-3];
            }
              alreadyRolled.push_back(nodeContent[i]);
        }

          //generation of floor connections

        vector<int> nodeConnection(floors);

          //generation rules:
          //split up floors between main branch + branches (branches + 1)
          //cannot branch until second floor
          //make sure 1 longest floor for 'bottom' for virus <--- hardest part

          //allocate floors to branches
          vector<int> branchLen(branches,1);
          branchLen[0] = 3;
          for(int i = 0; i < floors - branches - 3; i++){
            branchLen[rand() % branches]++;
        }
          //main branch always leftmost, >= 3
          //leave one floor to guarantee a tiebreaker at the end!!

          vector<int> branchIndices(branches*2);
          int branchRT = 0;
          for(int i = 0; i < branches; i++){
              branchIndices[2*i] = branchRT;
              branchIndices[2*i+1] = branchRT + branchLen[i] - 1;
              branchRT += branchLen[i];
        }

          //decide where branches connect, s.t. always 1 longest floor
          //consec branches can branch off of preexisting branches
          vector<int> branchCon(branches);
          vector<int> branchLevel(branches);

          //main branch case
          branchCon[0] = -1;
          branchLevel[0] = branchLen[0];

          for(int i = 1; i < branches; i++){
              //decide which preexisting branch
              int j = rand() % i;
              //branch that branching off cannot have only 1 node
              while(branchLen[j] == 1){
                   j = rand() % i;
            }
              if(j == 0){
                  branchCon[i] = rand() % (branchLen[0] - 2) + 1;
            }
              else{
                  branchCon[i] = rand() % (branchLen[j] - 1) + branchIndices[2*j];
            }
        }

          //count levels for each branch; if tie in greatest floors, just add one floor. If no tie, add floor such that no tie.

          //fill branchLevel
          for(int i = 1; i < branches; i++){
              int j = branchCon[i];
              int levelTotal = branchLen[i];
              while(j != -1){
                  //detect which floor current floor is connected to, then repeat to go back branch until main branch to add to level total.
                  for(int k = 0; k < branches; k++){
                      if(j >= branchIndices[2*k] && j <= branchIndices[2*k+1]){
                          levelTotal += (j - branchIndices[2*k] + 1);
                          j = branchCon[k];
                          break;
                      }
                  }
              }
              branchLevel[i] = levelTotal;
          }

          //look for ties
          //first, find lowest floor
          int lowest = 0;
          for(int i = 0; i < branches; i++){
              if(branchLevel[i] > lowest){
                  lowest = branchLevel[i];
              }
          }
          //then, find occurences of lowest floor
          vector<int> lowestBranches;
          for(int i = 0; i < branches; i++){
              if(branchLevel[i] = lowest){
                  lowestBranches.push_back(i);
              }
          }
          //if tie, add one floor to any of the tied branches
          int floorAdded;
          if(lowestBranches.size() > 1){
              floorAdded = lowestBranches[rand() % lowestBranches.size()];
          }
          //if no tie, add one floor to longest branch so no new tie happens
          else{
              floorAdded = lowestBranches[0];
          }

          //finally assign nodeConnection
        for(int i = 0; i < branches; i++){
            for(int j = branchIndices[2*i]; j <= branchIndices[2*i+1]; j++){
                if(j == branchIndices[2*i]){
                    nodeConnection[j] = branchCon[i];
                }
                else{
                    nodeConnection[j] = j - 1;
                }
            }
        }
        //assign extra floor
        nodeConnection[floors-1] = branchIndices[2*floorAdded+1];

        open = true;
        while (open){
            cout << "Would you like to make any edits?" << endl;
            cout << "1. Yes!" << endl;
            cout << "2. No thanks!" << endl;
            cout << "3. Get this off my screen! (Delta)" << endl;

            getline(cin, editChoice);
            if(editChoice != "1" && editChoice != "2" && editChoice != "3"){
                cout << "ERROR: INVALID CHOICE CHOOMBA" << endl << endl;
                continue;
            }
            open = false;
        }

                if(editChoice == "1"){ //Edit the architecture
                    cout << "Feature not yet in. Sorry Choomba :(" << endl; // Remove this when we implement edits
                }
                else if(editChoice == "2"){ //Prints the architecture
                    cout << "Congrats Choomba! Enjoy your SuperAntiNetRunner NetArchitecture!" << endl;
                    printArchi(nodeContent, nodeConnection);
                }
                else if(choice == "3"){ //Quit command
                cout << "Ight! See you at The Afterlife" << endl;
                exit(EXIT_SUCCESS);
                }
    }


  // 2 vectors same size, 1st string-type, 2nd int-type
  // {"nodecontent0","nodecontent1","nodecontent2","nodecontent3","nodecontent4","nodecontent5","nodecontent6"}
  // {-1,0,1,1,2,3,3} <--- the node that the node at the same index is connected to

    return 0;
}