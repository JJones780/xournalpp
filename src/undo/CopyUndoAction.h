/*
 * Xournal++
 *
 * Undo action for page copy
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"
#include <XournalType.h>

class CopyUndoAction : public UndoAction
{
public:
	CopyUndoAction(PageRef pageref, int pageNr);
	~CopyUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;

private:
	XOJ_TYPE_ATTRIB;

	int pageNr;
};
