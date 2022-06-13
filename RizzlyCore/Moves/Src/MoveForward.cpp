/*
 * MoveForward.cpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#include "MoveForward.hpp"
#include "defines.hpp"

MoveForward::MoveForward() {
    setStepsCount(4);
}

void MoveForward::run(LegsVector& Legs) {
    if (!isAnyStep()) {
        return;
    };

    switch (current_step_) {
    case 0: {
        Legs[LegsOrder::FrontLeft]->setLevelAngleWithAcceleration(TypicalAngles::Pos120, 5);
        HAL_Delay(20);

        if (Legs[LegsOrder::FrontLeft]->getLevelMoveStatus() == MoveStatus::Finished) {setNextStep(); Legs[LegsOrder::FrontLeft]->resetMoveStatus(); HAL_Delay(100);};
        break;
    }

    case 1: {
        Legs[LegsOrder::FrontLeft]->setRotationAngleWithAcceleration(TypicalAngles::Pos120, 5);
        HAL_Delay(20);

        if (Legs[LegsOrder::FrontLeft]->getRotationMoveStatus() == MoveStatus::Finished) {setNextStep(); Legs[LegsOrder::FrontLeft]->resetMoveStatus(); HAL_Delay(100);} ;
        break;
    }
    case 2: {
        Legs[LegsOrder::FrontLeft]->setLevelAngleWithAcceleration(TypicalAngles::Pos0, 5);
        HAL_Delay(20);

        if (Legs[LegsOrder::FrontLeft]->getLevelMoveStatus() == MoveStatus::Finished) {setNextStep(); Legs[LegsOrder::FrontLeft]->resetMoveStatus(); HAL_Delay(100);};
        break;
    }
      case 3: {
        Legs[LegsOrder::FrontLeft]->setRotationAngleWithAcceleration(TypicalAngles::Pos0, 5);
        HAL_Delay(20);

        if (Legs[LegsOrder::FrontLeft]->getRotationMoveStatus() == MoveStatus::Finished) {setNextStep(); Legs[LegsOrder::FrontLeft]->resetMoveStatus(); HAL_Delay(100);};
        break;
    }
    default: {
        setStepZero();
        break;
    }
    };
    
}
