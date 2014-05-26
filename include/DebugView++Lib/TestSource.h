// (C) Copyright Gert-Jan de Vos and Jan Wilmans 2013.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)

// Repository at: https://github.com/djeedjay/DebugViewPP/

#pragma once

#include <boost/utility.hpp>
#include <boost/thread.hpp>
#include <boost/signals2.hpp>

#include "LogSource.h"
#include "DBWinBuffer.h"
#include "ProcessHandleCache.h"
#include "Win32Lib/utilities.h"

namespace fusion {
namespace debugviewpp {

class TestSource : public LogSource
{
public:
	explicit TestSource(LineBuffer& linebuffer);
	~TestSource();

	virtual bool AtEnd() const;
	virtual HANDLE GetHandle() const;
	virtual void Notify();
	virtual Lines GetLines();

	void Add(HANDLE handle, const char* text);
private:
	Timer m_timer;
};

} // namespace debugviewpp 
} // namespace fusion
