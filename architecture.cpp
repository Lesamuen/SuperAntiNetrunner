#include <string>
#include <iostream>

#include "architecture.h"

// DEFINE BASE FLOOR CONTENT

enum ContentType {NONE, PASSWORD, FILE, CONTROL, BLACKICE};
enum DV {BASIC = 6, STANDARD = 8, UNCOMMON = 10, ADVANCED = 12};

FloorContent::FloorContent ()
{
    contentType = ContentType::NONE;
    cost = 0;
}

FloorContent::~FloorContent ()
{
    // Does Nothing
}

ContentType FloorContent::getContentType ()
{
    return contentType;
}

int FloorContent::getCost ()
{
    return cost;
}

// TBD
void FloorContent::print ()
{
    std::cout << contentType << ": " << cost << "eb" << std::endl;
}

// PASSWORD DEF

Password::Password ()
{
    contentType = ContentType::PASSWORD;
    diffVal = DV::STANDARD;
    cost = 1000;
}

Password::Password (DV diffVal)
{
    contentType = ContentType::PASSWORD;
    this->diffVal = diffVal;
    if (diffVal == 6)
    {
        cost = 500;
    }
    else if (diffVal == 8)
    {
        cost = 1000;
    }
    else if (diffVal == 10)
    {
        cost = 5000;
    }
    else if (diffVal == 12)
    {
        cost = 10000;
    }
}

Password::~Password ()
{
    // Does Nothing
}

int Password::getDV ()
{
    return diffVal;
}

// FILE DEF

File::File ()
{
    contentType = ContentType::FILE;
    diffVal = DV::STANDARD;
    cost = 1000;
    fileDesc = "";
}

File::File (DV diffVal, std::string fileDesc)
{
    contentType = ContentType::FILE;
    this->diffVal = diffVal;
    if (diffVal == 6)
    {
        cost = 500;
    }
    else if (diffVal == 8)
    {
        cost = 1000;
    }
    else if (diffVal == 10)
    {
        cost = 5000;
    }
    else if (diffVal == 12)
    {
        cost = 10000;
    }
    this->fileDesc = fileDesc;
}

File::~File ()
{
    // Does Nothing
}

int File::getDV ()
{
    return diffVal;
}

std::string File::getContent ()
{
    return fileDesc;
}

void File::setContent (std::string fileDesc)
{
    this->fileDesc = fileDesc;
}

// CONTROL NODE DEF

ControlNode::ControlNode ()
{
    contentType = ContentType::CONTROL;
    diffVal = DV::STANDARD;
    cost = 1000;
    defense = nullptr;
}

ControlNode::ControlNode (DV diffVal, Defense* defense)
{
    contentType = ContentType::CONTROL;
    this->diffVal = diffVal;
    if (diffVal == 6)
    {
        cost = 500;
    }
    else if (diffVal == 8)
    {
        cost = 1000;
    }
    else if (diffVal == 10)
    {
        cost = 5000;
    }
    else if (diffVal == 12)
    {
        cost = 10000;
    }
    this->defense = defense;
}

ControlNode::~ControlNode ()
{
    delete defense;
}

int ControlNode::getDV ()
{
    return diffVal;
}

Defense* ControlNode::getDefense ()
{
    return defense;
}

// DEFENSE DEF

enum defenseCategory {ACTIVE, EMPLACED, ENVIRONMENTAL};
enum defenseDV {BASIC = 9, STANDARD = 13, UNCOMMON = 17, ADVANCED = 21};

Defense::Defense ()
{
    diffVal = defenseDV::STANDARD;
    defuseMinutes = 3;
    cost = 1000;
    category = defenseCategory::ACTIVE;
    type = "";
    desc = "";
    trigger = "";
    data = "";
}

Defense::Defense (defenseDV diffVal, int defuseMinutes, defenseCategory category, std::string type, std::string desc, std::string trigger, std::string data)
{
    this->diffVal = diffVal;
    this->defuseMinutes = defuseMinutes;
    this->category = category;
    this->type = type;
    this->desc = desc;
    this->trigger = trigger;
    this->data = data;
    if (diffVal == 9)
    {
        cost = 500;
    }
    else if (diffVal == 13)
    {
        cost = 1000;
    }
    else if (diffVal == 17)
    {
        cost = 5000;
    }
    else if (diffVal == 21)
    {
        cost = 10000;
    }
}

