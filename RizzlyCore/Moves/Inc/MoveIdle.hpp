/*
 * MoveIdle.hpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_MOVEIDLE_HPP_
#define MOVES_MOVEIDLE_HPP_

#include "MovePattern.hpp"

class MoveIdle : public MovePattern
{
public:
    void run(LegsVector& Legs) override;
    virtual ~MoveIdle() {};

};

#endif /* MOVES_MOVEIDLE_HPP_ */
