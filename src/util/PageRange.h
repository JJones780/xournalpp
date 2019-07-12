/*
 * Xournal++
 *
 * A page range for PDF export etc. (e.g. 1-2,5,7)
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "XournalType.h"

class PageRangeEntry
{
public:
	PageRangeEntry(int first, int last);
	virtual ~PageRangeEntry();

public:
	int getLast();
	int getFirst();

private:
	XOJ_TYPE_ATTRIB;

	int first;
	int last;
};

using PageRangeVector = vector<PageRangeEntry *>;

class PageRange
{
private:
	PageRange() = delete;
	virtual ~PageRange() = delete;

public:
	static bool isSeparator(char c);
	static PageRangeVector parse(const char* str);
};
