#include <iostream>
#include "Player.hpp"

namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game &game, const std::string &name);
        void steal(Player &player);
        void block(Player &player);
        std::string role() const override;
        void cancel() override;
    };
}