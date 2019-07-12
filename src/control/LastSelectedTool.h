/*
 * Xournal++
 *
 * Handle last selected tool config, if the tool is changed e.g. by right click
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "ToolBase.h"

#include <XournalType.h>

class Tool;

class LastSelectedTool : public ToolBase
{
public:
	LastSelectedTool(Tool* tool);
	~LastSelectedTool() override;

public:
	/**
	 * Restore the tool config and return it
	 */
	Tool* restoreAndGet();

private:
	XOJ_TYPE_ATTRIB;

	/**
	 * The last tool
	 */
	Tool* tool;
};
