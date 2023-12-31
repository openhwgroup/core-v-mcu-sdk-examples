/*
 * Copyright 2021 QuickLogic
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "target/core-v-mcu/include/core-v-mcu-config.h"
#include "hal/include/hal_apb_soc_ctrl_reg_defs.h"
#include "hal/include/hal_pinmux.h"

void hal_setpullup( uint8_t io_num, uint8_t on )
{
	SocCtrl_t * psoc_ctrl = ( SocCtrl_t* ) SOC_CTRL_START_ADDR;
	psoc_ctrl->io_ctrl_b[ io_num ].cfg = ( uint8_t ) ( on
		& REG_IO_CTRL_CFG_MASK );
}

void hal_setpinmux( uint8_t io_num, uint8_t mux_sel )
{
	SocCtrl_t * psoc_ctrl = ( SocCtrl_t* ) SOC_CTRL_START_ADDR;
	psoc_ctrl->io_ctrl_b[ io_num ].mux = ( uint8_t ) ( mux_sel
		& REG_IO_CTRL_MUX_MASK );
}

uint8_t hal_getpinmux( uint8_t io_num )
{
	SocCtrl_t * psoc_ctrl = ( SocCtrl_t* ) SOC_CTRL_START_ADDR;
	return psoc_ctrl->io_ctrl_b[ io_num ].mux;
}
