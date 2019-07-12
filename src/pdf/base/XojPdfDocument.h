/*
 * Xournal++
 *
 * PDF Document Container
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "XojPdfPage.h"
#include "XojPdfBookmarkIterator.h"
#include "XojPdfDocumentInterface.h"

#include "pdf/base/XojPdfDocumentInterface.h"

#include <XournalType.h>

class XojPdfDocument : XojPdfDocumentInterface
{
public:
	XojPdfDocument();
	XojPdfDocument(const XojPdfDocument& doc);
	~XojPdfDocument() override;

public:
	void operator=(XojPdfDocument& doc);
	bool operator==(XojPdfDocument& doc);
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

public:
	XojPdfDocumentInterface* getDocumentInterface();

private:
	XOJ_TYPE_ATTRIB;

	XojPdfDocumentInterface* doc;
};

