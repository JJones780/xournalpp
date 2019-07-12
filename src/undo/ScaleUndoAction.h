/*
 * Xournal++
 *
 * Undo action for rescale (EditSelection)
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"

class ScaleUndoAction : public UndoAction
{
public:
	ScaleUndoAction(PageRef page, vector<Element*>* elements, double x0, double y0, double fx, double fy);
	~ScaleUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;
	string getText() override;

private:
	void applyScale(double fx, double fy);

private:
	XOJ_TYPE_ATTRIB;

	vector<Element*> elements;

	double x0;
	double y0;
	double fx;
	double fy;
};
