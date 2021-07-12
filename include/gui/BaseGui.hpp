//
// Created by Laurent on 7/10/2021.
//

#ifndef FM_BASEGUI_HPP
#define FM_BASEGUI_HPP

#include <iostream>
#include <forward_list>
#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/menubar.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/listbox.hpp>
#include <item/IItem.hpp>
#include <stat/Stats.hpp>
#include <item/ItemFactory.hpp>
#include "fm2.h"

class BaseGui : public nana::form
{
public:
    BaseGui();

    void setItem(std::shared_ptr<IItem> &item);
    void setItem(IItem *item);

    nana::menubar &getMenuBar();

private:

    void update_gui();

    void create_menus();

    std::shared_ptr<IItem> m_item = nullptr;
    nana::menubar m_menubar{*this};
    nana::place m_place{*this};
    std::forward_list<nana::label> m_stat_labels;
    std::forward_list<fm2> m_stat_list;
//    nana::listbox m_listbox{*this, nana::rectangle{30, 30, 710, 740}};
};

#endif //FM_BASEGUI_HPP
