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
        for (auto &stat : m_stats)
        {
            m_weight += static_cast<float>(stat->getWeight());
            m_max_weight += stat->getMax();
        }
    }

    explicit IItem(const std::vector<stat_infos> &stats)
    {
        for (auto &stat : stats)
        {
            auto stat_ptr = m_test[stat.name](stat.min, stat.max);
            m_stats.emplace_back(stat_ptr);
            m_weight += static_cast<float>(stat_ptr->getWeight());
            m_max_weight += stat_ptr->getMax();
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
        for (auto &stat : m_stats)
            std::cout << stat->getStat() << " " << stat->getName() << " weight: " << stat->getWeight() << " weight per stat: " << stat->getWeightPerStat() << std::endl;
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
            {"Initiative",             &IItem::createNewStat<Initiative>},
            {"Vitalité",               &IItem::createNewStat<Vitalite>},
            {"Pods",                   &IItem::createNewStat<Pods>},
            {"Chance",                 &IItem::createNewStat<Chance>},
            {"Force",                  &IItem::createNewStat<Force>},
            {"Agilité",                &IItem::createNewStat<Agilite>},
            {"Intelligence",           &IItem::createNewStat<Intelligence>},
            {"Résistance Poussée",     &IItem::createNewStat<RePou>},
            {"Résistance Critiques",   &IItem::createNewStat<ReCrit>},
            {"Résistance Terre",       &IItem::createNewStat<ReTerre>},
            {"Résistance Neutre",      &IItem::createNewStat<ReNeutre>},
            {"Résistance Feu",         &IItem::createNewStat<ReFeu>},
            {"Résistance Air",         &IItem::createNewStat<ReAir>},
            {"Résistance Eau",         &IItem::createNewStat<ReEau>},
            {"Puissance",              &IItem::createNewStat<Puissance>},
            {"Puissance (pièges)",     &IItem::createNewStat<PuiPiege>},
            {"Sagesse",                &IItem::createNewStat<Sagesse>},
            {"Prospection",            &IItem::createNewStat<Prospection>},
            {"Fuite",                  &IItem::createNewStat<Fuite>},
            {"Tacle",                  &IItem::createNewStat<Tacle>},
            {"Chasse",                 &IItem::createNewStat<Chasse>},
            {"Dommages Pièges",        &IItem::createNewStat<DoPiege>},
            {"Dommages Poussée",       &IItem::createNewStat<DoPou>},
            {"Dommages Critiques",     &IItem::createNewStat<DoCri>},
            {"Dommages Eau",           &IItem::createNewStat<DoEau>},
            {"Dommages Feu",           &IItem::createNewStat<DoFeu>},
            {"Dommages Terre",         &IItem::createNewStat<DoTerre>},
            {"Dommages Air",           &IItem::createNewStat<DoAir>},
            {"Dommages Neutre",        &IItem::createNewStat<DoNeutre>},
            {"% Résistance Eau",       &IItem::createNewStat<RePerEau>},
            {"% Résistance Feu",       &IItem::createNewStat<RePerFeu>},
            {"% Résistance Air",       &IItem::createNewStat<RePerAir>},
            {"% Résistance Terre",     &IItem::createNewStat<RePerTerre>},
            {"% Résistance Neutre",    &IItem::createNewStat<RePerNeutre>},
            {"Esquive PA",             &IItem::createNewStat<EsquivePa>},
            {"Esquive PM",             &IItem::createNewStat<EsquivePm>},
            {"Retrait PA",             &IItem::createNewStat<RetraitPa>},
            {"Retrait PM",             &IItem::createNewStat<RetraitPm>},
            {"Renvoie dommages",       &IItem::createNewStat<Renvoi>},
            {"% Critique",             &IItem::createNewStat<Crit>},
            {"Soin",                   &IItem::createNewStat<Soin>},
            {"% Résistance mêlée",     &IItem::createNewStat<RePerMe>},
            {"% Résistance distance",  &IItem::createNewStat<RePerDi>},
            {"% Résistance aux sorts", &IItem::createNewStat<RePerSo>},
            {"% Résistance aux armes", &IItem::createNewStat<RePerAr>},
            {"% Dommages d'armes",     &IItem::createNewStat<DoPerAr>},
            {"% Dommages aux sorts",   &IItem::createNewStat<DoPerSo>},
            {"% Dommages mêlée",       &IItem::createNewStat<DoPerMe>},
            {"% Dommages distance",    &IItem::createNewStat<DoPerDi>},
            {"Dommages",               &IItem::createNewStat<Dommages>},
            {"Invocation",             &IItem::createNewStat<Invocation>},
            {"PO",                     &IItem::createNewStat<PO>},
            {"PM",                     &IItem::createNewStat<GaPM>},
            {"PA",                     &IItem::createNewStat<GaPA>}
    };
    std::string m_name;
};

#endif //FM_IITEM_HPP
