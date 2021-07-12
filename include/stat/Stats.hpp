//
// Created by Laurent on 7/10/2021.
//

#ifndef FM_STATS_HPP
#define FM_STATS_HPP

#include <string>

struct IStat
{
    int stat;
    int min;
    int max;
    float weight_per_stat;
    float weight;
    int stat_per_rune;

    IStat(int stat, int min, int max, int stat_per_rune, float weight_per_stat) : stat(stat), min(min), max(max), stat_per_rune(stat_per_rune), weight_per_stat(weight_per_stat)
    {
        weight = static_cast<float>(stat) * weight_per_stat;
    };

    [[nodiscard]] float getWeight() const
    {
        return weight;
    }

    void setWeight(float w)
    {
        this->weight = w;
    }

    [[nodiscard]] int getStat() const
    {
        return stat;
    }

    void setStat(int s)
    {
        this->stat = s;
    }

    [[nodiscard]] int getMin() const
    {
        return min;
    }

    [[nodiscard]] int getMax() const
    {
        return max;
    }

    [[nodiscard]] float getWeightPerStat() const
    {
        return weight_per_stat;
    }

    virtual std::string getName() = 0;

    void addNormal()
    {
        if (stat + stat_per_rune > max)
            return;
        stat += stat_per_rune;
        weight += stat_per_rune * weight_per_stat;
    }

    void addPa()
    {
        if (stat + stat_per_rune * 3 > max)
            return;
        stat += (stat_per_rune * 3);
        weight += (stat_per_rune * 3) * weight_per_stat;
    }

    void addRa()
    {
        if (stat + stat_per_rune * 10 > max)
            return;
        stat += (stat_per_rune * 10);
        weight += (stat_per_rune * 10) * weight_per_stat;
    }
};

struct Initiative : IStat
{
    Initiative(int stat, int min, int max) : IStat(stat, min, max, 10, 0.1)
    {

    }

    std::string getName() override
    {
        return "Initiative";
    }
};

struct Vitalite : IStat
{
    Vitalite(int stat, int min, int max) : IStat(stat, min, max, 5, 0.2)
    {

    }

    std::string getName() override
    {
        return std::string("Vitalité");
    }
};

struct Pods : IStat
{
    Pods(int stat, int min, int max) : IStat(stat, min, max, 10, 0.25)
    {

    }

    std::string getName() override
    {
        return "Pods";
    }
};

struct Chance : IStat
{
    Chance(int stat, int min, int max) : IStat(stat, min, max, 1, 1)
    {

    }

    std::string getName() override
    {
        return "Chance";
    }
};

struct Intelligence : IStat
{
    Intelligence(int stat, int min, int max) : IStat(stat, min, max, 1, 1)
    {

    }

    std::string getName() override
    {
        return "Intelligence";
    }
};

struct Agilite : IStat
{
    Agilite(int stat, int min, int max) : IStat(stat, min, max, 1, 1)
    {

    }

    std::string getName() override
    {
        return std::string("Agilité");
    }
};

struct Force : IStat
{
    Force(int stat, int min, int max) : IStat(stat, min, max, 1, 1)
    {

    }

    std::string getName() override
    {
        return "Force";
    }
};

struct RePou : IStat
{
    RePou(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return std::string("Résistance Poussée");
    }
};

struct ReCrit : IStat
{
    ReCrit(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return std::string("Résistance Critiques");
    }
};

struct ReTerre : IStat
{
    ReTerre(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return std::string("Résistance Terre");
    }
};

struct ReNeutre : IStat
{
    ReNeutre(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return std::string("Résistance Neutre");
    }
};

struct ReFeu : IStat
{
    ReFeu(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return std::string("Résistance Feu");
    }
};

struct ReAir : IStat
{
    ReAir(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return std::string("Résistance Air");
    }
};

struct ReEau : IStat
{
    ReEau(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return std::string("Résistance Eau");
    }
};

struct Puissance : IStat
{
    Puissance(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return "Puissance";
    }
};

