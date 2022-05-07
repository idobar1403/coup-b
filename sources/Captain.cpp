#include <iostream>
#include "Captain.hpp"

namespace coup
{
    Captain::Captain(Game &game, const std::string &name) : Player(game, name)
    {
        this->p_role = "Captain";
    }
    void Captain::steal(Player &p)
    {
        if(this->game.turn()!= this->p_name){
            throw std::invalid_argument("not turn");
        }
        if(this->game.check_in_game(p.get_name())){
            if(p.coins()>=2){
                p.decrease_cash(2);
                this->increase_cash(2);
                this->game.add_action(this->p_name, "steal 2");
                this->action_player = &p;
            }
            else if(p.coins()==1){
                p.decrease_cash(1);
                this->increase_cash(1);
                this->game.add_action(this->p_name, "steal 1");
                this->action_player = &p;
            }
            else{
                this->increase_cash(0);
                this->game.add_action(this->p_name, "steal 0");
                this->action_player = &p;
            }
            this->game.update_turns();
            this->game.update_rounds();
        }
    }
    void Captain::block(Player &p)
    {
        std::string s=this->game.last_action(p.get_name());
        if(s!="steal 0" && s!="steal 1" && s!="steal 2"){
            throw std::invalid_argument("cant block non steal action");
        }
        if (this->game.check_in_game(p.get_name()))
        {
            p.cancel();
            this->game.add_action(p.get_name(), "canceld");
        }
    }
    std::string Captain::role() const
    {
        return this->p_role;
    }
    void Captain::cancel(){
        if(this->game.last_action(this->p_name)=="steal 2"){
            this->decrease_cash(2);
            this->action_player->increase_cash(2);
        }
        if(this->game.last_action(this->p_name)=="steal 1"){
            this->decrease_cash(1);
            this->action_player->increase_cash(1);
        }
    }
}