#include <iostream>
#include "Assassin.hpp"

namespace coup
{
    Assassin::Assassin(Game &game, const std::string &name) : Player(game, name)
    {
        this->p_role = "Assassin";
        this->coup_cost = 3;
    }
    void Assassin::coup(Player &p)
    {
        
        if (this->game.turn() != this->p_name)
        {
            throw std::invalid_argument("not the player turn");
        }
        if (!this->game.check_in_game(p.get_name()))
        {
            throw std::invalid_argument("player not in game");
        }
        if (this->cash < this->org_cash && this->cash >= this->coup_cost)
        {
            this->game.remove_player(p.get_name());
            p.update_death_round(this->game.get_round_number());
            this->action_player = &p;
            this->decrease_cash(this->coup_cost);
            this->game.add_action(this->p_name, "coup 3");
        }
        else if (this->cash >= this->org_cash)
        {
            this->game.remove_player(p.get_name());
            p.update_death_round(this->game.get_round_number());
            this->action_player = &p;
            this->decrease_cash(this->org_cash);
            this->game.add_action(this->p_name, "coup 7");
        }
        else
        {
            throw std::invalid_argument("not enough money");
        }
        if (p.place_in_turns > this->place_in_turns)
        {
            this->game.update_turns();
            this->game.update_rounds();
        }
    }
    std::string Assassin::role() const
    {
        return this->p_role;
    }
    void Assassin::cancel()
    {
        if (this->game.last_action(this->p_name) == "coup 3")
        {
            if (this->action_player->round_died == this->game.get_round_number())
            {
                this->game.add_dead_player(this->action_player->get_name(), this->action_player->place_in_turns);
                this->game.add_action(this->p_name, "canceld");
            }
        }
    }
}