/*
 * Xournal++
 *
 * Undo page swap action
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"
#include "model/PageRef.h"

class Control;

class SwapUndoAction : public UndoAction
{
public:
	SwapUndoAction(size_t pageNr, bool moveUp, PageRef swappedPage, PageRef otherPage);

	~SwapUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;
	vector<PageRef> getPages() override;
	string getText() override;

private:
	void swap(Control* control);

private:
	XOJ_TYPE_ATTRIB;

	size_t pageNr;
	PageRef swappedPage;
	PageRef otherPage;
	bool moveUp;
};
