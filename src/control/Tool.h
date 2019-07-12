/*
 * Xournal++
 *
 * A tool
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "ToolBase.h"

#include <XournalType.h>

class Tool : public ToolBase
{
public:
	Tool(string name, ToolType tool, int color, int capabilities, double* thickness);
	~Tool() override;

public:
	string getName();

	bool hasCapability(ToolCapabilities cap);

	double getThickness(ToolSize size);

protected:
	void setCapability(int capability, bool enabled);

private:
	Tool(const Tool& t) = delete;
	void operator=(const Tool& t) = delete;

private:
	XOJ_TYPE_ATTRIB;

	string name;
	ToolType type;

	double* thickness;

	int capabilities;

	friend class ToolHandler;
};
