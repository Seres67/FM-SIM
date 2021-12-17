//
// Created by Laurent on 7/9/2021.
//

#ifndef FM_IITEM_HPP
#define FM_IITEM_HPP

#include <utility>
#include <vector>
#include <iostream>
#include <memory>
#include <functional>
#include <map>
#include <stat/Stats.hpp>
#include <util/Utils.hpp>

class IItem
{
public:
    explicit IItem(std::vector<std::shared_ptr<IStat>> stats) : m_stats(std::move(stats))
    {
        for (auto &stat: m_stats)
        {
            m_weight += static_cast<float>(stat->weight);
            m_max_weight += stat->max;
        }
    }

    explicit IItem(const std::vector<stat_infos> &stats)
    {
        for (auto &stat: stats)
        {
            auto stat_ptr = m_test[stat.name](stat.min, stat.max);
            m_stats.emplace_back(stat_ptr);
            m_weight += static_cast<float>(stat_ptr->weight);
            m_max_weight += stat_ptr->max;
        }
    }

    [[nodiscard]] std::vector<std::shared_ptr<IStat>> &getStats()
    {
        return m_stats;
    }

    [[nodiscard]] int getMaxWeight() const
    {
        return m_max_weight;
    }

    [[nodiscard]] float getWeight() const
    {
        return m_weight;
    }

    void setWeight(float weight)
    {
        m_weight = weight;
    }

    void printStats()
    {
        for (auto &stat: m_stats)
            std::cout << stat->stat << " " << stat->getName() << " weight: " << stat->weight << " weight per stat: " << stat->weight_per_stat << std::endl;
        std::cout << "Max item weight: " << m_max_weight << std::endl;
    }

    virtual std::string getName()
    {
        return "";
    }

private:
    template<typename T>
    static IStat *createNewStat(int min, int max)
    {
        return new T(0, min, max);
    }

protected:
    std::vector<std::shared_ptr<IStat>> m_stats;
    float m_weight = 0;
    int m_max_weight = 0;
    std::map<std::string, std::function<IStat *(int, int)>> m_test = {
            {"Initiative",             &IItem::createNewStat<Stats::Initiative>},
            {"Vitalité",               &IItem::createNewStat<Stats::Vitalite>},
            {"Pods",                   &IItem::createNewStat<Stats::Pods>},
            {"Chance",                 &IItem::createNewStat<Stats::Chance>},
            {"Force",                  &IItem::createNewStat<Stats::Force>},
            {"Agilité",                &IItem::createNewStat<Stats::Agilite>},
            {"Intelligence",           &IItem::createNewStat<Stats::Intelligence>},
            {"Résistance Poussée",     &IItem::createNewStat<Stats::RePou>},
            {"Résistance Critiques",   &IItem::createNewStat<Stats::ReCri>},
            {"Résistance Terre",       &IItem::createNewStat<Stats::ReTerre>},
            {"Résistance Neutre",      &IItem::createNewStat<Stats::ReNeutre>},
            {"Résistance Feu",         &IItem::createNewStat<Stats::ReFeu>},
            {"Résistance Air",         &IItem::createNewStat<Stats::ReAir>},
            {"Résistance Eau",         &IItem::createNewStat<Stats::ReEau>},
            {"Puissance",              &IItem::createNewStat<Stats::Puissance>},
            {"Puissance (pièges)",     &IItem::createNewStat<Stats::PuiPiege>},
            {"Sagesse",                &IItem::createNewStat<Stats::Sagesse>},
            {"Prospection",            &IItem::createNewStat<Stats::Prospection>},
            {"Fuite",                  &IItem::createNewStat<Stats::Fuite>},
            {"Tacle",                  &IItem::createNewStat<Stats::Tacle>},
            {"Chasse",                 &IItem::createNewStat<Stats::Chasse>},
            {"Dommages Pièges",        &IItem::createNewStat<Stats::DoPiege>},
            {"Dommages Poussée",       &IItem::createNewStat<Stats::DoPou>},
            {"Dommages Critiques",     &IItem::createNewStat<Stats::DoCri>},
            {"Dommages Eau",           &IItem::createNewStat<Stats::DoEau>},
            {"Dommages Feu",           &IItem::createNewStat<Stats::DoFeu>},
            {"Dommages Terre",         &IItem::createNewStat<Stats::DoTerre>},
            {"Dommages Air",           &IItem::createNewStat<Stats::DoAir>},
            {"Dommages Neutre",        &IItem::createNewStat<Stats::DoNeutre>},
            {"% Résistance Eau",       &IItem::createNewStat<Stats::RePerEau>},
            {"% Résistance Feu",       &IItem::createNewStat<Stats::RePerFeu>},
            {"% Résistance Air",       &IItem::createNewStat<Stats::RePerAir>},
            {"% Résistance Terre",     &IItem::createNewStat<Stats::RePerTerre>},
            {"% Résistance Neutre",    &IItem::createNewStat<Stats::RePerNeutre>},
            {"Esquive PA",             &IItem::createNewStat<Stats::EsquivePa>},
            {"Esquive PM",             &IItem::createNewStat<Stats::EsquivePm>},
            {"Retrait PA",             &IItem::createNewStat<Stats::RetraitPa>},
            {"Retrait PM",             &IItem::createNewStat<Stats::RetraitPm>},
            {"Renvoie dommages",       &IItem::createNewStat<Stats::Renvoi>},
            {"% Critique",             &IItem::createNewStat<Stats::Crit>},
            {"Soin",                   &IItem::createNewStat<Stats::Soin>},
            {"% Résistance mêlée",     &IItem::createNewStat<Stats::RePerMe>},
            {"% Résistance distance",  &IItem::createNewStat<Stats::RePerDi>},
            {"% Résistance aux sorts", &IItem::createNewStat<Stats::RePerSo>},
            {"% Résistance aux armes", &IItem::createNewStat<Stats::RePerAr>},
            {"% Dommages d'armes",     &IItem::createNewStat<Stats::DoPerAr>},
            {"% Dommages aux sorts",   &IItem::createNewStat<Stats::DoPerSo>},
            {"% Dommages mêlée",       &IItem::createNewStat<Stats::DoPerMe>},
            {"% Dommages distance",    &IItem::createNewStat<Stats::DoPerDi>},
            {"Dommages",               &IItem::createNewStat<Stats::Dommages>},
            {"Invocation",             &IItem::createNewStat<Stats::Invocation>},
            {"PO",                     &IItem::createNewStat<Stats::PO>},
            {"PM",                     &IItem::createNewStat<Stats::PM>},
            {"PA",                     &IItem::createNewStat<Stats::PA>}
    };
    std::string m_name;
};

#endif //FM_IITEM_HPP
