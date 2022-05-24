/*
 * rizzlyapp.cpp
 *
 *  Created on: May 24, 2022
 *      Author: piotr
 */

#include "rizzlyapp.hpp"
#include "ServoDriver.hpp"
#include "Leg.hpp"

/* Global object declarations */
using ServosVector = std::map<ServoOrder, ServoDriverPtr>;
using LegsVector = std::map<LegsOrder, std::shared_ptr<Leg>>;

ServosVector Servos;
LegsVector Legs;

inline void InitServos() {
    Servos[ServoOrder::FrontLeftJoint1] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_1, 0, 120, 800, 1800, true);
}

inline void InitLegs() {
   Legs[LegsOrder::FrontLeft] = std::make_shared<Leg>(Servos[ServoOrder::FrontLeftJoint1], Servos[ServoOrder::FrontLeftJoint1]);
}

/* Object creates and inits */
void RizzlyAppInit() {
    InitServos();
    InitLegs();
}

void RizzlyAppMainLoop() {
    while (true) {
        Legs[LegsOrder::FrontLeft]->setRotationAngle(TypicalAngles::Pos45);
        HAL_Delay(2000);
        Legs[LegsOrder::FrontLeft]->setRotationAngle(TypicalAngles::Pos0);
        HAL_Delay(2000);
    }
}
