#include <iostream>
#include <algorithm>
#include "Game.hpp"

namespace coup
{
    Game::Game()
    {
        this->number_of_turns = 0;
        this->round_number = 0;
    };
    void Game::add_player(const std::string &name)
    {
        if (this->number_of_turns > 0 || this->players_in_game.size() > this->max_players)
        {
            throw std::invalid_argument("can't add players anymore");
        }
        this->players_in_game.push_back(name);
    }
    void Game::remove_player(const std::string &name)
    {
        if (check_in_game(name))
        {
            this->players_in_game.erase(std::remove(this->players_in_game.begin(), this->players_in_game.end(), name), this->players_in_game.end());
        }
        else
        {
            throw std::invalid_argument("player as already been eliminated\n");
        }
    }
    void Game::add_dead_player(const std::string &name, int index)
    {
        if (this->get_players_size() < index+1)
        {
            this->players_in_game.push_back(name);
        }
        else
        {
            this->players_in_game.insert(this->players_in_game.begin() + index, name);
        }
        if(index<=this->number_of_turns){
            this->update_turns();
        }
    }
    std::string Game::turn() const
    {
        unsigned long num = (unsigned long)(this->number_of_turns);
        return this->players_in_game.at(num);
    }
    std::vector<std::string> Game::players() const
    {
        return this->players_in_game;
    }
    std::string Game::last_action(const std::string &name) const
    {
        if (this->actions.count(name) == 0)
        {
            return "none";
        }
        return this->actions.at(name);
    }
    bool Game::check_in_game(const std::string &name) const
    {
        return (std::count(this->players_in_game.begin(), this->players_in_game.end(), name) != 0);
    }
    void Game::add_action(const std::string &name, const std::string &action)
    {
        if (check_in_game(name))
        {
            this->actions[name] = action;
        }
        else
        {
            throw std::invalid_argument("player not in game\n");
        }
    }
    int Game::get_round_number() const
    {
        return this->round_number;
    }
    int Game::get_players_size() const
    {
        return this->players_in_game.size();
    }
    int Game::get_number_of_turns() const
    {
        return this->number_of_turns;
    }
    void Game::update_turns()
    {
        this->number_of_turns += 1;
        if(this->number_of_turns>=this->players_in_game.size())
        {
            this->number_of_turns=0;
        }
    }
    void Game::update_rounds()
    {
        unsigned long num = (unsigned long)(this->number_of_turns) % this->players_in_game.size();
        if (num == 0)
        {
            this->round_number += 1;
        }
    }
    std::string Game::winner(){
        if(this->players_in_game.size()==1 && this->round_number>0){
            return this->players_in_game[0];
        }
            throw std::invalid_argument("game not finished");
        
    }
}
