/*
 * Xournal++
 *
 * Undo move action (EditSelection)
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"

class Layer;
class Redrawable;
class XojPage;

class MoveUndoAction : public UndoAction
{
public:
	MoveUndoAction(Layer* sourceLayer, PageRef sourcePage, vector<Element*>* selected, double mx, double my,
				   Layer* targetLayer, PageRef targetPage);
	~MoveUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;
	vector<PageRef> getPages() override;
	string getText() override;

private:
	void switchLayer(vector<Element*>* entries, Layer* oldLayer, Layer* newLayer);
	void repaint();
	void move();

private:
	XOJ_TYPE_ATTRIB;

	vector<Element*> elements;
	PageRef targetPage;

	Layer* sourceLayer = nullptr;
	Layer* targetLayer = nullptr;

	string text;

	double dx = 0;
	double dy = 0;
};
