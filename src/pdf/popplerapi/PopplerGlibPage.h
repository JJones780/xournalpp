/*
 * Xournal++
 *
 * PDF Page GLib Implementation
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "pdf/base/XojPdfPage.h"

#include <poppler.h>


class PopplerGlibPage : public XojPdfPage
{
public:
	PopplerGlibPage(PopplerPage* page);
	PopplerGlibPage(const PopplerGlibPage& other);
	~PopplerGlibPage() override;
	void operator=(const PopplerGlibPage& other);

public:
	double getWidth() override;
	double getHeight() override;

	void render(cairo_t* cr, bool forPrinting = false) override;

	vector<XojPdfRectangle> findText(string& text) override;

	int getPageId() override;

private:
	XOJ_TYPE_ATTRIB;

	PopplerPage* page;
};

