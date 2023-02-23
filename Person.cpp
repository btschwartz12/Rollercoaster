//
//  Person.cpp
//  RollerCoaster
//
//  Created by Dylan Sussman on 10/2/19.
//  Copyright © 2019 Dylan Sussman. All rights reserved.
//

#include <stdio.h>

class Person
{
private:
    double height;
    bool fastPass;
public:
    //Contructor which takes a height parameter and a fast pass parameter
    Person(double h, bool f)
    {
        height = h;
        fastPass = f;
    }
    double getHeight()
    {
        return height;
    }
    bool getFastPass()
    {
        return fastPass;
    }
};
