/*
 * Xournal++
 *
 * Dialog with export settings
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "control/settings/Settings.h"
#include "gui/GladeGui.h"

#include <PageRange.h>

class ExportDialog : public GladeGui
{
public:
	ExportDialog(GladeSearchpath* gladeSearchPath);
	~ExportDialog() override;

public:
	void show(GtkWindow* parent) override;
	void removeDpiSelection();
	void initPages(int current, int count);
	int getPngDpi();
	bool isConfirmed();
	PageRangeVector getRange();

private:
	XOJ_TYPE_ATTRIB;

	int currentPage = 0;
	int pageCount = 0;

	bool confirmed = false;
};
