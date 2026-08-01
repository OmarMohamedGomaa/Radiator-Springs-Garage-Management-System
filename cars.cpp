#include "cars.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>


std::list<int> car::numbers;

car::car() {}

car::car(int no, std::string n, int a, std::string tname, int s, int c):name(n),team(tname)
{
    // check the uniqueness of the number
    if (std::find(numbers.begin(), numbers.end(), no) != numbers.end())
        throw  std::invalid_argument("invalid number");
    else
    {
        car_no = no;      
        numbers.push_front(no);
    }
    // check that age is a posotive number   
    if (a >= 0)
        age = a;
    else 
        throw  std::invalid_argument("invalid age");
    

    // check that speed is a posotive number
    if (s >= 0)
        speed = s;
    else 
        throw  std::invalid_argument("invalid speed");
    

    // check that capacity is a posotive number
    if (c >= 0)
        capacity = c;
    else 
        throw  std::invalid_argument("invalid capacity");
    
    
}

void car::set_car_type(carType t)
{
    type = t;
}
std::string car::getName() 
{ 
    return name; 
}
void car::setName(const std::string& n)
{
    name = n;
}

void car::setCarNo(int no) 
{
    // check the uniqueness of the number
    if (std::find(numbers.begin(), numbers.end(), no) != numbers.end())
        throw  std::invalid_argument("invalid number");
    else
    {
        car_no = no;      
        numbers.push_front(no);
    }
}
int car::getCarNo() 
{ 
    return car_no; 
}

void car::setAge(int a) 
{
    // check that age is a posotive number   
    if (a >= 0)
        age = a;
    else 
        throw  std::invalid_argument("invalid age");
    updatePerformanceScore();
}
int car::getAge()
{ 
    return age; 
}

carType car::getType() { return type; }

void car::setTeam(const std::string& t) 
{
    team = t;
}
std::string car::getTeam() 
{ 
    return team; 
}

void car::setSpeed(int s) 
{
    // check that speed is a posotive number
    if (s >= 0)
        speed = s;
    else 
        throw  std::invalid_argument("invalid speed");
    updatePerformanceScore();
    
}
int car::getSpeed() 
{ 
    return speed; 
}

void car::setCapacity(int c) 
{
    // check that capacity is a posotive number
    if (c >= 0)
        capacity = c;
    else 
        throw  std::invalid_argument("invalid capacity");
    updatePerformanceScore();
    
}
int car::getCapacity() { return capacity; }

void car::updatePerformanceScore() 
{
    // will be implemented in the subclasses
    performance_score = 0;
}

void car::setPerformanceScore(int s) 
{ 
    performance_score = s; 
}
int car::getPerformanceScore() 
{ 
    return performance_score; 
}
void car::display_info()
{
    std::cout<<"Car Number: "<<getCarNo()<<std::endl;
    std::cout<<"Car Name: "<<getName()<<std::endl;
    std::cout<<"Car Age: "<<getAge()<<std::endl;
    std::cout<<"Car Team: "<<getTeam()<<std::endl;
    std::cout<<"Car Speed: "<<getSpeed()<<std::endl;
    std::cout<<"Car Capacity: "<<getCapacity()<<std::endl;
    std::cout<<"Car Performance Score: "<<getPerformanceScore()<<std::endl;
}
car::~car() 
{
    // remove the car number from the numbers list
    numbers.remove(car_no);
}

