/*
 * Xournal++
 *
 * Undo action for font changes
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"
#include <XournalType.h>

class FontUndoActionEntry;
class Layer;
class Redrawable;
class Text;
class XojFont;

class FontUndoAction : public UndoAction
{
public:
	FontUndoAction(PageRef page, Layer* layer);
	~FontUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;
	string getText() override;

	void addStroke(Text* e, XojFont& oldFont, XojFont& newFont);

private:
	XOJ_TYPE_ATTRIB;

	std::vector<FontUndoActionEntry*> data;

	Layer* layer;
};
