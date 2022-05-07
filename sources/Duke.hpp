#include <iostream>
#include "Player.hpp"

namespace coup
{
    class Duke : public Player
    {
    public:
        Duke(Game &game, const std::string &name);
        void block(Player &p);
        void tax();
        std::string role() const override;
    };
}