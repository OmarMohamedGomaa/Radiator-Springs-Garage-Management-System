#pragma once
#include <string>
#include <list>

enum class carType {
    Racer ,
    Support
};


class car
{
/*
attributes : 
    ● Car Number
    ● Full Name
    ● Age (in racing seasons)
    ● Type (Racer or Support Vehicle)
    ● Racing Team
    ● Speed
    ● Capacity
*/
private:
    std::string name;
    int car_no ;
    int age;
    carType type;
    std::string team;
    int speed;
    int capacity;
    int performance_score; /*Performance Score is not entered by the user. It must be
                            calculated automatically based on the car's Speed and Capacity,
                            using a different formula for each subclass*/
    
    
public:

    car();
    car(int no,std::string name,int age,std::string team ,int speed , int capacity);    

    static std::list<int> numbers;
    void setName(const std::string& n) ;
    std::string getName() ;

    void setCarNo(int no) ;
    int getCarNo() ;

    void setAge(int a) ;
    int getAge() ;

    carType getType() ;
    void set_car_type(carType);

    void setTeam(const std::string& t) ;
    std::string getTeam() ;

    void setSpeed(int s) ;
    int getSpeed()  ;

    void setCapacity(int c) ;
    int getCapacity()  ;

    int getPerformanceScore() ;
    virtual void updatePerformanceScore() ;
    void setPerformanceScore(int s) ;

    virtual void display_info();
    virtual ~car();
};