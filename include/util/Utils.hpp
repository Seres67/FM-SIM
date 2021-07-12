//
// Created by Laurent on 7/12/2021.
//

#ifndef FM_UTILS_HPP
#define FM_UTILS_HPP

#include <utility>
#include <vector>
#include <string>

class Utils
{
public:
    static std::vector<std::string> getAllStatsNames();
};

struct stat_infos_s
{
    int min, max;
    std::string name;

    stat_infos_s(int min, int max, std::string name)
    {
        this->min = min;
        this->max = max;
        this->name = std::move(name);
    }
};

using stat_infos = struct stat_infos_s;

#endif //FM_UTILS_HPP
