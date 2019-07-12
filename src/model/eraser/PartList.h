/*
 * Xournal++
 *
 * A list with parts
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <XournalType.h>

#include <gtk/gtk.h>

class EraseableStrokePart;

class PartList
{
public:
	PartList();
	virtual ~PartList();

private:
	PartList(const PartList& list) = delete;
	void operator=(const PartList& list) = delete;

public:
	void add(EraseableStrokePart* part);
	PartList* clone();

private:
	XOJ_TYPE_ATTRIB;

	GList* data = nullptr;

	friend class EraseableStroke;
};
