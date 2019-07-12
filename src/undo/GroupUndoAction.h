/*
 * Xournal++
 *
 * Undo action to group a list of undo actions of the same type
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"
#include <XournalType.h>

class GroupUndoAction : public UndoAction
{
public:
	GroupUndoAction();
	~GroupUndoAction() override;

public:
	void addAction(UndoAction* action);

	/**
	 * Get the affected pages
	 */
	vector<PageRef> getPages() override;

	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;

private:
	XOJ_TYPE_ATTRIB;

	vector<UndoAction*> actions;
};
