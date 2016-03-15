#include "state_stack.h"

void State_Stack::pushState(GameState* state)
{
    states.push ( state );
    return;
}

void State_Stack::popState()
{
    delete states.top();
    states.pop();
}

void State_Stack::changeState(GameState* state)
{
    if (!states.empty())
        popState();

    pushState(state);
}

GameState* State_Stack::peekState()
{
    if ( states.empty() )
        return nullptr;

    return states.top();
}

State_Stack::~State_Stack()
{
    while ( !states.empty() )
        popState();
}
