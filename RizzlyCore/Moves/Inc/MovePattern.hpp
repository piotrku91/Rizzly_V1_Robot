/*
 * MovePattern.hpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_INC_MOVEPATTERN_HPP_
#define MOVES_INC_MOVEPATTERN_HPP_

#include "Leg.hpp"

class MovePattern {
    public:
    virtual void run(LegsVector& Legs) = 0;

};


#endif /* MOVES_INC_MOVEPATTERN_HPP_ */
