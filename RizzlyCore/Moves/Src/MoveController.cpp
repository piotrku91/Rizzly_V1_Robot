/*
 * MoveController.cpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#include <MoveController.hpp>

MoveController::MoveController(LegsVector& Legs, MovesAvailable& moves_definitions):legs_(Legs), current_state_(MoveState::Idle), moves_(moves_definitions) {
	// TODO Auto-generated constructor stub

}

MoveController::~MoveController() {
	// TODO Auto-generated destructor stub
}

void MoveController::process()
{
	if (moves_.empty() || (moves_.find(current_state_) == moves_.end())) {return;};

	moves_[current_state_]->run(legs_);
	
}

void MoveController::setState(MoveState new_state)
{
	current_state_ = new_state;
}
