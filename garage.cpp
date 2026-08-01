#include "garage.h"
#include "racer.h"
#include "support.h"
#include <iostream>
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;
garage::garage()
{
}
void garage::add_car(car *c)
{
    cars.push_back(c);
}
void garage::retire(car *c)
{
    cars.remove(c);
}
void garage::display_cars()
{
    for (auto c : cars)
    {
        c->display_info();
        std::cout<<std::endl;
    }

}
car * garage::find_car(int car_no)
{
    for (auto c : cars)
    {
        if (c->getCarNo() == car_no)    
            return c;
    }
    return nullptr;
}
std::string garage::report()
{
    std::string report = "Garage Report:\n";
    for (auto c : cars)
    {       
        report += "Car Number: " + std::to_string(c->getCarNo()) + "\n";
        report += "Car Name: " + c->getName() + "\n";
        report += "Car Age: " + std::to_string(c->getAge()) + "\n";
        report += "Car Team: " + c->getTeam() + "\n";
        report += "Car Speed: " + std::to_string(c->getSpeed()) + "\n";
        report += "Car Capacity: " + std::to_string(c->getCapacity()) + "\n";
        report += "Car Performance Score: " + std::to_string(c->getPerformanceScore()) + "\n";
        report += "\n";
    }   
    return report;
}
void garage::write_json()
{
    json j;
    for (auto c : cars)
    {
        json car_json;
        car_json["car_no"] = c->getCarNo();
        car_json["name"] = c->getName();
        car_json["age"] = c->getAge();      
        car_json["team"] = c->getTeam();
        car_json["speed"] = c->getSpeed();
        car_json["capacity"] = c->getCapacity();
        car_json["performance_score"] = c->getPerformanceScore();
        carType type = c->getType();
        if (type == carType::Racer)
        {
            car_json["type"] = "Racer";
            car_json["races"] = dynamic_cast<racer*>(c)->get_races();
            car_json["laps"] = dynamic_cast<racer*>(c)->get_laps();
        }
        else if (type == carType::Support)
        {
            car_json["type"] = "Support";
            car_json["crew"] = dynamic_cast<support*>(c)->get_crew_number();
            car_json["reliability"] = dynamic_cast<support*>(c)->get_reliability_score();
        } 
        j.push_back(car_json);
    }
    std::ofstream file("garage.json");
    file << j.dump(4);
    file.close();
}
void garage::read_json()
{
    std::ifstream file("garage.json");
    if (!file.is_open())
    {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    json j;
    file >> j;
    for (const auto& car_json : j)
    {
        int car_no = car_json["car_no"];
        std::string name = car_json["name"];
        int age = car_json["age"];
        std::string team = car_json["team"];
        int speed = car_json["speed"];
        int capacity = car_json["capacity"];
        std::string type = car_json["type"];
        if (type == "Racer")
        {
            int races = car_json["races"] ;
            int laps = car_json["laps"];
            cars.push_back(new racer(car_no,name,age,team,speed,capacity,races,laps));    
        }
        else if (type == "Support")
        {
            int crew = car_json["crew"] ;
            int reliability = car_json["reliability"];
            cars.push_back(new support(car_no,name,age,team,speed,capacity,crew,reliability));    
        }
    }
    file.close(); 
}     
garage::~garage()
{
    for(auto c : cars)
        delete c;
}