Defense::Defense (Defense* defense)
{
    this->diffVal = defense->diffVal;
    this->defuseMinutes = defense->defuseMinutes;
    this->category = defense->category;
    this->type = defense->type;
    this->desc = defense->desc;
    this->trigger = defense->trigger;
    this->data = defense->data;
    this->cost = defense->cost;
}

Defense::~Defense ()
{
    // Does nothing
}

int Defense::getDV ()
{
    return diffVal;
}

int Defense::getCost ()
{
    return cost;
}

int Defense::getDefuse ()
{
    return defuseMinutes;
}

int Defense::getCategory ()
{
    return category;
}

std::string Defense::getType ()
{
    return type;
}

std::string Defense::getDesc ()
{
    return desc;
}

std::string Defense::getTrigger ()
{
    return trigger;
}

std::string Defense::getData ()
{
    return data;
}

// BLACK ICE DEF

BlackIceGroup::BlackIceGroup ()
{
    contentType = ContentType::BLACKICE;
    group = new BlackIce*[3];
    cost = 0;
    numBI = 0;
}

BlackIceGroup::~BlackIceGroup ()
{
    // Delete all black ice objects, then delete group
    for (int i = 0; i < numBI; i++)
    {
        delete group[i];
    }
    delete[] group;
}

void BlackIceGroup::addBlackIce (BlackIce* blackIce)
{
    // If demon exists, then cannot add
    if (numBI == 1 && group[0]->getType() == 2)
    {
        throw 0;
    }
    // If trying to add demon, cap is 1
    if (blackIce->getType() == 2 && numBI > 0)
    {
        throw 1;
    }
    // If group is full (3), cannot add
    if (numBI == 3)
    {
        throw 2;
    }

    group[numBI] = blackIce;
    numBI++;
}

bool BlackIceGroup::removeBlackIce (std::string name)
{
    bool found = false;
    int i;
    for (i = 0; i < numBI; i++)
    {
        if (group[i]->getName() == name)
        {
            found = true;
            break;
        }
    }

    // If not found, return false
    if (!found)
    {
        return false;
    }
    
    delete group[i];
    group[i] = nullptr;
    numBI--;

    return true;
}

enum BIType {PERSONNEL, PROGRAM, DEMON};

BlackIce::BlackIce ()
{
    name = "";
    icon = "";
    cost = 0;
    type = BIType::PERSONNEL;
    stats = new int[5];
    effect = "";
}

BlackIce::BlackIce (std::string name, std::string icon, int cost, BIType type, int rez, int per, int spd, int atk, int def, std::string effect)
{
    this->name = name;
    this->icon = icon;
    this->cost = cost;
    this->type = type;
    stats = new int[5];
    stats[0] = rez;
    stats[1] = per;
    stats[2] = spd;
    stats[3] = atk;
    stats[4] = def;
    this->effect = effect;
}

BlackIce::BlackIce (BlackIce* blackIce)
{
    name = blackIce->name;
    icon = blackIce->icon;
    cost = blackIce->cost;
    type = blackIce->type;
    stats = new int[5];
    for (int i = 0; i < 5; i++)
    {
        stats[i] = blackIce->stats[i];
    }
    effect = blackIce->effect;
}

BlackIce::~BlackIce ()
{
    delete[] stats;
}

std::string BlackIce::getName ()
{
    return name;
}

std::string BlackIce::getIcon ()
{
    return icon;
}

int BlackIce::getCost ()
{
    return cost;
}

int BlackIce::getType ()
{
    return type;
}

int* BlackIce::getStats ()
{
    return stats;
}

std::string BlackIce::getEffect ()
{
    return effect;
}

Demon::Demon ()
{
    name = "";
    icon = "";
    cost = 0;
    type = BIType::DEMON;
    stats = new int[4];
}

Demon::Demon (std::string name, std::string icon, int cost, int rez, int interface, int netActions, int combatNum)
{
    this->name = name;
    this->icon = icon;
    this->cost = cost;
    type = BIType::DEMON;
    stats = new int[4];
    stats[0] = rez;
    stats[1] = interface;
    stats[2] = netActions;
    stats[3] = combatNum;
}

Demon::Demon (Demon* demon)
{
    name = demon->name;
    icon = demon->icon;
    cost = demon->cost;
    type = BIType::DEMON;
    stats = new int[4];
    for (int i = 0; i < 4; i++)
    {
        stats[i] = demon->stats[i];
    }
}

Demon::~Demon ()
{
    delete[] stats;
}