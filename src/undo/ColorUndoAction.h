/*
 * Xournal++
 *
 * Undo action for color changes (Edit selection)
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"
#include <XournalType.h>

class ColorUndoActionEntry;
class Element;
class Layer;
class Redrawable;

class ColorUndoAction : public UndoAction
{
public:
	ColorUndoAction(PageRef page, Layer* layer);
	~ColorUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;
	string getText() override;

	void addStroke(Element* e, int originalColor, double newColor);

private:
	XOJ_TYPE_ATTRIB;

	std::vector<ColorUndoActionEntry*> data;
	Layer* layer;
};
