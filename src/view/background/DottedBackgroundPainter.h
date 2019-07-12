/*
 * Xournal++
 *
 * Draws dotted background
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "BaseBackgroundPainter.h"

#include <XournalType.h>

class DottedBackgroundPainter : public BaseBackgroundPainter
{
public:
	DottedBackgroundPainter();
	~DottedBackgroundPainter() override;

public:
	void paint() override;
	void paintBackgroundDotted();

	/**
	 * Reset all used configuration values
	 */
	void resetConfig() override;

private:
	XOJ_TYPE_ATTRIB;
};
