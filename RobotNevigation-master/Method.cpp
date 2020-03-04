#include <iostream>
#include <math.h>
#include "Method.h"

using namespace std;

Method::Method()
{
    row = 0;
    column = 0;
    cost = 0;
    node = 0;
    euclideanDis = 100000000000.0;
    manhattanDis = 100000000000.0;
}

Method::~Method()
{

}

void Method::askForFile()
{
    cout << "Please input the filename here: " << endl;
    cin >> fileName;
}

//Euclidean distance from N to the goal (Strategy 1)
void Method::moveEuclidean()
{
    cost = 0;
    node = 0;
    askForFile();
    file f(fileName);
    f.getFile();

    row = f.getFileRow();
    column = f.getFileColumn();

    Grid g(row, column);
    g.opGrid(fileName);

    cout << "Euclidean distance from N to the goal (Strategy 1)" << endl;
    
    //while initial stage != final stage
    while (g.init_x != g.final_x || g.init_y != g.final_y)
    {
        double temp_dis = 0.0;
        int position = -1;
        euclideanDis = 100000000000.0;
        //check four firections
        //0:UP, 1:down, 2:LEFT, 3:RIGHT

        if (g.init_x - 1 > -1 && (g.myGrid[g.init_x - 1][g.init_y] == '.' || g.myGrid[g.init_x - 1][g.init_y] == 'g'))
        {
            cout << "You can go up" << endl;
            node++;
            temp_dis = getEuclideanDistance(g.init_x - 1, g.init_y, g.final_x, g.final_y);
            if(temp_dis <= euclideanDis)
            {
                euclideanDis = temp_dis;
                position = 0;
            }
        }
        if (g.init_x + 1 < row && (g.myGrid[g.init_x + 1][g.init_y] == '.' || g.myGrid[g.init_x + 1][g.init_y] == 'g'))
        {
            cout << "You can go down" << endl;
            node++;
            temp_dis = getEuclideanDistance(g.init_x + 1, g.init_y, g.final_x, g.final_y);
            if (temp_dis <= euclideanDis)
            {
                euclideanDis = temp_dis;
                position = 1;
            }
        }
        if (g.init_y - 1 > -1 && (g.myGrid[g.init_x][g.init_y - 1] == '.' || g.myGrid[g.init_x][g.init_y - 1] == 'g'))
        {
            cout << "You can go left" << endl;
            node++;
            temp_dis = getEuclideanDistance(g.init_x, g.init_y - 1, g.final_x, g.final_y);
            if (temp_dis <= euclideanDis)
            {
                euclideanDis = temp_dis;
                position = 2;
            }
        }
        if (g.init_y + 1 < row && (g.myGrid[g.init_x][g.init_y + 1] == '.' || g.myGrid[g.init_x][g.init_y + 1] == 'g'))
        {
            cout << "You can go right" << endl;
            node++;
            temp_dis = getEuclideanDistance(g.init_x, g.init_y + 1, g.final_x, g.final_y);
            if (temp_dis <= euclideanDis)
            {
                euclideanDis = temp_dis;
                position = 3;
            }
        }
        
        if (position == 0)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x - 1][g.init_y] = 'i';
            g.init_x = g.init_x - 1;
        }
        else if (position == 1)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x + 1][g.init_y] = 'i';
            g.init_x = g.init_x + 1;
        }
        else if (position == 2)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x][g.init_y - 1] = 'i';
            g.init_y = g.init_y - 1;
        }
        else if (position == 3)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x][g.init_y + 1] = 'i';
            g.init_y = g.init_y + 1;
        }

        g.printGrid();
        cost++;
        cout << "Cost: " << cost << endl;
        cout << "Node: " << node << endl;
    }
}

