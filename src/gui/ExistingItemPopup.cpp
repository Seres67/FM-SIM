//
// Created by Laurent on 7/11/2021.
//

#include <gui/ExistingItemPopup.hpp>

ExistingItemPopup::ExistingItemPopup(BaseGui *owner) : nana::form(*owner)
{
    caption("Preset");

    m_place.div("vert<label weight=15%><button margin=2 gap=2>");
    m_title.caption("Select existing item!");
    m_title.text_align(nana::align::center, nana::align_v::center);
    m_place["label"] << m_title;
    for (auto &item : m_existing_items)
    {
        m_item_buttons.emplace_front(this->handle());
        auto &button = m_item_buttons.front();
        button.caption(item->getName());
        m_place["button"] << button;
        button.events().click([this, owner, &item](){
            owner->setItem(item);
            close();
        });
    }
    m_place.collocate();
}
