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
#include "gui/GladeGui.h"
#include "model/Font.h"

#include <XournalType.h>

class FontButton : public AbstractToolItem
{
public:
	FontButton(ActionHandler* handler, GladeGui* gui, string id, ActionType type,
			   string description, GtkWidget* menuitem = nullptr);
	~FontButton() override;

public:
	void activated(GdkEvent* event, GtkMenuItem* menuitem, GtkToolButton* toolbutton) override;
	void setFont(XojFont& font);
	XojFont getFont();
	string getToolDisplayName() override;
	void showFontDialog();

protected:
	GtkToolItem* createItem(bool horizontal) override;
	GtkToolItem* createTmpItem(bool horizontal) override;
	GtkToolItem* newItem() override;

	GtkWidget* newFontButton();
	static void setFontFontButton(GtkWidget* fontButton, XojFont& font);

	GtkWidget* getNewToolIcon() override;

private:
	XOJ_TYPE_ATTRIB;


	GtkWidget* fontButton = nullptr;
	GladeGui* gui = nullptr;
	string description;

	XojFont font;
};
