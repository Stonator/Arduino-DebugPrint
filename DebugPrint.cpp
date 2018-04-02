
#include "DebugPrint.h"

CDebugPrint::CDebugPrint(Print *p_pDebugPrint)
    : m_pDebugPrint(p_pDebugPrint)
{
}

size_t CDebugPrint::write(uint8_t c)
{
    if(m_pDebugPrint)
        return(m_pDebugPrint->write(c));
    return(0);
}
