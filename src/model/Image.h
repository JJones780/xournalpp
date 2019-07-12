/*
 * Xournal++
 *
 * An Image on the document
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "Element.h"
#include <XournalType.h>

class Image : public Element
{
public:
	Image();
	~Image() override;

public:
	void setWidth(double width);
	void setHeight(double height);

	void setImage(string data);
	void setImage(cairo_surface_t* image);
	void setImage(GdkPixbuf* img);
	cairo_surface_t* getImage();

	void scale(double x0, double y0, double fx, double fy) override;
	void rotate(double x0, double y0, double xo, double yo, double th) override;

	/**
	 * @overwrite
	 */
	Element* clone() override;

public:
	// Serialize interface
	void serialize(ObjectOutputStream& out) override;
	void readSerialized(ObjectInputStream& in) override;

private:
	void calcSize() override;

	static cairo_status_t cairoReadFunction(Image* image, unsigned char* data, unsigned int length);
private:
	XOJ_TYPE_ATTRIB;


	cairo_surface_t* image = nullptr;

	string data;

	string::size_type read = false;
};
