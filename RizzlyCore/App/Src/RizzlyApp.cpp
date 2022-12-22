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

#include "InputController.hpp"
#include "InputHardwareButtons.hpp"

#include "MoveController.hpp"
#include "MoveIdle.hpp"
#include "MoveForward.hpp"

ServosVector Servos;
LegsVector Legs;
MovesAvailable Moves;

InputHardwareButtons HardwareButtons;
InputController InputControl{ &HardwareButtons };
MoveController MoveControl{ Legs, Moves };

inline void InitServos() {
    Servos[ServoOrder::FrontLeftJoint1] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_1, 0, 120, 800, 1800, true);
    Servos[ServoOrder::FrontLeftJoint2] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_2, 0, 120, 800, 1800, true);
    Servos[ServoOrder::BackRightJoint1] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_3, 0, 120, 800, 1800, true);
    Servos[ServoOrder::BackRightJoint2] = std::make_shared<ServoDriver>(&htim1, TIM_CHANNEL_4, 0, 120, 800, 1800, true);
    Servos[ServoOrder::FrontRightJoint1] = std::make_shared<ServoDriver>(&htim2, TIM_CHANNEL_1, 0, 120, 800, 1800, true);
    Servos[ServoOrder::FrontRightJoint2] = std::make_shared<ServoDriver>(&htim2, TIM_CHANNEL_2, 0, 120, 800, 1800, true);
    Servos[ServoOrder::BackLeftJoint1] = std::make_shared<ServoDriver>(&htim2, TIM_CHANNEL_3, 0, 120, 800, 1800, true);
    Servos[ServoOrder::BackLeftJoint2] = std::make_shared<ServoDriver>(&htim2, TIM_CHANNEL_4, 0, 120, 800, 1800, true);
}

inline void InitLegs() {
    Legs[LegsOrder::FrontLeft] = std::make_shared<Leg>(Servos[ServoOrder::FrontLeftJoint1], Servos[ServoOrder::FrontLeftJoint2]);
    Legs[LegsOrder::FrontRight] = std::make_shared<Leg>(Servos[ServoOrder::FrontRightJoint1], Servos[ServoOrder::FrontRightJoint2]);
    Legs[LegsOrder::BackLeft] = std::make_shared<Leg>(Servos[ServoOrder::BackLeftJoint1], Servos[ServoOrder::BackLeftJoint2]);
    Legs[LegsOrder::BackRight] = std::make_shared<Leg>(Servos[ServoOrder::BackRightJoint1], Servos[ServoOrder::BackRightJoint2]);
}

inline void InitMoves() {
    Moves[MoveState::Idle] = std::make_shared<MoveIdle>();
    Moves[MoveState::Forward] = std::make_shared<MoveForward>(Legs);
}

void detectInputAndSetMoveState()
{
    switch (InputControl.detectInput())
    {
    case InputAxis::Front: {
        MoveControl.setState(MoveState::Forward);
        break;
    }
    case InputAxis::Back: {
        break;
    }
    case InputAxis::Right: {
        break;
    }
    case InputAxis::Left: {
        break;
    }
    case InputAxis::None:
    {
        break;
    }
    default: break;
    }
}

/* Object creates and inits */
void RizzlyAppInit() {
    InitServos();
    InitLegs();
    InitMoves();
}

void RizzlyAppHomePos()
{

    Legs[LegsOrder::FrontLeft]->setAll(45, 45);
    Legs[LegsOrder::FrontRight]->setAll(45, 45);
    Legs[LegsOrder::BackLeft]->setAll(45, 45);
    Legs[LegsOrder::BackRight]->setAll(45, 45);

    HAL_Delay(50);

    Legs[LegsOrder::FrontLeft]->setAll(0, 45);
    Legs[LegsOrder::FrontRight]->setAll(90, 45);
    Legs[LegsOrder::BackLeft]->setAll(90, 45);
    Legs[LegsOrder::BackRight]->setAll(0, 45);

}

void RizzlyAppMainLoop() {
    MoveControl.setState(MoveState::Forward);

    RizzlyAppHomePos();

    while (true) {
        detectInputAndSetMoveState();
        MoveControl.process();
    };
}
