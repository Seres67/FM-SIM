//
// Created by Laurent on 7/10/2021.
//

#ifndef FM_ANNEAUVOLKORNE_HPP
#define FM_ANNEAUVOLKORNE_HPP

#include "IItem.hpp"

class AnneauVolkorne : public IItem
{
public:
    explicit AnneauVolkorne() : IItem{{std::make_shared<Vitalite>(0, 201, 250), std::make_shared<Chance>(0, 81, 100), std::make_shared<DoEau>(0, 16, 20), std::make_shared<RePerEau>(0, 7, 10),
                                              std::make_shared<Crit>(0, 4, 5)}}
    {

    }

    std::string getName() override
    {
        return "Anneau Volkorne";
    }
};


#endif //FM_ANNEAUVOLKORNE_HPP
