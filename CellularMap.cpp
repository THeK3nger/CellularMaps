#include <iostream>
#include<stdlib.h>
#include<time.h>

#include "CellularMap.h"

CellularMap::CellularMap(int width, int height, int walls_probability) : 
    height(height), width(width), walls_probability(walls_probability) 
{
    map = new int[height*width];
    randomFill();
}

CellularMap::~CellularMap()
{
    delete map;
}

void CellularMap::randomFill() 
{
    srand (time(NULL));
    for (int row = 0; row < this->height; row++) {
        for (int column = 0; column < this->width; column++)
        {
            // If coordinates lie on the the edge of the map (creates a border).
            // We want border on a map.
            if (column == 0 || row == 0 || (column == width - 1) || (row == height - 1))
            {
                map[getIndex(column, row)] = 1;
            }
            // Else, fill with a wall a random percent of the time
            else
            {
                int mapMiddle = (height / 2);

                // Add an empty line in the center of the map. This leads to better maps.
                // There is no other reason.
                if (row == mapMiddle)
                {
                    map[getIndex(column, row)] = 0;
                }
                else
                {
                    map[getIndex(column, row)] = (rand() % 101 >= walls_probability) ? 0 : 1;
                }
            }
        }
    }
}

void CellularMap::evolveMap()
{
    evolveMap(CellularMap::CM_CONSERVATIVE);
}


void CellularMap::evolveMap(RuleSet rule) {
    // By initializing column in the outer loop, its only created ONCE
    for (int row = 0; row <= height - 1; row++)
    {
        for (int column = 0; column <= width - 1; column++)
        {
            map[getIndex(column, row)] = placeWallLogic(column, row, rule);
        }
    }
}

int CellularMap::placeWallLogic(int x, int y,RuleSet rule)
{
    int numWalls = getAdjacentWalls(x, y, 1, 1);
    int numWalls2 = getAdjacentWalls(x, y, 2, 2);

    if (map[getIndex(x,y)] == 1)
    {
        return (numWalls >= 3) ? 1 : 0;
    }
    else
    {
        if (rule == CellularMap::CM_CONSERVATIVE) {
            if (numWalls >= 5 || numWalls2 <= 2) {
                return 1;
            }
        } else {
            if (numWalls >= 5) {
                return 1;
            }
        }
    }
    return 0;
}

int CellularMap::getAdjacentWalls(int x, int y, int scope_x, int scope_y)
{
    int startX = x - scope_x;
    int startY = y - scope_y;
    int endX = x + scope_x;
    int endY = y + scope_y;

    int wallCounter = 0;

    for (int iY = startY; iY <= endY; iY++) {
        for (int iX = startX; iX <= endX; iX++)
        {
            if (!(iX == x && iY == y))
            {
                if (isWall(iX,iY))
                {
                    wallCounter += 1;
                }
            }
        }
    }
    return wallCounter;
}

bool CellularMap::isOutOfBound(int x, int y)
{
    return (x < 0 || y<0 || x>width - 1 || y > height - 1);
}

bool CellularMap::isWall(int x, int y)
{
    // Out of bound is considered a wall.
    return (isOutOfBound(x, y)) || (map[getIndex(x, y)] == 1);
}
