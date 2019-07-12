/*
 * Xournal++
 *
 * Undo action for eraser
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"
#include <XournalType.h>

class Layer;
class Redrawable;
class Stroke;

class EraseUndoAction : public UndoAction
{
public:
	EraseUndoAction(PageRef page);
	~EraseUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	void addOriginal(Layer* layer, Stroke* element, int pos);
	void addEdited(Layer* layer, Stroke* element, int pos);
	void removeEdited(Stroke* element);

	void finalize();

	string getText() override;
	
private:
	XOJ_TYPE_ATTRIB;

	GList* edited = nullptr;
	GList* original = nullptr;
};
