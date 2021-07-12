//
// Created by Laurent on 7/11/2021.
//

#ifndef FM_NEWITEMPOPUP_HPP
#define FM_NEWITEMPOPUP_HPP

#include <gui/BaseGui.hpp>
#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/widgets/panel.hpp>

class NewItemPopup : public nana::form
{
public:
    explicit NewItemPopup(BaseGui *owner);

private:
    std::forward_list<nana::button> m_item_buttons;
    nana::label m_title{*this};
    nana::place m_place{*this};
    nana::panel<true> m_panel{*this};
    nana::button m_add_stat{m_panel};
    std::vector<std::string> m_stat_list;
    nana::combox m_stat_selector{m_panel};
    nana::textbox m_min_text{m_panel}, m_max_text{m_panel};
    nana::listbox m_stat_display{*this};
    nana::button m_item_finished{*this};
    nana::place m_panel1_place;
};


#endif //FM_NEWITEMPOPUP_HPP
