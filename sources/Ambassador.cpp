#include <iostream>
#include "Ambassador.hpp"

namespace coup
{
    Ambassador::Ambassador(Game &game, const std::string &name) : Player(game, name)
    {
        this->p_role = "Ambassador";
    }
    void Ambassador::transfer(Player &player1, Player &player2)
    {
        if (this->game.turn() != this->p_name)
        {
            throw std::invalid_argument("not the player turn");
        }
        if (this->coins() >= this->max_hold)
        {
            throw std::invalid_argument("need to do coup");
        }
        if (!this->game.check_in_game(player1.get_name()) || !this->game.check_in_game(player2.get_name()))
        {
            throw std::invalid_argument("not all players in game");
        }
        if (player1.coins() > 0)
        {
            player1.decrease_cash(1);
            player2.increase_cash(1);
            this->action_player = &player1;
            this->game.update_turns();
            this->game.update_rounds();
            this->game.add_action(this->p_name, "transfer");
        }
        else
        {
            throw std::invalid_argument("player1 has 0 cash");
        }
    }
    void Ambassador::block(Player &p)
    {
        if (p.role() == "Captain")
        {
            if (this->game.check_in_game(p.get_name()))
            {
                p.cancel();
                this->game.add_action(p.get_name(), "canceld");
            }
        }
        else
        {
            throw std::invalid_argument("not captain");
        }
    }
    std::string Ambassador::role() const
    {
        return this->p_role;
    }
}