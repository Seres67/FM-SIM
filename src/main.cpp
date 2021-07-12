#include <gui/BaseGui.hpp>
#include <nana/gui.hpp>

int main()
{
    BaseGui gui;

    gui.show();
    nana::exec();
    return 0;
}
