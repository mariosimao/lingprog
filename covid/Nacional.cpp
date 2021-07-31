#include <vector>
#include <string>
#include <ctime>
#include "Nacional.h"
#include "Estadual.h"

using namespace std;

Nacional::Nacional(string name, vector<Estadual> states)
{
    _name = name;
    _states = states;
}

string Nacional::name()
{
    return _name;
}

vector<Estadual> Nacional::states()
{
    return _states;
}


int Nacional::deathsOnDate(time_t date)
{
    int deaths = 0;

    for (auto it = _states.begin(); it != _states.end(); it++)
    {
        deaths += it->deathsOnDate(date);
    }

    return deaths;
}

int Nacional::totalDeathsOnDate(time_t date)
{
    int deaths = 0;

    for (auto it = _states.begin(); it != _states.end(); it++)
    {
        deaths += it->totalDeathsOnDate(date);
    }

    return deaths;
}
