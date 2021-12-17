//
// Created by Laurent on 7/10/2021.
//

#ifndef FM_STATS_HPP
#define FM_STATS_HPP

#include <string>
#include <utility>

template<size_t N>
struct StringLiteral
{
    constexpr explicit StringLiteral(const char (&str)[N])
    {
        std::copy_n(str, N, value);
    }

    char value[N]{};
};

struct IStat
{
    int stat;
    int min;
    int max;
    float weight_per_stat;
    float weight;
    int stat_per_rune;
    const char *name{};

    IStat(int stat, int min, int max, int stat_per_rune, float weight_per_stat, const char *name) : stat(stat), min(min), max(max), weight_per_stat(weight_per_stat),
                                                                                                    stat_per_rune(stat_per_rune), name(name)
    {
        weight = static_cast<float>(stat) * weight_per_stat;
    }

    [[nodiscard]] std::string getName() const
    {
        return name;
    };

    virtual void addNormal() = 0;

    virtual void addPa() = 0;

    virtual void addRa() = 0;
};

template<int StatPerRune, float WeightPerStat, StringLiteral Name>
struct AStat : IStat
{
    AStat(int stat, int min, int max) : IStat(stat, min, max, StatPerRune, WeightPerStat, Name.value)
    {

    }


    void addNormal() override
    {
        if (stat + stat_per_rune > max)
            return;
        stat += stat_per_rune;
        weight += stat_per_rune * weight_per_stat;
    }

    void addPa() override
    {
        if (stat + stat_per_rune * 3 > max)
            return;
        stat += (stat_per_rune * 3);
        weight += (stat_per_rune * 3) * weight_per_stat;
    }

    void addRa() override
    {
        if (stat + stat_per_rune * 10 > max)
            return;
        stat += (stat_per_rune * 10);
        weight += (stat_per_rune * 10) * weight_per_stat;
    }
};

namespace Stats
{
    using Initiative = AStat<10, 0.1f, StringLiteral("Initiative")>;
    using Vitalite = AStat<5, 0.2f, StringLiteral("Vitalité")>;
    using Pods = AStat<10, 0.25, StringLiteral("Pods")>;
    using Chance = AStat<1, 1.f, StringLiteral("Chance")>;
    using Intelligence = AStat<1, 1.f, StringLiteral("Intelligence")>;
    using Force = AStat<1, 1.f, StringLiteral("Force")>;
    using Agilite = AStat<1, 1.f, StringLiteral("Agilité")>;
    using RePou = AStat<1, 2.f, StringLiteral("Résistance Poussée")>;
    using ReCri = AStat<1, 2.f, StringLiteral("Résistance Critiques")>;
    using ReTerre = AStat<1, 2.f, StringLiteral("Résistance Terre")>;
    using ReAir = AStat<1, 2.f, StringLiteral("Résistance Air")>;
    using ReFeu = AStat<1, 2.f, StringLiteral("Résistance Feu")>;
    using ReEau = AStat<1, 2.f, StringLiteral("Résistance Eau")>;
    using ReNeutre = AStat<1, 2.f, StringLiteral("Résistance Neutre")>;
    using Puissance = AStat<1, 2.f, StringLiteral("Puissance")>;
    using PuiPiege = AStat<1, 2.f, StringLiteral("Puissance (pièges)")>;
    using Sagesse = AStat<1, 3.f, StringLiteral("Sagesse")>;
    using Prospection = AStat<1, 3.f, StringLiteral("Prospection")>;
    using Fuite = AStat<1, 4.f, StringLiteral("Fuite")>;
    using Tacle = AStat<1, 4.f, StringLiteral("Tacle")>;
    using Chasse = AStat<1, 5.f, StringLiteral("Chasse")>;
    using DoPiege = AStat<1, 5.f, StringLiteral("Dommages Pièges")>;
    using DoPou = AStat<1, 5.f, StringLiteral("Dommages Poussée")>;
    using DoCri = AStat<1, 5.f, StringLiteral("Dommages Critiques")>;
    using DoAir = AStat<1, 5.f, StringLiteral("Dommages Air")>;
    using DoFeu = AStat<1, 5.f, StringLiteral("Dommages Feu")>;
    using DoTerre = AStat<1, 5.f, StringLiteral("Dommages Terre")>;
    using DoNeutre = AStat<1, 5.f, StringLiteral("Dommages Neutre")>;
    using DoEau = AStat<1, 5.f, StringLiteral("Dommages Eau")>;
    using RePerEau = AStat<1, 6.f, StringLiteral("% Résistance Eau")>;
    using RePerFeu = AStat<1, 6.f, StringLiteral("% Résistance Feu")>;
    using RePerAir = AStat<1, 6.f, StringLiteral("% Résistance Air")>;
    using RePerTerre = AStat<1, 6.f, StringLiteral("% Résistance Terre")>;
    using RePerNeutre = AStat<1, 6.f, StringLiteral("% Résistance Neutre")>;
    using EsquivePa = AStat<1, 7.f, StringLiteral("Esquive PA")>;
    using EsquivePm = AStat<1, 7.f, StringLiteral("Esquive PM")>;
    using RetraitPa = AStat<1, 7.f, StringLiteral("Retrait PA")>;
    using RetraitPm = AStat<1, 7.f, StringLiteral("Retrait PM")>;
    using Renvoi = AStat<1, 20.f, StringLiteral("Renvoi")>;
    using Crit = AStat<1, 10.f, StringLiteral("Critique")>;
    using Soin = AStat<1, 10.f, StringLiteral("Soin")>;
    using RePerMe = AStat<1, 15.f, StringLiteral("% Résistance mêlée")>;
    using RePerDi = AStat<1, 15.f, StringLiteral("% Résistance distance")>;
    using RePerSo = AStat<1, 15.f, StringLiteral("% Résistance aux sorts")>;
    using RePerAr = AStat<1, 15.f, StringLiteral("% Résistance aux armes")>;
    using DoPerMe = AStat<1, 15.f, StringLiteral("% Dommages mêlée")>;
    using DoPerDi = AStat<1, 15.f, StringLiteral("% Dommages distance")>;
    using DoPerSo = AStat<1, 15.f, StringLiteral("% Dommages aux sorts")>;
    using DoPerAr = AStat<1, 15.f, StringLiteral("% Dommages aux armes")>;
    using Dommages = AStat<1, 20.f, StringLiteral("Dommmages")>;
    using Invocation = AStat<1, 30.f, StringLiteral("Invocation")>;
    using PO = AStat<1, 51.f, StringLiteral("Portée")>;
    using PM = AStat<1, 90.f, StringLiteral("PM")>;
    using PA = AStat<1, 100.f, StringLiteral("PA")>;
}

#endif //FM_STATS_HPP
