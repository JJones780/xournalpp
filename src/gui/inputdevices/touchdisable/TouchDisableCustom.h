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


class TouchDisableCustom : public TouchDisableInterface
{
public:
	TouchDisableCustom(string enableCommand, string disableCommand);
	~TouchDisableCustom() override;

public:
	void enableTouch() override;
	void disableTouch() override;

private:
	XOJ_TYPE_ATTRIB;

	string enableCommand;
	string disableCommand;
};
