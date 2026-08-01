#include "program.h"

int main()
{
    garage Garage;
    Garage.read_json();
    main_menu(&Garage);
    return 0;
}