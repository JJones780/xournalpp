/*
 * Xournal++
 *
 * Undo action for insert (write text, draw stroke...)
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"

class Element;
class Layer;
class Redrawable;

class InsertUndoAction : public UndoAction
{
public:
	InsertUndoAction(PageRef page, Layer* layer, Element* element);
	~InsertUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;

private:
	XOJ_TYPE_ATTRIB;

	Layer* layer;
	Element* element;
};

class InsertsUndoAction : public UndoAction
{
public:
	InsertsUndoAction(PageRef page, Layer* layer, vector<Element*> elements);
	~InsertsUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;

private:
	XOJ_TYPE_ATTRIB;

	Layer* layer;
	vector<Element*> elements;

};
