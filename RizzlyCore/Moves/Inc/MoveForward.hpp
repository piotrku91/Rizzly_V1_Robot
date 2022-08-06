/*
 * MoveForward.hpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_MOVEFORWARD_HPP_
#define MOVES_MOVEFORWARD_HPP_

#include "MovePattern.hpp"
#include "defines.hpp"

class MoveForward : public MovePattern, MovePatternLegsInput
{
public:
    MoveForward(LegsVector& legs);
    void run() override;
    virtual ~MoveForward() {};
    

};

#endif /* MOVES_MOVEFORWARD_HPP_ */
