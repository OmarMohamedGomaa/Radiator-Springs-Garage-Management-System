#pragma once
#include "cars.h"

class garage
{
private:
    std::list<car*> cars;
public:
    garage();
    void add_car(car *c);
    void retire(car *c);
    void display_cars();
    car * find_car(int car_no);
    std::string report();
    void write_json();
    void read_json();
    ~garage();
};

