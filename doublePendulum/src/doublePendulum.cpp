//as seen in https://medium.com/geekculture/simulating-ascii-double-pendulums-in-c-c8a1b948fe8c



#define _USE_MATH_DEFINES                                                               //macro needed for using math constants from cmath

#include <iostream>
#include <windows.h>																    //for console API
#include <cmath>                                                                        //for Pi (M_PI)
#include <vector>                                                                       //for vectors
#include <utility>                                                                      //for pair
#include <thread>



/*
Gobal Variables
*/
int xSize = 100;																		//window x size
int ySize = 100;																		//window y size
short offsetx = 25;																		//pendulum position offset
int offsety = -32;																		//pendulum position offset
float g = 1.0;																			//gravity constant
float dt = 0.3;																			//time step
float damping = 0.995;																	//damping coefficient

//the following variables handle writing characters directly to the console
HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);										//get a handle to the console for standard output
DWORD dwWritten;																		//allocates a fdouble word (4 bytes of storage) (essentially a windows.h unsigned int)
HWND myconsole = GetConsoleWindow();													//a handle to the specific console window generated, which we have named myconsole
HDC dc = GetDC(myconsole);																//retrieves a handle to a device context (DC) for the client area of a specified window

//define a strcut for the pendulum
struct Pendulum
{
    float p1Length = 10;
    float p2Length = 15;
    float p1angle = M_PI / 2;
    float p2angle = M_PI / 2;
    float p1x = p1Length * sin(p1angle);
    float p1y = p1Length * cos(p1angle);
    float p2x = p2Length * sin(p2angle);
    float p2y = p2Length * cos(p2angle);
    float p1v = 0;
    float p2v = 0;
    float p1a = 0;
    float p2a = 0;
    float m1 = 2;
    float m2 = 2;

    //need to define a bresenheim fucntion
};


void update(Pendulum* pendulum)
{
    while (true)
    {
        std::vector<std::pair<int, int>> v;
        std::vector<std::pair<int, int>> v2;
        pendulum->p1x = pendulum->p1Length * sin(pendulum->p1angle);
        pendulum->p1y = pendulum->p1Length * cos(pendulum->p1angle);
        pendulum->p2x = pendulum->p2Length * sin(pendulum->p2angle);
        pendulum->p2y = pendulum->p2Length * cos(pendulum->p2angle);
        v = pendulum->bresenham(0, pendulum->p1x, 0, pendulum -> p1y);
        v2 = pendulum->bresenham2(pendulum->p1x, pendulum->p2x + pendulum->p1x, pendulum->p1y, pendulum->p2y + pendulum->p1y);
        FillConsoleOutputCharacter(hOutput, char(219), 1, {offsetx + xSize / 2,(ySize / 2) + offsety }, &dwWritten);
        pendulum->p1v += pendulum->p1a;
        pendulum->p2v += pendulum->p2a;
        pendulum->p1angle += pendulum->p1v;
        pendulum->p2angle += pendulum->p2v;
        float num1 = -g * (2 * pendulum->m1 + pendulum->m2) * sin(pendulum -> p1angle) - pendulum->m2 * g * sin(pendulum->p1angle - 2 * pendulum->p2angle)
            - 2 * sin(pendulum->p1angle - pendulum -> p2angle) * pendulum->m2 * (pendulum->p2v * pendulum->p2v * pendulum->p2Length + pendulum->p1v * pendulum->p1v * pendulum->p1Length * cos(pendulum->p1angle - pendulum->p2angle));
        float den1 = pendulum->p1Length * (2 * pendulum->m1 + pendulum->m2 - pendulum->m2 * cos(2 * pendulum->p1angle - 2 * pendulum->p2angle));
        float num2 = 2 * sin(pendulum->p1angle - pendulum->p2angle) * (pendulum->p1v * pendulum->p1v * pendulum->p1Length * (pendulum->m1 + pendulum->m2) + g * (pendulum->m1 + pendulum->m2) * cos(pendulum->p1angle) + pendulum->p2v * pendulum->p2v * pendulum->p2Length * pendulum->m2 * cos(pendulum->p1angle - pendulum->p2angle));
        float den2 = pendulum->p2Length * (2 * pendulum->m1 + pendulum->m2 - pendulum->m2 * cos(2 * pendulum->p1angle - 2 * pendulum->p2angle));
        pendulum->p1a = (num1 / den1) * dt;
        pendulum->p2a = (num2 / den2) * dt;
        pendulum->p1v = pendulum->p1v * damping;
        pendulum->p2v = pendulum->p2v * damping;
        Sleep(25);
        for (int i = 0; i < v.size(); i++)
        {
            FillConsoleOutputCharacter(hOutput, ' ', 1, { (xSize / 2) + v[i].first,(ySize / 2) + v[i].second }, &dwWritten);
        }
        for (int i = 0; i < v2.size(); i++)
        {
            FillConsoleOutputCharacter(hOutput, ' ', 1, { (xSize / 2) + v2[i].first,(ySize / 2) + v2[i].second }, &dwWritten);
        }
    }
}

int main()
{
    std::vector<std::thread> tv;
    while (true)
    {
        if (kbhit())
        {
            char ch = getch();
            if (ch == 'g') // you can use whatever key you want here.
            {
                Pendulum* temp = new Pendulum();
                tv.emplace_back([&]() {update(temp); });
            }
        }
    }
    for (auto& it : tv)
    {
        it.join();
    }
}