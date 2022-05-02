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

#ifndef __I2SCALLBACKS_HPP__
#define __I2SCALLBACKS_HPP__

#include <array>
#include <cstdint>
#include <stm32f4xx_hal.h>

class I2SCallbacks
{
public:

    enum class Types
    {
        HAL_I2SEx_TxRxHalfCpltCallback,
        HAL_I2SEx_TxRxCpltCallback,
        capacity,   // special type to get the max size. Do not select as an interrupt vector!
    };

    virtual void callback() = 0;

    static inline std::array<I2SCallbacks*, static_cast<std::size_t>(Types::capacity)> m_callback_handlers;

    void register_handler(Types callback_type, I2SCallbacks *handler)
    {
        if (m_callback_handlers[static_cast<int>(callback_type)] == nullptr)
        {
            m_callback_handlers[static_cast<int>(callback_type)] = handler;
        }
        else
        {
            while(true) { /* something went wrong assigning the handler */ }
        }
    }

};

#endif // __I2SCALLBACKS_HPP__