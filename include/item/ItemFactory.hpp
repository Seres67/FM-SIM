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

        for (const std::shared_ptr<IStat> &stat : stats)
        {
            int min = stat->min;
            int max = stat->max;

            if (min == max)
            {
                stat->stat = max;
                stat->weight = (max * stat->weight_per_stat);
                weight += stat->weight;
                continue;
            }
            std::uniform_int_distribution<> distrib(min, max);
            stat->stat = (distrib(gen));
            stat->weight = (stat->stat * stat->weight_per_stat);
            weight += stat->weight;
        }
        item->setWeight(static_cast<float>(weight));
    }
};

#endif //FM_ITEMFACTORY_HPP
