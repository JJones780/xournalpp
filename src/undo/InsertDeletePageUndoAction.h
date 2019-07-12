/*
 * Xournal++
 *
 * Undo action for insert page / delete page
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"
#include <XournalType.h>

class InsertDeletePageUndoAction : public UndoAction
{
public:
	InsertDeletePageUndoAction(PageRef page, int pagePos, bool inserted);
	~InsertDeletePageUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;
private:
	bool insertPage(Control* control);
	bool deletePage(Control* control);

private:
	XOJ_TYPE_ATTRIB;

	bool inserted;
	int pagePos;
};
