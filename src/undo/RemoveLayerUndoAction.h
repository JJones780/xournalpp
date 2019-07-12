/*
 * Xournal++
 *
 * Undo action for remove layer
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"

class Layer;
class LayerController;

class RemoveLayerUndoAction : public UndoAction
{
public:
	RemoveLayerUndoAction(LayerController* layerController, PageRef page, Layer* layer, int layerPos);
	~RemoveLayerUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;

private:
	XOJ_TYPE_ATTRIB;

	LayerController* layerController;
	Layer* layer;
	int layerPos;
};
