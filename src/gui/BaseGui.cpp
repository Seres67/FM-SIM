//
// Created by Laurent on 7/11/2021.
//

#include <gui/BaseGui.hpp>
#include <gui/ExistingItemPopup.hpp>
#include <gui/NewItemPopup.hpp>
#include <string>

BaseGui::BaseGui() : nana::form(nana::rectangle{100, 100, 800, 800})
{
    caption("Simulateur FM 2.60");
    m_place.div("vert<margin=[5,5,5,5] gap=2 weight=5% menubar><vert margin=[5,5,5,5] gap=2 weight=8% field1>");
    m_place["menubar"] << m_menubar;
    create_menus();
//    m_listbox.append_header("Min", 60);
//    m_listbox.append_header("Max", 60);
//    m_listbox.append_header("Stats", 200);
//    m_listbox.append_header("", 60);
//    m_listbox.append_header("Pa", 60);
//    m_listbox.append_header("Ra", 60);
}

void BaseGui::create_menus()
{
    m_menubar.push_back("&App");
    m_menubar.at(0).append("&Exit", [this](nana::menu::item_proxy &ip)
    {
        std::cout << "closing!" << std::endl;
        close();
    });
    m_menubar.push_back("&Item");
    m_menubar.at(1).append("&New Item");
    auto submenu = m_menubar.at(1).create_sub_menu(0);
    submenu->append("&Preset", [this](nana::menu::item_proxy &ip)
    {
        ExistingItemPopup fm2(this);
        fm2.caption("Select existing item!");
        fm2.show();
        fm2.modality();
    });
    submenu->append("Ne&w", [this](nana::menu::item_proxy &ip)
    {
        NewItemPopup fm2(this);
        fm2.caption("New item!");
        fm2.show();
        fm2.modality();
    });
}

void BaseGui::setItem(std::shared_ptr<IItem> &item)
{
    m_item = item;
    ItemFactory::createItem(m_item.get());

    update_gui();
}

void BaseGui::setItem(IItem *item)
{
    m_item = std::shared_ptr<IItem>(item);
    ItemFactory::createItem(m_item.get());

    update_gui();
}

nana::menubar &BaseGui::getMenuBar()
{
    return m_menubar;
}

void BaseGui::update_gui()
{
    if (!m_item)
        return;
    m_stat_list.clear();
    auto stats = m_item->getStats();
    for (auto &stat : stats)
    {
        m_stat_list.emplace_front(*this, stat);
        auto &stat_list = m_stat_list.front();
        m_place["field1"] << stat_list;
    }
    collocate();

//    m_listbox.clear();
//    auto cat = m_listbox.at(0);
//    auto &stats = m_item->getStats();
//    for (auto &stat : stats)
//        cat.append({std::to_string(stat->getMin()), std::to_string(stat->getMax()), std::string(std::to_string(stat->getStat()) + " " + stat->getName())});
}
