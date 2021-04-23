#pragma once

#include <graphics/Graphics.hpp>
#include <structures/Mouse.hpp>
#include <structures/Cursor.hpp>
#include <structures/Time.hpp>

namespace sdlu {
	// TODO: Eventually we should initialize things once the object gets created
	extern int Initialize();
	extern void Quit();
}