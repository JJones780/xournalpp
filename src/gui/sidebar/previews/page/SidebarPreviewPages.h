/*
 * Xournal++
 *
 * Previews of the pages in the document
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "gui/sidebar/previews/base/SidebarPreviewBase.h"

#include <XournalType.h>
#include <memory>
#include <utility>

class SidebarPreviewPages : public SidebarPreviewBase
{
public:
	SidebarPreviewPages(Control* control, GladeGui* gui, SidebarToolbar* toolbar);
	~SidebarPreviewPages() override;

public:
	/**
	 * Called when an action is performed
	 */
	void actionPerformed(SidebarActions action) override;

	/**
	 * @overwrite
	 */
	string getName() override;

	/**
	 * @overwrite
	 */
	string getIconName() override;

	/**
	 * Update the preview images
	 * @overwrite
	 */
	void updatePreviews() override;

	/**
	 * Opens the page preview context menu, at the current cursor position, for
	 * the given page.
	 */
	void openPreviewContextMenu();

public:
	// DocumentListener interface (only the part which is not handled by SidebarPreviewBase)
	void pageSizeChanged(size_t page) override;
	void pageChanged(size_t page) override;
	void pageSelected(size_t page) override;
	void pageInserted(size_t page) override;
	void pageDeleted(size_t page) override;

private:
	/**
	 * Unselect the last selected page, if any
	 */
	void unselectPage();

	/**
	 * The context menu to display when a page is right-clicked.
	 */
	GtkWidget* const contextMenu = nullptr;

	/**
	 * The data passed to the menu item callbacks.
	 */
	struct ContextMenuData
	{
		SidebarToolbar* toolbar;
		SidebarActions actions;
	};


	/**
	 * The signals connected to the context menu items. This must be kept track
	 * of so the data can be deallocated safely.
	 */
	std::vector<std::tuple<GtkWidget*, gulong, std::unique_ptr<ContextMenuData>>> contextMenuSignals;

private:
	XOJ_TYPE_ATTRIB;

};
