/*
 * Xournal++
 *
 * Undo action for text editing
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
class Text;
class TextEditor;

class TextUndoAction : public UndoAction
{
public:
	TextUndoAction(PageRef page, Layer* layer, Text* text, string lastText, TextEditor* textEditor);
	~TextUndoAction() override;

public:
	bool undo(Control* control) override;
	bool redo(Control* control) override;

	string getText() override;

	string getUndoText();

	void textEditFinished();

private:
	XOJ_TYPE_ATTRIB;

	Layer* layer;
	Text* text;
	string lastText;
	string newText;

	TextEditor* textEditor;
};
