#include <ctime>
#include "Estadual.h"

using namespace std;

Estadual::Estadual(string uf, map<time_t, int> deathsPerDay)
{
    _uf = uf;
    _deathsPerDay = deathsPerDay;
};

string Estadual::uf()
{
    return _uf;
}

int Estadual::deathsOnDate(time_t date)
{
    return _deathsPerDay.find(date)->second ;
}

int Estadual::totalDeathsOnDate(time_t referenceDate)
{
    int totalDeaths = 0;

    for (auto it = _deathsPerDay.begin(); it != _deathsPerDay.end(); it++)
    {
        time_t date = it->first;
        int deaths = it->second;

        if (date <= referenceDate) {
            totalDeaths += deaths;
        }
    }

    return totalDeaths;
}

float Estadual::movingAvarage(time_t date, int numberOfDays)
{
    if (numberOfDays <= 1) {
        throw "Days of moving avarage should be greater than 1.";
    }

    time_t auxDate = date;
    int totalDeaths = 0;

    for (int i = 0; i < numberOfDays; i++)
    {
        totalDeaths += deathsOnDate(auxDate);

        struct tm* tm = localtime(&date);
        tm->tm_mday -= 1;
        auxDate = mktime(tm);
    }

    return totalDeaths / numberOfDays;
}

float Estadual::growRate(time_t date, int numberOfDays)
{
    struct tm* tm = localtime(&date);
    tm->tm_mday -= 1;
    time_t previousDay = mktime(tm);

    float movingAvarageOnDate = movingAvarage(date, numberOfDays);
    float movingAvarageOnPreviousDay = movingAvarage(previousDay, numberOfDays);

    return (movingAvarageOnDate / movingAvarageOnPreviousDay) - 1;
}
