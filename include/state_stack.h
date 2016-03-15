#ifndef STATE_STACK_H_INCLUDED
#define STATE_STACK_H_INCLUDED

#include <stack>
#include "base/game_state.hpp"

class State_Stack
{
    public:
        void        pushState       (GameState* state);
        void        popState        ();
        void        changeState     (GameState* state);
        GameState*  peekState       ();

                    ~State_Stack    ();

    private:
        std::stack <GameState*> states;

        void        popTop          ();
};


#endif // STATE_STACK_H_INCLUDED
