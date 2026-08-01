#include "cars.h"
#include "support.h"
#include "racer.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "program.h"

using namespace std;



int main_menu(garage *Garage)
{
    int choice;
    cout<<"======================="<<endl;
    cout<<"||     Main Menu     ||"<<endl;
    cout<<"======================="<<endl;
    cout<<"|1. Check in Car |"<<endl;
    cout<<"|2. Retire Car   |"<<endl;
    cout<<"|3. Display Cars |"<<endl;
    cout<<"|4. Tune up      |"<<endl;
    cout<<"|5. Report       |"<<endl;
    cout<<"|6. Exit         |"<<endl;
    cout<<"enter your choice : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        add_car(Garage);
        break;
    case 2:
        retire_car(Garage);
        break;
    case 3:
        display_cars(Garage);
        break;
    case 4:
        tune_up(Garage);
        break;
    case 5:
        report(Garage);
        break;
    case 6:
        cout<<"Exiting..."<<endl;
        return 0;
        break;
    default:
        cout<<"Invalid choice!"<<endl;
        main_menu(Garage);
        break;
    }
    update_json(Garage);
    return main_menu(Garage);
    
}
void add_car(garage *Garage)
{
    try{
        carType type;
        int car_no, age, speed, capacity;
        string name, team;
        cout<<"Enter Car Type (0 for Racer, 1 for Support): ";
        int type_input;
        cin>>type_input;
        if (type_input == 0)
            type = carType::Racer;
        else if (type_input == 1)
            type = carType::Support;
        else            
        {
            cout<<"Invalid Car Type!"<<endl;
            return;
        }
        cout<<"Enter Car Number: ";
        cin>>car_no;
        cout<<"Enter Car Name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Car Age: ";
        cin>>age;
        cout<<"Enter Car Team: ";
        cin.ignore();
        getline(cin,team);
        cout<<"Enter Car Speed: ";
        cin>>speed;
        cout<<"Enter Car Capacity: ";   
        cin>>capacity;
        if (type == carType::Racer)
        {
            cout<<"Enter Number of Races: ";
            int races ;
            cin>>races;
            cout<<"Enter Number of Laps: ";
            int laps ;
            cin>>laps;
            racer *new_r = new racer(car_no, name, age, team, speed, capacity, races, laps);
            new_r->set_car_type(type);
            Garage->add_car(new_r);
        }
        else if (type == carType::Support)
        {
            cout<<"Enter Number of Crew Members: ";
            int crew ;
            cin>>crew;
            cout<<"Enter Reliability Score: ";  
            int reliability ;
            cin>>reliability;
            support *new_s = new support(car_no, name, age, team, speed, capacity, crew, reliability);
            new_s->set_car_type(type);
            Garage->add_car(new_s);
        }
    }
    catch(const invalid_argument& e)
    {
        
        cout << "Error: " << e.what() << ". Car not added.\n";
        main_menu(Garage);
    }
}
void retire_car(garage *Garage)
{
    int car_no;
    cout<<"Enter Car Number to Retire: ";
    cin>>car_no;
    car *c = Garage->find_car(car_no);
    if (c != nullptr)
    {
        c->display_info();
        cout<<"are you sure you want to retire this car? (y/n): ";
        char choice;
        cin>>choice;
        if (choice == 'y' || choice == 'Y')
        {
            Garage->retire(c);
            if(c->getType() == carType::Racer)
            {    
                racer * r  =  dynamic_cast<racer*>(c) ;
                delete r;
            }
            else if(c->getType() == carType::Support)
            {
                support * s = dynamic_cast<support*>(c) ;
                delete s;
            }    
            cout<<"Car Retired Successfully!"<<endl;
        }
        else
            cout<<"Car Not Retired!"<<endl;
    }
    else
        cout<<"Car Not Found!"<<endl;
}
void display_cars(garage *Garage)
{
    Garage->display_cars();
}
void report(garage *Garage)   
{
    cout<<Garage->report()<<endl;
}
void tune_up(garage *Garage)
{   try
    {
        int car_no;
        cout<<"Enter Car Number to Tune Up: ";
        cin>>car_no;
        car *c = Garage->find_car(car_no);
        if (c != nullptr)
        {
            c->display_info();
            cout<<"Enter New Speed: ";
            int new_speed ;
            cin>>new_speed;
            cout<<"Enter New Capacity: ";
            int new_capacity ;
            cin>>new_capacity;
            c->setSpeed(new_speed);
            c->setCapacity(new_capacity);
            c->updatePerformanceScore();   
            cout<<"Car Tuned Up Successfully!"<<endl;
        }
        else
            cout<<"Car Not Found!"<<endl;
    }
    catch(const invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        main_menu(Garage);
    }
}
void update_json(garage *Garage)
{
    Garage->write_json();
}