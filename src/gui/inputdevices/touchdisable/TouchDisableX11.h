/*
 * Xournal++
 *
 * Interface for touch disable implementations
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <XournalType.h>

#include "TouchDisableInterface.h"

#define X11_ENABLED

#ifdef WIN32
#undef X11_ENABLED
#endif
#ifdef __APPLE__
#undef X11_ENABLED
#endif

#ifdef X11_ENABLED

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/extensions/XInput.h>

class TouchDisableX11 : public TouchDisableInterface
{
public:
	TouchDisableX11();
	~TouchDisableX11() override;

public:
	void enableTouch() override;
	void disableTouch() override;
	void init() override;

private:
	XOJ_TYPE_ATTRIB;

	/**
	 * X11 Display
	 */
	Display* display = nullptr;

	/**
	 * Touch device ID
	 */
	Atom touchAtom = None;

	/**
	 * Touch device
	 */
	XDeviceInfo* touch = nullptr;

	/**
	 * Touch device
	 */
	XDevice* touchdev = nullptr;

	/**
	 * Enable flag
	 */
	Atom enabledAtom = None;
};

#endif
