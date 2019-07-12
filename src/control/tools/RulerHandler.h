/*
 * Xournal++
 *
 * Handles input of the ruler
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "BaseStrokeHandler.h"

class RulerHandler : public BaseStrokeHandler
{
public:
	RulerHandler(XournalView* xournal, XojPageView* redrawable, PageRef page);
	~RulerHandler() override;

private:
	void drawShape(Point& currentPoint, const PositionInputData& pos) override;
	void snapRotation(double& x, double& y);

private:
	XOJ_TYPE_ATTRIB;
};

