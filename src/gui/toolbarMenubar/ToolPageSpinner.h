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
#include <XournalType.h>

class GladeGui;
class SpinPageAdapter;

class ToolPageSpinner : public AbstractToolItem
{
public:
	ToolPageSpinner(GladeGui* gui, ActionHandler* handler, string id, ActionType type);
	~ToolPageSpinner() override;

public:
	SpinPageAdapter* getPageSpinner();
	void setText(string text);
	string getToolDisplayName() override;

protected:
	GtkToolItem* newItem() override;
	GtkWidget* getNewToolIcon() override;

private:
	XOJ_TYPE_ATTRIB;

	GladeGui* gui = nullptr;

	SpinPageAdapter* pageSpinner = nullptr;
	GtkWidget* lbPageNo = nullptr;
};
