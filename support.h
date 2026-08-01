#pragma once
#include "cars.h"


class support: public car
{
private:
    int crew;
    int reliability;
    void updatePerformanceScore() ;
public:
    support(int no,std::string name,int age,std::string team ,int speed , int capacity,int crew, int reliability);
    support();
    
    void display_info();

    void set_crew_number(int c);
    int get_crew_number();

    void set_reliability_score(int r);
    int get_reliability_score();

    ~support();
};

