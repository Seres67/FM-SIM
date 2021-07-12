//
// Created by Laurent on 7/9/2021.
//

#ifndef FM_RUNE_HPP
#define FM_RUNE_HPP

#include <stat/Stats.hpp>

class Rune
{
public:
    Rune(int weight, const IStat &stat) : m_weight(weight)/*, m_stat(stat)*/
    {

    }

    [[nodiscard]] int getWeight() const
    {
        return m_weight;
    }

//    [[nodiscard]] IStat getStat() const
//    {
//        return m_stat;
//    }

private:
    int m_weight;
//    IStat m_stat;
};


#endif //FM_RUNE_HPP
