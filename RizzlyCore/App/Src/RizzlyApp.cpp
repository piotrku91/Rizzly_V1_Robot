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
#include "MoveController.hpp"
#include "MoveIdle.hpp"
#include "MoveForward.hpp"

ServosVector Servos;
LegsVector Legs;
MovesAvailable Moves;
MoveController Controller{Legs, Moves};

inline void InitServos() {
    Servos[ServoOrder::FrontLeftJoint1] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_1, 0, 120, 800, 1800, true);
    Servos[ServoOrder::FrontLeftJoint2] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_2, 0, 120, 800, 1800, true);
    Servos[ServoOrder::BackRightJoint1] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_3, 0, 120, 800, 1800, true);
    Servos[ServoOrder::BackRightJoint2] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_4, 0, 120, 800, 1800, true);
}

inline void InitLegs() {
    Legs[LegsOrder::FrontLeft] = std::make_shared<Leg>(Servos[ServoOrder::FrontLeftJoint1], Servos[ServoOrder::FrontLeftJoint2]);
    Legs[LegsOrder::BackRight] = std::make_shared<Leg>(Servos[ServoOrder::BackRightJoint1], Servos[ServoOrder::BackRightJoint2]);
}

inline void InitMoves() {
   Moves[MoveState::Idle] = std::make_shared<MoveIdle>();
   Moves[MoveState::Forward] = std::make_shared<MoveForward>(Legs);
}

/* Object creates and inits */
void RizzlyAppInit() {
    InitServos();
    InitLegs();
    InitMoves();
}

void RizzlyAppMainLoop() {
    while (true) {
        Controller.setState(MoveState::Forward);
        Controller.process();
    };
}
