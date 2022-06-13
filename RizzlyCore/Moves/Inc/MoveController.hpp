/*
 * MoveController.h
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_MOVECONTROLLER_H_
#define MOVES_MOVECONTROLLER_H_

#include "Leg.hpp"
#include "MovePattern.hpp"

enum class MoveState
{
Idle,
Forward,
Backward,
Rotation
};

using MovesAvailable = std::map<MoveState, std::shared_ptr<MovePattern>>;

class MoveController final {
private:
	LegsVector& legs_;
	MoveState current_state_;
	MovesAvailable& moves_;

public:
	MoveController(LegsVector& Legs, MovesAvailable& moves_definitions);
	void process();
	void setState(MoveState new_state);
	virtual ~MoveController();
};

#endif /* MOVES_MOVECONTROLLER_H_ */
