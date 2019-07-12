/*
 * Xournal++
 *
 * Undo action for insert  layer
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
class LayerController;

class InsertLayerUndoAction : public UndoAction
{
public:
	InsertLayerUndoAction(LayerController* layerController, PageRef page, Layer* layer, int layerPosition);
	~InsertLayerUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;

private:
	XOJ_TYPE_ATTRIB;

	int layerPosition;
	LayerController* layerController;
	Layer* layer;
};
