/*
 * Xournal++
 *
 * The about dialog
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "gui/GladeGui.h"

class FillTransparencyDialog : public GladeGui
{
public:
	FillTransparencyDialog(GladeSearchpath* gladeSearchPath, int alpha);
	~FillTransparencyDialog() override;

public:
	void show(GtkWindow* parent) override;

	int getResultAlpha();

private:
	void setPreviewImage(int alpha);

private:
	XOJ_TYPE_ATTRIB;

	int resultAlpha = -1;
};
