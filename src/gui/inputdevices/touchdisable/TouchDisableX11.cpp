#include "TouchDisableX11.h"

#ifdef X11_ENABLED

#include <gdk/gdkx.h>

TouchDisableX11::TouchDisableX11()
 : display(NULL),
   touchAtom(None),
   touch(NULL),
   touchdev(NULL),
   enabledAtom(None)
{
	XOJ_INIT_TYPE(TouchDisableX11);
}

TouchDisableX11::~TouchDisableX11()
{
	XOJ_CHECK_TYPE(TouchDisableX11);

	if (touchdev)
	{
		XCloseDevice(display, touchdev);
		touchdev = NULL;
	}

	display = NULL;

	XOJ_RELEASE_TYPE(TouchDisableX11);
}

void TouchDisableX11::init()
{
	XOJ_CHECK_TYPE(TouchDisableX11);

	// Get display from GTK
	display = gdk_x11_display_get_xdisplay(gdk_display_get_default());
	if (display == NULL)
	{
		g_error("Could not open X11 display");
		return;
	}

	touchAtom = XInternAtom(display, "TOUCHSCREEN", true);
	if (touchAtom == None)
	{
		touchAtom = XInternAtom(display, XI_TOUCHSCREEN, false);
	}


	int inputDeviceCount = 0;
	XID touchId = 0;
	XDeviceInfo* devices = XListInputDevices(display, &inputDeviceCount);
	for (int i = 0; i < inputDeviceCount; i++)
	{
		if (touchId == 0 && devices[i].type == touchAtom)
		{
			touchId = devices[i].id;
		}

		if (devices[i].id == touchId)
		{
			touch = devices + i;
		}
	}

	if (touch == NULL)
	{
		g_warning("Could not find touchscreen device for disabling");
		return;
	}

	touchdev = XOpenDevice(display, touch->id);
	if (!touchdev)
	{
		g_warning("Failed to open touch device «%s»", touch->name);
		return;
	}

	g_message("X11 Touch disabler active for device «%s»", touch->name);

	enabledAtom = XInternAtom(display, "Device Enabled", false);
}

void TouchDisableX11::enableTouch()
{
	XOJ_CHECK_TYPE(TouchDisableX11);

	if (!touchdev)
	{
		return;
	}

	unsigned char value = 1;
	XChangeDeviceProperty(display, touchdev, enabledAtom, XA_INTEGER, 8, PropModeReplace, &value, 1);
	g_message("X11 Touch enabled");
}

void TouchDisableX11::disableTouch()
{
	XOJ_CHECK_TYPE(TouchDisableX11);

	if (!touchdev)
	{
		return;
	}
	unsigned char value = 0;
	XChangeDeviceProperty(display, touchdev, enabledAtom, XA_INTEGER, 8, PropModeReplace, &value, 1);
	g_message("X11 Touch disabled");
}

#endif
