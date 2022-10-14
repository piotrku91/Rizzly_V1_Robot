#pragma once

enum class InputAxis
{
Front,
Back,
Left,
Right,
None
};

class InputInterface
{
public:
virtual InputAxis getInput() = 0;
};