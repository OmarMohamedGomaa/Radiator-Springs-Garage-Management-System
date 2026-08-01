#include "racer.h"
#include <iostream>
#include <stdexcept>
#define CAPACITY_FACTOR 1
#define SPEED_FACTOR 10


racer::racer()
{
}
racer::racer(int no,std::string name,int age,std::string team ,int speed , int capacity,int r , int l):car(no, name, age, team, speed, capacity)
{
    if (l >= 0 )
        laps = l;
    else
        throw std::invalid_argument("cannot have negative laps");

    if (r >= 0 )
        races = r;
    else
        throw std::invalid_argument("cannot have negative races");
    updatePerformanceScore();
    std::cout<<"Car Checked In Successfully!"<<std::endl;
}
void racer::updatePerformanceScore() 
{
    int score = (getSpeed() * SPEED_FACTOR) + (getCapacity() * CAPACITY_FACTOR);
    setPerformanceScore(score);
}
void racer::set_races(int r)
{
    if (r >= 0 )
        races = r;
    else    
        throw std::invalid_argument("cannot have negative races");
}
int racer::get_races()
{
    return races;   
}
void racer::set_laps(int l)
{
    if (l >= 0 )
        laps = l;
    else    
        throw std::invalid_argument("cannot have negative laps");
}
int racer::get_laps()
{
    return laps;
}
void racer::display_info ()
{
    std::cout<<"Car Type: Racer"<<std::endl;
    std::cout<<"Car Number: "<<getCarNo()<<std::endl;
    std::cout<<"Car Name: "<<getName()<<std::endl;
    std::cout<<"Car Age: "<<getAge()<<std::endl;
    std::cout<<"Car Team: "<<getTeam()<<std::endl;
    std::cout<<"Car Speed: "<<getSpeed()<<std::endl;
    std::cout<<"Car Capacity: "<<getCapacity()<<std::endl;
    std::cout<<"Car Performance Score: "<<getPerformanceScore()<<std::endl;

}
racer::~racer()
{
    car::numbers.remove(getCarNo());
}
