// MIT License

// Copyright (c) 2022 Chris Sutton

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <I2SManager.hpp>
#include <SEGGER_RTT.h>
#include <gpio.h>

I2SManager::I2SManager(I2S_HandleTypeDef &hi2s2) : m_hi2s2(hi2s2)
{
	// switch relay to audio FX bypass
	HAL_GPIO_WritePin(RelayCoilOut_GPIO_Port, RelayCoilOut_Pin, GPIO_PIN_SET);
}

HAL_StatusTypeDef I2SManager::start_i2s_dma()
{
    return HAL_I2SEx_TransmitReceive_DMA (&m_hi2s2, m_tx_buffer.data(), m_rx_buffer.data(), 4);
}

void I2SManager::i2s_half_complete_transfer_action()
{   
    // passthru
	m_tx_buffer[0] = m_rx_buffer[0];
	m_tx_buffer[1] = m_rx_buffer[1];
	m_tx_buffer[2] = m_rx_buffer[2];
	m_tx_buffer[3] = m_rx_buffer[3];

	SEGGER_RTT_printf(0,"%u %u %u %u", m_tx_buffer[0], m_tx_buffer[1], m_tx_buffer[2], m_tx_buffer[3]);
}
void I2SManager::i2s_full_complete_transfer_action()
{
    // passthru
	m_tx_buffer[4] = m_rx_buffer[4];
	m_tx_buffer[5] = m_rx_buffer[5];
	m_tx_buffer[6] = m_rx_buffer[6];
	m_tx_buffer[7] = m_rx_buffer[7];

	SEGGER_RTT_printf(0," %u %u %u %u\n", m_tx_buffer[4], m_tx_buffer[5], m_tx_buffer[6], m_tx_buffer[7]);
}
