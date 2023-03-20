/****************************************************************************
* This file is part of the PCF8574AT Custom Component for PSoC Devices.
*
* Copyright (C) 2017 Carlos Diaz <carlos.santiago.diaz@gmail.com>
*
* Permission to use, copy, modify, and/or distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
****************************************************************************/

#include "project.h"
#include <stdint.h>
#include <stdbool.h>

#include "LCD_I2C_LL_I2C.h"

void LCD_I2C_writeByte(const uint8_t addr, const uint8_t data)
{
#if defined(CY_SCB_I2C_H) // SCB Block
    I2C_I2CMasterSendStart(addr, 0);
    I2C_I2CMasterWriteByte(data);
    I2C_I2CMasterSendStop();
#else // UDB Block
    I2C_MasterSendStart(addr, 0);
    I2C_MasterWriteByte(data);
    I2C_MasterSendStop();
#endif
}

/* [] END OF FILE */
