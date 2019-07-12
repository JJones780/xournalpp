/*
 * Xournal++
 *
 * Toolbar icon for separator (only used for drag and drop and so)
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <gtk/gtk.h>

/**
 * Menuitem handler
 */
class ToolbarSeparatorImage
{
private:
	ToolbarSeparatorImage() = delete;
	virtual ~ToolbarSeparatorImage() = delete;

public:
	static GtkWidget* newSepeartorImage();
};
