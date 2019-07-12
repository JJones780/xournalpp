/*
 * Xournal++
 *
 * PDF Document Export Abstraction Interface
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "XojPdfExport.h"

#include "control/jobs/ProgressListener.h"
#include "model/Document.h"

class XojCairoPdfExport : public XojPdfExport
{
public:
	XojCairoPdfExport(Document* doc, ProgressListener* progressListener);
	~XojCairoPdfExport() override;

public:
	bool createPdf(Path file) override;
	bool createPdf(Path file, PageRangeVector& range) override;
	string getLastError() override;

	/**
	 * Export without background
	 */
	void setNoBackgroundExport(bool noBackgroundExport) override;

private:
	bool startPdf(Path file);
	void endPdf();
	void exportPage(size_t page);

private:
	XOJ_TYPE_ATTRIB;

	Document* doc = nullptr;
	ProgressListener* progressListener = nullptr;

	cairo_surface_t* surface = nullptr;
	cairo_t* cr = nullptr;

	bool noBackgroundExport = false;

	string lastError;
};

