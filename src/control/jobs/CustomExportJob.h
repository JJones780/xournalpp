/*
 * Xournal++
 *
 * A customized export
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "BaseExportJob.h"
#include "ImageExport.h"

#include "view/DocumentView.h"

#include <PageRange.h>
#include <i18n.h>
#include <map>


class CustomExportJob : public BaseExportJob
{
public:
	CustomExportJob(Control* control);

protected:
	~CustomExportJob() override;

public:
	void run() override;

public:
	bool showFilechooser() override;

protected:
	void afterRun() override;

	void addFilterToDialog() override;

	/**
	 * Create one Graphics file per page
	 */
	void exportGraphics();

	bool isUriValid(string& uri) override;

private:
	XOJ_TYPE_ATTRIB;

	/**
	 * The range to export
	 */
	PageRangeVector exportRange;

	/**
	 * PNG dpi
	 */
	int pngDpi = 300;

	/**
	 * Export graphics format
	 */
	ExportGraphicsFormat format = EXPORT_GRAPHICS_UNDEFINED;

	/**
	 * XOJ Export, else PNG Export
	 */
	bool exportTypeXoj = false;

	string lastError;

	string chosenFilterName;

	std::map<string, ExportType*> filters;
};
