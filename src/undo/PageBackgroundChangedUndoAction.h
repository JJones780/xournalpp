/*
 * Xournal++
 *
 * Undo action for background change
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"

#include "model/BackgroundImage.h"
#include "model/PageRef.h"


class PageBackgroundChangedUndoAction : public UndoAction
{
public:
	PageBackgroundChangedUndoAction(PageRef page, PageType origType, int origPdfPage,
									BackgroundImage origBackgroundImage, double origW, double origH);
	~PageBackgroundChangedUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;

private:
	XOJ_TYPE_ATTRIB;

	PageType origType;
	int origPdfPage;
	BackgroundImage origBackgroundImage;
	double origW;
	double origH;

	PageType newType;
	int newPdfPage = -1;
	BackgroundImage newBackgroundImage;
	double newW = 0;
	double newH = 0;
};
