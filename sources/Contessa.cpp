#include <iostream>
#include "Contessa.hpp"

namespace coup
{
    Contessa::Contessa(Game &game, const std::string &name) : Player(game, name)
    {
        this->p_role = "Contessa";
    }
    void Contessa::block(Player &p)
    {
        if (this->game.check_in_game(p.get_name()))
        {
            if (this->game.last_action(p.get_name()) == "coup 3")
            {
                p.cancel();
            }
            else{
                throw std::invalid_argument("cant block coup 7");
            }
        }
    }
    std::string Contessa::role() const
    {
        return this->p_role;
    }
}