/*
 * Xournal++
 *
 * Handles input to draw an coordinate system
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "BaseStrokeHandler.h"

class CoordinateSystemHandler : public BaseStrokeHandler
{
public:
	CoordinateSystemHandler(XournalView* xournal, XojPageView* redrawable, PageRef page, bool flipShift = false, bool flipControl = false);
	~CoordinateSystemHandler() override;

private:
	void drawShape(Point& currentPoint, const PositionInputData& pos) override;
private:
	XOJ_TYPE_ATTRIB;
	Point startPoint;
	bool started = false;
};

