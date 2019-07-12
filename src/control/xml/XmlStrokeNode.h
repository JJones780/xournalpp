/*
 * Xournal++
 *
 * XML Writer helper class
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "XmlNode.h"
#include "model/Point.h"

class XmlStrokeNode : public XmlNode
{
public:
	XmlStrokeNode(const char* tag);
	~XmlStrokeNode() override;

public:
	void setPoints(Point* points, int pointsLength);
	void setWidth(double width, double* widths, int widthsLength);

	void writeOut(OutputStream* out) override;

private:
	XOJ_TYPE_ATTRIB;

	Point* points;
	int pointsLength;

	double width;

	double* widths;
	int widthsLength;
};
