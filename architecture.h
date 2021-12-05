#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include <string>

/*
A net architecture consists of a number of "floors", more like rooms/nodes.
There is one entry/root floor. Every floor can have only 1 parent, but can have 1 or more child floors. The root floor can only have 1 child floor.
Each floor has a single object of: a password, control node, file, a group of black ice, or a demon.
All such objects have an associated cost.
A password, a control node, and a file have a DV associated with them.
A black ice GROUP object is a list of black ice objects; a demon is just a specialized black ice object.
A black ice object is the only object with a flat cost element; all other costs are determined by DVs.
A file has a string description to differentiate it from other files.
A control node has an associated defense object. Each defense object has: a DV to counter it, which determines its cost, a string name, and a string description of all its capabilities.
*/

// NONE, PASSWORD, FILE, CONTROL, BLACKICE
enum ContentType;
// BASIC, STANDARD, UNCOMMON, ADVANCED; 6, 8, 10, 12
enum DV;

class FloorContent
{
    public:
        // Default is NONE
        FloorContent ();
        ~FloorContent ();
        ContentType getContentType ();
        int getCost ();
        // Override per subclass; print content
        void print ();
    protected:
        ContentType contentType;
        int cost;
};

class Password : public FloorContent
{
    public:
        Password ();
        Password (DV diffVal);
        ~Password ();
        // Returns difficulty value of password backdoor
        int getDV ();
    private:
        DV diffVal;
};

class File : public FloorContent
{
    public:
        File ();
        File (DV diffVal, std::string fileDesc);
        ~File ();
        // Returns difficulty value of file access
        int getDV ();
        // Returns content/identifier of file
        std::string getContent ();
        // Update content/identifier
        void setContent (std::string fileDesc);
    private:
        DV diffVal;
        std::string fileDesc;
};

class ControlNode : public FloorContent
{
    public:
        ControlNode ();
        ControlNode (DV diffVal, Defense* defense);
        ~ControlNode ();
        // Returns difficulty value of node control
        int getDV ();
        // Returns pointer to the associated defense
        Defense* getDefense ();
    private:
        DV diffVal;
        Defense* defense;
};

// ACTIVE, EMPLACED, ENVIRONMENTAL
enum defenseCategory;
// BASIC, STANDARD, UNCOMMON, ADVANCED; 9, 13, 17, 21
enum defenseDV;

class Defense
{
    public:
        Defense ();
        Defense (defenseDV diffVal, int defuseMinutes, defenseCategory category, std::string type, std::string desc, std::string trigger, std::string data);
        // Copy constructor
        Defense (Defense* defense);
        ~Defense ();
        // Returns difficulty value of defense
        int getDV ();
        // Returns cost of defense
        int getCost ();
        // Returns the counter time
        int getDefuse ();
        // Returns category of defense
        int getCategory ();
        // Returns name/type of defense
        std::string getType ();
        // Returns description of defense
        std::string getDesc ();
        // Returns triggers of defense
        std::string getTrigger ();
        // Returns list of various data tags
        std::string getData ();
    private:
        defenseDV diffVal;
        // The amount of minute it takes to counter the defense with Electronics/Security Tech
        int defuseMinutes;
        int cost;
        defenseCategory category;
        std::string type;
        std::string desc;
        std::string trigger;
        // List of tags such as HP or special notes
        std::string data;
};

class BlackIceGroup : public FloorContent
{
    public:
        BlackIceGroup ();
        ~BlackIceGroup ();
        // Add a black ice to the group; error thrown if unable to
        void addBlackIce (BlackIce* blackIce);
        // Remove a black ice by name; returns false if unable to find, otherwise true
        bool removeBlackIce (std::string name);
    private:
        // Number of Black Ice, up to 3; demons are max 1
        int numBI;
        // List of Black Ice in Group
        BlackIce** group;
};

// PERSONNEL, PROGRAM, DEMON
enum BIType;

class BlackIce
{
    public:
        BlackIce ();
        BlackIce (std::string name, std::string icon, int cost, BIType type, int rez, int per, int spd, int atk, int def, std::string effect);
        // Copy constructor
        BlackIce (BlackIce* blackIce);
        ~BlackIce ();
        std::string getName ();
        std::string getIcon ();
        int getCost ();
        int getType ();
        // Returns pointer to stat array
        int* getStats ();
        std::string getEffect ();
    protected:
        std::string name;
        // Descriptor of appearance
        std::string icon;
        int cost;
        BIType type;
        // REZ, Perception, Speed, Attack, Defense (array length 5)
        int* stats;
    private:
        // Result of successful hit
        std::string effect;
};

class Demon : public BlackIce
{
    public:
        Demon ();
        Demon (std::string name, std::string icon, int cost, int rez, int interface, int netActions, int combatNum);
        // Copy constructor
        Demon (Demon* demon);
        ~Demon ();
        // Stats are instead: REZ, Interface, NET Actions, Combat Number (array length 4)
};

class Floor
{
    public:
        Floor ();
        Floor (Floor* parent);
        ~Floor ();
        // Return pointer to parent floor
        Floor* getParent ();
        // Return list of children
        Floor** getChildren ();
        // Sets parent to new parent if possible; returns false if unable to (new parent is already parent)
        bool setParent (Floor* parent);
        // Looks for child in list of children; returns false if not present, returns true if able to remove.
        bool removeChild (Floor* child);
        // Add a child to list of children; returns false if unable to (floor is already child)
        bool addChild (Floor* child);
    private:
        // Pointer to singular parent
        Floor* parent;
        // Array of pointers to children
        Floor** children;
        // Size of array for expansion & branch counting
        int numChildren;
        // Actual content of floor
        FloorContent* content;
};

class NetArchitecture
{
    public:
        NetArchitecture ();
        ~NetArchitecture ();
        // Uses BFS to find and label all floors, maybe print them too
        void print ();
        // Root floor only has 1 child. Lowest breadth only has 1 floor (Use BFS). 1 demon per 6 floors.
        bool testValid ();
    private:
        int numFloors;
        int numBranches;
        // Root floor
        Floor* lobby;
        // List of all floors, where index is value in BFS search. Size is numFloors.
        Floor** floorBFSList;
};

#endif