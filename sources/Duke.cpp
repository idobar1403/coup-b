#include <iostream>
#include "Duke.hpp"

namespace coup
{
    Duke::Duke(Game &game, const std::string &name) : Player(game, name)
    {
        this->p_role = "Duke";
    }
    void Duke::block(Player &p)
    {
        if (this->game.check_in_game(p.get_name()))
        {
            if (this->game.last_action(p.get_name()) == "foreign aid")
            {
                p.decrease_cash(2);
            }
            else{
                throw std::invalid_argument("bad action");
            }
        }
        else{
            throw std::invalid_argument("player not in game");
        }
    }
    void Duke::tax()
    {
        if (this->game.turn() == this->p_name)
        {
            this->increase_cash(3);
            this->game.update_turns();
            this->game.update_rounds();
            this->game.add_action(this->p_name, "tax");
        }
    }
    std::string Duke::role() const
    {
        return this->p_role;
    }

}