struct PuiPiege : IStat
{
    PuiPiege(int stat, int min, int max) : IStat(stat, min, max, 1, 2)
    {

    }

    std::string getName() override
    {
        return std::string("Puissance (pièges)");
    }
};

struct Sagesse : IStat
{
    Sagesse(int stat, int min, int max) : IStat(stat, min, max, 1, 3)
    {

    }

    std::string getName() override
    {
        return "Sagesse";
    }
};

struct Prospection : IStat
{
    Prospection(int stat, int min, int max) : IStat(stat, min, max, 1, 3)
    {

    }

    std::string getName() override
    {
        return "Prospection";
    }
};

struct Fuite : IStat
{
    Fuite(int stat, int min, int max) : IStat(stat, min, max, 1, 4)
    {

    }

    std::string getName() override
    {
        return "Fuite";
    }
};

struct Tacle : IStat
{
    Tacle(int stat, int min, int max) : IStat(stat, min, max, 1, 4)
    {

    }

    std::string getName() override
    {
        return "Tacle";
    }
};

struct Chasse : IStat
{
    Chasse(int stat, int min, int max) : IStat(0, 1, 1, 1, 5)
    {

    }

    std::string getName() override
    {
        return "Chasse";
    }
};

struct DoPiege : IStat
{
    DoPiege(int stat, int min, int max) : IStat(stat, min, max, 1, 5)
    {

    }

    std::string getName() override
    {
        return std::string("Dommages Pièges");
    }
};

struct DoPou : IStat
{
    DoPou(int stat, int min, int max) : IStat(stat, min, max, 1, 5)
    {

    }

    std::string getName() override
    {
        return std::string("Dommages Poussée");
    }
};

struct DoCri : IStat
{
    DoCri(int stat, int min, int max) : IStat(stat, min, max, 1, 5)
    {

    }

    std::string getName() override
    {
        return "Dommages Critiques";
    }
};

struct DoEau : IStat
{
    DoEau(int stat, int min, int max) : IStat(stat, min, max, 1, 5)
    {

    }

    std::string getName() override
    {
        return "Dommages Eau";
    }
};

struct DoFeu : IStat
{
    DoFeu(int stat, int min, int max) : IStat(stat, min, max, 1, 5)
    {

    }

    std::string getName() override
    {
        return "Dommages Feu";
    }
};

struct DoTerre : IStat
{
    DoTerre(int stat, int min, int max) : IStat(stat, min, max, 1, 5)
    {

    }

    std::string getName() override
    {
        return "Dommages Terre";
    }
};

struct DoAir : IStat
{
    DoAir(int stat, int min, int max) : IStat(stat, min, max, 1, 5)
    {

    }

    std::string getName() override
    {
        return "Dommages Air";
    }
};

struct DoNeutre : IStat
{
    DoNeutre(int stat, int min, int max) : IStat(stat, min, max, 1, 5)
    {

    }

    std::string getName() override
    {
        return "Dommages Neutre";
    }
};

struct RePerEau : IStat
{
    RePerEau(int stat, int min, int max) : IStat(stat, min, max, 1, 6)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance Eau");
    }
};

struct RePerFeu : IStat
{
    RePerFeu(int stat, int min, int max) : IStat(stat, min, max, 1, 6)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance Feu");
    }
};

struct RePerAir : IStat
{
    RePerAir(int stat, int min, int max) : IStat(stat, min, max, 1, 6)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance Air");
    }
};

struct RePerTerre : IStat
{
    RePerTerre(int stat, int min, int max) : IStat(stat, min, max, 1, 6)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance Terre");
    }
};

struct RePerNeutre : IStat
{
    RePerNeutre(int stat, int min, int max) : IStat(stat, min, max, 1, 6)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance Neutre");
    }
};

struct EsquivePa : IStat
{
    EsquivePa(int stat, int min, int max) : IStat(stat, min, max, 1, 7)
    {

    }

