#include "AStaff.h"

AStaff::AStaff()
{

}

void AStaff::Use()
{
    AWeapon::Use();

    std::cout << "Staff use" << std::endl;
}