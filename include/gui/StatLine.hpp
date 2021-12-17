/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/

#ifndef FM2_H
#define FM2_H

#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <utility>
#include <stat/Stats.hpp>

//<*includes

//*>


class StatLine : public nana::panel<true>
{
public:
    StatLine() = default;

    explicit StatLine(nana::window wd, std::shared_ptr<IStat> stat, const nana::rectangle &r = {}, bool visible = true) : nana::panel<true>(wd, r, visible), m_stat(std::move(stat))
    {
        this->create(wd, r, visible);
        setMinText(std::to_string(m_stat->min));
        setMaxText(std::to_string(m_stat->max));
        setStatText(std::to_string(m_stat->stat) + " " + m_stat->getName());
    }

    bool create(nana::window wd, const nana::rectangle &r = {}, bool visible = true)
    {
        if (!nana::panel<true>::create(wd, r, visible))
            return false;

        init_();

        //<*ctor

        //*>

        return true;
    }

    void setMinText(std::string min)
    {
        m_min_label.caption(std::move(min));
    }

    void setMaxText(std::string max)
    {
        m_max_label.caption(std::move(max));
    }

    void setStatText(std::string stat)
    {
        m_stat_label.caption(std::move(stat));
    }

private:
    void init_()
    {
        place_.bind(*this);
        place_.div("vert margin=[5,5,5,5] <weight=7% margin=[5,5,5,5] gap=2 arrange=[5%,5%,variable,5%,5%,5%] m_stat_field>");
        // m_min_label
        m_min_label.create(*this);
        place_["m_stat_field"] << m_min_label;
        m_min_label.caption("min");
        m_min_label.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
        // m_max_label
        m_max_label.create(*this);
        place_["m_stat_field"] << m_max_label;
        m_max_label.caption("max");
        m_max_label.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
        // m_stat_label
        m_stat_label.create(*this);
        place_["m_stat_field"] << m_stat_label;
        m_stat_label.caption("stat");
        m_stat_label.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
        // m_normal_button
        m_normal_button.create(*this);
        place_["m_stat_field"] << m_normal_button;
        m_normal_button.caption("");
        m_normal_button.events().click([this](){
            m_stat->addNormal();
            setStatText(std::to_string(m_stat->stat) + " " + m_stat->getName());
        });
        // m_pa_button
        m_pa_button.create(*this);
        place_["m_stat_field"] << m_pa_button;
        m_pa_button.caption("Pa");
        m_pa_button.events().click([this](){
            m_stat->addPa();
            setStatText(std::to_string(m_stat->stat) + " " + m_stat->getName());
        });
        // m_ra_button
        m_ra_button.create(*this);
        place_["m_stat_field"] << m_ra_button;
        m_ra_button.caption("Ra");
        m_ra_button.events().click([this](){
            m_stat->addRa();
            setStatText(std::to_string(m_stat->stat) + " " + m_stat->getName());
        });

        place_.collocate();
    }


protected:
    nana::place place_;
    nana::label m_min_label;
    nana::label m_max_label;
    nana::label m_stat_label;
    nana::button m_normal_button;
    nana::button m_pa_button;
    nana::button m_ra_button;


    //<*declarations
    std::shared_ptr<IStat> m_stat;
    //*>
};

#endif //FM2_H

