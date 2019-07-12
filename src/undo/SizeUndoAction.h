/*
 * Xournal++
 *
 * Undo action resize
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
class SizeUndoActionEntry;
class Stroke;

class SizeUndoAction : public UndoAction
{
public:
	SizeUndoAction(PageRef page, Layer* layer);
	~SizeUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;
	string getText() override;

	void addStroke(Stroke* s, double originalWidth, double newWidth,
				   vector<double> originalPressure, vector<double> newPressure, int pressureCount);

public:
	static vector<double> getPressure(Stroke* s);

private:
	XOJ_TYPE_ATTRIB;

	std::vector<SizeUndoActionEntry*> data;

	Layer* layer;
};
