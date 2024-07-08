#pragma once
#include <array>
#include <cstdint>


class Renderer
{
private:
    static const unsigned int m_fieldWidth = 100; 
    static const unsigned int m_fieldHeight = 30; 
    static constexpr unsigned int m_pixels = m_fieldWidth * m_fieldHeight;

    const char* m_symbols = " .#2345678";

    // ~#Oo\-/|

    // seems pretty janky just putting that in here


    const char* m_intro =
    "....................................................................................................\n"
    "....................................................................................................\n"
    "....................................................................................................\n"
    "..........._______....______...__....__...______....................................................\n"
    "..........|       \\../      \\.|  \\..|  \\./      \\...................................................\n"
    "..........| $$$$$$$\\|  $$$$$$\\| $$\\.| $$|  $$$$$$\\..................................................\n"
    "..........| $$__/ $$| $$..| $$| $$$\\| $$| $$.__\\$$..................................................\n"
    "..........| $$    $$| $$..| $$| $$$$\\ $$| $$|    \\..................................................\n"
    "..........| $$$$$$$.| $$..| $$| $$\\$$ $$| $$.\\$$$$..................................................\n"
    "..........| $$......| $$__/ $$| $$.\\$$$$| $$__| $$..................................................\n"
    "..........| $$.......\\$$    $$| $$..\\$$$.\\$$    $$..................................................\n"
    "...........\\$$........\\$$$$$$..\\$$...\\$$..\\$$$$$$...................................................\n"
    "....................................................................................................\n"
    "....................................................................................................\n"
    "...LEFT.SLIDER.......................................................................RIGHT.SLIDER...\n"
    "....................................................................................................\n"
    "....\\......../.........................................................................../\\.........\n"
    ".....\\../\\../.........................................................................../##\\........\n"
    "......\\/..\\/.........................................................................../_##_\\.......\n"
    ".........................................................................................||.........\n"
    "...../#####..............................................................................||.........\n"
    ".....|..............................................................................................\n"
    ".....\\####\\..............................................................................TT.........\n"
    "...........|.............................................................................||.........\n"
    ".....#####/............................................................................\\-##-/.......\n"
    "........................................................................................\\##/........\n"
    ".........................................................................................\\/.........\n"
    "....................................................................................................\n"
    "...Press.ESC.to.quit.........................................................Press.SPACE.to.start...\n"
    "....................................................................................................\n";

    std::array<uint_fast8_t,m_pixels> m_consoleBufferOld;
    std::array<uint_fast8_t,m_pixels> m_consoleBuffer;

public:
    Renderer();
    ~Renderer();
    // void setGameCoordRange(unsigned int width, unsigned int height); 
    void setCursorPosition(int x, int y);
    void renderGameField(bool intro);
    void setFieldVal(unsigned int x,unsigned int y, unsigned int symbolIndex);
    unsigned int getFieldVal(unsigned int x,unsigned int y);
    void updateField();
    void showConsoleCursor(bool showFlag);
};

