/*
 * rizzlyapp.cpp
 *
 *  Created on: May 24, 2022
 *      Author: piotr
 */

#include <RizzlyApp.hpp>
#include <vector>
#include "Leg.hpp"
#include "ServoDriver.hpp"

/* Global object declarations */
using ServosVector = std::map<ServoOrder, ServoDriverPtr>;
using LegsVector = std::map<LegsOrder, std::shared_ptr<Leg>>;

ServosVector Servos;
LegsVector Legs;

inline void InitServos() {
    Servos[ServoOrder::FrontLeftJoint1] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_1, 0, 120, 800, 1800, true);
    Servos[ServoOrder::FrontLeftJoint2] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_2, 0, 120, 800, 1800, true);
}

inline void InitLegs() {
    Legs[LegsOrder::FrontLeft] = std::make_shared<Leg>(Servos[ServoOrder::FrontLeftJoint1], Servos[ServoOrder::FrontLeftJoint2]);
}

/* Object creates and inits */
void RizzlyAppInit() {
    InitServos();
    InitLegs();
}

void RizzlyAppMainLoop() {
    uint32_t i = 120;
    while (true) {
        
        Legs[LegsOrder::FrontLeft]->setLevelAngleWithAcceleration(i, 5);
        HAL_Delay(10);

        if (Legs[LegsOrder::FrontLeft]->getLevelMoveStatus() == MoveStatus::Finished) {
            Legs[LegsOrder::FrontLeft]->setRotationAngleWithAcceleration(i, 10);
            HAL_Delay(10);
        };

         if (Legs[LegsOrder::FrontLeft]->finished()) {
             if (i == 120) { i = 0;} else {i = 120;};
            Legs[LegsOrder::FrontLeft]->resetMoveStatus();
            HAL_Delay(1000);
        };





    };
}
