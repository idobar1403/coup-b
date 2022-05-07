#include <iostream>
#include "Player.hpp"

namespace coup
{
    class Assassin : public Player
    {
    public:
        Assassin(Game &game, const std::string &name);
        void coup(Player &p) override;
        std::string role() const override;
        void cancel() override;
        int org_cash=7;
    };
}