/*
 * Xournal++
 *
 * Draws lined backgrounds of all sorts
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "BaseBackgroundPainter.h"

#include <XournalType.h>

class LineBackgroundPainter : public BaseBackgroundPainter
{
public:
	LineBackgroundPainter(bool ruled);
	~LineBackgroundPainter() override;

public:
	void paint() override;

	/**
	 * Reset all used configuration values
	 */
	void resetConfig() override;


	void paintBackgroundRuled();
	void paintBackgroundLined();

private:
	XOJ_TYPE_ATTRIB;

	bool ruled;
};
