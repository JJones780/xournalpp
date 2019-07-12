/*
 * Xournal++
 *
 * Draws graph backgrounds of all sorts
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "BaseBackgroundPainter.h"

#include <XournalType.h>

class GraphBackgroundPainter : public BaseBackgroundPainter
{
public:
	GraphBackgroundPainter();
	~GraphBackgroundPainter() override;

public:
	void paint() override;
	void paintBackgroundGraph();

	/**
	 * Reset all used configuration values
	 */
	void resetConfig() override;

	double getUnitSize();

private:
	XOJ_TYPE_ATTRIB;
};
