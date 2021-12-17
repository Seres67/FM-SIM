//
// Created by Laurent on 7/11/2021.
//

#ifndef FM_ALLIANCEGLOURSONNE_HPP
#define FM_ALLIANCEGLOURSONNE_HPP


#include "IItem.hpp"

class AllianceGloursonne : public IItem
{
public:
    AllianceGloursonne() : IItem{
            {std::make_shared<Stats::Vitalite>(0, 201, 250), std::make_shared<Stats::Chance>(0, 41, 60), std::make_shared<Stats::Agilite>(0, 41, 60), std::make_shared<Stats::Sagesse>(0, 31, 40),
             std::make_shared<Stats::PO>(1, 1, 1), std::make_shared<Stats::Initiative>(0, 301, 400), std::make_shared<Stats::Prospection>(0, 7, 10), std::make_shared<Stats::DoEau>(0, 8, 12),
             std::make_shared<Stats::DoAir>(0, 8, 12), std::make_shared<Stats::RePerNeutre>(0, 5, 7), std::make_shared<Stats::RePerTerre>(0, 5, 7), std::make_shared<Stats::RePerNeutre>(0, 5, 7),
             std::make_shared<Stats::Tacle>(0, 4, 5)}}
    {

    }

    std::string getName() override
    {
        return "Alliance Gloursonne";
    }
};


#endif //FM_ALLIANCEGLOURSONNE_HPP
