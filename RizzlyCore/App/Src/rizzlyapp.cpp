/*
 * rizzlyapp.cpp
 *
 *  Created on: May 24, 2022
 *      Author: piotr
 */

#include "rizzlyapp.hpp"

/* Global object declarations */
using ServosVector = std::map<ServoOrder, std::shared_ptr<ServoDriver>>;
ServosVector Servos;

inline void InitServos() {
    Servos[ServoOrder::FrontLeftJoint1] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_1, 0, 120, 800, 1800, true);

}

/* Object creates and inits */
void RizzlyAppInit() {
    InitServos();
}

void RizzlyAppMainLoop() {
    while (true) {
        Servos[ServoOrder::FrontLeftJoint1]->moveToAngle(120);
        HAL_Delay(2000);
        Servos[ServoOrder::FrontLeftJoint1]->moveToAngle(0);
        HAL_Delay(2000);
    }
}
