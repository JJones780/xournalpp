/*
 * Xournal++
 *
 * Part of the customizable toolbars
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "ToolButton.h"
#include "gui/GladeGui.h"

#include <XournalType.h>

class ToolMenuHandler;

class ToolSelectCombocontrol : public ToolButton
{
public:
	ToolSelectCombocontrol(ToolMenuHandler* toolMenuHandler, ActionHandler* handler, string id);
	~ToolSelectCombocontrol() override;

public:
	void selected(ActionGroup group, ActionType action) override;

protected:
	GtkToolItem* newItem() override;
	void addMenuitem(string text, string icon, ActionType type, ActionGroup group);

private:
	XOJ_TYPE_ATTRIB;

	ToolMenuHandler* toolMenuHandler = nullptr;
	GtkWidget* popup = nullptr;

	GtkWidget* iconWidget = nullptr;
	GtkWidget* labelWidget = nullptr;
};
