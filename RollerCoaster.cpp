//
//  RollerCoaster.cpp
//  RollerCoaster
//
//  Created by Dylan Sussman on 10/2/19.
//  Copyright © 2019 Dylan Sussman. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include "Person.cpp"
#include <array>
using namespace std;

class RollerCoaster
{
private:
    queue<Person> fastPass;
    queue<Person> normalLine;
public:
    RollerCoaster(array<Person, 500> line);
    int estimateNormalWaitTime();
    int fastPassWaitTime();
    bool addPersonToLine(Person p);
    void removePersonFromLine(Person p);
    void shrinkAndEliminate();
};

RollerCoaster::RollerCoaster(array<Person, 500> line)
{
    for(Person p:line)
    {
        if(p.getFastPass())
        {
            fastPass.push(p);
        }
        else
        {
            normalLine.push(p);
        }
    }
};

int RollerCoaster::estimateNormalWaitTime()
{
    int waitTime = 0;
    //Runs thru normalLine queue and adds 1 minute to waitTime for each Person in normalLine
    for(int i = 0; i < normalLine.size(); i++)
    {
        waitTime++;
    }
    waitTime += fastPassWaitTime(); //Adds fastPassWaitTime to waitTime to get total wait time
    return waitTime;
};

int RollerCoaster::fastPassWaitTime()
{
    int waitTime = 0;
    //Runs thru fastPass queue and adds 0.5 minutes for each Person in fastPass line
    for(int i = 0; i < fastPass.size(); i++)
    {
        waitTime += 0.5;
    }
    return waitTime;
};

bool RollerCoaster::addPersonToLine(Person p)
{
    //If the Person is shorter than 42.0 inches they aren't added to the line
    if(p.getHeight() < 42.0)
    {
        cout << "Get out of here you short fool!";
        return false;
    }
    //If the Person has a fast pass they're added to the fastPass queue
    if(p.getFastPass())
    {
        fastPass.push(p);
        return true;
    }
    //If the Person doesn't have a fast pass they're added to the normalLine queue
    else
    {
        normalLine.push(p);
        return true;
    }
};

void RollerCoaster::removePersonFromLine(Person p)
{
    //If the person is in the fastPass queue they're removed from it
    if(p.getFastPass())
    {
        fastPass.pop();
    }
    //If the person is in the normalLine queue they're removed from it
    else
    {
        normalLine.pop();
    }
};

void RollerCoaster::shrinkAndEliminate()
{
    
};
