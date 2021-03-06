/*
 * Xournal++
 *
 * Handles input to draw a rectangle
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "BaseStrokeHandler.h"

class RectangleHandler : public BaseStrokeHandler
{
public:
	RectangleHandler(XournalView* xournal, XojPageView* redrawable, PageRef page);
	virtual ~RectangleHandler();

private:
	virtual void drawShape(Point& currentPoint, bool shiftDown);

private:
	XOJ_TYPE_ATTRIB;
};

