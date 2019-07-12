/*
 * Xournal++
 *
 * A job which redraws a page or a page region
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "Job.h"

#include <XournalType.h>

#include <gtk/gtk.h>

class Rectangle;
class XojPageView;

class RenderJob : public Job
{
public:
	RenderJob(XojPageView* view);

protected:
	~RenderJob() override;

public:
	JobType getType() override;

	void* getSource() override;

	void run() override;

private:
	/**
	 * Repaint the widget in UI Thread
	 */
	void repaintWidget(GtkWidget* widget);

	void rerenderRectangle(Rectangle* rect);

private:
	XOJ_TYPE_ATTRIB;

	XojPageView* view;
};
