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

#include "AbstractToolItem.h"
#include "control/zoom/ZoomListener.h"

#include <XournalType.h>

#define SCALE_LOG_OFFSET 0.20753

class ZoomControl;

class ToolZoomSlider : public AbstractToolItem, public ZoomListener
{
public:
	ToolZoomSlider(ActionHandler* handler, string id, ActionType type, ZoomControl* zoom);
	~ToolZoomSlider() override;

public:
	static void sliderChanged(GtkRange* range, ToolZoomSlider* self);
	static bool sliderButtonPress(GtkRange* range, GdkEvent *event, ToolZoomSlider* self);
	static bool sliderButtonRelease(GtkRange* range, GdkEvent *event, ToolZoomSlider* self);
	static bool sliderHoverScroll(GtkWidget* range,  GdkEventScroll* event, ToolZoomSlider* self);
	static gchar* sliderFormatValue(GtkRange *range, gdouble value, ToolZoomSlider* self);

	void zoomChanged() override;
	void zoomRangeValuesChanged() override;
	string getToolDisplayName() override;

	// Should be called when the window size changes
	void updateScaleMarks();
	GtkToolItem* createItem(bool horizontal) override;
	GtkToolItem* createTmpItem(bool horizontal) override;

protected:
	void enable(bool enabled) override;
	GtkToolItem* newItem() override;
	GtkWidget* getNewToolIcon() override;

private:
	static double scaleFunc(double x);
	static double scaleFuncInv(double x);

private:
	XOJ_TYPE_ATTRIB;


	/**
	 * The slider is currently changing by user, do not update value
	 */
	bool sliderChangingByZoomControlOrInit = false;
	bool sliderChangingBySliderDrag = false;
	bool sliderChangingBySliderHoverScroll = false;
	gint64 sliderHoverScrollLastTime = 0;

	GtkWidget* slider = nullptr;
	ZoomControl* zoom = nullptr;
	bool horizontal = true;
};

