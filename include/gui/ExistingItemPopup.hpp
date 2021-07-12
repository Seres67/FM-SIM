//
// Created by Laurent on 7/11/2021.
//

#ifndef FM_EXISTINGITEMPOPUP_HPP
#define FM_EXISTINGITEMPOPUP_HPP

#include <vector>
#include <forward_list>
#include "BaseGui.hpp"
#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <item/AnneauVolkorne.hpp>
#include <item/AllianceGloursonne.hpp>
#include <item/Gelano.hpp>

class ExistingItemPopup : public nana::form
{
public:
    explicit ExistingItemPopup(BaseGui *owner);

private:
    std::vector<std::shared_ptr<IItem>> m_existing_items{std::make_shared<Gelano>(), std::make_shared<AnneauVolkorne>(), std::make_shared<AllianceGloursonne>()};
    std::forward_list<nana::button> m_item_buttons;
    nana::label m_title{*this};
    nana::place m_place{*this};
};

#endif //FM_EXISTINGITEMPOPUP_HPP
