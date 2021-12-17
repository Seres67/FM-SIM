//
// Created by Laurent on 7/9/2021.
//

#ifndef FM_GELANO_HPP
#define FM_GELANO_HPP

#include <stat/Stats.hpp>
#include "IItem.hpp"

class Gelano : public IItem
{
public:
    explicit Gelano() : IItem{{std::make_shared<Stats::PA>(1, 1, 1)}}
    {

    }

    std::string getName() override
    {
        return "Gelano";
    }
};


#endif //FM_GELANO_HPP