//Manhattan distance to the goal (Strategy 2)
void Method::moveManhattan()
{
    cost = 0;
    node = 0;
    askForFile();
    file f(fileName);
    f.getFile();

    row = f.getFileRow();
    column = f.getFileColumn();

    Grid g(row, column);
    g.opGrid(fileName);

    cout << "Manhattan distance to the goal (Strategy 2)" << endl;

    //while initial stage != final stage
    while (g.init_x != g.final_x || g.init_y != g.final_y)
    {
        double temp_dis = 0.0;
        int position = -1;
        manhattanDis = 100000000000.0;
        //check four firections
        //0:UP, 1:down, 2:LEFT, 3:RIGHT

        if (g.init_x - 1 > -1 && (g.myGrid[g.init_x - 1][g.init_y] == '.' || g.myGrid[g.init_x - 1][g.init_y] == 'g'))
        {
            cout << "You can go up" << endl;
            node++;
            temp_dis = getManhattanDistance(g.init_x - 1, g.init_y, g.final_x, g.final_y);
            if (temp_dis <= manhattanDis)
            {
                manhattanDis = temp_dis;
                position = 0;
            }
        }
        if (g.init_x + 1 < row && (g.myGrid[g.init_x + 1][g.init_y] == '.' || g.myGrid[g.init_x + 1][g.init_y] == 'g'))
        {
            cout << "You can go down" << endl;
            node++;
            temp_dis = getManhattanDistance(g.init_x + 1, g.init_y, g.final_x, g.final_y);
            if (temp_dis <= manhattanDis)
            {
                manhattanDis = temp_dis;
                position = 1;
            }
        }
        if (g.init_y - 1 > -1 && (g.myGrid[g.init_x][g.init_y - 1] == '.' || g.myGrid[g.init_x][g.init_y - 1] == 'g'))
        {
            cout << "You can go left" << endl;
            node++;
            temp_dis = getManhattanDistance(g.init_x, g.init_y - 1, g.final_x, g.final_y);
            if (temp_dis <= manhattanDis)
            {
                manhattanDis = temp_dis;
                position = 2;
            }
        }
        if (g.init_y + 1 < row && (g.myGrid[g.init_x][g.init_y + 1] == '.' || g.myGrid[g.init_x][g.init_y + 1] == 'g'))
        {
            cout << "You can go right" << endl;
            node++;
            temp_dis = getManhattanDistance(g.init_x, g.init_y + 1, g.final_x, g.final_y);
            if (temp_dis <= manhattanDis)
            {
                manhattanDis = temp_dis;
                position = 3;
            }
        }

        if (position == 0)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x - 1][g.init_y] = 'i';
            g.init_x = g.init_x - 1;
        }
        else if (position == 1)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x + 1][g.init_y] = 'i';
            g.init_x = g.init_x + 1;
        }
        else if (position == 2)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x][g.init_y - 1] = 'i';
            g.init_y = g.init_y - 1;
        }
        else if (position == 3)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x][g.init_y + 1] = 'i';
            g.init_y = g.init_y + 1;
        }

        g.printGrid();
        cost++;
        cout << "Cost: " << cost << endl;
        cout << "Node: " << node << endl;
    }
}

//A* (Strategy 3)
void Method::moveAstarEuclidean()
{
    cost = 0;
    node = 0;
    askForFile();
    file f(fileName);
    f.getFile();

    row = f.getFileRow();
    column = f.getFileColumn();

    Grid g(row, column);
    g.opGrid(fileName);

    cout << "A* (Strategy 3)" << endl;

    //while initial stage != final stage
    while (g.init_x != g.final_x || g.init_y != g.final_y)
    {
        double temp_dis = 0.0;
        int position = -1;
        euclideanDis = 100000000000.0;
        //check four firections
        //0:UP, 1:down, 2:LEFT, 3:RIGHT

        if (g.init_x - 1 > -1 && (g.myGrid[g.init_x - 1][g.init_y] == '.' || g.myGrid[g.init_x - 1][g.init_y] == 'g'))
        {
            cout << "You can go up" << endl;
            node++;
            temp_dis = getEuclideanDistance(g.init_x - 1, g.init_y, g.final_x, g.final_y) + cost;
            if (temp_dis <= euclideanDis)
            {
                euclideanDis = temp_dis;
                position = 0;
            }
        }
        if (g.init_x + 1 < row && (g.myGrid[g.init_x + 1][g.init_y] == '.' || g.myGrid[g.init_x + 1][g.init_y] == 'g'))
        {
            cout << "You can go down" << endl;
            node++;
            temp_dis = getEuclideanDistance(g.init_x + 1, g.init_y, g.final_x, g.final_y) + cost;
            if (temp_dis <= euclideanDis)
            {
                euclideanDis = temp_dis;
                position = 1;
            }
        }
        if (g.init_y - 1 > -1 && (g.myGrid[g.init_x][g.init_y - 1] == '.' || g.myGrid[g.init_x][g.init_y - 1] == 'g'))
        {
            cout << "You can go left" << endl;
            node++;
            temp_dis = getEuclideanDistance(g.init_x, g.init_y - 1, g.final_x, g.final_y) + cost;
            if (temp_dis <= euclideanDis)
            {
                euclideanDis = temp_dis;
                position = 2;
            }
        }
        if (g.init_y + 1 < row && (g.myGrid[g.init_x][g.init_y + 1] == '.' || g.myGrid[g.init_x][g.init_y + 1] == 'g'))
        {
            cout << "You can go right" << endl;
            node++;
            temp_dis = getEuclideanDistance(g.init_x, g.init_y + 1, g.final_x, g.final_y) + cost;
            if (temp_dis <= euclideanDis)
            {
                euclideanDis = temp_dis;
                position = 3;
            }
        }

        if (position == 0)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x - 1][g.init_y] = 'i';
            g.init_x = g.init_x - 1;
        }
        else if (position == 1)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x + 1][g.init_y] = 'i';
            g.init_x = g.init_x + 1;
        }
        else if (position == 2)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x][g.init_y - 1] = 'i';
            g.init_y = g.init_y - 1;
        }
        else if (position == 3)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x][g.init_y + 1] = 'i';
            g.init_y = g.init_y + 1;
        }

        g.printGrid();
        cost++;
        cout << "Cost: " << cost << endl;
        cout << "Node: " << node << endl;
    }
}

