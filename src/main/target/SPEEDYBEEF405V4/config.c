/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include "platform.h"

#ifdef USE_TARGET_CONFIG

#include "io/serial.h"
#include "pg/pinio.h"
#include "pg/piniobox.h"
#include "target.h"
#include "flight/mixer.h"
#include "osd/osd.h"
#include "pg/motor.h"
#include "config_helper.h"
#include "drivers/io.h"
#include "drivers/dma.h"
#include "drivers/timer.h"
#include "drivers/timer_def.h"
#include "target.h"

#define  USE_TARGET_CONFIG
static targetSerialPortFunction_t targetSerialPortFunction[] = {
    { SERIAL_PORT_USART2, FUNCTION_RX_SERIAL },
    { SERIAL_PORT_UART4, FUNCTION_MSP },
    { SERIAL_PORT_UART5,  FUNCTION_ESC_SENSOR },
};
void targetConfiguration(void)
{
    pinioConfigMutable()->config[0] = PINIO_CONFIG_OUT_INVERTED | PINIO_CONFIG_MODE_OUT_PP;
    pinioBoxConfigMutable()->permanentId[0] = BOXARM;
    
    targetSerialPortFunctionConfig(targetSerialPortFunction, ARRAYLEN(targetSerialPortFunction));
    motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DSHOT300;
}
#endif