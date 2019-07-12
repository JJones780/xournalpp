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

#include "AbstractToolItem.h"
#include "control/ToolHandler.h"

#include <XournalType.h>

class ColorSelectImage;

class ColorToolItem : public AbstractToolItem
{
public:
	ColorToolItem(ActionHandler* handler, ToolHandler* toolHandler, GtkWindow* parent, int color,
			bool selektor = false);
	~ColorToolItem() override;

public:
	void actionSelected(ActionGroup group, ActionType action) override;
	void enableColor(int color);
	bool colorEqualsMoreOreLess(int color);
	void activated(GdkEvent* event, GtkMenuItem* menuitem, GtkToolButton* toolbutton) override;

	string getToolDisplayName() override;
	GtkWidget* getNewToolIcon() override;

	string getId() override;

	int getColor();

	/**
	 * Enable / Disable the tool item
	 */
	void enable(bool enabled) override;

protected:
	GtkToolItem* newItem() override;
	void updateName();
	bool isSelector();

	/**
	 * Free the allocated icons
	 */
	void freeIcons();

	/**
	 * Show colochooser to select a custom color
	 */
	void showColorchooser();

private:
	XOJ_TYPE_ATTRIB;

	/**
	 * Color
	 */
	int color;

	/**
	 * Name of the Color
	 */
	string name;

	/**
	 * Icon to display
	 */
	ColorSelectImage* icon = nullptr;

	/**
	 * Switch to pen if the color icon is pressed
	 */
	bool switchToPen = false;

	GtkWindow* parent = nullptr;
	ToolHandler* toolHandler = nullptr;

	static bool inUpdate;
};
