#include "support.h"
#include <stdexcept>
#include <iostream>
#define CAPACITY_FACTOR 5
#define SPEED_FACTOR 5
support::support()
{
    
}
support::support(int no,std::string name,int age,std::string team ,int speed , int capacity,int c , int r):car(no, name, age, team, speed, capacity)
{
    if (c >= 0 )
        crew = c;
    else
        throw std::invalid_argument("cannot have negative crew members");
    if (r >= 0 )
        reliability = r;
    else
        throw std::invalid_argument("cannot have negative reliability score");
    set_car_type(carType::Support);
    updatePerformanceScore();
    std::cout<<"Car Checked In Successfully!"<<std::endl;
}

void support::set_crew_number(int c)
{
    if (c >= 0 )
        crew = c;
    else
        throw std::invalid_argument("cannot have negative crew members");
}
int support::get_crew_number()
{
    return crew;
}

void support::set_reliability_score(int r)
{
    if (r >= 0 )
        reliability = r;
    else
        throw std::invalid_argument("cannot have negative reliability score");
}
int support::get_reliability_score()
{
    return reliability;
}
void support::updatePerformanceScore() 
{
    int score = (getSpeed() * SPEED_FACTOR) + (getCapacity() * CAPACITY_FACTOR);
    setPerformanceScore(score);
}
void support::display_info()
{
    std::cout<<"Car Type: Support"<<std::endl;
    std::cout<<"Car Number: "<<getCarNo()<<std::endl;
    std::cout<<"Car Name: "<<getName()<<std::endl;
    std::cout<<"Car Age: "<<getAge()<<std::endl;
    std::cout<<"Car Team: "<<getTeam()<<std::endl;
    std::cout<<"Car Speed: "<<getSpeed()<<std::endl;
    std::cout<<"Car Capacity: "<<getCapacity()<<std::endl;
    std::cout<<"Car Performance Score: "<<getPerformanceScore()<<std::endl;
    std::cout<<"Crew members: "<<get_crew_number()<<std::endl;
    std::cout<<"Reliabilty score: "<<get_reliability_score()<<std::endl;
}

support::~support()
{
    car::numbers.remove(getCarNo());
}
