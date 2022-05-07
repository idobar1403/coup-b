#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <vector>
#include <unordered_map>

#pragma once

namespace coup
{
    class Game
    {
    protected:
        std::vector<std::string> players_in_game;
        std::unordered_map<std::string, std::string> actions;
        int round_number;
        int number_of_turns;
    public:
        Game();
        std::string turn() const;
        int get_players_size() const;
        std::string winner();
        std::vector<std::string> players() const;
        std::vector<std::string> player_turn() const;
        std::string last_action(const std::string &name) const;
        void add_player(const std::string &name);
        void add_action(const std::string &name, const std::string &action);
        bool check_in_game(const std::string &name) const;
        void remove_player(const std::string &name);
        int get_round_number() const;
        int get_number_of_turns() const;
        void update_turns();
        void update_rounds();
        const int max_players = 6;
        void add_dead_player(const std::string &name, int index);
    };
}
#endif