    std::string getName() override
    {
        return "Esquive PA";
    }
};

struct EsquivePm : IStat
{
    EsquivePm(int stat, int min, int max) : IStat(stat, min, max, 1, 7)
    {

    }

    std::string getName() override
    {
        return "Esquive PM";
    }
};

struct RetraitPa : IStat
{
    RetraitPa(int stat, int min, int max) : IStat(stat, min, max, 1, 7)
    {

    }

    std::string getName() override
    {
        return "Retrait PA";
    }
};

struct RetraitPm : IStat
{
    RetraitPm(int stat, int min, int max) : IStat(stat, min, max, 1, 7)
    {

    }

    std::string getName() override
    {
        return "Retrait PM";
    }
};

struct Renvoi : IStat
{
    Renvoi(int stat, int min, int max) : IStat(stat, min, max, 1, 10)
    {

    }

    std::string getName() override
    {
        return "Renvoie dommages";
    }
};

struct Crit : IStat
{
    Crit(int stat, int min, int max) : IStat(stat, min, max, 1, 10)
    {

    }

    std::string getName() override
    {
        return "% Critique";
    }
};

struct Soin : IStat
{
    Soin(int stat, int min, int max) : IStat(stat, min, max, 1, 10)
    {

    }

    std::string getName() override
    {
        return "Soin";
    }
};

struct RePerMe : IStat
{
    RePerMe(int stat, int min, int max) : IStat(stat, min, max, 1, 15)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance mêlée");
    }
};

struct RePerDi : IStat
{
    RePerDi(int stat, int min, int max) : IStat(stat, min, max, 1, 15)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance distance");
    }
};

struct RePerSo : IStat
{
    RePerSo(int stat, int min, int max) : IStat(stat, min, max, 1, 15)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance aux sorts");
    }
};

struct RePerAr : IStat
{
    RePerAr(int stat, int min, int max) : IStat(stat, min, max, 1, 15)
    {

    }

    std::string getName() override
    {
        return std::string("% Résistance aux armes");
    }
};

struct DoPerAr : IStat
{
    DoPerAr(int stat, int min, int max) : IStat(stat, min, max, 1, 15)
    {

    }

    std::string getName() override
    {
        return "% Dommages d'armes";
    }
};

struct DoPerSo : IStat
{
    DoPerSo(int stat, int min, int max) : IStat(stat, min, max, 1, 15)
    {

    }

    std::string getName() override
    {
        return "% Dommages aux sorts";
    }
};

struct DoPerMe : IStat
{
    DoPerMe(int stat, int min, int max) : IStat(stat, min, max, 1, 15)
    {

    }

    std::string getName() override
    {
        return std::string("% Dommages mêlée");
    }
};

struct DoPerDi : IStat
{
    DoPerDi(int stat, int min, int max) : IStat(stat, min, max, 1, 15)
    {

    }

    std::string getName() override
    {
        return "% Dommages distance";
    }
};

struct Dommages : IStat
{
    Dommages(int stat, int min, int max) : IStat(stat, min, max, 1, 20)
    {

    }

    std::string getName() override
    {
        return "Dommages";
    }
};

struct Invocation : IStat
{
    Invocation(int stat, int min, int max) : IStat(stat, min, max, 1, 30)
    {

    }

    std::string getName() override
    {
        return "Invocation";
    }
};

struct PO : IStat
{
    PO(int stat, int min, int max) : IStat(stat, min, max, 1, 51)
    {

    }

    std::string getName() override
    {
        return std::string("Portée");
    }
};

struct GaPM : IStat
{
    GaPM(int stat, int min, int max) : IStat(stat, min, max, 1, 90)
    {

    }

    std::string getName() override
    {
        return "PM";
    }
};

struct GaPA : IStat
{
    GaPA(int stat, int min, int max) : IStat(stat, min, max, 1, 100)
    {

    }

    std::string getName() override
    {
        return "PA";
    }
};

#endif //FM_STATS_HPP
