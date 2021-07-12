//
// Created by Laurent on 7/9/2021.
//

#ifndef FM_ITEMFACTORY_HPP
#define FM_ITEMFACTORY_HPP

#include "IItem.hpp"
#include <random>

class ItemFactory
{
public:
    static void createItem(IItem *item)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        int weight = 0;

        if (item == nullptr)
            return;
        auto stats = item->getStats();

        for (auto &stat : stats)
        {
            int min = stat->getMin();
            int max = stat->getMax();

            if (min == max)
            {
                stat->setStat(max);
                stat->setWeight(max * stat->getWeightPerStat());
                weight += stat->getWeight();
                continue;
            }
            std::uniform_int_distribution<> distrib(min, max);
            stat->setStat(distrib(gen));
            stat->setWeight(stat->getStat() * stat->getWeightPerStat());
            weight += stat->getWeight();
        }
        item->setWeight(static_cast<float>(weight));
    }
};

#endif //FM_ITEMFACTORY_HPP
