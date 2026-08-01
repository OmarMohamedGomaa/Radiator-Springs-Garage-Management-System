#pragma once
#include "cars.h"

class racer : public car
{
private:
    int races;
    int laps;

    void updatePerformanceScore() ;
public:
    racer(int no,std::string name,int age,std::string team ,int speed , int capacity,int races ,int laps);
    racer();
    void set_races(int r);
    int get_races();
    void set_laps(int l);
    int get_laps();
    void display_info();
    ~racer();
};