//A* (Strategy 4)
void Method::moveAstarManhattan()
{
    cost = 0;
    node = 0;
    askForFile();
    file f(fileName);
    f.getFile();

    row = f.getFileRow();
    column = f.getFileColumn();

    Grid g(row, column);
    g.opGrid(fileName);

    cout << "A* (Strategy 4)" << endl;

    //while initial stage != final stage
    while (g.init_x != g.final_x || g.init_y != g.final_y)
    {
        double temp_dis = 0.0;
        int position = -1;
        manhattanDis = 100000000000.0;
        //check four firections
        //0:UP, 1:down, 2:LEFT, 3:RIGHT

        if (g.init_x - 1 > -1 && (g.myGrid[g.init_x - 1][g.init_y] == '.' || g.myGrid[g.init_x - 1][g.init_y] == 'g'))
        {
            cout << "You can go up" << endl;
            node++;
            temp_dis = getManhattanDistance(g.init_x - 1, g.init_y, g.final_x, g.final_y) + cost;
            if (temp_dis <= manhattanDis)
            {
                manhattanDis = temp_dis;
                position = 0;
            }
        }
        if (g.init_x + 1 < row && (g.myGrid[g.init_x + 1][g.init_y] == '.' || g.myGrid[g.init_x + 1][g.init_y] == 'g'))
        {
            cout << "You can go down" << endl;
            node++;
            temp_dis = getManhattanDistance(g.init_x + 1, g.init_y, g.final_x, g.final_y) + cost;
            if (temp_dis <= manhattanDis)
            {
                manhattanDis = temp_dis;
                position = 1;
            }
        }
        if (g.init_y - 1 > -1 && (g.myGrid[g.init_x][g.init_y - 1] == '.' || g.myGrid[g.init_x][g.init_y - 1] == 'g'))
        {
            cout << "You can go left" << endl;
            node++;
            temp_dis = getManhattanDistance(g.init_x, g.init_y - 1, g.final_x, g.final_y) + cost;
            if (temp_dis <= manhattanDis)
            {
                manhattanDis = temp_dis;
                position = 2;
            }
        }
        if (g.init_y + 1 < row && (g.myGrid[g.init_x][g.init_y + 1] == '.' || g.myGrid[g.init_x][g.init_y + 1] == 'g'))
        {
            cout << "You can go right" << endl;
            node++;
            temp_dis = getManhattanDistance(g.init_x, g.init_y + 1, g.final_x, g.final_y) + cost;
            if (temp_dis <= manhattanDis)
            {
                manhattanDis = temp_dis;
                position = 3;
            }
        }

        if (position == 0)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x - 1][g.init_y] = 'i';
            g.init_x = g.init_x - 1;
        }
        else if (position == 1)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x + 1][g.init_y] = 'i';
            g.init_x = g.init_x + 1;
        }
        else if (position == 2)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x][g.init_y - 1] = 'i';
            g.init_y = g.init_y - 1;
        }
        else if (position == 3)
        {
            g.myGrid[g.init_x][g.init_y] = 'O';
            g.myGrid[g.init_x][g.init_y + 1] = 'i';
            g.init_y = g.init_y + 1;
        }

        g.printGrid();
        cost++;
        cout << "Cost: " << cost << endl;
        cout << "Node: " << node << endl;
    }
}

double Method::getEuclideanDistance(int init_x, int init_y, int final_x, int final_y)
{
    return sqrt((init_x - final_x) * (init_x - final_x) + (init_y - final_y) * (init_y - final_y));
}

double Method::getManhattanDistance(int init_x, int init_y, int final_x, int final_y)
{
    return (abs(init_x - final_x) + abs(init_y - final_y));
}