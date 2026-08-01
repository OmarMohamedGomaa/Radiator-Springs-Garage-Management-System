#include "cars.h"
#include "support.h"
#include "racer.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "program.h"

using namespace std;

int read_positive_int(const string &prompt)
{
    while (true)
    {
        cout << prompt;
        string text;
        if (!getline(cin, text))
        {
            cin.clear();
            continue;
        }

        try
        {
            int value = stoi(text);
            if (value <= 0)
                throw invalid_argument("Value must be a positive integer");
            return value;
        }
        catch (const exception &)
        {
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
    }
}

int read_menu_choice()
{
    while (true)
    {
        int value = read_positive_int("enter your choice : ");
        if (value >= 1 && value <= 6)
            return value;
        cout << "Invalid choice. Enter a number between 1 and 6." << endl;
    }
}

int read_non_negative_int(const string &prompt)
{
    while (true)
    {
        cout << prompt;
        string text;
        if (!getline(cin, text))
        {
            cin.clear();
            continue;
        }

        try
        {
            int value = stoi(text);
            if (value < 0)
                throw invalid_argument("Value must be zero or a positive integer");
            return value;
        }
        catch (const exception &)
        {
            cout << "Invalid input. Please enter a non-negative integer." << endl;
        }
    }
}

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
    choice = read_menu_choice();
    
    try
    {
    switch (choice)
    {
    case 1:
        add_car(Garage);
        return main_menu(Garage);
        break;
    case 2:
        retire_car(Garage);
        return main_menu(Garage);
        break;
    case 3:
        display_cars(Garage);
        return main_menu(Garage);
        break;
    case 4:
        tune_up(Garage);
        return main_menu(Garage);
        break;
    case 5:
        report(Garage);
        return main_menu(Garage);
        break;
    case 6:
        cout<<"Exiting..."<<endl;
        return 0;
        break;
    default:
        cout<<"Invalid choice!"<<endl;
        break;
    }
    }
    catch(const invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        main_menu(Garage);
    }
    update_json(Garage);
    return 0;
    
}
void add_car(garage *Garage)
{
    try{
        carType type;
        int car_no, age, speed, capacity;
        string name, team;
        cout<<"Enter Car Type (0 for Racer, 1 for Support): ";
        int type_input = read_non_negative_int("");
        if (type_input == 0)
            type = carType::Racer;
        else if (type_input == 1)
            type = carType::Support;
        else            
        {
            cout<<"Invalid Car Type!"<<endl;
            return;
        }
        car_no = read_positive_int("Enter Car Number: ");
        cout<<"Enter Car Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,name);
        age = read_positive_int("Enter Car Age: ");
        cout<<"Enter Car Team: ";
        getline(cin,team);
        speed = read_positive_int("Enter Car Speed: ");
        capacity = read_positive_int("Enter Car Capacity: ");
        if (type == carType::Racer)
        {
            int races = read_positive_int("Enter Number of Races: ");
            int laps = read_positive_int("Enter Number of Laps: ");
            racer *new_r = new racer(car_no, name, age, team, speed, capacity, races, laps);
            new_r->set_car_type(type);
            Garage->add_car(new_r);
        }
        else if (type == carType::Support)
        {
            int crew = read_positive_int("Enter Number of Crew Members: ");
            int reliability = read_positive_int("Enter Reliability Score: ");
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
    int car_no = read_positive_int("Enter Car Number to Retire: ");
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
        int car_no = read_positive_int("Enter Car Number to Tune Up: ");
        car *c = Garage->find_car(car_no);
        if (c != nullptr)
        {
            c->display_info();
            int new_speed = read_positive_int("Enter New Speed: ");
            int new_capacity = read_positive_int("Enter New Capacity: ");
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