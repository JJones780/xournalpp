/*
 * Xournal++
 *
 * Gzip Helper
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "Path.h"
#include <zlib.h>

class GzUtil
{
private:
	GzUtil() = delete;
	virtual ~GzUtil() = delete;

public:
	static gzFile openPath(Path path, string flags);
};

