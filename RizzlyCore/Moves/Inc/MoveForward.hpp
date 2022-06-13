/*
 * MoveForward.hpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_MOVEFORWARD_HPP_
#define MOVES_MOVEFORWARD_HPP_

#include "MovePattern.hpp"

class MoveForward : public MovePattern
{
public:
    MoveForward();
    void run(LegsVector& Legs) override;
    virtual ~MoveForward() {};

};

#endif /* MOVES_MOVEFORWARD_HPP_ */
