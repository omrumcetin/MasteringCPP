#pragma once
#include "AWeapon.h"

class AStaff :  public AWeapon
{
public:
    AStaff();

    virtual void Use() override;

};

