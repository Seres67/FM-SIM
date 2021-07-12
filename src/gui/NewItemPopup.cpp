//
// Created by Laurent on 7/11/2021.
//

#include <gui/NewItemPopup.hpp>
#include <util/Utils.hpp>

NewItemPopup::NewItemPopup(BaseGui *owner) : nana::form(*owner)
{
    caption("New item");
    m_place.div("vert margin=[5,5,5,5] gap=2 arrange=[variable,15%,70%] _field_");

    m_place["_field_"] << m_title;
    m_title.caption("Create a new item!");
    m_title.text_align(nana::align::center, nana::align_v::center);

    m_panel1_place.bind(m_panel);
    m_panel1_place.div("weight=15% margin=[5,5,5,5] gap=2 arrange=[10%,10%,variable,20%] _field_");
    m_place["_field_"] << m_panel;

    m_panel1_place["_field_"] << m_min_text;
    m_min_text.tip_string("Min").multi_lines(false);

    m_panel1_place["_field_"] << m_max_text;
    m_max_text.tip_string("Max").multi_lines(false);

    m_panel1_place["_field_"] << m_stat_selector;
    m_stat_selector.option(0);
    m_stat_list = Utils::getAllStatsNames();
    for (auto &stat : m_stat_list)
        m_stat_selector.push_back(stat);

    m_panel1_place["_field_"] << m_add_stat;
    m_add_stat.caption("Add");
    m_add_stat.events().key_press([this](const nana::arg_keyboard &key)
    {
        if (key.key == 10 || key.key == 13)
        {
            auto selected = m_stat_selector.option();
            if (selected > m_stat_list.size())
                return;
            std::string stat_selected = m_stat_list[selected];
            if (m_min_text.text().empty() || m_max_text.text().empty())
                return;
            auto min = m_min_text.text();
            auto max = m_max_text.text();
            m_stat_display.at(0).append({min, max, stat_selected});
            m_stat_selector.erase(selected);
            m_stat_list.erase(m_stat_list.begin() + static_cast<long long>(selected));
            m_stat_selector.option(0);
        }
    });
    m_add_stat.events().click([this]()
    {
        auto selected = m_stat_selector.option();
        if (selected > m_stat_list.size())
            return;
        std::string stat_selected = m_stat_list[selected];
        if (m_min_text.text().empty() || m_max_text.text().empty())
            return;
        auto min = m_min_text.text();
        auto max = m_max_text.text();
        m_stat_display.at(0).append({min, max, stat_selected});
        m_stat_selector.erase(selected);
        m_stat_list.erase(m_stat_list.begin() + static_cast<long long>(selected));
        m_stat_selector.option(0);
    });

    m_place["_field_"] << m_stat_display;
    m_stat_display.append_header("Min", 50);
    m_stat_display.append_header("Max", 50);
    m_stat_display.append_header("Stat", 180);

    m_place["_field_"] << m_item_finished;
    m_item_finished.caption("Finish");
    m_item_finished.events().click([this, owner](){
        std::vector<stat_infos> stats;
        for (auto & text: m_stat_display.at(0))
            stats.emplace_back(stat_infos({std::stoi(text.text(0)), std::stoi(text.text(1)), text.text(2)}));
        auto *item = new IItem(stats);
        owner->setItem(item);
        close();
    });

    m_place.collocate();
    m_panel1_place.collocate();
}
