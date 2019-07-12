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

#include "Attribute.h"
#include <XournalType.h>

class DoubleArrayAttribute : public XMLAttribute
{
public:
	DoubleArrayAttribute(const char* name, double* values, int count);
	~DoubleArrayAttribute() override;

public:
	void writeOut(OutputStream* out) override;

private:
	XOJ_TYPE_ATTRIB;


	double* values;
	int count;
};
