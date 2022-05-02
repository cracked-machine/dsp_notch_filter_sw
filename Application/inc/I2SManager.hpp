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

#ifndef __I2S_MANAGER_HPP__
#define __I2S_MANAGER_HPP__

#include <I2SCallbacks.hpp>


class I2SManager
{
public:
    I2SManager(I2S_HandleTypeDef &hi2s2);
    HAL_StatusTypeDef start_i2s_dma();

    void i2s_half_complete_transfer_action();
    void i2s_full_complete_transfer_action();

    /// @brief inner class to register i2s_half_complete_transfer_action() with HAL global callback
    struct _HalfComplete : public I2SCallbacks
    {
        I2SManager *m_outer;
        _HalfComplete(I2SManager *outer) {
            m_outer = outer;
            register_handler(I2SCallbacks::Types::HAL_I2SEx_TxRxHalfCpltCallback, this);
        }
        void callback() { m_outer->i2s_half_complete_transfer_action(); }
        
    };

    /// @brief _HalfComplete object
    _HalfComplete m_HalfComplete{this};


    /// @brief inner class to register i2s_full_complete_transfer_action() with HAL global callback
    struct _FullComplete : public I2SCallbacks
    {
        I2SManager *m_outer;
        _FullComplete(I2SManager *outer) {
            m_outer = outer;
            I2SCallbacks::register_handler(I2SCallbacks::Types::HAL_I2SEx_TxRxCpltCallback, this);
        }
        void callback() { m_outer->i2s_full_complete_transfer_action(); }
        
    };    

    /// @brief _FullComplete object
    _FullComplete m__FullComplete{this};
    
private: 

    I2S_HandleTypeDef m_hi2s2;

    /// @brief Size of RX/TX buffers for ADC/DAC
    static constexpr uint8_t m_buffer_size {8};

    /// @brief The bytes received from the CS5343 ADC (via DMA)
    std::array<uint16_t, m_buffer_size> m_rx_buffer;
    /// @brief The bytes transmitted into the CS4344 DAC (via DMA)
    std::array<uint16_t, m_buffer_size> m_tx_buffer;



};


#endif // __I2S_MANAGER_HPP__