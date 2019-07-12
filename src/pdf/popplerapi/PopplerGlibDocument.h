/*
 * Xournal++
 *
 * Poppler GLib Implementation
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "pdf/base/XojPdfDocumentInterface.h"

#include <poppler.h>

class PopplerGlibDocument : public XojPdfDocumentInterface
{
public:
	PopplerGlibDocument();
	PopplerGlibDocument(const PopplerGlibDocument& doc);
	~PopplerGlibDocument() override;

public:
	void assign(XojPdfDocumentInterface* doc) override;
	bool equals(XojPdfDocumentInterface* doc) override;

public:
	bool save(Path filename, GError** error) override;
	bool load(Path filename, string password, GError** error) override;
	bool load(gpointer data, gsize length, string password, GError** error) override;
	bool isLoaded() override;

	XojPdfPageSPtr getPage(size_t page) override;
	size_t getPageCount() override;
	XojPdfBookmarkIterator* getContentsIter() override;

private:
	XOJ_TYPE_ATTRIB;

	PopplerDocument* document = nullptr;
};
