/*
 * Xournal++
 *
 * Part of the customizable toolbars
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <XournalType.h>

class ToolbarItem
{
public:
	ToolbarItem(string name);
	ToolbarItem(const ToolbarItem& item);
	ToolbarItem();
	virtual ~ToolbarItem();

private:
	void operator=(const ToolbarItem& other) = delete;

public:
	string getName();

	bool operator==(ToolbarItem& other);

	int getId();

private:
	XOJ_TYPE_ATTRIB;

	string name;
	int id;

	static int sid;
};
