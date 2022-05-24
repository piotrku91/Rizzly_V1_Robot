#pragma once

#include <stdint.h>

enum class ServoOrder
{
    FrontLeftJoint1,
    FrontLeftJoint2,
    FrontRightJoint1,
    FrontRightJount2,
    BackLeftJoint1,
    BackLeftJoint2,
    BackRightJoint1,
    BackRightJoint2
};

enum class LegsOrder
{
    FrontLeft
};

enum TypicalAngles
{
    Pos0 = 0,
    Pos45 = 45,
    Pos90 = 90,
    Pos120 = 120
};

